//传统 C++ 通过拷贝构造函数和赋值操作符为类对象设计了拷贝 / 复制的概念，
//但为了实现对资源的移动操作，调用者必须使用先复制、再析构的方式，否则就需要自己实现移动对象的接口。
//试想，搬家的时候是把家里的东西直接搬到新家去，而不是将所有东西复制一份（重买）再放到新家、
//再把原来的东西全部销毁，这是非常反人类的一件事情。
//
//传统的 C++ 没有区分『移动』和『拷贝』的概念，造成了大量的数据移动，浪费时间和空间。
//右值引用的出现恰好就解决了这两个概念的混淆问题

//#include <iostream>
//
//class A {
//public:
//	int *pointer;
//	A() :pointer(new int(1)) {
//		std::cout << "构造" << pointer << std::endl;
//	}
//	// 无意义的对象拷贝
//	A(A& a) :pointer(new int(*a.pointer)) {
//		std::cout << "拷贝" << pointer << std::endl;
//	}
//
//	A(A&& a) :pointer(a.pointer) {
//		a.pointer = nullptr;
//		std::cout << "移动" << pointer << std::endl;
//	}
//
//	~A() {
//		std::cout << "析构" << pointer << std::endl;
//		delete pointer;
//	}
//};
//// 防止编译器优化
//A return_rvalue(bool test) {
//	A a, b;							 // ①：构造两个 A 对象，于是获得两个构造函数的输出;
//	if (test) return a;
//	else return b;			        // ②：函数返回后，产生一个将亡值，因为要被赋值obj，所以被 A 的移动构造（A(A&&)）引用
//									//从而延长生命周期，并将这个右值中的指针拿到，保存到了 obj 中，而将亡值的指针被设置为 nullptr，
//									//防止了这块内存区域被销毁。
//}
//int main() {
//	A obj = return_rvalue(false);
//	std::cout << "obj:" << std::endl;
//
//	std::cout << obj.pointer << std::endl;
//	std::cout << *obj.pointer << std::endl;
//
//	return 0;
//}


//再来看看涉及标准库的例子：
#include <iostream> // std::cout
#include <utility>  // std::move
#include <vector>   // std::vector
#include <string>   // std::string

int main() {

	std::string str = "Hello world.";
	std::vector<std::string> v;

	// 将使用 push_back(const T&), 即产生拷贝行为
	v.push_back(str);
	// 将输出 "str: Hello world."
	std::cout << "str: " << str << std::endl;

	// 将使用 push_back(const T&&), 不会出现拷贝行为
	// 而整个字符串会被移动到 vector 中，所以有时候 std::move 会用来减少拷贝出现的开销
	// 这步操作后, str 中的值会变为空
	v.push_back(std::move(str));
	// 将输出 "str: "
	std::cout << "str: " << str << std::endl;

	return 0;
}

