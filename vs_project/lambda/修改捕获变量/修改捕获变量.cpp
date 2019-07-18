//修改捕获变量
#include <iostream>
using namespace std;

int main()
{
	int a = 123; cout << &a << endl;
	auto f = [a]()mutable {cout << ++a <<endl; };//不会报错
	cout << a << endl;//输出123
	f();//输出124
	cout << &a << endl;
}