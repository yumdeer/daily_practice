#include <iostream>
#include <vector>
#include <unordered_map>
//#include <allocators>
#include <algorithm>
#include <iterator>
using namespace std;

//最常规的方法：先排序，然后循环比较
//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		sort(nums1.begin(), nums1.end());
//		sort(nums2.begin(), nums2.end());
//		int n1 = (int)nums1.size(), n2 = (int)nums2.size();
//		int i1 = 0, i2 = 0;
//		vector<int> res;
//		while (i1 < n1 && i2 < n2) {
//			if (nums1[i1] == nums2[i2]) {
//				res.push_back(nums1[i1]);
//				i1++;
//				i2++;
//			}
//			else if (nums1[i1] > nums2[i2]) {
//				i2++;
//			}
//			else {
//				i1++;
//			}
//		}
//		return res;
//	}
//};

//自己的尝试：想要利用一个中间数组，判断有多少相同的数（数组对应下标元素），例如i=2,a[2]++，则可以知道有几个元素等于2。
//失败了，因为同一个向量里面也有相同元素。o(╥﹏╥)o
//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		int arr_[1000];
//		for (int i = 0; i < nums1.size(); i++)
//			arr_[i] = 0;
//		for (int i = 0; i < nums1.size(); i++)
//		{
//			arr_[nums1[i]]++;
//		}
//		for (int i = 0; i < nums2.size(); i++)
//		{
//			arr_[nums2[i]]++;
//		}
//		int num_arr = 0;
//		for (int i = 0; i < nums1.size(); i++)
//		{
//			if (arr_[i] == 2)
//				num_arr++;
//		}
//
//		vector<int> arr_copy;
//		for (int i = 0; i < (nums1.size() > nums2.size() ? nums1.size() : nums2.size()); i++)
//		{
//			if (arr_[i] == 2)
//				arr_copy.push_back(i);
//		}
//
//		return arr_copy;
//
//	}
//};


//利用set_intersection（）函数求排序范围交叉点，然后去重
//class Solution {
//public:
//	vector<int> intersect(vector<int>& a, vector<int>& b) {
//		sort(a.begin(), a.end());
//		sort(b.begin(), b.end());
//		std::vector<int>::iterator it = set_intersection( a.begin(), a.end(), b.begin(), b.end(), a.begin() );
//		//能进行算术运算的迭代器只有随即访问迭代器，要求容器元素存储在连续内存空间里，vector，string，deque的迭代器是有加减法的，但是map，set，multimap,multiset的迭代器是没有加减法的，list也不可以 
//		//该知识点是在刷leetcode347题时想到的
//		int num = it - a.begin();
//		a.resize(num);
//		//a.resize(it - a.begin()); 
//		//a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
//		return a;
//	}
//};

//利用无序映射，键值通常用于唯一标识元素
//class Solution {
//public:
//	vector<int> intersect(vector<int>& a, vector<int>& b) {
//		unordered_map<int, int> ctr;
//		for (int i : a)
//			ctr[i]++;
//		vector<int> out;
//		for (int i : b)
//			if (ctr[i]-- > 0)
//				out.push_back(i);
//		return out;
//	}
//};

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> dict;
		vector<int> res;
		for (int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
		for (int i = 0; i < (int)nums2.size(); i++)
			if (--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
		return res;
	}
};



int main()
{
	vector<int> nums1{ 4,9,5};
	vector<int> nums2{ 9,4,9,8,4};
	Solution sol;
	
	
	for (auto i : sol.intersect(nums1, nums2))
		cout << i << " ";
	cout << endl;

	return 0;
}






//#include <iostream>     // std::cout
//#include <algorithm>    // std::set_intersection, std::sort
//#include <vector>       // std::vector
//
//int main() {
//	int first[] = { 5,10,15,20,25 };
//	int second[] = { 50,40,30,20,10 };
//	std::vector<int> v(10);                      // 0  0  0  0  0  0  0  0  0  0
//	std::vector<int>::iterator it;
//
//	std::sort(first, first + 5);     //  5 10 15 20 25
//	std::sort(second, second + 5);   // 10 20 30 40 50
//
//	it = std::set_intersection(first, first + 5, second, second + 5, v.begin());
//	// 10 20 0  0  0  0  0  0  0  0
//	std::cout << &v[1]<<" "<< &v[2]<<std::endl;
//	v.resize(it - v.begin());                      // 10 20
//
//	std::cout << "The intersection has " << (v.size()) << " elements:\n";
//	for (it = v.begin(); it != v.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	return 0;
//}