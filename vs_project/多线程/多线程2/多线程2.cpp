//实验一 callable objects 是什么？可调用对象
//#include <iostream>
//#include <thread>
//
//using namespace std;
//
////function object
//struct A {
//	void operator()() {
//		cout << "I`m A " << endl;
//	}
//};
//void show() {
//	cout << "I am show" << endl;
//}
//
//int main() {
//	show();
//	A a;
//	a();
//
//	thread th = thread(A());
//	th.join();
//
//}


//实验二 类传入引用
#include <iostream>
#include <string>
#include <thread>

using namespace std;

//function object
class A {
public:
	void operator()(string &s);
};

void A::operator()(string &s) {                   //符号重载
	cout << "S is " << s << endl;
}

int main() {
	string s = "hello";
	thread th = thread( A(), std::ref(s) );
	th.join();

}