#include <iostream>
using namespace std;

class A {
public:
	A(const int*);
protected:
	int o[4];
};

class B : public A {
public:
	B(int, int);
};

class X {
public:
	X(int, int);
protected:
	int o[4];
};

class Y : public X {
public:
	Y(int, int);
};

A::A(const int *p) : o(p) {};
B::B(int p0, int p1) : A({ p0, p1 }) {};
X::X(int p0, int p1) : o({ p0, p1 }) {};
Y::Y(int p0, int p1) : X(p0, p1) {};

int main() {
	A a({ 1, 2 });
	B b(3, 4);
	X x(5, 6);
	Y y(7, 8);
	// A a1({1});
	// A a2({1, 2});
	// A a3({1, 2, 3})
}