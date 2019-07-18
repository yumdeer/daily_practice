#include "iostream"
#include "vector"
#include "string"

using namespace std;


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix = "";
		for (int idx = 0; strs.size() > 0; prefix += strs[0][idx], idx++)
			for (int i = 0; i < strs.size(); i++)
				if (idx >= strs[i].size() || (i > 0 && strs[i][idx] != strs[i - 1][idx]))
					return prefix;
		return prefix;
	}
};

int main()
{
	string fin[3] = { "flower" ,"flow","flight" };
	vector<string> bin(fin,fin+3);
	//vector<string> fin(3);
	//fin[0] = "flower";
	//fin[1] = "flow";
	//fin[2] = "flight";

	Solution Longest;
	string n = Longest.longestCommonPrefix(bin);
	//string n = Longest.longestCommonPrefix(fin);
	cout << n <<endl;

	return 0;
}