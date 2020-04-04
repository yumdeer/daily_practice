//#include <iostream>
//#include <future>
//#include <thread>
//
//int main()
//{
//	// future from a packaged_task
//	std::packaged_task<int()> task([] { return 7; }); // wrap the function
//	std::future<int> f1 = task.get_future();  // get a future
//	std::thread t(std::move(task)); // launch on a thread
//
//	// future from an async()
//	std::future<int> f2 = std::async(std::launch::async, [] { return 8; });
//
//	// future from a promise
//	std::promise<int> p;
//	std::future<int> f3 = p.get_future();
//	std::thread([&p] { p.set_value_at_thread_exit(9); }).detach();
//
//	std::cout << "Waiting..." << std::flush;
//	f1.wait();
//	f2.wait();
//	f3.wait();
//	std::cout << "Done!\nResults are: "
//		<< f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
//	t.join();
//}


#include <iostream>
#include <thread>
#include <future>

void initiazer(std::promise<int> * promObj)
{
	std::cout << "Inside Thread" << std::endl;
	promObj->set_value(35);
}

int main()
{
	std::promise<int> promiseObj;
	std::future<int> futureObj = promiseObj.get_future();
	std::thread th(initiazer, &promiseObj);
	std::cout << futureObj.get() << std::endl;
	th.join();
	return 0;
}
