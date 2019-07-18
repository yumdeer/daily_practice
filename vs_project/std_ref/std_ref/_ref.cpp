#include<iostream>
#include<functional>  
using namespace std;


template<typename T>
void functest(T a) {
	++a;
}

int main() {

	int a = 1;
	int& b = a;
	functest(a);
	cout << a << endl;  //1
	functest(b);
	cout << a << endl;  //1
	functest(ref(a));
	cout << a << endl;  //2

}