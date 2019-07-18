//#include <iostream>     // std::cout
//#include <functional>   // std::ref
//
//int main() {
//	int foo(10);
//
//	auto bar = std::ref(foo);
//
//	++bar;
//
//	std::cout << foo << '\n';
//
//	return 0;
//}

//测试多线程函数重载
//如果将重载的函数作为线程的入口函数，会发生编译错误！编译器搞不清楚是哪个函数
#include<iostream>
#include<thread>
#include <string>

using namespace std;

void show(const int str,  int id)
{
	cout << "int "<< "线程 " << ++id << " ：" << str*3 << endl;
}

void show(const char str[],  int id)
{
	cout <<"char "<< "线程 " << ++id << " ：" << str << endl;
}

void show( string& str,  int id)
{
	cout << "string " << "线程 " << ++id << " ：" << str << endl;
}

//template<class T, class U>
//void show(T str, U id)
//{
//	cout << "线程 " << id + 1 << " ：" << str << endl;
//}

int main()
{
	//https://segmentfault.com/q/1010000019252660

	//错误示例：
	//※※当show是函数重载时，便不能直接以show作为std::thread的构造函数的实际参数。
	//void (*memfunc)(string& str, int id)  = &show;
	//thread t0(memfunc, "1.hello cplusplus!", 0);
	//t0.join();

	//可以用lambda expression
	thread t1([]() { show("1.hello cplusplus!", 0); });
	t1.join();
	//样例里转发的不是thread构造函数的形式参数，而是一个副本。
	//int a = 0;
	//thread t1([](auto&&... args) { show(std::forward<decltype(args)>(args)...); }, "1.hello cplusplus!", std::ref(a));
	//t1.join();

	int b = 1;
	string s = "2.cplusplus!";
	//static_cast强制转换
	thread t2(static_cast<void(*)(std::string &, int)>(show), std::ref(s), b);
	t2.join();

	int c = 2;
	thread t3([&c]() { show(1, c); });
	t3.join();

	return 0;
}



//引入类模板
//
//#include<iostream>
//#include<thread>
//#include <string>
//using namespace std;
////using memfunc_type = void (Complex::*)() const;
//
//class Complex
//{
//public:
//	Complex() :realPart_(0), imagPart_(0) {}
//
//	Complex(double rp, double ip) : realPart_(rp), imagPart_(ip) {}
//
//	double & real() { return realPart_; }
//	double & imag() { return imagPart_; }
//
//	const double & real() const { return realPart_; }
//	const double & imag() const { return imagPart_; }
//
//	double square() const { return realPart_ * realPart_ - imagPart_ * imagPart_; }
//
//	void display() const
//	{
//		std::cout << "Square of the Complex number (" << realPart_ << ") + i (" << imagPart_ << " ) is " << square() << std::endl;
//	}
//
//	void display(unsigned nTimes) const { while (nTimes-- > 0)display(); }
//
//private:
//
//	double realPart_;
//	double imagPart_;
//
//};
//
//void Test3()
//{
//	Complex c1(1, 0.74), c2(2, 0.35);
//
//	void (Complex::*memfunc)() const = &Complex::display;
//	std::thread sqCalc1(memfunc, &c1);
//	std::thread sqCalc2(memfunc, &c2);
//
//	sqCalc1.join();
//	sqCalc2.join();
//}
//
//int main()
//{
//	Test3();
//
//	return 0;
//}