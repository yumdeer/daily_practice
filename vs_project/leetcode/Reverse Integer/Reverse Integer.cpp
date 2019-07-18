#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		long long res = 0;
		while (x) {
			res = res * 10 + x % 10;
			x /= 10;
		}
		return (res<INT_MIN || res>INT_MAX) ? 0 : res;
	}
};

int main()
{
	Solution m_sol;
	int num = -123;
	cout << m_sol.reverse(num) << endl;

	return 0;

}
