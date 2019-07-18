//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	A() : m_ival(0)
//	{
//		test();
//	}
//
//	virtual void func()
//	{
//		cout << m_ival << endl;
//	}
//
//	void test()
//	{
//		func();
//	}
//
//public:
//	int m_ival;
//};
//
//class B : public A
//{
//public:
//	B()
//	{
//		test();
//	}
//
//	void func()
//	{
//		++m_ival;
//		cout << m_ival << endl;
//	}
//};
//
//int main()
//{
//	//A* p = new A;//0 0
//	//A* p = new B;//0 1 2
//	B* p = new B;  //0 1 2 
//	p->test();
//	delete p;
//
//	return 0;
//}


#include<iostream>
using namespace std;

class A {
public:
	~A() {
		cout << 111 << endl;
	}
	virtual void Fun()
	{
		cout << "A" << endl;
	}
};

class B :public A {
public:
	~B() {
		cout << 222 << endl;
	}
	void Fun()
	{
		cout << "B" << endl;
	}

};

int main() {
	B *a = new B();
	a->Fun();

	delete a;


	return 0;
}




