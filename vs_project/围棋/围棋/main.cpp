#include<iostream>
using namespace std;

int main()
{
	char Go[100][100];
	int is=0,flag=0,num=0;
	int n,m;

	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)                 //输入
			for(int j=0;j<m;j++)
			{	
				cin>>Go[i][j];
			}
		 for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(Go[i][j]=='?')
					num++;
			}


		while(1)                            //给字符W或B周围的?赋值
		{  
			gg: ;flag=0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if( Go[i][j]=='W' )
					{
						if(Go[i-1][j]=='?')
							{ Go[i-1][j]='B';flag=1;}
						if(Go[i+1][j]=='?')
							{Go[i+1][j]='B';flag=1;}
						if(Go[i][j-1]=='?')
							{Go[i][j-1]='B';flag=1;}
						if(Go[i][j+1]=='?')
							{Go[i][j+1]='B';flag=1;}
					}
					if( Go[i][j]=='B' )
					{
						if(Go[i-1][j]=='?')
							{Go[i-1][j]='W';flag=1;}
						if(Go[i+1][j]=='?')
							{Go[i+1][j]='W';flag=1;}
						if(Go[i][j-1]=='?')
							{Go[i][j-1]='W';flag=1;}
						if(Go[i][j+1]=='?')
							{Go[i][j+1]='W';flag=1;}
					}
				}
				if(flag==1)
					goto gg;
			}
			if(flag==0)
				break;
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if( Go[i][j]!=Go[i][j+1] && Go[i][j]!=Go[i+1][j] )
				{  
		    
				}
				else
				{
					is++;
				}
			}
		}

		if(num==n*m)
			is=0;

		if( is==0  )
			cout <<"Possible"<<endl;
		else
			cout <<"Impossible"<<endl;
	}

	return 0;
}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    int n,m;
//    bool p;
//    string op;
//    while(cin>>n&&cin>>m)
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
//            if(u==1)
//                break;
//        }
//        if(u==0)
//            an=0;
//        else
//            for(int i=0;i<=n-1;i++)
//                for(int j=0;j<=m-1;j++)
//                    if(a[i][j]=='W')
//                        if((i+j)%2!=p)
//                            an++;
//                    else if(a[i][j]=='B')
//                        if((i+j)%2==p)
//                            an++;
//        if(an==0)
//        cout<<"Possible\n";
//        else
//        cout<<"Impossible"<<endl;
//    }
//    return 0;
//}

#include<iostream>
using namespace std;

int main()
{
	char Go[100][100];
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++)                 //输入
		for(int j=0;j<m;j++)
		{	
			cin>>Go[i][j];
		}

	 for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(Go[i][j]=='?');
		}
			break;
	 }
}	