#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		unordered_map<int, int> hash;
//		vector<int> result;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			int numberToFind = target - nums[i];
//
//			//if numberToFind is found in map, return them
//			if (hash.find(numberToFind) != hash.end())
//			{
//				//+1 because indices are NOT zero based
//				result.push_back(hash[numberToFind] );
//				result.push_back(i);
//				return result;
//			}
//
//			//number was not found. Put it in the map.
//			hash[nums[i]] = i;
//		}
//		return result;
//	}
//};

//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		unordered_map<int, int> map;
//		int n = (int)nums.size();
//		for (int i = 0; i < n; i++) {
//			auto p = map.find(target - nums[i]);
//			if (p != map.end()) {
//				return { p->second , i };
//			}
//			map[nums[i]] = i;
//		}
//	}
//};

//best answer
static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();
class Solution
{
public:
	/* 性能低下，现在换种新思路
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int r1 = -1, r2 = -1;
		for(int i = 0; i<nums.size()-1; ++i)
		{
			for(int j = i+1; j<nums.size(); ++j)
			{
				if(nums[i]+nums[j] == target)
				{
					r1 = i; r2 = j;
					return vector<int>{r1, r2};
				}
			}
		}

		return vector<int>{r1, r2};
	}
	*/

	// 新思路，两根指针分别指向vector首部以及尾部
	// 左侧指针向右移，右侧指针向左移
	// 两指针指向的内存数据相加与target比较
	// 左侧指针只在相加结果<target时右移，
	// 右侧指针只在相加结果>target时左移。
	// 左侧指针与右侧指针相遇时结束。
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> ret;
		// 对nums排序并保存下标
		std::vector< std::pair<int, int> > nums_;

		int nums_size = nums.size();
		for (int i = 0; i < nums_size; ++i)
		{ 
			nums_.push_back(make_pair(nums[i], i)); 
		}
		std::sort(nums_.begin(), nums_.end());

		// 下标声明
		int l = 0, r = nums_.size() - 1;
		while (l < r)
		{
			if (nums_[l].first + nums_[r].first == target)
			{
				ret.push_back(nums_[l].second);
				ret.push_back(nums_[r].second);
				break;
			}
			else if (nums_[l].first + nums_[r].first > target)
			{
				r--;
			}
			else l++;
		}

		return ret;
	}
};

int main()
{
	//int arr[100] = {0};
	//cout << arr[0] << " " << arr[1]<<" "<<arr[100];
	Solution m_sol;
	vector<int> nums{ 2,7,11,15 };
	vector<int> m_return;
	m_return=m_sol.twoSum(nums , 13);
	for (auto i : m_return)
		cout << i << " ";

	return 0;
}

