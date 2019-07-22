#include <iostream>

template<typename T, int i = 1>
class someComputing {
public:
	typedef volatile T* retType; // 类型计算
	enum { retValume = i + someComputing<T, i - 1>::retValume }; // 数值计算，递归
	static void f() { std::cout << "someComputing: i=" << i << '\n'; }
};
template<typename T> // 模板特例，递归终止条件
class someComputing<T, 0> {
public:
	enum { retValume = 0 };
};

template<typename T>
class codeComputing {
public:
	static void f() { T::f(); } // 根据类型调用函数，代码计算
};

int main() {
	someComputing<int>::retType a = 0;
	std::cout << sizeof(a) << '\n'; // 64-bit 程序指针
	// VS2013 默认最大递归深度500，GCC4.8 默认最大递归深度900（-ftemplate-depth=n）
	std::cout << someComputing<int, 500>::retValume << '\n'; // 1+2+...+500
	codeComputing<someComputing<int, 99>>::f();
	std::cin.get(); 
	
	return 0;
}