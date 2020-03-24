#include "foo.h"

template <typename T>
Foo<T>::Foo(T num) : nums(num) 
{

}


template <typename T>
void Foo<T>::doSomething(T param)
{
    //implementation
	cout << nums << endl;
	cout << "hello " <<endl;
}