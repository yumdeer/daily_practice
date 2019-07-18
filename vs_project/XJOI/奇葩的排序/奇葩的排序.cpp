#include <iostream>
#include <deque>
#include <iterator>
//#include <allocators>
#include <algorithm>
#include<windows.h>

//using namespace std;
//
//int  Ascending(deque<int> serial_,int n)
//{
//	int succ=0;
//	for(int i=1;i<n;i++)
//		if(serial_[i-1] > serial_[i])
//		{
//			succ++;
//			if(succ>1) 
//			 break;
//		}
//    if(succ == 0)  
//		succ = -1;
//	else if(succ>1) 
//		succ=0;
//	else if(serial_.front() < serial_.back()) 
//		succ=0;
//
//	return  succ;
//}
//
//
//int main()
//{
//	DWORD start_time=GetTickCount();
//	{
//
//	int n;int last,num_flag=0;
//	cin >> n;
//	deque<int> serial_;
//	for(int i=0;i<n;i++)
//	{
//		int num_temporary;
//		cin >> num_temporary;
//		serial_.push_back(num_temporary);
//	}
//
//	while(  Ascending(serial_,n)==1 ) // || Ascending(serial_,n)==-1)
// 	{
//
//		last=serial_.back();	
//		serial_.pop_back();
//		serial_.push_front(last);
//		num_flag++;
//	}
//
//	if( Ascending(serial_,n) == -1 && num_flag ==0 ) cout << "0" <<endl;
//	else if(num_flag == 0)
//		cout << "-1" <<endl;
//	else cout << num_flag <<endl;
//
//	//for(int i=0;i<n;i++)
//	//{
//	//cout <<serial_.front() << " ";
//	//serial_.pop_front();
//	//}
//	
//	}
//	DWORD end_time=GetTickCount();
//	cout<<"The run time is:"<<(end_time-start_time)<<"ms!"<<endl;
//
//	return 0;
//}
//





using namespace std;
int a[100003];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	int k=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			ans++;  
			k=i;
		}
	}
	if(ans==1 && a[n]<=a[1])
	{
		printf("%d",n-k);
	}
	else if(ans==0)
	{
		printf("0");
	}
	else
	{
		printf("-1");
	}
	return 0;
}