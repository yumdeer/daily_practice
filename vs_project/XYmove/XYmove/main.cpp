#include "point.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Entering main ..." << endl;
	point a[2];
	for (int i=0;i<2;i++)
		a[i].move(10*(i+1),10+10*(i+1));
	cout << "Exiting main ..." << endl;

}