#include<iostream>

template<typename T>
class IsClass
{
private:
	typedef char One;
	typedef struct { char a[2]; } Two;
	template<typename C>
	static One test(int C::*) {}
	template<typename C>
	static Two test(...) {}
public:
	enum { Yes = sizeof(IsClass<T>::test<T>(0)) == 1 };
};

//class Aa
//{
//public:
//	int i;
//	int j;
//	int k;
//};

//void f(const Aa &a, int Aa::*pint)
//{
//	std::cout << a.*pint << std::endl;
//}

class A
{
public:
	A(int b) :a(b) {}
public:
	int a;
};


int main() {

	//Aa a = { 1, 2, 3 };

	//f(a, &Aa::i);
	//f(a, &Aa::j);
	//f(a, &Aa::k);


	A m(10);
	int(A::*p) = &A::a;												//注意，这里是将A.a的"地址"赋值给p，本质不是哦，看下面程序
	std::cout << "p=" << p //<< ",a=" << a 
			  << ",m.*p=" << m.*p << std::endl;						//输出p=1，而不是一个地址哦，a=10,m.*p=10
	m.*p = 11;
	std::cout << "p=" << p //<< ",a=" << a 
			  << ",m.*p=" << m.*p << std::endl;						//p=1，a=11,m.*p=11
	A *s = &m;
	s->*p = 12; 
	std::cout << "p=" << p //<< ",a=" << a
			  << ",s->*p=" << s->*p << std::endl;					//p=1，a=12，s->*p=12
	
	return 0;
}