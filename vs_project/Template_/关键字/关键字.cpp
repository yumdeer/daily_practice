#include <iostream>

template<typename T>
class aTMP {
public: 
	typedef const T reType;
};

void f() { 
	std::cout << "global f()\n"; 
}

template<typename T>
class Base {
public:
	template <int N = 99>
	void f() { 
		std::cout << "member f(): " << N << '\n'; 
	}
};

template<typename T>
class Derived : public Base<T> {
public:
	typename T::reType m; // typename 不能省略
	Derived(typename T::reType a) : m(a) { }
	void df1() { f(); }							 // 调用全局 f()，而非想象中的基类 f()
	//void df2() { this->template f(); }		 // 基类 f<99>(),VS无法通过，g++顺利通过
	void df2() { Base<T>::template f(); }		 // 基类 f<99>()
	void df3() { Base<T>::template f<22>(); }	 // 强制基类 f<22>()
	void df4() { ::f(); }						 // 强制全局 f()
};

int main() {
	Derived<aTMP<int>> a(10);
	a.df1(); 
	a.df2(); 
	a.df3(); 
	a.df4();
	
	return 0;
}