// file: a.cpp
#include <iostream>

template<typename T>
class MyClass { 

};

template MyClass<double>::MyClass(); // 显示实例化构造函数 MyClass<double>::MyClass()

template class MyClass<long>;        // 显示实例化整个类 MyClass<long>

template<typename T>
void print(T const& m) {
	std::cout << "a.cpp: " << m << '\n'; 
}

void fa() {
	print(1);   // print<int>，隐式实例化
	print(0.1); // print<double>
}

void fb(); // fb() 在 b.cpp 中定义，此处声明

int main() {
	fa();
	fb();

	return 0;
}