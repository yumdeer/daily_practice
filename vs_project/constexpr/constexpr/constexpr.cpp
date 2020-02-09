//////#define LEN 10
//////
//////constexpr int len_foo() {
////////int len_foo() {
//////	return 5;
//////}
//////
////////函数体不能声明变量或定义新的类型,只能包含声明、null语句或者一条return语句
//////constexpr int fibonacci(const int n) {
//////	return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
//////}
//////
////////c++14后开始允许constexpr修饰的函数包含条件分支语句,循环语句
////////表达式可以改变一个对象的值，只需该对象的生命期在声明为constexpr的函数内部开始。
////////constexpr int fibonacci(const int n) {
////////	if (n == 1) return 1;
////////	if (n == 2) return 1;
////////	int result = 1;
////////	for (int i = 1; i <= n; ++i)
////////		result *= i;
////////	return result;
////////}
//////
//////int main() {
//////	char arr_1[10];
//////	char arr_2[LEN];
//////	//int len = 5;
//////	//char arr_3[len + 5];          // 非法
//////	const int len_2 = 10;
//////	char arr_4[len_2 + 5];        // 合法
//////	char arr_5[len_foo() + 5];  // 非法 ，int len_foo()前面加上constexpr 则合法。
//////	char arr_6[fibonacci(5)];
//////
//////	return 0;
//////}
////
////#include <iostream>
////using namespace std;
////
////// C++98/03
////template<int N> struct Factorial_Cpp03
////{
////	const static int value = N * Factorial_Cpp03<N - 1>::value;
////};
////template<> struct Factorial_Cpp03<0>
////{
////	const static int value = 1;
////};
////
////// C++11
////constexpr int factorial_Cpp11(int n)
////{
////	return n == 0 ? 1 : n * factorial_Cpp11(n - 1);
////}
////
////// C++14
////constexpr int factorial_Cpp14(int n)
////{
////	int result = 1;
////	for (int i = 1; i <= n; ++i)
////		result *= i;
////	return result;
////}
////
/////*
////static_assert(常量表达式，提示字符串)。
////如果第一个参数常量表达式的值为真(true或者非零值)，那么static_assert不做任何事情，就像它不存在一样，
////否则会产生一条编译错误，错误位置就是该static_assert语句所在行，错误提示就是第二个参数提示字符串。
////*/
////int main()
////{
////	static_assert(Factorial_Cpp03<3>::value == 6, "error_Factorial_Cpp03");
////	static_assert(factorial_Cpp11(3) == 6, "error_factorial_Cpp11");
////	static_assert(factorial_Cpp14(3) == 6, "error_factorial_Cpp14");
////	return 0;
////}
//
//
//
//// constexpr.cpp
//// Compile with: cl /EHsc /W4 constexpr.cpp
//#include <iostream>
//
//using namespace std;
//
//// Pass by value
//constexpr float exp(float x, int n)
//{
//	return n == 0 ? 1 :
//		n % 2 == 0 ? exp(x * x, n / 2) :
//		exp(x * x, (n - 1) / 2) * x;
//};
//
//// Pass by reference
//constexpr float exp2(const float& x, const int& n)
//{
//	return n == 0 ? 1 :
//		n % 2 == 0 ? exp2(x * x, n / 2) :
//		exp2(x * x, (n - 1) / 2) * x;
//};
//
//// Compile-time computation of array length
//template<typename T, int N>
//constexpr int length(const T(&)[N])
//{
//	return N;
//}
//
//// Recursive constexpr function
//constexpr int fac(int n)
//{
//	return n == 1 ? 1 : n * fac(n - 1);
//}
//
////int num = 6;
////constexpr void fun(int num) {
////	num++;
////	cout << num << endl;
////}
//
//
//// User-defined type
//class Foo
//{
//public:
//	constexpr explicit Foo(int i) : _i(i) {}
//	constexpr int GetValue() const
//	{
//		return _i;
//	}
//private:
//	int _i;
//};
//
//int main()
//{
//	//fun(5);
//	//cout << num << endl;
//
//	// foo is const:
//	constexpr Foo foo(5);
//	// foo = Foo(6); //Error!
//
//	// Compile time:
//	constexpr float x = exp(5, 3);
//	constexpr float y{ exp(2, 5) };
//	constexpr int val = foo.GetValue();
//	constexpr int f5 = fac(5);
//	const int nums[]{ 1, 2, 3, 4 };
//	const int nums2[length(nums) * 2]{ 1, 2, 3, 4, 5, 6, 7, 8 };
//
//	// Run time:
//	cout << "The value of foo is " << foo.GetValue() << endl;
//}


// A C++ program to demonstrate the use of constexpr 
#include<iostream> 
#include<time.h>   //用到clock()函数
using namespace std;

constexpr long int fib(int n)
{
	return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}

int main()
{
	int begintime, endtime;
	begintime = clock();	//计时开始
	// value of res is computed at compile time.  
	const long int res = fib(30);
	cout << res << endl;
	endtime = clock();	//计时结束
	cout << endtime - begintime << endl;

	return 0;
}