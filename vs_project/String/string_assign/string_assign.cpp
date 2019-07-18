#include <iostream>
#include <string>

int main ()
{
	std::string str;
	std::string base="The quick brown fox jumps over a lazy dog.";

	// used in the same order as described above:

	str.assign(base);
	std::cout << str << '\n';

	str.assign(base,10,9);
	std::cout << str << '\n';         // "brown fox"

	str.assign("pangrams are cool",7);
	std::cout << str << '\n';         // "pangram"

	str.assign("c-string");
	std::cout << str << '\n';         // "c-string"

	str.assign(10,'*');
	std::cout << str << '\n';         // "**********"

	str.assign<int>(10,0x2D);
	std::cout << str << '\n';         // "----------"

	str.assign(base.begin()+16,base.end()-12);
	std::cout << str << '\n';         // "fox jumps over"

	return 0;
}