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

// [a,b)
void sum(long start,long end,long& ans) {
	long s = 0;
	for (long i = start; i < end; i++) {
		s += i;
	}
	ans = s;
}

const long S = 100000000;

int main() {

	measure([]() {
		long ans1, ans2;
		thread t1 = thread(sum, 0, S / 2, std::ref(ans1));
		thread t2 = thread(sum, S / 2, S, std::ref(ans2));
		t1.join();
		t2.join();
		cout << (ans1 + ans2) << endl;
	});

	measure([]() {
		long ans;
		sum(0,S,ans);
		cout << ans << endl;
	});

	return 0;
}