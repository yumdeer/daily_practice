#include<iostream>
using namespace std;
int a[20][20];
int main()
{  
	int n;
	int m=1;
	cin>>n;
  
	int t=n*n;
  
	//for(int i=0;i<n;i++)
	//	for(int j=0;j<=i;j++)
	//	 {
	//		if(i%2==0)
	//		{
	//			a[i-j][j]=m;
	//			m++;
	//		}      
	//		else if(i%2!=0) 
	//		{
	//			a[j][i-j]=m;
	//			m++;
	//		}
	//	 }
       
	for(int i=0;i<n-1;i++)
		 for(int j=0;j<=i;j++)
		 {
			if(i%2==0)
			{
				a[n-1-i+j][n-1-j]=t;
				t--;
			}      
			else if(i%2!=0) 
			{
				a[n-1-j][n-1-i+j]=t;
				t--;
			}
		 }
  
	for(int p=0;p<n;p++)
	  {
		for(int q=0;q<n;q++)
		cout<<a[p][q]<<" ";
		cout<<endl;
	  }
  
  return 0;
}