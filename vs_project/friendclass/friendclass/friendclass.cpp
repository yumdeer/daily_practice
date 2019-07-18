#include <iostream>

using namespace std;

class A;    //当用到友元成员函数时，需注意友元声明与友元定义之间的互相依赖。这是类A的声明

class B
{
public:
    void set_show(int x, A &a);             //该函数是类A的友元函数
};

class A
{
public:
    friend void B::set_show(int x, A &a);   //该函数是友元成员函数的声明
private:
    int data;
    void show() { cout << data << endl; }
};


void B::set_show(int x, A &a)       //只有在定义类A后才能定义该函数，毕竟，它被设为友元是为了访问类A的成员
{
    a.data = x;
    cout << a.data << endl;
}

int main(void)
{
    class A a;
    class B b;

    b.set_show(1, a);

    return 0;
}