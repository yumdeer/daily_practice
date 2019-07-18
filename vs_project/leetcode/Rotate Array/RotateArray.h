#include <vector>


class Solution {
public:
	void rotate(std::vector<int>& v, int k) {                               //向左旋转范围内的元素，
		std::rotate(v.rbegin(), v.rbegin() + k % v.size(), v.rend());  //旋转范围中元素的顺序，使中间[first,last)指向的元素v.rbegin() + k % v.size()成为新的第一个元素。
	}
};