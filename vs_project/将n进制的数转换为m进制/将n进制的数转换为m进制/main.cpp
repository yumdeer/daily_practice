#include<iostream>
#include<string>
#include<cmath>
#include<stack>
using namespace std;

/*将十进制的n转化为base进制*/
void convert(stack<char> &S,int n,int base)
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
	stack <char> S;
	int n,m;
    string  number;
	cin >> n ;
	//getline(cin,number);
	cin >> number;
	cin >> m;

	/*转化为10进制*/
	int sum=0;
	for(int i=number.size()-1;i>=0;i--)
		if(number[i]>='0'&&number[i]<='9')
		sum=sum+(number[i]-'0') * pow((double)n,(int)(number.size()-i-1));
	else if(number[i]>='A'&&number[i]<='Z')
		sum=sum+(number[i]-'A'+10) * pow((double)n,(int)(number.size()-i-1));
	
	/*借用栈的后进先出的特性*/
	convert(S,sum,m);
	while(!S.empty())
	{
		cout << S.top();
		S.pop();
	}
	cout <<endl;

	return 0;
}

//#include<cmath>
//#include<string>
//using namespace std;
//int a[40];//存放余数
//int main()
//{
// int n,m;
// cin>>n;
// string s;//n进制数
// cin>>s;
// cin>>m;
//   
// int sum=0;
// for(int i=s.size()-1;i>=0;i--)
//  {
//    if(s[i]>='0'&&s[i]<='9')
//		sum=sum+(s[i]-'0') * pow((double)n,(int)(s.size()-i-1));
//    else if(s[i]>='A'&&s[i]<='Z')
//		sum=sum+(s[i]-'A'+10) * pow((double)n,(int)(s.size()-i-1));
//  }
//   
// int j=1;
//   
// if(sum==0)
//	cout<<0;
// else
// {
//    while(sum!=0)
//	 {
//	   a[j]=sum%m;
//	   sum=sum/m;
//	   j++;
//	 }
//   
//	 for(int i=j-1;i>=1;i--)
//	 {
//	   if(a[i]<=9)
//	    cout<<a[i];
//	   else
//	   cout<<char(a[i]-10+'A');
//	 }
// }
//      return 0;
//}