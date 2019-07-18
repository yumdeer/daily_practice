#include <iostream>
using namespace  std;

int main()
{
	{
		int x=1;
		cout<<x<<" The zero  output!"<<endl;
		{
			cout<<x<<" The first output!"<<endl;
			int x=2;                                       //必须要重新初始化才会改变作用域
			cout<< x <<" The second output!"<<endl;
			  {
			   int x=3;
			   cout<<x<<" The third output!"<<endl;
			  }
			cout<<x<<" The fourth output!"<<endl;
		}
		cout<<x<<" The fifth output!"<<endl;
	}
	return 0;
}
