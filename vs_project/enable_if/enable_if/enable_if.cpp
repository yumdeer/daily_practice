#include <iostream>
#include <string>
#include <type_traits>

//对于arithmetic类型的入参返回0，对于非arithmetic类型返回1，通过arithmetic将所有的入参分为两大类进行处理。
template<class T>
typename std::enable_if<std::is_arithmetic<T>::value, int>::type foo(T t) {//函数返回类型为int
	std::cout << t << std::endl;
	return t;
}

template<class T>
typename std::enable_if<!std::is_arithmetic<T>::value, int>::type foo(T t) {//函数返回类型为int
	std::cout << typeid(T).name() << std::endl;
	return 1;
}

int main() {
	int num = 5;
	int array[2][2] = { 2,3,4,5 };
	char character = 'A';
	std::string str = "hello";
	std::string strarr[2][2] = { "hello","world","I","miss" };

	std::cout << "int : "	  << foo(num)		 << std::endl;
	std::cout << "array : "   << foo(array)		 << std::endl;
	std::cout << "char : "	  << foo(character)	 << std::endl;
	std::cout << "string : "  << foo(str)		 << std::endl;
	std::cout << "strarr : "  << foo(strarr)	 << std::endl;

	return 0;
}