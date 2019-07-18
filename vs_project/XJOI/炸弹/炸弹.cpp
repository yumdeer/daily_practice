#include<iostream>
using namespace std;
int t,n,m,sum;
char k;
int x[1010],y[1010],a,b;
bool g[1010][1010],temp;
int main()
{
	cin>>t;
	for(int ti=1;ti<=t;ti++)
	{
		for(int i=1;i<1010;i++)
			x[i]=0;
		for(int i=1;i<1010;i++)
			y[i]=0;
		for(int i=1;i<1010;i++)
			for(int j=1;j<1010;j++)
				g[i][j]=0;
		temp=sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>k;
				if(k=='*')
				{
					x[i]++;                         //炸弹所在的纵行，每有一个+1
					y[j]++;							//炸弹所在的横行，每有一个+1
					g[i][j]=1;
					sum++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(x[i]+y[j]-g[i][j]==sum)
				{
					a=i;b=j;
					temp=1;
					break;
				}
			}
			if(temp) break;
		}
		if(temp==0)cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			cout<<a<<" "<<b<<endl;
		}
	}
	return 0;
}

//#include <iostream>
//using namespace std;
//
//
//struct  
//{
//	int coordinate_x[1000];
//	int coordinate_y[1000];
//	char character[1000][1000];
//} Sbomb;
//
//int main()
//{
//	int T,n,m;
//	while(T--)
//	{
//		cin>>n>>m;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				cin >> Sbomb.character[i][j];
//			//}
//		}
//
//
//
//
//
//
//	}
//	return 0;
//}