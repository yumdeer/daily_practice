//#include <iostream>
//#include "stdlib.h"
//class   ObjectB{
//public:
//	int a;
//public:
//	ObjectB(int m=0)
//	{
//		a=m;
//	}
//};
//class   ObjectA{ 
//public:
//	ObjectB   Array[5]; 
//public: 
//	ObjectA(int   *p)
//	{
//		Array[0]=ObjectB(p[0]);
//		Array[1]=ObjectB(p[1]);
//		Array[2]=ObjectB(p[2]);
//	} 
//};
//
//int main()
//{
//	int p[5]={0,2,2,3,4};
//	ObjectA am=ObjectA(p);
//	std::cout<<am.Array[1].a<<std::endl;
//	return 0;
//}

#include <iostream>
using namespace std;
//int main()
//{
//	int a = 2 ;
//	if(a--==2)
//		cout << a <<endl;
//	return 0;
//}
//// C++ code to compute MIN element 
//#include <bits/stdc++.h> 

// Function to compute minimum element in array 
int compute_min(int arr[], int n) 
{ 
	// Assigning highest value 
	int MIN = INT_MAX; //+2147483647

	// Traversing and updating MIN 
	for (int i = 0; i < n; i++)  
		MIN = std::min(MIN, arr[i]);     

	// Printing MIN element 
	return  MIN; 
} 

// Driver code 
int main() 
{ 
	// array with MIN to compute 
	int arr[] = { 2249403813, 2147389580, 2145837140, 2108938594, 2112076334 }; 

	// size of array 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Function call to compute MIN 
	compute_min(arr, n); 
} 