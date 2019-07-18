/* 
    题目： 求37%x=5的x的个数
	解题思路：找规律发现 x 取值为 32，16，8， 先37-5找到最大的那个数，然后发现其他数16,8是32的约数，且大于5. 
*/

#include<iostream>
#include<algorithm>
#include <cmath>

using namespace std;



using namespace std;
int main()
{
	int a,b,c,ans=0;
	a=5/2;
	cin>>a>>b;
	c=a-b;
	for(int i=1;i<=(int)sqrt((double)c);i++)
	{
		if(c%i==0)
		{
			if(i>b)
				ans++;
			if(c/i>b && i!=(int)sqrt((double)c))
				ans++;
		}
	}
	if(a!=b)
		cout<<ans<<endl;
	else
		cout<<"infinity";
	return 0;
}


/* 求一个数的所有约数*/
/*
#include <iostream>
#include <cstring>
#include <algorithm>

#define maxn 100

using namespace std;

int yueShu[maxn],length;

void approximateNumber(int n){
	int i;
	for(i=1;i*i<n;i++){
		if(n%i == 0){
			yueShu[length ++] = i;
			yueShu[length ++] = n/i;
		}
	}

	if(i*i == n)
		yueShu[length ++] = i;
}

void print(){
	cout<<yueShu[0];
	for(int i=1;i<length;i++)
		cout<<" "<<yueShu[i];
	cout<<endl;
}

int main(){
	int n;
	while(cin>>n){
		memset(yueShu,0,maxn*sizeof(int));
		length = 0;

		approximateNumber(n);
		sort(yueShu,yueShu + length);

		print();
	}
	return 0;
}
*/

