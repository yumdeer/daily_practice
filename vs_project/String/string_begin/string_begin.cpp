// string::begin/end
#include <iostream>
#include <string>

int main ()
{
	std::string str ("Test string");
	for ( std::string::iterator it=str.begin(); it!=str.end(); ++it)
		std::cout << *it;
	std::cout << '\n';

	return 0;
}