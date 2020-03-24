//#include "foo.h"
//
//
//int main()
//{
//	Foo<int> foo(10);
//	foo.doSomething(10);
//
//}


// main.cpp
#include "StringAdapter.h"

// Note: Main can not see the definition of the template from here (just the declaration)
//       So it relies on the explicit instantiation to make sure it links.
int main()
{

	StringAdapter<const char>  x("hi There");
	x.doAdapterStuff();
}
