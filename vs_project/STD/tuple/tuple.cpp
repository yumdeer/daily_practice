#include <iostream>
#include <tuple>
using namespace std;

// A Method that returns multiple values using 
// tuple in C++. 
tuple<int, int, char> foo(int n1, int n2)
{
	// Packing values to return a tuple 
	return make_tuple(n2, n1, 'a');
}

// A Method returns a pair of values using pair 
std::pair<int, int> foo1(int num1, int num2)
{
	// Packing two values to return a pair  
	return std::make_pair(num2, num1);
}

int main()
{
	int a, b;
	char cc;

	// Unpack the elements returned by foo 
	std::tie (a, b, cc) = foo(5, 10);

	// Storing  returned values in a pair  
	pair<int, int> p = foo1(5, 2);

	cout << "Values returned by tuple: ";
	cout << a << " " << b << " " << cc << endl;

	cout << "Values returned by Pair: ";
	cout << p.first << " " << p.second;

	std::tuple<int, char, double> mytuple(10, 'a', 3.14);
	std::cout << "the elements is: ";
	std::cout << std::get<0>(mytuple) << " ";
	std::cout << std::get<1>(mytuple) << " ";
	std::cout << std::get<2>(mytuple) << " " << '\n';;

	return 0;
}



