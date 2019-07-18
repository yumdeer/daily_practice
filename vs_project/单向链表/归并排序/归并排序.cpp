#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <fstream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	inline void insertBack(ListNode** head, ListNode** tail, ListNode* n) //从尾部插入
	{
		if (n)
		{
			if (*head == NULL)
			{
				*head = n;
				*tail = n;
			}
			else
			{
				(*tail)->next = n;
				*tail = n;
			}
		}
	}

	ListNode *sortList(ListNode *head) {
		if (!head) return NULL;
		if (head->next == NULL) return head;
		//划分
		ListNode *tmpNode = head;
		head = head->next;
		ListNode *sleft = NULL, *eleft = NULL;
		ListNode *sright = NULL, *eright = NULL;
		while (head)
		{
			ListNode *insNode = head;
			head = head->next;

			insNode->next = NULL;
			if (insNode->val > tmpNode->val)
				insertBack(&sright, &eright, insNode);
			else
				insertBack(&sleft, &eleft, insNode);
		}

		//递归调用	
		sleft = sortList(sleft);
		sright = sortList(sright);

		//下面三句话第一次没有加上，调试了一下午才找到原因
		eleft = sleft;
		if (eleft)
		{
			while (eleft->next)
				eleft = eleft->next;
		}

		//拼接起来
		if (eleft)
		{
			head = sleft;
			eleft->next = tmpNode;
		}
		else
			head = tmpNode;
		tmpNode->next = sright; //连接起来

		//返回结果
		return head;
	}
};

int main(int argc, char** argv)
{
	ifstream in("data.txt");
	ListNode* head = NULL;
	ListNode* tail = NULL;
	int val;

	Solution s;
	while (in >> val)
	{
		ListNode*tmp = new ListNode(val);
		s.insertBack(&head, &tail, tmp);
	}
	head = s.sortList(head);
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}