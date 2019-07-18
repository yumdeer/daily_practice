//1、如果 vector 长度为零，即 vector 为空，内部没有元素，那就不能取得第一个元素的地址。
//因为此时第一个元素还不存在。如果此时调用 data() 方法，其返回值为 NULL，但如果调用其他 4 种办法，程序直接崩溃，
//所以这里在调用除 data() 方法以外的形式来获得首地址的时候要注意判断 vector 是否为空；
//
//2、如果 vector 的长度变化了（例如：不停地进行 push_back），那就可能导致之前取得的首地址变为无效。
//所以，为了安全，每次进行 push_back, insert, assign 之类的操作之后，都需要重新取得首地址。
//因为之前取得的地址可能已经无效了。

#include <iostream>
#include <array>

using namespace std;

void foo(int *p, int len) {
	cout << *p << " " << *(p+2) << endl;
}


int main(){

	std::array<int,4> arr = { 1,2,3,4 };

// C 风格接口传参 , 获取首地址
	// foo(arr, arr.size());           // 非法, 无法隐式转换
	foo(&arr[0], arr.size());
	foo(arr.data(), arr.size());
	foo(&arr.at(0), arr.size());
	foo(&arr.front(), arr.size());
	foo(&*arr.begin(), arr.size());

// 使用 `std::sort`
	std::sort(arr.begin(), arr.end());

	return 0;
}