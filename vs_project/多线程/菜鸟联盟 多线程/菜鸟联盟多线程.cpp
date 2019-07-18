#include <iostream>
#include <thread>
//
//std::thread::id main_thread_id = std::this_thread::get_id();
//
//void hello()
//{
//	std::cout << "Hello Concurrent World\n";
//	if (main_thread_id == std::this_thread::get_id())
//		std::cout << "This is the main thread.\n";
//	else
//		std::cout << "This is not the main thread.\n";
//}
//
//void pause_thread(int n) {
//	std::this_thread::sleep_for(std::chrono::seconds(n));
//	std::cout << "pause of " << n << " seconds ended\n";
//}
//
//int main() {
//	std::thread t(hello);
//	t.join();
//	std::cout << t.hardware_concurrency() << std::endl; //检测硬件并发返回硬件线程上下文的数量。//可以并发执行多少个(不准确)
//	std::cout << "native_handle " << t.native_handle() << std::endl;//返回实现定义的底层线程句柄。
//	std::thread a(hello);
//	a.detach();
//	std::thread threads[5];                         // 默认构造线程
//
//	std::cout << "Spawning 5 threads...\n";
//	for (int i = 0; i < 5; ++i)
//		threads[i] = std::thread(pause_thread, i + 1);   // move-assign threads
//	std::cout << "Done spawning threads. Now waiting for them to join:\n";
//	for (auto &thread : threads)
//		thread.join();
//	std::cout << "All threads joined!\n";
//
//	return 0;
//}

#include <string>
using namespace std;

int main()
{
	char stuff[20];
	cin.getline(stuff,10,':');//从istream中10个字符(包含结束标记符)保存在stuff对应的数组中，如果遇到：或 字数达到限制，则读取终止
	cout << stuff <<endl;

	return 0;
}

