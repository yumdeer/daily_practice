#include<iostream>
#include<stdio.h>
using namespace std;
int num=0;
int a[19][19];
int x=0,y=0;
int numm=0;
 
void array(int n)
{
    while( x<n-1 )
    {
        while( y<n-1 )
        {   
            num++;
            a[x][y++]=num;           
        }
        num++;
        a[x][y]=num;   
        a[x++][y]=num;
         
    }
    num++;
    a[x][y]=num;
 
    while( x>1+numm )
    {
        while( y>0+numm )
        {   
              a[x][y--]=num;   
              num++;         
        }
        a[x][y]=num;       
        a[x--][y]=num;
        num++;
    }
   a[x][y]=num;

    int xx;
    if(n%2==0)
     xx= (n>>1) +1 ;
	else
	  xx=n>>1;
    if( xx > 1)
    {
      numm++;y++;
	  array(n-1);           //奇数能实现，偶数错了
    }
    else return;
 
}
 
 
int main()
{
    int n;
    cin >> n;
    array(n);
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << a[i][j] << " " ;
        cout <<endl;
    }
 
    return 0;
}