#include <iostream>
#include <utility>  // std::swap
#include <omp.h>
#include <string.h> // memcpy

//// dynamic code, 普通函数版本
//void bubbleSort(int* data, int n)
//{
//	for (int i = n - 1; i > 0; --i) {
//		for (int j = 0; j < i; ++j)
//			if (data[j] > data[j + 1]) std::swap(data[j], data[j + 1]);
//	}
//}
//// 数据长度为 4 时，手动循环展开
//inline void bubbleSort4(int* data)
//{
//#define COMP_SWAP(i, j) if(data[i]>data[j]) std::swap(data[i], data[j])
//	COMP_SWAP(0, 1); COMP_SWAP(1, 2); COMP_SWAP(2, 3);
//	COMP_SWAP(0, 1); COMP_SWAP(1, 2);
//	COMP_SWAP(0, 1);
//}
//
//// 递归函数版本，指导模板思路，最后一个参数是哑参数（dummy parameter），仅为分辨重载函数
//class recursion { };
//void bubbleSort(int* data, int n, recursion)
//{
//	if (n <= 1) return;
//	for (int j = 0; j < n - 1; ++j) if (data[j] > data[j + 1]) std::swap(data[j], data[j + 1]);
//	bubbleSort(data, n - 1, recursion());
//}
//
//// static code, 模板元编程版本
//template<int i, int j>
//inline void IntSwap(int* data) { // 比较和交换两个相邻元素
//	if (data[i] > data[j]) std::swap(data[i], data[j]);
//}
//
//template<int i, int j>
//inline void IntBubbleSortLoop(int* data) { // 一次冒泡，将前 i 个元素中最大的置换到最后
//	IntSwap<j, j + 1>(data);
//	IntBubbleSortLoop < j < i - 1 ? i : 0, j<i - 1 ? (j + 1) : 0>(data);
//}
//template<>
//inline void IntBubbleSortLoop<0, 0>(int*) { }
//
//template<int n>
//inline void IntBubbleSort(int* data) { // 模板冒泡排序循环展开
//	IntBubbleSortLoop<n - 1, 0>(data);
//	IntBubbleSort<n - 1>(data);
//}
//template<>
//inline void IntBubbleSort<1>(int* data) { }


//int main() {
//	double t1, t2, t3;
//	const int num = 100000000;
//	int data[4]; 
//	int inidata[4] = { 3,4,2,1 };
//	t1 = omp_get_wtime();
//	for (int i = 0; i < num; ++i) {
//		memcpy(data, inidata, 4);
//		bubbleSort(data, 4); 
//	}
//	t1 = omp_get_wtime() - t1;
//	t2 = omp_get_wtime();
//
//	for (int i = 0; i < num; ++i) {
//		memcpy(data, inidata, 4); bubbleSort4(data); 
//	}
//	t2 = omp_get_wtime() - t2;
//	t3 = omp_get_wtime();
//
//	for (int i = 0; i < num; ++i) { 
//		memcpy(data, inidata, 4); IntBubbleSort<4>(data);
//	}
//	t3 = omp_get_wtime() - t3;
//	std::cout << t1 / t3 << '\t' << t2 / t3 << '\n';
//	
//	std::cin.get(); 
//	return 0;
//}


/*     */
//// 整合成一个类模板实现，看着好，但引入了 代码膨胀
//template<int n>
//class IntBubbleSortC {
//	template<int i, int j>
//	static inline void IntSwap(int* data) { // 比较和交换两个相邻元素
//		if (data[i] > data[j]) 
//			std::swap(data[i], data[j]);
//	}
//	template<int i, int j>
//	static inline void IntBubbleSortLoop(int* data) { // 一次冒泡
//		IntSwap<j, j + 1>(data);
//		IntBubbleSortLoop < j < i - 1 ? i : 0, j<i - 1 ? (j + 1) : 0>(data);
//	}
//	template<>
//	static inline void IntBubbleSortLoop<0, 0>(int*) { }
//public:
//	static inline void sort(int* data) {
//		IntBubbleSortLoop<n - 1, 0>(data);
//		IntBubbleSortC<n - 1>::sort(data);
//	}
//};
//template<>
//class IntBubbleSortC<0> {
//public:
//	static inline void sort(int* data) { }
//};
//
//int main() {
//	int data[4] = { 3,4,2,1 };
//	IntBubbleSortC<4>::sort(data); // 如此调用
//	for (int i : data)
//		std::cout << i << " ";
//
//	std::cin.get(); 
//	return 0;
//}

/*     */
//#include <iostream>
//#include <utility>  // std::swap
//
//// 整合成一个类模板实现，看着好，但引入了 代码膨胀
//template<int n>
//class IntBubbleSortC {
//	template<int i, int j> static void IntSwap(int* data);
//	template<int i, int j> static void IntBubbleSortLoop(int* data);
//	template<> static void IntBubbleSortLoop<0, 0>(int*) { }
//public:
//	static void sort(int* data);
//};
//template<>
//class IntBubbleSortC<0> {
//public:
//	static void sort(int* data) { }
//};
//
//template<int n> template<int i, int j>
//void IntBubbleSortC<n>::IntSwap(int* data) {
//	if (data[i] > data[j]) std::swap(data[i], data[j]);
//}
//template<int n> template<int i, int j>
//void IntBubbleSortC<n>::IntBubbleSortLoop(int* data) {
//	IntSwap<j, j + 1>(data);
//	IntBubbleSortLoop < j < i - 1 ? i : 0, j<i - 1 ? (j + 1) : 0>(data);
//}
//template<int n>
//void IntBubbleSortC<n>::sort(int* data) {
//	IntBubbleSortLoop<n - 1, 0>(data);
//	IntBubbleSortC<n - 1>::sort(data);
//}
//
//int main() {
//	int data[40] = { 3,4,2,1 };
//	IntBubbleSortC<2>::sort(data);  IntBubbleSortC<3>::sort(data);
//	IntBubbleSortC<4>::sort(data);  IntBubbleSortC<5>::sort(data);
//	IntBubbleSortC<6>::sort(data);  IntBubbleSortC<7>::sort(data);
//	IntBubbleSortC<8>::sort(data);  IntBubbleSortC<9>::sort(data);
//	IntBubbleSortC<10>::sort(data); IntBubbleSortC<11>::sort(data);
//#if 0
//	IntBubbleSortC<12>::sort(data); IntBubbleSortC<13>::sort(data);
//	IntBubbleSortC<14>::sort(data); IntBubbleSortC<15>::sort(data);
//	IntBubbleSortC<16>::sort(data); IntBubbleSortC<17>::sort(data);
//	IntBubbleSortC<18>::sort(data); IntBubbleSortC<19>::sort(data);
//	IntBubbleSortC<20>::sort(data); IntBubbleSortC<21>::sort(data);
//
//	IntBubbleSortC<22>::sort(data); IntBubbleSortC<23>::sort(data);
//	IntBubbleSortC<24>::sort(data); IntBubbleSortC<25>::sort(data);
//	IntBubbleSortC<26>::sort(data); IntBubbleSortC<27>::sort(data);
//	IntBubbleSortC<28>::sort(data); IntBubbleSortC<29>::sort(data);
//	IntBubbleSortC<30>::sort(data); IntBubbleSortC<31>::sort(data);
//#endif
//
//	std::cin.get(); 
//	return 0;
//}

/*    */
#include <iostream>
#include <utility>  // std::swap

// static code, 模板元编程版本
template<int i, int j>
class IntSwap {
public: 
	static void swap(int* data);
};

template<int i, int j>
class IntBubbleSortLoop {
public: 
	static void loop(int* data);
};
template<>
class IntBubbleSortLoop<0, 0> {
public:
	static void loop(int* data) { }
};

template<int n>
class IntBubbleSort {
public: 
	static void sort(int* data);
};
template<>
class IntBubbleSort<0> {
public: 
	static void sort(int* data) { }
};

template<int i, int j>
void IntSwap<i, j>::swap(int* data) {
	if (data[i] > data[j]) 
		std::swap(data[i], data[j]);
}
template<int i, int j>
void IntBubbleSortLoop<i, j>::loop(int* data) {
	IntSwap<j, j + 1>::swap(data);
	IntBubbleSortLoop < j < i - 1 ? i : 0, j<i - 1 ? (j + 1) : 0>::loop(data);
}
template<int n>
void IntBubbleSort<n>::sort(int* data) {
	IntBubbleSortLoop<n - 1, 0>::loop(data);
	IntBubbleSort<n - 1>::sort(data);
}

int main() {
	int data[40] = { 3,4,2,1 };
	IntBubbleSort<2>::sort(data);  IntBubbleSort<3>::sort(data);
	IntBubbleSort<4>::sort(data);  IntBubbleSort<5>::sort(data);
	IntBubbleSort<6>::sort(data);  IntBubbleSort<7>::sort(data);
	IntBubbleSort<8>::sort(data);  IntBubbleSort<9>::sort(data);
	IntBubbleSort<10>::sort(data); IntBubbleSort<11>::sort(data);
#if 0
	IntBubbleSort<12>::sort(data); IntBubbleSort<13>::sort(data);
	IntBubbleSort<14>::sort(data); IntBubbleSort<15>::sort(data);
	IntBubbleSort<16>::sort(data); IntBubbleSort<17>::sort(data);
	IntBubbleSort<18>::sort(data); IntBubbleSort<19>::sort(data);
	IntBubbleSort<20>::sort(data); IntBubbleSort<21>::sort(data);

	IntBubbleSort<22>::sort(data); IntBubbleSort<23>::sort(data);
	IntBubbleSort<24>::sort(data); IntBubbleSort<25>::sort(data);
	IntBubbleSort<26>::sort(data); IntBubbleSort<27>::sort(data);
	IntBubbleSort<28>::sort(data); IntBubbleSort<29>::sort(data);
	IntBubbleSort<30>::sort(data); IntBubbleSort<31>::sort(data);
#endif

	std::cin.get(); 
	return 0;
}