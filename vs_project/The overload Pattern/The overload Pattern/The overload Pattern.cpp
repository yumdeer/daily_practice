#include <iostream>
#include <string>
#include <variant>
#include <vector>
using namespace std;

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...)->overloaded<Ts...>;



int main()
{
	overloaded s{
		[](int) {cout << "int" << endl; },
		[](double) {cout << "double" << endl; },
		[](string) {cout << "string" << endl; },
	};
	s(1); // int
	s(1.0); // double
	s("hello world"); // string

	std::variant<int, float, std::string> intFloatString{ "Hello" };
	std::visit(overloaded{
		  [](const int& i) { std::cout << "int: " << i; },
		  [](const float& f) { std::cout << "float: " << f; },
		  [](const std::string& s) { std::cout << "string: " << s; }
		},
		intFloatString
	);


	return 0;
}