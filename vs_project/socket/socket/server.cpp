/*************************************************************************
	> File Name: server.cpp
	> Author: SongLee
	> E-mail: lisong.shine@qq.com
	> Created Time: 2016年04月28日 星期四 22时02分43秒
	> Personal Blog: http://songlee24.github.io/
	> https ://blog.csdn.net/lisonglisonglisong/article/details/51328062
 ************************************************************************/
#include<netinet/in.h>   // sockaddr_in
#include<sys/types.h>    // socket
#include<sys/socket.h>   // socket
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/select.h>   // select
#include<sys/ioctl.h>
#include<sys/time.h>
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#define BUFFER_SIZE 1024

struct PACKET_HEAD
{
	int length;
};

class Server
{
private:
	struct sockaddr_in server_addr;
	socklen_t server_addr_len;
	int listen_fd;    // 监听的fd
	int max_fd;       // 最大的fd
	fd_set master_set;   // 所有fd集合，包括监听fd和客户端fd   
	fd_set working_set;  // 工作集合
	struct timeval timeout;
public:
	Server(int port);
	~Server();
	void Bind();
	void Listen(int queue_len = 20);
	void Accept();
	void Run();
	void Recv(int nums);
};

Server::Server(int port)
{
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htons(INADDR_ANY);
	server_addr.sin_port = htons(port);
	// create socket to listen
	listen_fd = socket(PF_INET, SOCK_STREAM, 0);
	if (listen_fd < 0)
	{
		cout << "Create Socket Failed!";
		exit(1);
	}
	int opt = 1;
	setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
}

Server::~Server()
{
	for (int fd = 0; fd <= max_fd; ++fd)
	{
		if (FD_ISSET(fd, &master_set))
		{
			close(fd);
		}
	}
}

void Server::Bind()
{
	if (-1 == (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr))))
	{
		cout << "Server Bind Failed!";
		exit(1);
	}
	cout << "Bind Successfully.\n";
}

void Server::Listen(int queue_len)
{
	if (-1 == listen(listen_fd, queue_len))
	{
		cout << "Server Listen Failed!";
		exit(1);
	}
	cout << "Listen Successfully.\n";
}

void Server::Accept()
{
	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);

	int new_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_addr_len);
	if (new_fd < 0)
	{
		cout << "Server Accept Failed!";
		exit(1);
	}

	cout << "new connection was accepted.\n";
	// 将新建立的连接的fd加入master_set
	FD_SET(new_fd, &master_set);
	if (new_fd > max_fd)
	{
		max_fd = new_fd;
	}
}

void Server::Run()
{
	max_fd = listen_fd;   // 初始化max_fd
	FD_ZERO(&master_set);
	FD_SET(listen_fd, &master_set);  // 添加监听fd

	while (1)
	{
		FD_ZERO(&working_set);
		memcpy(&working_set, &master_set, sizeof(master_set));

		timeout.tv_sec = 30;
		timeout.tv_usec = 0;

		int nums = select(max_fd + 1, &working_set, NULL, NULL, &timeout);
		if (nums < 0)
		{
			cout << "select() error!";
			exit(1);
		}

		if (nums == 0)
		{
			//cout << "select() is timeout!";
			continue;
		}

		if (FD_ISSET(listen_fd, &working_set))
			Accept();   // 有新的客户端请求
		else
			Recv(nums); // 接收客户端的消息
	}
}

void Server::Recv(int nums)
{
	for (int fd = 0; fd <= max_fd; ++fd)
	{
		if (FD_ISSET(fd, &working_set))
		{
			bool close_conn = false;  // 标记当前连接是否断开了

			PACKET_HEAD head;
			recv(fd, &head, sizeof(head), 0);   // 先接受包头，即数据总长度

			char* buffer = new char[head.length];
			bzero(buffer, head.length);
			int total = 0;
			while (total < head.length)
			{
				int len = recv(fd, buffer + total, head.length - total, 0);
				if (len < 0)
				{
					cout << "recv() error!";
					close_conn = true;
					break;
				}
				total = total + len;
			}

			if (total == head.length)  // 将收到的消息原样发回给客户端
			{
				int ret1 = send(fd, &head, sizeof(head), 0);
				int ret2 = send(fd, buffer, head.length, 0);
				if (ret1 < 0 || ret2 < 0)
				{
					cout << "send() error!";
					close_conn = true;
				}
			}

			delete buffer;

			if (close_conn)  // 当前这个连接有问题，关闭它
			{
				close(fd);
				FD_CLR(fd, &master_set);
				if (fd == max_fd)  // 需要更新max_fd;
				{
					while (FD_ISSET(max_fd, &master_set) == false)
						--max_fd;
				}
			}
		}
	}
}

int main()
{
	Server server(15000);
	server.Bind();
	server.Listen();
	server.Run();
	return 0;
}