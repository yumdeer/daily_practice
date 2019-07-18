//#include <iostream>
//using namespace std;
// 
//class A
//{
//public:
//	 A():i(0){};
//	virtual void f() {cout << "A::f()"<<i<<endl;}
//    int i;
//};
//int main()
// {
//	 A a;
//	a.f();
//	cout << sizeof(a) << endl;
//
//	int *p=(int *)&a;
//	cout << *p <<endl;
//	return 0;
// }

#include <iostream>
using namespace std;
 
class A
{
public:
	 A():i(10){};
	virtual void f() {cout << "A::f()"<<i<<endl;}
    int i;
};
class B:public A
{
	
};

int main()
 {
	A a;
	B b;
	
	cout << a.i<<" "<< b.i <<endl;
	cout << sizeof(a) << " " <<sizeof(b) << endl;

	int *p=(int *)&a;
	//p++;
	cout << p << " " << *p<<endl;
	p=(int*)&b;
	cout << p << " " << *p << endl;
	
	return 0;
 }