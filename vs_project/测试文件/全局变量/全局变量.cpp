#include <iostream>
using namespace std;

static int a=0;
//int a = 0;

void add()
{
	a++;
}

//void add(int a)
//{
//	a++;
//}

int main()
{
	//int a = 0;
	a++;
	add();
	//add(a);
	cout << a << endl;
	return 0;
}