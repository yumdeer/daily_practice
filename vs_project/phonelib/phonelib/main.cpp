#include "info.h"
#include <iostream>
using namespace std; 
 
int main()
{
    Info s;
	int n;
	cout<< "please input a number to know how much the message need to add:" ;
	cin >> n ;
	Info tmp;
	for (int i=0;i<n;i++ )
    {
	tmp.insert();
	}
	int m;
	cout << "please input a number to know how much the message need to search:";
	cin >> m;
    for (int j=0;j<m;j++ )
    {
      s.search();
	}
    return 0;
}
