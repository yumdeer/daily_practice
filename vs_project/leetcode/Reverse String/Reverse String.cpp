#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		int n = s.length();
		for (int i = 0; i <= n/2-1; ++i)
			swap(s[i], s[n-1-i]);
		return s;
	}
};

int main()
{
	Solution m_sol;
	string input = "A man, a plan, a canal : Panama";
	//m_sol.reverseString(input);
	cout << m_sol.reverseString(input)<< endl;

	return 0;
}

//static int fast_io = [](){ 
//	std::ios::sync_with_stdio(false); 
//	cin.tie(nullptr); return 0; 
//}();
//
//
//class Solution {
//public:
//	void reverseString(vector<char>& s) {
//		int a = 0;
//		int b = s.size() - 1;
//		while (a < b)
//			swap(s[a++], s[b--]);
//	}
//};