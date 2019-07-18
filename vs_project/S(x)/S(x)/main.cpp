#include <iostream>

int sum(int a );
int main()
{   using namespace std;
	int n,x=0,num=0;
	int id=0;
	std::cin >> n ;
	for( x=0; x<n ;x++ )
	{
		num=sum(x);
		if( x*x+num*x == n )
		{ 
		  id=1;
		  cout << x <<endl;
		}	
	}
	if(id==0)
	{
		cout << -1 <<endl;
	}
	return 0;
}

int sum( int a )
{ 
	int m=0;
    while( a )
    {
	  m+=a%10;
      a=a/10;  
    }
	return  m ;
}