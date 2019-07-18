#include<iostream>
#include<stack>
//#include<Vector>
using namespace std;

//template <typename T>
//class Stack:public Vector<T>
//{
//public:
//	void push(T const& e){insert(size(),e);}
//	T pop(){return remove(size()-1);}
//	T& top(){return(*this)[size()-1];}


void convert(stack<char> &S,_int64 n,int base)
{
	static char digit[]=
		{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	while( n>0)
	{
		int remainder=(int)(n % base);
		S.push( digit[remainder] );
		n/=base;
	}
}


int main()
{
	_int64 n=64;int base=8;           //将64转换为8进制
	stack<char> S;
	convert(S,n,base);
	while(!S.empty())
	{
		cout << S.top();
		S.pop();
	}
	cout <<endl;

	return 0;
}