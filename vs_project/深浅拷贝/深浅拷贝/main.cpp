#include<iostream>
#include<Windows.h>
#include<string.h>
using namespace std;

//class String
//{
//public:
//	//构造
//	String(const char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//
//	//拷贝构造
//	String(const String& s)
//		:_str(new char[strlen(s._str)+1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	//重载等号
//	//s1(this)=s2(s)
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			//释放旧空间
//			delete[] _str;
//			//开辟新空间并拷贝s内容
//			char* newstr = new char[strlen(s._str) + 1];
//			strcpy(newstr, s._str);
//			//this指向新空间
//			_str = newstr;
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		if(_str)
//			delete[] _str;
//	}
//private:
//	char* _str;
//};
//void test2()
//{
//	String s1;
//	String s2("hello");
//	String s3(s2);
//	String s4 = s2;
//}
//int main()
//{
//	//test1();
//	test2();
//	system("pause");
//	return 0;
//}






class String
{
public:
	//构造
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
 
	//拷贝构造
	String(const String& s)
		:_str(nullptr)
	{
		//用s构造新的String
		String tmp(s._str);
		//交换this和tmp
		swap(_str, tmp._str);
	}
 
	//重载=
	//s1=s2
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String tmp(s._str);
			swap(_str, tmp._str);
		}
		return *this;
	}
        
	//String& operator=(String& s)
	//{
	//
	//	swap(_str, s._str);
	//	return *this;
	//}
       
	~String()
	{
		if (_str)
			delete[] _str;
	}
private:
	char* _str;
};
void test3()
{
	String s1;
	String s2("hello");
	String s3(s2);
	String s4;
	s4=s2;
}
int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}
