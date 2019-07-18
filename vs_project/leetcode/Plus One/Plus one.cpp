#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
//#include <allocators>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {

		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				return digits;
			}
		}
		digits[0] = 1;
		digits.push_back(0);
		return digits;
	}
};

int main()
{
	vector<int>  vec{1,2,9};
	Solution sol_;
	sol_.plusOne( vec );

	for (int i : vec)
		cout << i << endl;

	return 0;
}