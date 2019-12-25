#include <iostream>
#include <vector>

void foo(unsigned i) {
	std::cout << "This is unsigned Function : " << i << "\n";
}

template <typename T>
void foo(const T& t) {
	std::cout << "This is template Function : " << t << "\n";
}

int  negate(int  i){
  std::cout << "This is ordinary Function : " ;
  return  -i;
}

//template  < typename  T >
//typename  T::value_type  negate(const T& t) {
//  std::cout << "This is template Function : " ;
//  return  -T(t);
//}


template <typename T>
void negate(const T& t) {
	std::cout << "This is template Function2 : ";
	typename T::value_type n = -t[0];
	std::cout << n << std::endl;
}

template <bool, typename T = void>
struct enable_if
{};

template <typename T>
struct enable_if<true, T> {
	typedef T type;
};

template  < class  T , typename  std::enable_if < std::is_integral < T > ::value ,T > ::type * = nullptr >  
void do_stuff(T& t) {
	std::cout << "do_stuff of integral type\n";
	// an implementation for integral types (int, char, unsigned, etc.)
}
//template <class T, typename std::enable_if_t<std::is_integral<T>::value>* = nullptr>
//	void do_stuff(T& t) {
//	// an implementation for integral types (int, char, unsigned, etc.)
//}

class tst {

};

template  <class T, typename std::enable_if<std::is_class<T>::value,T>::type* = nullptr >
void do_stuff(T& t) {
	std::cout << "do_stuff of class types\n";
	// an implementation for class types
}

//template <class T,typename std::enable_if_t<std::is_class<T>::value>* = nullptr>
//	void do_stuff(T& t) {
//	// an implementation for class types
//}

//这两个函数如果是普通函数的话，根据重载的规则是不会通过编译的。即便是模板函数，如果这两个函数都能推导出正确的结果，也会产生重载二义性问题。
//但是正因为std::enable_if的运用使这两个函数的返回值在同一个函数调用的推导过程中只有一个合法，遵循SFINAE原则，则可以顺利通过编译。
template <typename T>
typename std::enable_if<std::is_trivial<T>::value>::type SFINAE_test(T value)
{
	std::cout << "T is trival" << std::endl;
}

template <typename T>
typename std::enable_if<!std::is_trivial<T>::value>::type SFINAE_test(T value)
{
	std::cout << "T is none trival" << std::endl;
}

template <typename T>
class vector {
	vector(size_t n, const T val) {
		std::cout << "This is vector ordinary constructor" << std::endl;
	};

	template <class InputIterator>
	vector(InputIterator first, InputIterator last) {
		std::cout << "This is vector Iterator constructor" << std::endl;
	};

};

int main() {
	
	foo(-66);
	foo(77);

	foo(77u);

	std::cout << negate(88) << std::endl;

	std::vector<int> vec{10};
	negate(vec);

	int num = 999;
	do_stuff(num);
	tst t;
	do_stuff(t);

	SFINAE_test(std::string("123"));
	SFINAE_test(123);

	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	std::vector<int> v3(arr, arr + 4);

	return 0;
}