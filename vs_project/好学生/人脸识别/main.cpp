#include<iostream>
using namespace std;

int main()
{
    int n,m;
	cin >> n >> m ;
	int a[101]={0};
	char hwork[101][101];
	int max,max_sign;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>hwork[i][j];

	for(int j=0;j<m;j++)
	{   
		max_sign=0;
		max=hwork[0][j];
		for(int i=1;i<n;i++)                 //i=1，排除第一项i=0的情况，循环结束找到最大值在分析
		{	
			if( hwork[i][j] == max )         //每次第一行都是最大计算在内，a[0]每次都++；a[0]可能是最大也可能不是；
			{
				a[i]++; 	                //如果有相等的结果，每个结果都计算
			}
			if( hwork[i][j] > max )         
			{
					max=hwork[i][j];
					max_sign=i;		         //将导致入选过数相等,每次只计算最大的i的值，因此需要单独分析等于的情况
			}
		} 
		if(hwork[0][j] > max)               //i=0,判断a[0]是否比之前得出的最大值大
		{
			a[0]++;
		}  
		a[max_sign]++;     
	}


	int num=0;
	for(int i=0;i<n;i++)
	{	
		if(a[i]!=0)
			num++;
	}
	cout << num << endl;

    return 0;
}



