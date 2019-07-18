#include "test.h"

int main()
{
	test t0;
	std::cout << "t0.a："<< t0.add() << std::endl;
	std::cout << "t0.b：" << t0.b << std::endl;	
	t0.b++;
	std::cout << "t0.b：" << t0.b << std::endl;
	
	//手动调用析构函数仅仅是调用了一个函数，对象本身不会被析构
	//并且当对象被销毁是系统自动再次调用析构
	//手动析构不释放内存时，自动析构不会受影响，如果手动析构释放了内存，
	//那么自动析构可能再次释放该内存，导致一种不可决定的行为
	t0.~test(); 
	t0.add_2();

	std::cout  << std::endl;
	test t1;

	return 0;
}