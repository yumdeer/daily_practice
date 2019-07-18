//用Future获得多线程返回值

#include <iostream>
#include <thread>
#include <future>
#include <vector>

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
long sum(long start, long end) {
	long s = 0;
	for (long i = start; i < end; i++) {
		s += i;
	}
	return s;
}

const long S = 100000000;

int main() {

	measure([]() {
		const long K = 6;
		vector<future<long>> vf;
		vf.reserve(K);
		for (int i = 0; i < K; i++)
		{
			vf.push_back(async(sum, i == 0 ? 0 : (S / K) * i, (S / K)*(i + 1)));  //async()返回类型future
		}
		long ans = 0;
		for (int i = 0; i < K; i++)
		{
			ans += vf[i].get();
		}
		cout << ans << endl;
	});

	measure([]() {
		long ans = sum(0, S);
		cout << ans << endl;
	});

	return 0;
}