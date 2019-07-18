#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

template<class T>
void measure(T&& func) {
	using namespace std::chrono;
	auto start = system_clock::now();
	func();
	duration<double> diff = system_clock::now() - start;
	cout << "elapsed: " << diff.count() << "second" << endl;

}

void func() {
	long long s = 0;
	for (int i = 0; i < 100000000; i++)
		s += i;
}

int main() {

	//measure([]() {
	//	long long s = 0;
	//	for (int i = 0; i < 100000000; i++)
	//		s += i;
	//});

	measure(func);
	
	return 0;
}