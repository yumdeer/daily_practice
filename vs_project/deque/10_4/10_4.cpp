#include <iostream>
#include <algorithm> 
#include <iterator>
#include <vector> 
#include <list>
#include <deque>

template<class T>
void printContainer(const char* msg,const T &s)
{
	std::cout<<msg<<":";
	copy(s.begin(),s.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;
}
int main()
{
	std::deque<int>s;
	for(int i=0;i<10;i++)
	{
		int x;
		std::cin >>x ;
		s.push_front(x);
	}
	printContainer("deque at first",s);
	std::list<int> I(s.rbegin(),s.rend());
	printContainer("list at first",I);

	std::list<int>::iterator iter = I.begin();
	while(iter != I.end())
	{
		int v=*iter;
		iter = I.erase(iter);
		I.insert(++iter,v);
	}
	printContainer("list at last",I);
	s.assign(I.begin(),I.end());
	printContainer("deque at last",s);

	return 0;
}




//#include <iostream>
//#include <algorithm> 
//#include <iterator>
//#include <vector> 
//#include <list>
//#include <deque>
//using namespace std;
//
//template<class T>
//void printContainer(const char* msg,const T &s)
//{
//	cout<<msg<<":";
//	copy(s.begin(),s.end(),ostream_iterator<int>(cout," "));
//	cout<<endl;
//}
//int main()
//{
//	std::deque<int>s;
//	for(int i=0;i<10;i++)
//	{
//		int x;
//		std::cin >>x ;
//		s.push_front(x);
//	}
//	printContainer("deque at first",s);
//	std::list<int>I(s.rbegin(),s.rend());
//	printContainer("list at first",s);
//}