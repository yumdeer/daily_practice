//#include <iostream>
//
//using namespace std;
//
//class A;    //当用到友元成员函数时，需注意友元声明与友元定义之间的互相依赖。这是类A的声明
//
//class B
//{
//public:
//    void set_show(int x, A &a);             //该函数是类A的友元函数
//};
//
//class A
//{
//public:
//    friend void B::set_show(int x, A &a);   //该函数是友元成员函数的声明
//private:
//    int data;
//    void show() { cout << data << endl; }
//};
//
//
//void B::set_show(int x, A &a)       //只有在定义类A后才能定义该函数，毕竟，它被设为友元是为了访问类A的成员
//{
//    a.data = x;
//    cout << a.data << endl;
//}
//
//int main(void)
//{
//    class A a;
//    class B b;
//
//    b.set_show(1, a);
//
//    return 0;
//}


#include <iostream>

using namespace std;

class Box
{
	double width;
public:
	void printWidth();
	friend void printWidth1(Box box);
	void setWidth(double wid);
	Box() : width(10) {};
};

// 成员函数定义
void Box::setWidth(double wid)
{
	width = wid;
}


void  Box::printWidth()
{
	/* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
	cout << "Width of box : " << width << endl;
}
// 请注意：printWidth1() 不是任何类的成员函数
void  printWidth1(Box box)
{
	/* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
	cout << "Width of box : " << box.width << endl;
}

// 程序的主函数
int main()
{
	Box boxfox;
	Box boxfxk;
	// 使用成员函数设置宽度
	boxfox.setWidth(20.0);

	// 使用友元函数输出宽度
	boxfox.printWidth();

	printWidth1(boxfox);
	printWidth1(boxfxk);
	return 0;
}