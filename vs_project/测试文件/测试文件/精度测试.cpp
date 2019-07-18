#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	double d1 = 5.85000000;
	double d2 = 3.210000001;
	double  d3 = d1 - d2;
	cout << d3 << endl;
	cout << setprecision(9)  << d3 << endl;
	cout << setprecision(10) << d3 << endl;

	system("pause");
	return 0;
}