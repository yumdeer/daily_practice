#include <iostream>
#include <vector>


std::vector<int> f1(int a) 
{
	std::cout << "f1() called" << std::endl;  
	return std::vector<int> {1,2,3};
}
std::vector<int> f2(int b, int c) 
{
	std::cout << "f2() called" << std::endl;
	return std::vector<int> {4, 5, 6};
}
std::vector<int> f3(int d) 
{
	std::cout << "f3() called" << std::endl;
	return std::vector<int> {7, 8, 9};
}

template<typename T, typename TtoVectorU>
auto operator>>=(std::vector<T> const& ts, TtoVectorU f) -> decltype(f(ts.front()));

int main()
{
	auto test_result = [=](int a)->int { 	
		return [](int b)->int {
			 std::cout << b << std::endl; 
			 return 7777;
		}(8888);

	};
	std::cout << test_result(6666) << std::endl;

	std::cout << "************" << std::endl;

	//// generic lambda, operator() is a template with one parameter
	//auto vglambda = [](auto printer) {
	//	return [=](auto&&... ts) // generic lambda, ts is a parameter pack
	//	{
	//		printer(std::forward<decltype(ts)>(ts)...);
	//		return [=] { printer(ts...); }; // nullary lambda (takes no parameters)
	//	};
	//};
	//auto p = vglambda([](auto v1, auto v2, auto v3) { std::cout << v1 << v2 << v3 << std::endl; });
	//auto q = p(1, 'a', 3.14); // outputs 1a3.14
	//q();                      // outputs 1a3.14

	//std::cout << "************" << std::endl;

	//   f3( f2( f1(1) , f1(2) ) ) 
	std::vector<int> results_s;

	std::vector<int> bb = f1(1);
	std::vector<int> cc = f1(2);
	for (int bElement : bb)
	{
		for (int cElement : cc)
		{
			std::vector<int> dd = f2(bElement, cElement);
			for (int dElement : dd)
			{
				auto ee = f3(dElement);
				std::copy(ee.begin(), ee.end(), std::back_inserter(results_s));
			}
		}
	}
	for (int num_s : results_s) { std::cout << "num_s = "<< num_s << std::endl; }

	std::cout << "************" << std::endl;

	std::vector<int> results = f1(1) >>= [=](int b) { 
		return f1(2) >>= [=](int c) { 
			return f2(b, c) >>= [=](int d) { 
				return f3(d);
			}; 
		}; 
	};

	for (int num : results) { std::cout << "num = " << num << std::endl; }

	return 0;
}

template<typename T, typename TtoVectorU>
auto operator>>=(std::vector<T> const& ts, TtoVectorU f) -> decltype(f(ts.front()))
{
	decltype(f(ts.front())) us;
	for (T const& t : ts)
	{
		auto ft = f(t);
		std::copy(ft.begin(), ft.end(), std::back_inserter(us));
	}
	return us;
}