#ifndef MOVECONST_H_
#define MOVECONST_H_
#include<iostream>
using namespace std;

class IntNum
{
 public:
	IntNum(int x=0):xptr(new int (x)){cout << "call constructor.."<<endl;}
	IntNum(const IntNum &n):xptr(new int(*n.xptr)){cout << "call copy constructor.."<<endl;}
	IntNum(IntNum &&n):xptr(n.xptr){ n.xptr=nullptr; cout << "call copy constructor.."<<endl;}
	~IntNum(){delete xptr; cout<<"Destructing constructor..."<<endl;}
 private:
	int *xptr;
};


#endif