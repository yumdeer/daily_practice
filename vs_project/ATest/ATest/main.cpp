//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(){cout<<"构造函数"<<endl;};
//	A(A &a){cout<<"复制构造函数"<<endl;};
//	void operator()(int a, int b){cout<<"重载（）运算符函数"<<endl;} 
//};
//
//void set(A visit){
//     visit(1,2);
//}
//
//int main()
//{
//	A a=  A();
//	cout<<endl;
//	set( A());
// 
//	return 0;
//}

//#include <iostream>
//#include <stdio.h>
//#include <conio.h>
//
//int main()
//{
//	while(1)
//	{
//		_getch();
//		auto a = _getch();
//		std::cout <<"a:"<< a << std::endl;
//		//printf("%d\n",a);
//		auto b= _getch();
//		std::cout << "b:" << b << std::endl;
//		//printf("%d\n",b);
//	}
//
//	return 0;
//}

//#include <conio.h>
//#include <ctype.h>
//
//int main(void)
//{
//	int ch;
//
//	_cputs("Type 'Y' when finished typing keys: ");
//	do
//	{
//		ch = _getch();
//		ch = toupper(ch);
//	} while (ch != 'Y');
//
//	_putch(ch);
//	_putch('\r');    // Carriage return回程
//	_putch('\n');    // Line feed换行
//}

//

#include "stdio.h"
#define SQR(x) x*x

int main()
{
	int a, k =3;
	a = ++SQR(k + 1);   //k+1*k+1=2k+1 ++k+1*k+1=4+4+1
	printf("%d\n", a);
}