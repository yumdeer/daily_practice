#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
	int len = 4;
	//std::array<int, len> arr = { 1,2,3,4 };
	std::array<int,4> arr = { 1,2,3,4 };

	return 0;
}

//#include <string>
//#include <iterator>
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int main()
//{
//	// 用聚合初始化构造
//	std::array<int, 3> a1{ {1, 2, 3} }; // CWG 1270 重申前的 C++11 中要求双花括号
//										// （ C++11 之后的版本和 C++14 起不要求）
//	std::array<int, 3> a2 = { 1, 2, 3 };  // = 后决不要求
//	std::array<std::string, 2> a3 = { std::string("a"), "b" };
//
//	// 支持容器操作
//	std::sort(a1.begin(), a1.end());
//	std::reverse_copy(a2.begin(), a2.end(),
//		std::ostream_iterator<int>(std::cout, " "));
//
//	std::cout << '\n';
//
//	// 支持带范围 for 循环
//	for (const auto& s : a3)
//		std::cout << s << ' ';
//}