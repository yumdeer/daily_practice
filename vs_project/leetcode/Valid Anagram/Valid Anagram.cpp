//字符串组成相同


#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		int n = s.length();
		int counts[26] = { 0 };
		for (int i = 0; i < n; i++) {
			counts[s[i] - 'a']++;
			counts[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++)
			if (counts[i]) return false;
		return true;
	}
};

int main()
{
	Solution m_sol;
	string s = "zhang";
	string t = "hznag";
	cout << m_sol.isAnagram(s,t) <<endl;

	return 0;
}