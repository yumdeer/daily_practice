#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	std::string str,str1;
	getline(cin,str1);
	{
		std:: cout <<setiosflags(ios::right)<<setw(15)<< "孤独" <<endl;
		std:: cout <<setiosflags(ios::right)<<setw(15)<< "+" <<endl ;
		//std::cin >>setiosflags(ios::right)>>setw(15)>> str;
	}

	getline(cin,str);
	if (str== "           手机")
	{
		std ::cout << "________________"<<endl;
		std ::cout <<endl;
		std:: cout <<setiosflags(ios::right)<<setw(15)<< "一群人的孤独" <<endl;
	}

	cout << endl;

	return 0;
}