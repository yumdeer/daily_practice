/*
nullptr 出现的目的是为了替代 NULL。在某种意义上来说，传统 C++ 会把 NULL、0 视为同一种东西，
这取决于编译器如何定义 NULL，有些编译器会将 NULL 定义为((void*)0)，有些则会直接将其定义为 0。
*/

#include <iostream>
void foo(char *);
void foo(int);
int main() {

	if (NULL == (void *)0) std::cout << "NULL == 0" << std::endl;
	else std::cout << "NULL != 0" << std::endl;

	foo(0);
	//foo(NULL); // G++编译无法通过 //它将不知道调用 foo(char *)还是 foo(int); //这里IDE它通过了
	foo(nullptr);

	return 0;
}
void foo(char *ch) {
	std::cout << "call foo(char*)" << std::endl;
}
void foo(int i) {
	std::cout << "call foo(int)" << std::endl;
}