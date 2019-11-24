#include <iostream>
#include <process.h>
#include <windows.h>
#include <mutex>
#include <cstdio>

#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

using namespace std;

class singleton
{
protected:
	singleton()
	{
		// 初始化
		pthread_mutex_init(&mutex, NULL);
		m_count++;
		printf("Singelton begin\n");
		Sleep(1000);                            // 加sleep为了放大效果
		printf("Singelton end\n");
	}

private:
	static singleton* p;

public:
	static pthread_mutex_t mutex;
	static singleton* initance();
	static void print();
	static int m_count;
};

int singleton::m_count = 0;
pthread_mutex_t singleton::mutex;
singleton* singleton::p = NULL;


singleton* singleton::initance()
{
	if (p == NULL)
	{
		// 加锁
		pthread_mutex_lock(&mutex);
		if (p == NULL)
			p = new singleton();
		pthread_mutex_unlock(&mutex);
	}
	return p;
}

void singleton::print() {
	//cout << "This is Print the m_count:  " << m_count << endl;
	cout << m_count << endl;
}
// 回调函数
void threadFunc(void *p) {
	DWORD id = GetCurrentThreadId();        // 获得线程id
	cout << id << endl;
	singleton::initance()->print();      // 构造函数并获得实例，调用静态成员函数
}

int main(int argc, const char * argv[]) {
	int threadNum = 3;
	HANDLE threadHdl[100];

	// 创建3个线程
	for (int i = 0; i < threadNum; i++) {
		threadHdl[i] = (HANDLE)_beginthread(threadFunc, 0, nullptr);
	}

	// 让主进程等待所有的线程结束后再退出
	for (int i = 0; i < threadNum; i++) {
		WaitForSingleObject(threadHdl[i], INFINITE);
	}
	cout << "main" << endl;                 // 验证主进程是否是最后退出
	return 0;
}

