//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <sstream>  //stringstream字符串流类型转换
//using namespace std;
//
///**
// * Definition for singly-linked list.
// **/
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//		ListNode dummy(INT_MIN);
//		ListNode *tail = &dummy;
//
//		while (l1 && l2) {
//			if (l1->val < l2->val) {
//				tail->next = l1;
//				l1 = l1->next;
//			}
//			else {
//				tail->next = l2;
//				l2 = l2->next;
//			}
//			tail = tail->next;
//		}
//
//		tail->next = l1 ? l1 : l2;
//		return dummy.next;
//	}
//};
//
//void trimLeftTrailingSpaces(string &input) {							//从左边开始删除多余空格
//	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) { //返回区间[first,end)中第一个值等于空格的元素的位置
//		return !isspace(ch);									//isspace()判断一个字符是否是空白符
//	}));
//}
//
//void trimRightTrailingSpaces(string &input) {							//从右边开始删除多余空格
//	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//		return !isspace(ch);
//	}).base(), input.end());
//}
//
//vector<int> stringToIntegerVector(string input) {		//字符串到整数向量
//	vector<int> output;
//	trimLeftTrailingSpaces(input);
//	trimRightTrailingSpaces(input);
//	input = input.substr(1, input.length() - 2);		//截取从1到length() - 2的字符串，去除输入的"[]"和"\n"
//	stringstream ss;
//	ss.str(input);
//	string item;
//	char delim = ',';
//	while (getline(ss, item, delim)) {
//		output.push_back(stoi(item));					//将字符串转换为整数
//	}
//	return output;
//}
//
//ListNode* stringToListNode(string input) {				//字符串到链表节点
//	// Generate list from the input
//	vector<int> list = stringToIntegerVector(input);
//
//	// Now convert that list into linked list
//	ListNode* dummyRoot = new ListNode(0);              //设置头节点
//	ListNode* ptr = dummyRoot;
//	for (int item : list) {
//		ptr->next = new ListNode(item);
//		ptr = ptr->next;
//	}
//	ptr = dummyRoot->next;
//	delete dummyRoot;
//	return ptr;
//}
//
//string listNodeToString(ListNode* node) {			//链表节点到字符串
//	if (node == nullptr) {
//		return "[]";
//	}
//
//	string result;
//	while (node) {
//		result += to_string(node->val) + ", ";		 //将数值转化为字符串。返回对应的字符串。
//		node = node->next;
//	}
//	return "[" + result.substr(0, result.length() - 2) + "]";
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		ListNode* l1 = stringToListNode(line);
//		getline(cin, line);
//		ListNode* l2 = stringToListNode(line);
//
//		ListNode* ret = Solution().mergeTwoLists(l1, l2);
//
//		string out = listNodeToString(ret);
//		cout << out << endl;
//	}
//	return 0;
//}
