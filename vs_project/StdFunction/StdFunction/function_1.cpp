//#include <iostream>
//
//using foo = void(int);  // 定义函数指针, using 的使用见上一节中的别名语法
//void functional(foo f) {
//	f(2);                  
//}
//
//int main() {
//	auto f = [](int value) {
//		std::cout << value << std::endl;
//	};
//	functional(f);  // 函数指针调用,将进入函数内部			输出：2
//	f(1);           // lambda 表达式调用					输出：1
//	return 0;
//}

//C++11 std::function 是一种通用、多态的函数封装，它的实例可以对任何可以调用的目标实体进行存储、复制和调用操作，
//它也是对 C++中现有的可调用实体的一种类型安全的包裹（相对来说，函数指针的调用不是类型安全的），
//换句话说，就是函数的容器。当我们有了函数的容器之后便能够更加方便的将函数、函数指针作为对象进行处理。
#include <functional>
#include <iostream>

int foo(int para) {
	return para;
}

int main() {

	int a = 123; 
	a += 1;
	int b = 220;
	auto f = [=] { std::cout << a << std::endl; };
	f();                                     //输出：124
	std::cout << std::endl;


	// std::function 包装了一个返回值为 int, 参数为 int 的函数
	std::function<int(int)> func = foo;

	int important = 10;
	std::function<int(int)> func2 = [&](int value) -> int {           //[&]或[=]
		return 1 + value + important;
	};
	std::cout << func(10) << std::endl;		//输出：10
	std::cout << func2(10) << std::endl;	//输出：21
}