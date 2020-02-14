#include <iostream>
#include <string>
using namespace std;

string Func()
{
	string nu = "123";
	return nu;
}

int main()
{
	//const string& s = Func();
	const string& s = Func();
	const string& ss = s;
	cout << ss << endl;

	string ab = "1234";
	string& a = ab;
	const string& aa = a;
	cout << aa << endl;
	a = "12345";
	cout << aa << endl;

	//const char num[4] = "123";
	//const string &numm = num;
	//string num = "123";
	//string* ss = &num;
	//cout << *ss << endl;


	return 0;
}