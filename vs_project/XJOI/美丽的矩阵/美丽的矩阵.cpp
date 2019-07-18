#include<iostream>
using namespace std;
int a[25];
int main()
{
	int b,c,d;
	d=0;
	for (b=0;b<=24;b++)
	{
		cin>>a[b];
	}
	for (b=0;b<=24;b++)
	{
		if(a[b]==1)
		{
			d=b+1;
			break;
		}
	}
	if (d==13)
	{
		cout<<"0";
	}
	else if (d==1||d==5||d==21||d==25)
	{
		cout<<"4";
	}
	else if (d==2||d==4||d==6||d==10||d==16||d==20||d==22||d==24)
	{
		cout<<"3";
	}
	else if (d==7||d==9||d==3||d==11||d==15||d==17||d==19||d==23)
	{
		cout<<"2";
	}
	//else if (d==8||d==12||d==14||d==18)
	//{
	//	cout<<"1";
	//}
	else cout<<"0";

	return 0;
}

