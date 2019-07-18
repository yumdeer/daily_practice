//求第n项
#include <iostream>
using namespace std;

unsigned long fibo(unsigned long int n)
{
	if (n <= 1)
		return n;
	else
		return fibo(n - 1) + fibo(n - 2);
}


int main()
{
	unsigned long n = 300;
	unsigned long fiboNum = fibo(n);
	cout << n << " "<<fiboNum;
	return 0;
}