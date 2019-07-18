//C++11 提供了原始字符串字面量的写法，可以在一个字符串前方使用 R 来修饰这个字符串，同时，将原始字符串使用括号包裹。

//#include <iostream>
//#include <string>
//
//int main() {
//	std::string str = "C:\\What\\The\\Fxxk";
//	std::cout << str << std::endl;
//
//	std::string str1 = "(C:\\What\\The\\Fxxk)";
//	std::cout << str1 << std::endl;
//
//	std::string str2 = R"(C:\\What\\The\\Fxxk)";
//	std::cout << str2 << std::endl;
//	return 0;
//}

//自定义字面量

#include <iostream>
#include <string>

std::string operator"" _cchar(const char *str, size_t len) {
	return std::string(str) + " is char*";
}

std::string operator"" _ulong(unsigned long long i) {
	return std::to_string(i) + " is unsinged long long";
}
std::string operator"" _ldouble(long double i) {
	return std::to_string(i) + " is long double";
}
int main() {
	auto str = "abc"_cchar;
	auto num = 1_ulong;
	auto num2 = 2.2_ldouble;
	std::cout << str << std::endl;
	std::cout << num << std::endl;
	std::cout << num2 << std::endl;
	return 0;
}