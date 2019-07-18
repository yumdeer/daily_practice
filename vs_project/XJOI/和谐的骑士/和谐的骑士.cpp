#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	if(n>m) swap(n,m);
	if(n==1) cout<<n*m;
	else if(n==2)
	{
		int k=m%4;
		if(4-k<k) k=4-k;
		cout<<m+k;
	}
	else cout<<(n*m+1)/2;
	return 0;
}