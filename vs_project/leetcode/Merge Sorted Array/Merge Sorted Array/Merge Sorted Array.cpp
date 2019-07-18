#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

 class Solution {
 public:
 	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
 		int numm1 = 0, numm2 = 0;
 		while (n--) {
 			if (nums1[numm1] <= nums2[numm2])
 				numm1++;
 			else {
                 swap(nums1[numm1++], nums2[numm2]);
             }
 		}
		sort(nums2.begin(),nums2.end());
          for(int i=nums2.size(),j=0;i<nums1.size(); ){
             nums1[i++]=nums2[j++];
         }
 	}
 };

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(string input) {
	return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums1 = stringToIntegerVector(line);
		getline(cin, line);
		int m = stringToInteger(line);
		getline(cin, line);
		vector<int> nums2 = stringToIntegerVector(line);
		getline(cin, line);
		int n = stringToInteger(line);

		Solution().merge(nums1, m, nums2, n);

		string out = integerVectorToString(nums1);
		cout << out << endl;
	}
	return 0;
}

//int main() {
//	int num1[3] = { 1, 2, 3 };
//	int num2[3] = { 2, 3, 4 };
//	swap(num1[0], num2[0]);
//	cout << num1[0] << " " << num2[0];
//
//	return 0;
//}