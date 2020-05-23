#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

static int NUM = 1;

void strname(std::string str, int num = NUM)
{
	std::cout << str << std::endl;
}

int main()
{
	auto str_tmp = [](std::string s) { 
		strname(s,NUM++);
	};

	std::string ss = "hello";
	std::cout << "Test 1 : " << std::endl;
	str_tmp(ss);

	auto str_tmp1 = std::bind(strname, std::placeholders::_1,NUM++);

	std::string sss = "world";
	std::cout << "Test 2 : " << std::endl;
	str_tmp1(sss);

	return 0;
}