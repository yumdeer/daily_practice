#include<iostream>

using namespace std;

int main()
{
	int x , y ;int sum=0; int out_=0;
	int mid[100];
	for(int i=0;i<100;i++) mid[i]=0;
	cin >> x >> y ;
	char character_matrix[100][100];
	for(int i =0 ; i<x ; i++)
		for(int j =0 ; j<y ; j++)
			cin >> character_matrix[i][j];
	for(int i =0 ; i<x ; i++)
		for(int j =0 ; j<y ; j++)
		{	
			if( character_matrix[i][j] <= character_matrix[i+1][j] )
			{
				mid[i]++;
			    character_matrix[i+1][j]= character_matrix[i][j]; 
			}
		}

	
	for(int i=0;i<y;i++)
		if(mid[i]==4)
		 //cout<<mid[i]<< " ";
			out_++;
	cout <<x-out_-1<<endl;

	return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//char a[101][101];
//bool c[101],b[101];
//int main()
//{
//	int i,I,n,m,s=0,x=0,d=0,j=0,y=0,k;
//	cin>>n>>m;
//	for(i=1;i<=n;i++)
//		for(I=1;I<=m;I++)
//			cin>>a[i][I];
//	for(I=1;I<=m;I++)
//	{
//		j++;
//		s=0;
//		for(i=1;i<n;i++)
//		{
//			if(a[i][I]>a[i+1][I])
//			{
//				s=1;
//				break;
//			}
//		}
//		x+=s;
//		if(s==0) d=1;
//		if(d==1) break;
//	}
//	if(d==1)
//	{
//		for(i=1;i<n;i++)
//		{
//			if(a[i][j]==a[i+1][j])
//			{
//				b[i]=true;
//				b[i+1]=true;
//			}
//		}
//	}
//	if(d==1)
//	{
//		for(I=j+1;I<=m;I++)
//		{
//			for(i=1;i<n;i++)
//			{
//				if(a[i][j]==a[i+1][j])
//				{
//					if(a[i][I]>a[i+1][I]&&b[i]==true)
//					{
//						x++;
//						c[I]=true;
//					}
//				}
//			}
//			for(i=1;i<n;i++)
//			{
//				if(a[i][j]==a[i+1][j])
//				{
//					if(a[i][I]<a[i+1][I]&&c[I]==false)
//					{
//						b[i]=false;
//					}
//				}
//			}
//		}
//	}
//	cout<<x<<endl;
//	return 0;
//}