// stdafx.cpp : 只包括标准包含文件的源文件
// test.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中
// 引用任何所需的附加头文件，而不是在此文件中引用
#include <iostream>
using namespace  std;

int main()
{
	char ch[]={"abc\0def"};
	char *p=ch;

	cout << *p+4 <<endl;             //输出101，a+4并转换为97+4
	cout << *(p+4) <<endl;           //输出d ， p指向ch[4]

	return 0;
}