#include <iostream>
#include <type_traits>
#include <utility>
#include <tuple>

template <typename T>
struct point
{
	T x;
	T y;
};

//template<class Iter> A(Iter, Iter)-> A<typename std::iterator_traits<Iter>::value_type>;
//template <typename X, typename Y> A(X, Y)->A<X, Y>;

int main() {
	std::pair p(1729, "taxicab");
	static_assert(std::is_same_v<decltype(p), std::pair<int, const char *>>);

	//std::tuple t(4, 3, 2.5); // same as auto t = std::make_tuple(4, 3, 2.5);
	auto t = std::make_tuple(4, 3, 2.5);
	static_assert(std::is_same_v<decltype(t), std::tuple<int, int, double>>);

	// New C++17 use
	point pt{ 0L,0L };

	return 1;
}
