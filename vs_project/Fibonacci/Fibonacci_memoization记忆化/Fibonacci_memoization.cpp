#include <vector>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <map>
#include <memory>
#include <chrono>

template<class T>
void measure(T&& func) {
	using namespace std::chrono;
	auto start = system_clock::now();
	func();
	duration<double> diff = system_clock::now() - start;
	std::cout << "elapsed: " << diff.count() << "second" << std::endl;

}

template <typename ReturnType, typename... Args>
std::function<ReturnType(Args...)>
memoize(ReturnType(*func) (Args...))
{
	auto cache = std::make_shared<std::map<std::tuple<Args...>, ReturnType>>();
	return ([=](Args... args) mutable {
		std::tuple<Args...> t(args...);
		if (cache->find(t) == cache->end())
			(*cache)[t] = func(args...);
		return (*cache)[t];
	});
}
enum class Cache : unsigned int { NO_RECLAIM, RECLAIM };

template <typename F_ret, typename... F_args>
std::function<F_ret(F_args...)>
memoized_recursion(F_ret(*func)(F_args...), Cache c = Cache::NO_RECLAIM)
{
	typedef std::function<F_ret(F_args...)> FunctionType;
	static std::unordered_map<decltype(func), FunctionType> functor_map;

	if (Cache::RECLAIM == c)
		return functor_map[func] = memoize(func);

	if (functor_map.find(func) == functor_map.end())
		functor_map[func] = memoize(func);

	return functor_map[func];
}

template <typename Sig, Sig funcptr>
struct static_memoizer;

template <typename F_ret, typename... F_args, F_ret(*func)(F_args...)>
struct static_memoizer<F_ret(*)(F_args...), func>
{
	static
		std::function<F_ret(F_args...)> &
		get(Cache c = Cache::NO_RECLAIM)
	{
		static std::function<F_ret(F_args...)> mfunc(memoize(func));

		if (Cache::RECLAIM == c)
			mfunc = memoize(func);

		return mfunc;
	}
};

#define STATIC_MEMOIZER(func) static_memoizer<decltype(&func), &func>::get()

unsigned long fibonacci(unsigned n)
{
	return (n < 2) ? n :
		memoized_recursion(fibonacci)(n - 1) +
		memoized_recursion(fibonacci)(n - 2);
}

unsigned long fib(unsigned n)
{
	return (n < 2) ? n :
		STATIC_MEMOIZER(fib)(n - 1) +
		STATIC_MEMOIZER(fib)(n - 2);
}

int main(void) {
	measure([]() {
		for (int i = 0; i < 300; i++)
			std::cout << fibonacci(i) << " ";
		std::cout << std::endl;
	});

	std::cout << std::endl;

	measure([]() {
		for (int i = 0; i < 600; i++)
			std::cout << fib(i) << " ";
		std::cout << std::endl;
	});

	memoized_recursion(fibonacci, Cache::RECLAIM);
}