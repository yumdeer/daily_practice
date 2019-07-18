//#include<cstdlib>
//#include<chrono>
//#include<iostream>
//#include<thread>
//#include<vector>
//#include <algorithm>
//
////void SleepSort(const int i)
////{
////	std::this_thread::sleep_for(std::chrono::milliseconds(i));
////	std::cout << i << " ";
////}
//
//void SleepSort(const int i, const int offset)
//{
//	std::this_thread::sleep_for(std::chrono::milliseconds(i + offset));
//	std::cout << i << " ";
//}
//
//int main()
//{
//	std::cout << "Sorted array is:\n";
//	std::vector<std::thread> threads;
//	std::vector<int> num;
//	int x;
//	while (std::cin >> x )
//		num.push_back(x);
//	//for (int i = 0; i < num.size(); ++i)
//	//	threads.push_back(std::thread(SleepSort, num[i]));
//
//	//添加负值排序
//	std::vector<int> data;
//	data.reserve(num.size() - 1);
//	for (int i = 0; i < num.size(); ++i)
//		data.push_back(num[i]);
//	const int minElem = std::abs(*std::min_element(data.begin(), data.end())); //min_element寻找范围 [first, last) 中的最小元素。
//	for (int i = 0; i < num.size(); ++i)
//		threads.push_back(std::thread(SleepSort, num[i], minElem));
//
//	for (auto& thread : threads)
//		thread.join();
//
//	return 0;
//}
//
//
