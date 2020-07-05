#include <thread>
#include <iostream>
#include <assert.h>
#include <chrono>
#include <future>
void threadFunction(std::future<void> futureObj)
{
	std::cout << "Thread Start" << std::endl;
	while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
	{
		std::cout << "Doing Some Work" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	std::cout << "Thread End" << std::endl;
}
int main()
{
	// Create a std::promise object
	std::promise<void> exitSignal;
	//Fetch std::future object associated with promise
	std::future<void> futureObj = exitSignal.get_future();
	// Starting Thread & move the future object in lambda function by reference
	std::thread th(&threadFunction, std::move(futureObj));
	//Wait for 10 sec
	std::this_thread::sleep_for(std::chrono::seconds(10));
	std::cout << "Asking Thread to Stop" << std::endl;
	//Set the value in promise
	exitSignal.set_value();
	//Wait for thread to join
	th.join();
	std::cout << "Exiting Main Function" << std::endl;
	return 0;
}