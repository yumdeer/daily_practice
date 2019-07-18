//#include<iostream>
//#include<stdio.h>
//#include<string>
//using namespace std;
//int main()
//{
//    int n,m;
//    bool p;
//    string op;
//    while(scanf("%d%d",&n,&m)==2)          // 输入两个长度为m的字符串
//    {
//        int an=0;
//        getline(cin,op);
//        int u=0;
//        string a[100];
//        for(int i=0;i<=n-1;i++)
//            getline(cin,a[i]);
//        for(int i=0;i<=n-1;i++)
//        {
//            for(int j=0;j<=m-1;j++)
//            {
//                if(a[i][j]=='W')
//                {
//                    p=(i+j)%2;
//                    u=1;
//                }
//                else if(a[i][j]=='B')
//                {
//                    p=(i+j+1)%2;
//                    u=1;
//                }
//            }
//            if(u==1)                                        //如果这一行有W或B，break
//                break;
//        }
//
//        if(u==0)											//全是？的特殊情况
//            an=0;
//        else
//            for(int i=0;i<=n-1;i++)
//                for(int j=0;j<=m-1;j++)
//                {
//					if(a[i][j]=='W')                         //测试前一个是否等于后一个p
//                        if((i+j)%2!=p)
//                            an++;
//					else if(a[i][j]=='B')
//						if((i+j)%2==p)
//							n++;                             //n++
//				}
//
//		if(an==0)
//		cout<<"Possible\n";
//        else
//        cout<<"Impossible"<<endl;
//    }
//    return 0;
//}

#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
    int n,m;
    bool p;
    string op;
    while(scanf("%d%d",&n,&m)==2)          // 输入两个长度为m的字符串
    {
        int an=0;
        getline(cin,op);
        int u=0;
        string a[100];
        for(int i=0;i<=n-1;i++)
            getline(cin,a[i]);
        for(int i=0;i<=n-1;i++)
        {
            for(int j=0;j<=m-1;j++)
            {
                if(a[i][j]=='W')
                {
                    p=(i+j)%2;
                    u=1;
                }
                else if(a[i][j]=='B')
                {
                    p=(i+j+1)%2;
                    u=1;
                }
            }
            if(u==1)
                break;
        }
        if(u==0)
            an=0;
        else
            for(int i=0;i<=n-1;i++)
                for(int j=0;j<=m-1;j++)
                    if(a[i][j]=='W')
                        if((i+j)%2!=p)
                            an++;
                    else if(a[i][j]=='B')
                        if((i+j)%2==p)
                            an++;
        if(an==0)
        cout<<"Possible\n";
        else
        cout<<"Impossible"<<endl;
    }
    return 0;
}
