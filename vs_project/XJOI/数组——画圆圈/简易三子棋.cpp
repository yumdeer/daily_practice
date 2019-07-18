#include <iostream>
using namespace std;

int main()
{
	char checker_board[4][4];
	int  ichecker_board[4][4]={0};
	int  iflag=0;

	while(1)
	{
		iflag=0;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
					ichecker_board[i][j]=0;
			}

		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				cin >> checker_board[i][j];
				if( checker_board[i][j]== 'X' )
					ichecker_board[i][j]++;
				else if( checker_board[i][j]== 'O' )
					ichecker_board[i][j]+=2;
				else if( checker_board[i][j]== '.' )
					ichecker_board[i][j]+=3;
			}
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
				{
					if(ichecker_board[i][j]==1 && ichecker_board[i-1][j-1]==1 && ichecker_board[i+1][j+1]==1 ||				    //Ð±Ïß
					   ichecker_board[i][j]==1 && ichecker_board[i-1][j]==1 && ichecker_board[i+1][j]==1     ||					//ºáÏß
					   ichecker_board[i][j]==1 && ichecker_board[i][j-1]==1 && ichecker_board[i][j+1]==1     ||					//ÊúÏß
					   ichecker_board[i][j]==3 && ichecker_board[i-1][j-1]==1 && ichecker_board[i+1][j+1]==1  ||
					   ichecker_board[i][j]==3 && ichecker_board[i-1][j]==1   && ichecker_board[i+1][j]==1  ||
					   ichecker_board[i][j]==3 && ichecker_board[i][j-1]==1   && ichecker_board[i][j+1]==1 
					   //ichecker_board[i][j]==3 && (ichecker_board[i-1][j-1]==1 || ichecker_board[i-1][j-1]==3 )  && (ichecker_board[i+1][j+1]==1 || ichecker_board[i+1][j+1]==3) ||
					   //ichecker_board[i][j]==3 && (ichecker_board[i-1][j]==1 || ichecker_board[i-1][j]==3 )  && (ichecker_board[i+1][j]==1 ||  ichecker_board[i+1][j]==3 ) ||
					   //ichecker_board[i][j]==3 && (ichecker_board[i][j-1]==1 || ichecker_board[i][j-1]==3 )  && (ichecker_board[i][j+1]==1 ||  ichecker_board[i][j+1]==3 ) 
					   )
						iflag ++ ;
					//if( ichecker_board[i][j]==2 && ichecker_board[i-1][j-1]==2 && ichecker_board[i+1][j+1]==2 || 
					//	ichecker_board[i][j]==2 && ichecker_board[i-1][j]==2 && ichecker_board[i+1][j]==2     ||
					//	ichecker_board[i][j]==2 && ichecker_board[i][j-1]==2 && ichecker_board[i][j+1]==2     ||
					//	ichecker_board[i][j]==3 && (ichecker_board[i-1][j-1]==2 || ichecker_board[i-1][j-1]==3 )  && (ichecker_board[i+1][j+1]==2 || ichecker_board[i+1][j+1]==3) ||
					//	ichecker_board[i][j]==3 && (ichecker_board[i-1][j]==2 || ichecker_board[i-1][j]==3 )  && (ichecker_board[i+1][j]==2 ||  ichecker_board[i+1][j]==3 ) ||
					//	ichecker_board[i][j]==3 && (ichecker_board[i][j-1]==2 || ichecker_board[i][j-1]==3 )  && (ichecker_board[i][j+1]==2 ||  ichecker_board[i][j+1]==3 ) 
					//	)
					//	iflag ++ ;
				}
		

			if( iflag ) cout << "YES" <<endl;
			else cout << "NO" <<endl;

	}
	return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//char a[10][10];
//int main()
//{
//	bool s=false;
//	while(scanf("%s",&a[1][1])!=EOF)
//	{
//		scanf("%s",&a[2][1]);
//		scanf("%s",&a[3][1]);
//		scanf("%s",&a[4][1]);
//		for(int i=1;i<=4;i++)
//		{
//			for(int j=1;j<=4;j++)
//			{
//				if(a[i][j]=='.')
//				{
//					if(a[i-1][j]=='X'&&a[i+1][j]=='X')
//					{
//						s=true;
//					}
//					else if(a[i+1][j]=='X'&&a[i+2][j]=='X')
//					{
//						s=true;
//					}
//					else if(a[i-1][j]=='X'&&a[i-2][j]=='X')
//					{
//						s=true;
//					}
//					else if(a[i][j-1]=='X'&&a[i][j+1]=='X')
//					{
//						s=true;
//					}
//					else if(a[i][j-1]=='X'&&a[i][j-2]=='X')
//					{
//						s=true;
//					}
//					else if(a[i][j+1]=='X'&&a[i][j+2]=='X')
//					{
//						s=true;
//					}
//					else if(a[i-1][j-1]=='X'&&a[i-2][j-2]=='X')
//					{
//						s=true;
//					}
//					else if(a[i+1][j+1]=='X'&&a[i+2][j+2]=='X')
//					{
//						s=true;
//					}
//					else if(a[i+1][j+1]=='X'&&a[i-1][j-1]=='X')
//					{
//						s=true;
//					}
//					else if(a[i-1][j+1]=='X'&&a[i-2][j+2]=='X')
//					{
//						s=true;
//					}
//					else if(a[i+1][j-1]=='X'&&a[i-1][j+1]=='X')
//					{
//						s=true;
//					}
//					else if(a[i+1][j-1]=='X'&&a[i+2][j-2]=='X')
//					{
//						s=true;
//					}
//				}
//			}
//		}
//		if(s==false)cout<<"NO"<<endl;
//		else cout<<"YES"<<endl;
//		s=false;
//	}
//	return 0;
//}