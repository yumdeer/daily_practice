#include<iostream>
#include<set>
#include<vector>
#include <iterator>
using namespace std;


//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		int a = nums.size();
//		int arr[a];
//		int judg = 0;
//			for (int i = 0; i != nums.size(); i++)
//				arr[i] = 0;
//		for (int i = 0; i != nums.size(); i++)
//		{
//			arr[nums[i]]++;
//			if (arr[i] > 1)
//			{
//				judg++;
//					break;
//			}
//		}
//
//		if (judg > 0)
//			return true;
//		else return false;
//	}
//};

//
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		return nums.size() > set<int>(nums.begin(), nums.end()).size();
	}
};

int main()
{
	
	vector<int> vec{ 1,2,3,1 };
	set<int> mySet (vec.begin(),vec.end());

	//auto a = mySet.end();
	//auto b = vec.end();

	//cout << a << endl;

	return 0;
}