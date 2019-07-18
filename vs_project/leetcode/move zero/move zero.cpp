#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		int i, j;
		i = j = 0;
		while (i < n) {
			if (nums[i] != 0) {
				nums[j++] = nums[i];
			}
			++i;
		}
		while (j < n) {
			nums[j++] = 0;
		}
	}
};

//class Solution {
//public:
//	void moveZeroes(vector<int>& nums) {
//		int j = 0;
//		// move all the nonzero elements advance
//		for (int i = 0; i < nums.size(); i++) {
//			if (nums[i] != 0) {
//				nums[j++] = nums[i];
//			}
//		}
//		for (; j < nums.size(); j++) {
//			nums[j] = 0;
//		}
//	}
//};

//class Solution {
//public:
//	void moveZeroes(vector<int>& nums) {
//		int k = 0;
//		if (nums.size() == 1)
//			;
//		else
//		{
//			for (vector<int>::iterator it = nums.begin(); it != nums.end(); )
//			{
//				if (*it == 0)
//				{
//					nums.erase(it);
//					k++;
//					it = nums.begin();
//				}
//				else it++;
//			}
//			nums.insert(nums.end(), k, 0);
//		}
//	}
//};

int main()
{
	vector<int> m_Input_vector {2, 3, 0, 1, 0, 3, 1, 2 };
	Solution m_Input_Solution;
    m_Input_Solution.moveZeroes(m_Input_vector);
	for(int i : m_Input_vector)
		cout << i << " "; 

	return 0;
}