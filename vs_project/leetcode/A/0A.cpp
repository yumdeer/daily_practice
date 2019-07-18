//#include <iostream>
//#include <string>
//#include <locale>   
//
//using namespace std;
//
//int main()
//{
//	//int a;
//	//a = 1000;
//	//cout << "hello world !" << endl;
//	//cout << a << endl;
//
//	//string s = " 你好！";
//	//cout << s << endl;
//
//	//wstring pi = L"pi is " + to_wstring(3.1415926);
//	//wstring perfect = to_wstring(1 + 2 + 4 + 7 + 14) + L" is a perfect number";
//	//wcout << pi << L'\n';
//	//wcout << perfect << L'\n';
//
//	//wcout.imbue(std::locale("chs"));
//	//wstring ws = L" 你好！";
//	//wcout << ws << endl;
//
//	//system("pause");
//	////getchar();
//	////getchar();
//
//
//
//
//	return 0;
//}


#include <iostream>
#include <stdio.h>
#include <string>

//typedef int P(); // 简单的
//typedef void Q(int *p, const std::string& s1, const std::string& s2, size_t size, bool is_true); // 复杂的
//
//class X {
//public:
//	P(eat_shit); // 等价于声明`int eat_shit();`
//	Q(bullshit); // 等价于声明`void bullshit(int *p, const string& s1, const string& s2, size_t size, bool is_true);`
//};
//
//int X::eat_shit() {
//	return 888;
//}
//
//void X::bullshit(int *p, const std::string& s1, const std::string& s2, size_t size, bool is_true) {
//	std::cout << "s1: " << s1 << ", s2: " << s2 << ", size: " << size << std::endl;
//	std::cout << "elems:" << std::endl;
//	for (int i = 0; i < size; i++) {
//		std::cout << *p++, (i == size - 1) ? "" : ",";
//	}
//	std::cout << std::endl;
//}
//
//int main() {
//	X *xx;
//	std::cout <<"shit ret:"<< xx->eat_shit() << std::endl;
//	int a[] = { 1, 3, 4, 5, 7 };
//	xx->bullshit(a, "foo", "bar", sizeof(a) / sizeof(int), true);
//}
//

template <typename T>
class list {
public:
	int val;
	list *next;
	list(int x) : val(x), next(NULL) {}
};

list<int>  *pre = new list<int>	(0);



