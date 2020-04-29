#include <iostream>

int recsum(int n) {
	if (n < 0)
		return 0;
	else if (n == 0 || n == 1)
		return 1;
	else
		return n + recsum(n - 1);
}

int tailrecsum(int n, int res = 0)
{
	if (n < 0)
		return 0;
	else if (n == 0)
		return res;
	else
		return tailrecsum(n - 1, n + res);
}

int main()
{
	std::cout << recsum(5) << std::endl; 
	std::cout << tailrecsum(5,0) << std::endl;

	return 0;
}