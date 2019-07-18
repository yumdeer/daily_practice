#include<iostream>
#include <string>
using namespace std;

int main()
{
	char i;
	string n,m;
	cin>>n>>m;
	i=m[0];
	cout<<n[0];
	for(int j=1;j<n.size();j++)
	{
		if(n[j]<i)
			cout<<n[j];
		else break;
	}
	cout<<m[0];
	return 0;
}