/*
	test 1
*/

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//#include <future>
//#include <string>
//#include <mutex>
//
//std::mutex m;
//struct X {
//	void foo(int i, const std::string& str) {
//		std::lock_guard<std::mutex> lk(m);
//		std::cout << str << ' ' << i << '\n';
//	}
//	void bar(const std::string& str) {
//		std::lock_guard<std::mutex> lk(m);
//		std::cout << str << '\n';
//	}
//	int operator()(int i) {
//		std::lock_guard<std::mutex> lk(m);
//		std::cout << i << '\n';
//		return i + 10;
//	}
//};
//
//template <typename RandomIt>
//int parallel_sum(RandomIt beg, RandomIt end)
//{
//	auto len = end - beg;
//	if (len < 1000)
//		return std::accumulate(beg, end, 0);
//
//	RandomIt mid = beg + len / 2;
//	auto handle = std::async(std::launch::async,parallel_sum<RandomIt>, mid, end);
//	int sum = parallel_sum(beg, mid);
//	return sum + handle.get();
//}
//
//int main()
//{
//	//std::vector<int> values{ 2, 0, 12, 3, 5, 0, 2, 7, 0, 8, 1 };
//	//int min{ 3 };
//	//auto sum = std::accumulate(std::begin(values), std::end(values), 0, [min](int sum, int v)
//	//{
//	//	if (v < min)
//	//		return sum;
//	//	return sum + v;
//	//});
//
//	//std::cout << "The sum of the elements greater than " << min - 1 << " is " << sum << std::endl;  // 35
//
//	std::vector<int> v(10000, 1);
//	std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';		//The sum is 10000
//
//	X x;
//	// Calls (&x)->foo(42, "Hello") with default policy:
//	// may print "Hello 42" concurrently or defer execution
//	auto a1 = std::async(&X::foo, &x, 42, "Hello");
//	// Calls x.bar("world!") with deferred policy
//	// prints "world!" when a2.get() or a2.wait() is called
//	auto a2 = std::async(std::launch::deferred, &X::bar, x, "world!");
//	// Calls X()(43); with async policy
//	// prints "43" concurrently
//	auto a3 = std::async(std::launch::async, X(), 43);
//	a2.wait();                     // prints "world!"
//	std::cout << a3.get() << '\n'; // prints "53"
//} // if a1 is not done at this point, destructor of a1 prints "Hello 42" here


/*
	test 2
*/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

using namespace std::chrono;
std::string fetchDataFromDB(std::string recvdData)
{
	// Make sure that function takes 5 seconds to complete
	std::this_thread::sleep_for(seconds(5));
	//Do stuff like creating DB Connection and fetching Data
	return "DB_" + recvdData;
}
std::string fetchDataFromFile(std::string recvdData)
{
	// Make sure that function takes 5 seconds to complete
	std::this_thread::sleep_for(seconds(4));
	//Do stuff like fetching Data File
	return "File_" + recvdData;
}
int main()
{
	// Get Start Time
	system_clock::time_point start = system_clock::now();

	//use std::async to replace Fuction of fetchDataFromDB("Data");
	std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");

	////Fetch Data from File
	std::string fileData = fetchDataFromFile("Data");
	//std::future<std::string> resultFromFile = std::async(std::launch::async, fetchDataFromFile, "Data");

	////Fetch Data from DB
	//std::string dbData = fetchDataFromDB("Data");
	std::string dbData = resultFromDB.get();
	//std::string fileData = resultFromFile.get();

	std::this_thread::sleep_for(seconds(1));

	// Get End Time
	auto end = system_clock::now();
	auto diff = duration_cast <std::chrono::seconds> (end - start).count();
	std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;
	//Combine The Data
	std::string data = dbData + " :: " + fileData;
	//Printing the combined Data
	std::cout << "Data = " << data << std::endl;
	return 0;
}

