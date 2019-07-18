#include<iostream>
using namespace std;

struct w
{
	int x;
	int y;
};

int main()
{
	int n;
	int num=0;
	cin >> n;
	int m=n;
	w *s=new w[n];
	int bz=0;
	while(n--)
	{	 
        cin>>s[n].x>>s[n].y;
	}

	for(int i=m;i>=0;i--)
		for(int j=0;j<m;j++)	
		{  
			if(s[i].y-s[j].y==0)
				continue;
			if( (s[i].x-s[j].x)/(s[i].y-s[j].y)==1 || (s[i].x-s[j].x)/(s[i].y-s[j].y)==-1 )
				num++;
		}

	cout << num/2 << endl;

	return 0;
}


//#include<iostream>
//using namespace std;
//int he[4001],zhengcha[2001],fucha[2001],zero;
//int main()
//{
//    int n,a,b,ans=0;
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        cin>>a>>b;
//        he[a+b]++;
//        if(a>b)  zhengcha[a-b]++;
//        else if(a<b) fucha[b-a]++;
//        else    zero++;
//    }
//    ans=zero*(zero-1)/2+ans;
//    for(int i=1;i<4000;i++)
//        ans=he[i]*(he[i]-1)/2+ans;
//    for(int i=1;i<2000;i++)
//    {
//        ans=zhengcha[i]*(zhengcha[i]-1)/2+ans;
//        ans=fucha[i]*(fucha[i]-1)/2+ans;
//    }
//    cout<<ans<<endl;
//    return 0;
//}