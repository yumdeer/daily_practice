#include <iostream>
#include <vector>
#include <iterator>
//#include <allocators>
#include <algorithm>

using namespace std;

int main()
{
	int input_num;
	cin >> input_num;
	int arr_[100];
	for(int i=0;i<input_num;i++)
		cin >>arr_[i];

	vector<int> output_(arr_,arr_+input_num);
	sort(output_.rbegin(),output_.rend());
	                                                                                                 
	
	for(int i=1;i<input_num/2;i++)
	{
		output_[i]=output_[i]^output_[input_num-i-1];
		output_[input_num-i-1]=output_[input_num-i-1]^output_[i];
		output_[i]=output_[input_num-i-1]^output_[i];
	}

	for(int i=0;i<input_num;i++)
		cout<<output_[i]<<" ";

	return 0 ;
}




//#include<bits/stdc++.h>
//using namespace std;
//int k[1001];
//int main()
//{  
//	int n,m;
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++)
//		scanf("%d",&k[i]);
//	for(int i=n-1;i>=1;i--)
//		for(int u=1;u<=i;u++)
//			if(k[u]>k[u+1])
//			{
//				m=k[u];
//				k[u]=k[u+1];
//				k[u+1]=m;
//			}
//			cout<<k[n];
//			for(int i=2;i<=n-1;i++)
//				cout<<" "<<k[i];
//			cout<<" "<<k[1];
//			return 0;
//}