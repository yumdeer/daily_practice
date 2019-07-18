// stdafx.cpp : 只包括标准包含文件的源文件
// Destructor.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中
// 引用任何所需的附加头文件，而不是在此文件中引用

#include<iostream> 
using namespace std;
class B {
public:
 B();
 B(int i);
 ~B();
 void print() const;
private:
 int b;
};
B::B() {
 b=0;
 cout << "B's default constructor called." << endl;
}
B::B(int i) {
 b=i;
 cout << "B's constructor called." << endl;
}
B::~B() {
 cout << "B's destructor called." << endl;
}
void B::print() const {
 cout << b << endl;
}
class C: public B {
public:
 C();
 C(int i, int j);
 ~C();
 void print() const;
private: 
 int c;
};
C::C() {
 c = 0;
 cout << "C's default constructor called." << endl;
}
C::C(int i,int j): B(i), c(j){
 cout << "C's constructor called." << endl;
}
C::~C() {
 cout << "C's destructor called." << endl;
}
void C::print() const {
 B::print();
 cout << c << endl;
}
int main() {
 C obj(5, 6);
 obj.print();
 return 0;
} 