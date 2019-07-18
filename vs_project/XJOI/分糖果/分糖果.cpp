#include<iostream>
using namespace std;
int main()
{
	int t;
	while(cin>>t&&t)
	{
		int i,sum=0,a[1005];
		for(i=0;i<t;i++)
			cin>>a[i];
		while(1)
		{
			int flag=0;
			for(i=0;i<t-1;i++)
				if(a[i]!=a[i+1])
				{
					flag=1;
					break;
				}
				if(!flag) break;
				sum++;
				int n=a[i]/2;
            for(i=0;i<t;i++)
				{
					a[i]/=2;       
					if(i!=t-1)
						a[i]+=a[i+1]/2;
					else 
						a[i]+=n;
				}
				for(i=0;i<t;i++)
					if(a[i]%2) a[i]++;
		}
		cout<<sum<<' '<<a[0]<<endl;
	}

	return 0;
}
