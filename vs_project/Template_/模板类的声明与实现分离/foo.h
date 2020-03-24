#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Foo
{
public:
	Foo(T num);
	void doSomething(T param);
private:
	T nums;
};



#include "foo.tpp"