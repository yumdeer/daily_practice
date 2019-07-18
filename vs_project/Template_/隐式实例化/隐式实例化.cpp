//#include <iostream>
//
//template<typename T>
//class aTMP {
//public:
//	void f1() { std::cout << "f1()\n"; }
//	void f2() { std::ccccout << "f2()\n"; } // 敲错键盘了，语义错误：没有 std::ccccout
//};
//
//int main() {
//	aTMP<int> a;
//	a.f1();
//	//a.f2(); // 这句代码被注释时，aTMP<int>::f2() 不被实例化，从而上面的错误被掩盖!
//
//	return 0;
//}

#include <iostream>

// 计算 N 的阶乘 N!
template<int N>
class aTMP {
public:
	enum { ret = N == 0 ? 1 : N * aTMP<N - 1>::ret }; // Lazy Instantiation，将产生无限递归!
};
template<>
class aTMP<0> {
public:
	enum { ret = 1 };
};

int main() {
	std::cout << aTMP<10>::ret << '\n';
	
	return 0;
}