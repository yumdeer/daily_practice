#include <iostream>

// 通例为空，若不匹配特例将报错，很好的调试手段（这里是 bool 就无所谓了）
template<bool c, typename Then, typename Else>
class IF_ {

};

template<typename Then, typename Else>
class IF_<true, Then, Else> {
public:
	typedef Then reType;
};

template<typename Then, typename Else>
class IF_<false, Then, Else> {
public:
	typedef Else reType;
};

// 隐含要求： Condition 返回值 ret，Statement 有类型 Next
template<template<typename> class Condition, typename Statement>
class WHILE_ {
	template<typename Statement>
	class STOP {
	public:
		typedef Statement reType;
	};
public:
	typedef typename IF_<Condition<Statement>::ret, WHILE_<Condition, typename Statement::Next>, STOP<Statement>>::reType::reType reType;
};
// 最小公倍数，普通函数
int lcm(int a, int b) {
	int r, lcm = a * b;
	while (r = a % b) { a = b; b = r; } // 因为用可变的存储，不能写成 a=b; b=a%b;
	return lcm / b;
}
// 递归函数版本
int gcd_r(int a, int b) { return b == 0 ? a : gcd_r(b, a%b); } // 简洁
int lcm_r(int a, int b) { return a * b / gcd_r(a, b); }


// 模板版本
template<int a, int b>
class lcm_T {
	template<typename stat>
	class cond { 
	public: 
		enum { ret = (stat::div != 0) };
	};

	template<int a, int b>
	class stat { 
	public: 
		typedef stat<b, a%b> Next; enum { div = a % b, ret = b }; 
	};

	static const int gcd = WHILE_<cond, stat<a, b>>::reType::ret;
public:
	static const int ret = a * b / gcd;
};
// 递归模板版本
template<int a, int b>
class lcm_T_r {
	template<int a, int b>
	class gcd {
	public:
		enum { ret = gcd<b, a%b>::ret };
	};

	template<int a> 
	class gcd<a, 0> { 
	public: 
		enum { ret = a };
	};

	public:
		static const int ret = a * b / gcd<a, b>::ret;
};

int main() {
	std::cout << lcm(100, 36) << '\n';
	std::cout << lcm_r(100, 36) << '\n';
	std::cout << lcm_T<100, 36>::ret << '\n';
	std::cout << lcm_T_r<100, 36>::ret << '\n';
	std::cin.get();
	
	return 0;
}