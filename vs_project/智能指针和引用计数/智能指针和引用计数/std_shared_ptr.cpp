//#include <iostream>
//using namespace std;
//
//int g = 0;
//template<typename T>
//int foo()
//{
//	int value = ++g;
//	return value;
//}
//
//int main()
//{
//	//Qs1
//	int a = 1;
//	//cout << a << " " << ++a << " " << a++ << endl;		//输出 3 3 1 
//	cout << a << " " << a++ << " " << ++a << endl;			//输出 3 2 3  先计算得到a=3 
//
//	//Qs2
//	int one = 1;
//	//int *b = &one;
//	int *b = new int(one);
//	cout << *b << " " << ++(*b) << " " << (*b)++ << endl;		//输出 3 3 1 
//	delete b;
//	//cout << *b << " " << (*b)++  << " " << ++(*b) << endl;	//输出 3 2 3
//
//	//Qs3
//	cout << foo<int>() << " " << foo<char>() << " " << foo<float>() << " " << foo<double>() << endl;
//
//	return 0;
//}

#include <iostream>
#include <string>
#include <memory>

void foo(std::shared_ptr<int> i)
{
	(*i)++;
}
int main()
{
	// 构造了一个 std::shared_ptr
	//std::shared_ptr<int> pointer(new int);
	//*pointer = 10;

	//使用 std::shared_ptr 仍然需要使用 new 来调用，这使得代码出现了某种程度上的不对称
	//std::make_shared 就能够用来消除显示的使用 new，所以std::make_shared 会分配创建传入参数中的对象，
	//并返回这个对象类型的std::shared_ptr指针。
	auto pointer = std::make_shared<int>(10);
	foo(pointer);
	std::cout << *pointer << std::endl; 

	auto pointer1 = std::make_shared<int>(10);
	auto pointer2 = pointer1;			 // 引用计数+1
	auto pointer3 = pointer1;			 // 引用计数+1
	int *p = pointer1.get();             // 这样不会增加引用计数

	std::cout << "pointer1.use_count() = " << pointer1.use_count() << std::endl;    // 3
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;    // 3
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;    // 3

	pointer2.reset();	//通过 reset() 来重置指针,并通过use_count()来查看一个对象的引用计数。
	std::cout << "reset pointer2:" << std::endl;
	std::cout << "pointer1.use_count() = " << pointer1.use_count() << std::endl;     // 2
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;     // 0, pointer2 已 reset
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;     // 2

	pointer3.reset();
	std::cout << "reset pointer3:" << std::endl;
	std::cout << "pointer1.use_count() = " << pointer1.use_count() << std::endl;     // 1
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;     // 0
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;     // 0, pointer3 已 reset

	// 离开作用域前，shared_ptr 会被析构，从而释放内存
	return 0;
}



