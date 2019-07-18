//给定一个字符串，找到它中的第一个非重复字符并返回它的索引。 如果它不存在，则返回-1。



#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <string>
#include <array>
using namespace std;
 
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		int num = s.length();
//		int arr[26] = { 0 };
//		for (int i = 0; i < num; i++)
//		{
//			arr[s[i] - 'a']++;
//		}
//		for (int i = 0; i < num; i++)
//		{
//			if (arr[s[i] - 'a'] == 1)
//				return i;
//		}
//		return -1;
//		
//	}
//};

//class Solution {
//public:
//	int firstUniqChar(string s) {
//		/*直接将字符的ascii码作为下标*/
//		unordered_map<char, int> m;
//		for (auto &c : s) {
//			m[c]++;
//		}
//		for (int i = 0; i < s.size(); i++) {
//			if (m[s[i]] == 1) return i;
//		}
//		return -1;
//	}
//};

class Solution {
public:
	int firstUniqChar(string s) {
		const auto size = s.size();
		switch (size) {
		case 0:
			return -1;
		case 1:
			return 0;
		default:
			auto letter_frequencies = array<size_t, 128>();
			for (auto i = string::size_type(0); i < size; i++) {
				letter_frequencies[s[i]]++;
			}
			for (auto i = string::size_type(0); i < size; i++) {
				if (letter_frequencies[s[i]] == 1) {
					return i;
				}
			}
			return -1;
		}
	}
};


int main()
{
	Solution m_sol;
	string s = "loveleetcode";
	cout<<m_sol.firstUniqChar(s)<<endl;

	return 0;

}


