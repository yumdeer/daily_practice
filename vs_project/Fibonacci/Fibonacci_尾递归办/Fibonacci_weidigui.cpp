//求第n项

#include <iostream>
using namespace std;

unsigned long fiboProcess(unsigned long *arrayfibo, unsigned long n)
{
	if (n < 2)
		return n;
	else
	{
		arrayfibo[n] = fiboProcess(arrayfibo, n - 1) + arrayfibo[n - 2];
		return arrayfibo[n];
	}
}

unsigned long fibo(unsigned long n)
{
	if (n <= 1)
		return n;
	unsigned long ret = 0;
	unsigned long* array = new unsigned long[n+1]; 
	if (NULL == array)
	{
		return -1;
	}
	array[0] = 0;
	array[1] = 1;

	ret = fiboProcess(array, n);
	
	delete []array;
	array = NULL;
	return ret;
}


int main()
{
	unsigned long n = 5;
	unsigned long fiboNum = fibo(n);
	cout << "第 "<< n << " 项为 "<< fiboNum;
	return 0;
}