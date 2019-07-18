//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <string>
//
//int* bogobogosort(int* toSort, int size);
//
///*
// * Taken from http://benpfaff.org/writings/clc/shuffle.html
// *
// * Copyright © 2004 Ben Pfaff
// */
//
//void shuffle(int *array, size_t n) {
//	if (n > 1) {
//		size_t i;
//		for (i = 0; i < n - 1; i++) {
//			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
//			int t = array[j];
//			array[j] = array[i];
//			array[i] = t;
//		}
//	}
//}
//
//int* bogobogosort_rec(int *toSort, int size) {
//	int* copy = (int*)malloc(size * sizeof(int));
//	memcpy(copy, toSort, size * sizeof(int));
//	int i;
//	if (size > 1) {
//		int* ret = bogobogosort_rec(copy, size - 1);
//		memcpy(copy, ret, (size - 1) * sizeof(int));
//		if (copy[size - 2] > copy[size - 1]) {
//			shuffle(copy, size);
//			ret = bogobogosort_rec(copy, size);
//			memcpy(copy, ret, size * sizeof(int));
//		}
//	}
//	for (i = 0; i < size; i++) {
//		if (toSort[i] == copy[i]) continue;
//	}
//	return copy;
//}
//
//int* bogobogosort(int* toSort, int size) {
//	int i;
//	int *result = (int*)malloc(size * sizeof(int));
//	int *tmp = bogobogosort_rec(toSort, size);
//	memcpy(result, tmp, size * sizeof(int));
//	for (i = 0; i < size; i++) {
//		if (result[i] == tmp[i]) continue;
//	}
//	return result;
//}
//
//int main() {
//	int num[6] = { 0,5,2,1,8,10 };
//	int size = 6;
//	int *newnum = new int[size];
//	newnum = bogobogosort(num, size);
//	for (int x=0;x< size;x++)
//		std::cout << newnum[x] << " ";
//	std::cout << std::endl;
//
//	return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <random>
//#include <cstdint>
//#include <chrono>
//
//#define BYTE_SIZE 8
//
//using namespace std;
//
//template < typename InputIterator >
//constexpr bool isSorted(InputIterator begin, InputIterator end)
//{
//	return (begin + 1 == end) ? true :
//		(*begin <= *(begin + 1)) ? isSorted(begin + 1, end) :
//		false;
//}
//
//template < typename InputIterator >
//constexpr size_t count(InputIterator begin, InputIterator end,
//	typename InputIterator::value_type val)
//{
//	return (begin == end) ? 0 :
//		((*begin == val) ? 1 : 0) + count(begin + 1, end, val);
//
//}
//
//template < typename InputIterator >
//bool containsSame(InputIterator begin_a, InputIterator end_a,
//	InputIterator begin_b, InputIterator end_b)
//{
//	size_t count_a, count_b;
//
//	for (InputIterator it = begin_a; it != end_a; ++it)
//	{
//		count_a = count(begin_a, end_a, *it);
//		count_b = count(begin_b, end_b, *it);
//		if (count_a != count_b)
//			return false;
//	}
//
//	return true;
//}
//
//template < typename InputIterator >
//void bogobogosort(InputIterator begin, InputIterator end)
//{
//	const unsigned SEED = std::chrono::system_clock::now().time_since_epoch().count();
//	const size_t ELEMENT_SIZE = BYTE_SIZE * sizeof(*begin);
//	const size_t BIT_LENGTH = ELEMENT_SIZE * (end - begin);
//
//	default_random_engine generator(SEED);
//	uniform_int_distribution< size_t > distribution(0, BIT_LENGTH - 1);
//
//	size_t pos, index, bit;
//	uintmax_t mask;
//
//	vector< typename InputIterator::value_type > original(begin, end);
//
//	do
//	{
//		pos = distribution(generator);
//		index = pos / ELEMENT_SIZE;
//		bit = pos % ELEMENT_SIZE;
//		mask = 1 << bit;
//		begin[index] ^= mask;
//	} while (!isSorted(begin, end) or
//		!containsSame(begin, end, original.begin(), original.end()));
//}
//
//int main(int argc, char* argv[])
//{
//	unsigned seed =std::chrono::system_clock::now().time_since_epoch().count();
//	default_random_engine generator(seed);
//	uniform_int_distribution< char > distribution('a', 'z');
//
//	std::vector< char > vec;
//	size_t n;
//
//	if (argc > 1)
//		n = atoi(argv[1]);
//
//	if (!n)
//		return 0;
//
//	for (size_t i = 0; i < n; i++)
//		vec.push_back(distribution(generator));
//
//	for (char c : vec)
//		cout << c << ' ';
//	cout << endl;
//
//	bogobogosort(vec.begin(), vec.end());
//
//	for (char c : vec)
//		cout << c << ' ';
//	cout << endl;
//
//	return 0;
//}

