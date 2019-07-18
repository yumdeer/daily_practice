#include <iostream>
using namespace std;

//fun.h
template <typename T>
void fun(T t) {
	cout << t << endl;
}


//use1.cpp
void test1() {
	fun<int>(1);
}

//use2.cpp

//extern template void fun<int>(int);
void test2() {
	fun<int>(2);
}

int main()
{
	test1();
	test2();

}