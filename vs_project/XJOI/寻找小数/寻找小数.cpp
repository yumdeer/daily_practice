#include<iostream>
using namespace std;

//int main()
//{
//    long long int a,b,c,i,e,f;
//    scanf("%lld%lld%lld",&a,&b,&c);
//    for(i=0;i<100000;i++)
//    {
//        e=a*10/b;
//        f=a*10%b;
//        a=f;
//        if(e==c)
//        {
//            printf("%d\n",i+1);
//            break;
//        }
//    }
//    if(i>=100000)
//        printf("-1\n");
//    return 0;
//}

int main()
{
	int m,b;
	cin >> m >> b;
	
	int x,y,num=0;

	for(int x=0;x<m*b;x++)
	{	
		y=-x/m+b;
		int a=x;
		for(;a>=0;a--)
			num+=a+y;
	}

	cout << num <<endl;
	return 0;
}