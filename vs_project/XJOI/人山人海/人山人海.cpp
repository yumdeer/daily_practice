#include<iostream>
#include <string>
using namespace std;

//int main()
//{
//	string peo[3]={" O ","/|\\","/ \\"};	
//	//for(int i=0;i<3;i++)
//	//	cout << peo[i] << endl ; 
//	
//	int n; cin>> n;
//
//
//	return 0;
//}


int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n-i-2;j++)
			cout<<"   ";
		for(int j=0;j<=i;j++)
		{
			if(j!=0) cout<<"   ";
			cout<<" O ";
		}
		cout<<endl;
		for(int j=0;j<=n-i-2;j++)
			cout<<"   ";
		for(int j=0;j<=i;j++)
		{
			if(j!=0) cout<<"   ";
			cout<<"/|\\";
		}
		cout<<endl;
		for(int j=0;j<=n-i-2;j++)
			cout<<"   ";
		for(int j=0;j<=i;j++)
		{
			if(j!=0) cout<<"   ";
			cout<<"/ \\";
		}
		cout<<endl;     
		cout<<endl;
	}
	return 0;

}
