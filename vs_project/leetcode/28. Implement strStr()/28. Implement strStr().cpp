#include <iostream>
//#include <vector>
//#include <iterator>
//#include <algorithm>
using namespace std;

//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		int m = haystack.length(), n = needle.length();
//		if (!n) {
//			return 0;
//		}
//		for (int i = 0; i < m - n + 1; i++) {
//			int j = 0;
//			for (; j < n; j++) {
//				if (haystack[i + j] != needle[j]) {
//					break;
//				}
//			}
//			if (j == n) {
//				return i;
//			}
//		}
//		return -1;
//	}
//};

class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.length(), n = needle.length(), p = 0;
		while (true) {
			if (p + n > m + 1) {
				return -1;
			}
			if (haystack.substr(p, n) == needle) {
				return p;
			}
			while ((p++ < m - n + 1) && (haystack[p] != needle[0]));
		}
	}
};


int main()
{
	string haystack = "hello";
	string needle = "ll";
	Solution m_sol;
	cout<< m_sol.strStr(haystack, needle)<<endl;


	return 0;
}




//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		int m = haystack.length(), n = needle.length(), p = 0;
//		while (true) {
//			if (p + n > m + 1) {
//				return -1;
//			}
//			if (haystack.substr(p, n) == needle) {
//				return p;
//			}
//			while ((p++ < m - n + 1) && (haystack[p] != needle[0]));
//		}
//	}
//};

//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		int m = haystack.length(), n = needle.length();
//		if (!n) {
//			return 0;
//		}
//		vector<int> lps = kmpProcess(needle);
//		for (int i = 0, j = 0; i < m; ) {
//			if (haystack[i] == needle[j]) {
//				i++;
//				j++;
//			}
//			if (j == n) {
//				return i - j;
//			}
//			if ((i < m) && (haystack[i] != needle[j])) {
//				if (j) {
//					j = lps[j - 1];
//				}
//				else {
//					i++;
//				}
//			}
//		}
//		return -1;
//	}
//private:
//	vector<int> kmpProcess(string& needle) {
//		int n = needle.length();
//		vector<int> lps(n, 0);
//		for (int i = 1, len = 0; i < n; ) {
//			if (needle[i] == needle[len]) {
//				lps[i++] = ++len;
//			}
//			else if (len) {
//				len = lps[len - 1];
//			}
//			else {
//				lps[i++] = 0;
//			}
//		}
//		return lps;
//	}
//};