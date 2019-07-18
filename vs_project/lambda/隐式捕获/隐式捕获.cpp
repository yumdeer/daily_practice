//隐式捕获

#include <iostream>
using namespace std;

class test
{
public:
	void hello() {
		cout << "test hello!\n";
	};
	void lambda() {
		auto fun = [this] { // 捕获了 this 指针
			this->hello(); // 这里 this 调用的就是 class test 的对象了
		};
		fun();
	}
};

int main()
{
	//显示传递
	cout << "/*******显示传递*******/" << endl;
	int i = 12;		cout << &i << endl;					//输出：010FF834	//012（8进制）十进制是10。
	auto func = [i] { cout << &i << " " << i << endl; };
	func();                                 // 输出：010FF828 12

	cout << endl;

	//隐式传递
	cout << "/*******隐式传递*******/" << endl;

	[](int j) { cout << &j << " " << j << endl; }(23);      //或通过“函数体”后面的‘()’传入参数
	cout << endl;

	cout << "1.拷贝捕获" << endl;
	int a = 123; cout << &a << endl;         //输出：010FF81C
	auto f = [=] { cout << &a << " " << a << endl; };
	f();                                     //输出：010FF810 123
	cout << endl;

	cout << "2.引用捕获" << endl;
	int b = 234;
	auto f_1 = [&] { cout << &b << " " << b << endl; };
	b = 345; cout << &b << endl;				//输出：010FF804
	f_1();                                    //输出：010FF804 345
	cout << endl;

	cout << "3.拷贝与引用混合" << endl;
	//[&, x]，变量x以引用形式捕获，其余变量以传值形式捕获
	int c = 456, d = 567;
	cout << &c << " " << &d << endl;          //输出：010FF7EC 010FF7E0
	auto f_2 = [=, &d] {
		cout << &c << " " << &d << " " << c << " " << d << endl;       //输出：010FF7D4 010FF7E0 456 567
	};
	f_2();
	cout << endl;

	cout << "4.[bar] 指定引用或拷贝" << endl;
	int e = 678;    cout << &e << endl;       //输出：010FF7C4
	auto f_3 = [e] { cout << &e << " " << e << endl; };
	f_3();									  // 输出：010FF7B8 678
	cout << endl;

	cout << "5.[this] 捕获 this 指针" << endl;
	//我们要跳到类中了
	test t;
	t.lambda();


	return 0;
}


