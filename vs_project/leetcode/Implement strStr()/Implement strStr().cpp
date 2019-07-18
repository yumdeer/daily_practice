//判断一个字符是否是另一个字符一部分


#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.length(), n = needle.length();
		if (!n) {
			return 0;
		}
		for (int i = 0; i < m - n + 1; i++) {
			int j = 0;
			for (; j < n; j++) {
				if (haystack[i + j] != needle[j]) {
					break;
				}
			}
			if (j == n) {
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	Solution m_sol;
	string haystack = "hello";
	string needle = "ll";
	cout<< m_sol.strStr(haystack, needle) <<endl;

	return 0;
}