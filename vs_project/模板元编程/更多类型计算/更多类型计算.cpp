//#include <iostream> // std::cout
//
//// whether T could be converted to U
//template<class T, class U>
//class ConversionTo {
//	typedef char Type1[1]; // 两种 sizeof 不同的类型
//	typedef char Type2[2];
//	static Type1& Test(U); // 较下面的函数，因为参数取值范围小，优先匹配
//	static Type2& Test(...); // 变长参数函数，可以匹配任何数量任何类型参数
//	static T MakeT(); // 返回类型 T，用这个函数而不用 T() 因为 T 可能没有默认构造函数
//public:
//	enum { ret = sizeof(Test(MakeT())) == sizeof(Type1) }; // 可以转换时调用返回 Type1 的 Test()
//};
//
//int main() {
//	std::cout << ConversionTo<int, double>::ret << '\n';
//	std::cout << ConversionTo<float, int*>::ret << '\n';
//	std::cout << ConversionTo<const int&, int&>::ret << '\n';
//	
//	std::cin.get();
//	return 0;
//}

#include <iostream>
#include <vector>

// thanks to Substitution failure is not an erro (SFINAE)
template<typename T>
struct has_typedef_value_type {
	typedef char Type1[1];
	typedef char Type2[2];
	template<typename C> static Type1& test(typename C::value_type*);
	template<typename> static Type2& test(...);
public:
	static const bool ret = sizeof(test<T>(0)) == sizeof(Type1); // 0 == NULL
};

struct foo {
	typedef float lalala;
};

int main() {
	std::cout << has_typedef_value_type<std::vector<int>>::ret << '\n';
	std::cout << has_typedef_value_type<foo>::ret << '\n';

	std::cin.get();
	return 0;
}