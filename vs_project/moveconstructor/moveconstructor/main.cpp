#include<iostream>
#include"moveconst.h"
using namespace std;


IntNum getNum()
{
	IntNum a;
	return a;
}

int main()
{
	cout << getNum().getInt()<<endl;
	return 0;
}