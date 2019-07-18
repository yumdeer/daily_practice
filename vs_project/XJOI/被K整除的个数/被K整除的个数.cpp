#include<iostream>
using namespace std;

//int main()
//{
//    long long k,a,b,num=0;
//	cin >> k >> a >> b;
//
//    num=(b-a)/k;
//	if(b%k==0)num++;
//
//	cout <<num <<endl;
//
//    return 0;
//}

#include<stdio.h>
using namespace std;
int main()
{
    long long k,a,b;
    long long ans=0;
    scanf("%lld%lld%lld",&k,&a,&b);
    for(;a<b;a++)
    {
        if(a%k==0) break;
    }
    for(;b>a;b--)
    {
        if(b%k==0) break;
    }
    if(b==a)
    {
        if(a%k==0)
        {
            printf("1");
            return 0;
        }
        else
        {
            printf("0");
            return 0;
        }
    }
    ans=(b-a)/k+1;
    printf("%lld",ans);
}