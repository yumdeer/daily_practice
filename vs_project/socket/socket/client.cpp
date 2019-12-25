/*************************************************************************
	> File Name: client.cpp
	> Author: SongLee
	> E-mail: lisong.shine@qq.com
	> Created Time: 2016年04月28日 星期四 23时10分15秒
	> Personal Blog: http://songlee24.github.io/
	> https ://blog.csdn.net/lisonglisonglisong/article/details/51328062
 ************************************************************************/
#include<netinet/in.h>   // sockaddr_in
#include<sys/types.h>    // socket
#include<sys/socket.h>   // socket
#include<arpa/inet.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<iostream>
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

class Client
{
private:
	struct sockaddr_in server_addr;
	socklen_t server_addr_len;
	int fd;
public:
	Client(string ip, int port);
	~Client();
	void Connect();
	void Send(string str);
	string Recv();
};

Client::Client(string ip, int port)
{
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	if (inet_pton(AF_INET, ip.c_str(), &server_addr.sin_addr) == 0)
	{
		cout << "Server IP Address Error!";
		exit(1);
	}
	server_addr.sin_port = htons(port);
	server_addr_len = sizeof(server_addr);
	// create socket
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
	{
		cout << "Create Socket Failed!";
		exit(1);
	}
}

Client::~Client()
{
	close(fd);
}

void Client::Connect()
{
	cout << "Connecting......" << endl;
	if (connect(fd, (struct sockaddr*)&server_addr, server_addr_len) < 0)
	{
		cout << "Can not Connect to Server IP!";
		exit(1);
	}
	cout << "Connect to Server successfully." << endl;
}

void Client::Send(string str)
{
	PACKET_HEAD head;
	head.length = str.size() + 1;   // 注意这里需要+1
	int ret1 = send(fd, &head, sizeof(head), 0);
	int ret2 = send(fd, str.c_str(), head.length, 0);
	if (ret1 < 0 || ret2 < 0)
	{
		cout << "Send Message Failed!";
		exit(1);
	}
}

string Client::Recv()
{
	PACKET_HEAD head;
	recv(fd, &head, sizeof(head), 0);

	char* buffer = new char[head.length];
	bzero(buffer, head.length);
	int total = 0;
	while (total < head.length)
	{
		int len = recv(fd, buffer + total, head.length - total, 0);
		if (len < 0)
		{
			cout << "recv() error!";
			break;
		}
		total = total + len;
	}
	string result(buffer);
	delete buffer;
	return result;
}

int main()
{
	Client client("127.0.0.1", 15000);
	client.Connect();
	while (1)
	{
		string msg;
		getline(cin, msg);
		if (msg == "exit")
			break;
		client.Send(msg);
		cout << client.Recv() << endl;
	}
	return 0;
}
