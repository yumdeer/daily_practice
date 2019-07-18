//多线程的好处：https://blog.csdn.net/shfqbluestone/article/details/45825269


////实验一 简单双线程输出
//#include <iostream>
//#include <thread>
//
//using namespace std;
//
//void func() {
//	cout << "hello,this is my thread ，thread id is " 
//	<<this_thread::get_id()	<< endl;
//}
//
//int main() {
//	cout << "this is main thread ，thread id is " << this_thread::get_id() << endl;
//	
//	thread th = thread(func);       //定义线程，传入函数指针
//	th.join();		//加入/汇合，说白了就是阻塞，阻塞主线程，让主线程等待子线程执行完毕，子线程和主线程汇合，然后主线程再往下走！
//	//th.detach();  //分离，也就是主线程不和子线程汇合了，你主线程执行你的，我子线程执行我的，你主线程也不必等我子线程运行结束，主线程可以先执行结束，这并不影响子线程的执行。
//}

//实验二 函数出入参数多线程输出,传入引用
//#include <iostream>
//#include <string>
//#include <thread>
//
//using namespace std;
//
//void func(string& s) {
//	cout << "hello,this is my thread ，thread id is "
//		<< s << endl;
//}
//
//int main() {
//	string s = "test";
//	thread th = thread( func,std::ref(s));       //传入函数指针，后面接函数参数（引用用ref()）
//	th.join(); 
//	cout << "this is main thread ，thread id is "
//		<< this_thread::get_id() << endl;
//	//th.detach();
//}

//实验三：
#include <iostream>
#include <thread>

using namespace std;

//auto fn = [](int *a) {
//	for (int i = 0; i < 10; i++)
//		cout << *a << endl;
//};
//
//int main() {
//	
//	[] {
//		int a = 100;
//		thread t(fn, &a);
//		t.detach();
//	}();
//	
//	
//
//	return 0;
//}


class thread_guard
{
private:
	thread &t;
public:
	explicit thread_guard(thread& _t) :
		t(_t) {}

	~thread_guard()
	{
		if (t.joinable())
			t.join();
	}

	thread_guard(const thread_guard&) = delete;
	thread_guard& operator=(const thread_guard&) = delete;
};

void func() {

	thread t([] {
		cout << "Hello thread" << endl;
	});

	thread_guard g(t);
}
void func1() {
	thread t([] {
		cout << "hello C++ 11" << endl;
	});

	try
	{
		;
	}
	catch (...)
	{
		t.join();
		throw;
	}
	t.join();
}
int main() {
	
	//func();
	func1();

	return 0;
}



