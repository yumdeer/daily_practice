




//#include<iostream>
//#include<memory.h>
//using namespace std;
//typedef long long ll;
//const ll mod=1000000;
//ll a[10000030],b[mod+100];
//
//int main()
//{
//	ll n;
//	a[0]=1;
//	a[1]=2;
//	cin>>n;
//	for(ll i=2;i<n;i++)
//		a[i]=(a[i-1]+a[i-2])%mod;
//
//	memset(b,0,sizeof(b));
//
//	for(int i=0;i<n;i++)
//		b[a[i]]++;
//	ll sum=0,m=n-1;
//	for(ll i=1000000;i>=0;i--)
//	{
//		if(b[i])
//		{
//			for(ll j=1;j<=b[i];j++){
//				sum=(sum+(i*m)%mod)%mod;
//			m--;
//		}
//	}
//}
//cout<<sum;
//return	0;
//}