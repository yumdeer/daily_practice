#include <iostream>

// 识别两个类型是否相同，提前进入模板元编程^_^
template<typename T1, typename T2> // 通例，返回 false
class theSameType { 
public: 
	enum { ret = false }; 
};

template<typename T>               // 特例，两类型相同时返回 true
class theSameType<T, T> { 
public: 
	enum { ret = true }; 
};

template<typename T, int i> 
class aTMP {

};

int main() {
	typedef unsigned int uint; // typedef 定义类型别名而不是引入新类型
	typedef uint uint2;
	std::cout << theSameType<unsigned, uint2>::ret << '\n';
	std::cout << theSameType<aTMP<unsigned, 2>, aTMP<uint2, 2>>::ret << '\n';
	std::cout << theSameType<aTMP<int, 2>, aTMP<int, 3>>::ret << '\n';
	
	return 0;
}
