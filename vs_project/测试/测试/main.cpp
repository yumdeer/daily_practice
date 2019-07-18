#include <iostream>


class A
{
 private:
	int a,b;
 public:
	int add(int  ,int );
};


int A::add(int a,int b)
{
	return a+b;
}

class B
{
 private:
	int a,b;
 public:
	int mul(int   ,int );
};


int B::mul(int a ,int b)
{

	return a*b;

}


int main()
{
	int c=0,d=0;
	A a;
	B b;
	c=a.add(1,2);
	d=b.mul(1,2);

	std::cout << c <<std::endl;
	std::cout << d <<std::endl;

	return 0;
}