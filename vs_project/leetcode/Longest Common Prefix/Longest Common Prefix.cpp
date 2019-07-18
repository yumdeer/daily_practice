#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;


//class Solution {
//public:
//	string longestCommonPrefix(vector<string>& strs) {
//
//	}
//};

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		if (n == 0) {
			return "";
		}
		string res = "";
		sort(strs.begin(), strs.end());// sort the array
		string first = strs[0]; // first word
		string last = strs[n - 1];// last word
		int limit = std::min(first.length(), last.length());
		for (int i = 0; i < limit; i++) {// find out the longest common prefix between first and last word
			if (first[i] == last[i]) {
				res += first[i];
			}
			else {
				break;
			}
		}
		return res;
	}
};

int main()
{
	Solution sol;
	vector<string> strs = { "flower","flow","flight","flgine","anbs" };
	cout << sol.longestCommonPrefix(strs) << endl;

	return 0;
}