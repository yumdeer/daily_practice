#include <iostream>
#include <string>

int main ()
{
	std::string str ("Test string");
	for (unsigned i=0; i<str.length(); ++i)
	{
		std::cout << str.at(i);
	}
	return 0;
}