//#include <iostream>
//#include <string>
//#include <thread>
//#include <chrono>
//
//using namespace std;
//
//int main() {
//	string s = "test";
//	auto f = [&s](int a,int b) {
//		cout << s << endl;
//		cout << a + b << endl;
//	};
//	f(2,3);
//
//	return 0;
//}


#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

int main() {
	string s = "test";
	thread f = thread( [&s](int a, int b) {
		cout << s << endl;
		cout << a + b << endl;
	},2,3 );
	f.join();

	return 0;
}