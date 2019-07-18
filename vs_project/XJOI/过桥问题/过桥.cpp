#include <iostream>
#include <deque>
#include <iterator>
//#include <allocators>
#include <algorithm>

using namespace std;

//每次回来一个过桥中数组最小的，然后最大的两个过桥，最回来最小的
int main()
{
	int n;int itime=0;
	cin >> n;
	deque <int> bridge_;
	int inumber_bridge;
	for(int i=0;i<n;i++)
	{
		cin >> inumber_bridge; 
		bridge_.push_back(inumber_bridge);
	} 
	
	if( bridge_.size() == 1 )
		cout << inumber_bridge <<endl;

	else
	{
		sort(bridge_.begin(),bridge_.end());          //按大小排序
	
		int ibiggest,ibigger,ismall,ismaller;
		int isize=bridge_.size();
	
		ismall=bridge_.front();						  //将最小的取出
		//itime += ismall;						     
		bridge_.pop_front();
		ismaller=bridge_.front();                     //将次小的取出
		//itime += ismaller;
		bridge_.pop_front();
	
		while(bridge_.size())
		{
			//初始化
			ibiggest = bridge_.back();				   //将最大的取出
			bridge_.pop_back();
			itime += ismaller + ismall  + ibiggest ;

			if(bridge_.size())
			{
				ibigger = bridge_.back();				//将次大的取出
				bridge_.pop_back();
				itime += ismaller;
			}		
		}

		if( isize %2 == 0)
			itime += ismaller;
	 
	///////////////最终结果为 (isize-2)/2 个（2*ismaller+ismall+ibiggest）相加 ，偶数在加一个次小值/////////////

		cout << itime <<endl;
	}

	return 0;
}

// 1 3 4 5 8 10



//#include<bits/stdc++.h>
//using namespace std;
//int a[1000010],ans=0;
//void f(int n)
//{
//	if(n<=2) ans+=a[n];
//	else if(n==3) ans+=a[1]+a[2]+a[3];
//	else
//	{
//		ans+=a[n]+a[1];
//		ans+=min(2*a[2],a[n-1]+a[1]);
//		f(n-2);
//	}
//}
//
//int main()
//{
//	int bridge[100];
//	int i,n;
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//	sort(a+1,a+n+1);
//	f(n);
//	printf("%d",ans); 
//	return 0;
//}























//void bubble_sort(int arr[], int len) {
//	int i, j;
//	for (i = 0; i < len - 1; i++)
//		for (j = 0; j < len - 1 - i; j++)
//			if (arr[j] > arr[j + 1])
//				swap(arr[j], arr[j + 1]);
//}

//	int *ibridge=new int[n];
//deque <int> vec(100); //(bridge,bridge+100);
//copy( bridge, bridge+50, vec.begin() );
//sort( vec.begin(), vec.end() );
//sort(bridge,bridge+100);
//int *BridgeCopy=new int[n];
//for(int i=0;i<n;i++)
//	BridgeCopy[i]=bridge[i];
//for(int i=0;i<n;i++)
//	cout << BridgeCopy[i] << " "; 
//int *ibridgeoveride=new int[n];