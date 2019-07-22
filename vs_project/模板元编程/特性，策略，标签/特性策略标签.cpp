#include <iostream> // std::cout
#include <vector>

//template<typename iter>
//typename iter::value_type mysum(iter begin, iter end) {
//	typename iter::value_type sum(0);
//	for (iter i = begin; i != end; ++i) sum += *i;
//	return sum;
//}
//
//int main() {
//	std::vector<int> v;
//	for (int i = 0; i < 100; ++i) v.push_back(i);
//	std::cout << mysum(v.begin(), v.end()) << '\n';
//	
//	std::cin.get(); 
//	return 0;
//}

//// 特性，traits
//template<typename iter>
//class mytraits {
//public: typedef typename iter::value_type value_type;
//};
//template<typename T>
//class mytraits<T*> {
//public: typedef T value_type;
//};
//
//template<typename iter>
//typename mytraits<iter>::value_type mysum(iter begin, iter end) {
//	typename mytraits<iter>::value_type sum(0);
//	for (iter i = begin; i != end; ++i) sum += *i;
//	return sum;
//}
//
//int main() {
//	int v[4] = { 1,2,3,4 };
//	std::cout << mysum(v, v + 4) << '\n';
//	std::cin.get(); return 0;
//}

#include <iostream>
#include <vector>

template<typename T1, typename T2> // 通例，返回 false
class theSameType { public: enum { ret = false }; };
template<typename T>               // 特例，两类型相同时返回 true
class theSameType<T, T> { public: enum { ret = true }; };

int main() {
	std::cout << theSameType< std::vector<int>::iterator::iterator_category,
		std::random_access_iterator_tag >::ret << '\n';
	
	std::cin.get();
	return 0;
}