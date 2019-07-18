#include <iostream>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {} //c++写法，构造函数，“:”后面是构造函数的参数列表，用于对成员变量初始化。
 };
 ListNode *head = NULL;

 void Insert(ListNode *node, int position) {		  //position表示要插入的位置
	 if (position == 0) {							  //插入的是第0个位置,为了方便，我们暂且规定头结点为第0个节点
													  //那么如果插入的是第0个位置的话,说明插入的节点要成为新的头结点
													  //而不管之前有没有头结点
		 node->next = head;
		 head = node;								  //完成头结点的更新,表示头结点现在是node节点
		 return;

	 }
	 ListNode *current_node = head;					   //从头结点开始遍历插入的位置
	 int i = 0;										   //表示已经遍历过的节点数目
	 while (current_node->next != NULL && i < position - 1) {
													   //不断寻找要插入的位置的前一个位置,然后插入在这个位置的节点与下一个位置的节点之间
		 current_node = current_node->next;            //不断更新current_node的值
		 i++;
	 }
	 if (i == position - 1) {							//找到了插入的位置，先更新插入节点的指针域,记录当前遍历到的位置的下一个节点
														//然后再接上前面的节点

		 node->next = current_node->next;
		 current_node->next = node;
	 }
 }

 void Output() {
	 ListNode *current_node = head;     //从头结点开始遍历
	 while (current_node != NULL) {
		 cout << current_node->val << " ";
		 current_node = current_node->next;
	 }
	 cout << endl;
 }

 class Solution
 {
 public:
	 ListNode* removeNthFromEnd(ListNode* head, int n)
	 {
		 ListNode** t1 = &head, *t2 = head;
		 for (int i = 1; i < n; ++i)
		 {
			 t2 = t2->next;
		 }
		 while (t2->next != NULL)
		 {
			 t1 = &((*t1)->next);
			 t2 = t2->next;
		 }
		 *t1 = (*t1)->next;
		 return head;
	 }
 };

 //class Solution {
 //public:
	// ListNode* removeNthFromEnd(ListNode* head, int n) {
	//	 auto node = head;
	//	 while (n--)
	//	 {
	//		 node = node->next;
	//	 }
	//	 if (node->next != NULL)
	//		 node->next = node->next->next;
	//	 else
	//		 node->next = NULL;

	//	 return head;
	// }
 //};

int main()
{
	ListNode* Node;
	int num[5] = {1,2,3,4,5};
	for (int i = 1; i <= 5; i++) {
		ListNode *node = new ListNode(num[i-1]);		 //用new给链表的每一个节点开辟空间
		  Insert(node, i - 1);							//调用成员函数
	}
	Solution Sol;
	//cout << head->val <<" "<< head->next->val<<" "<< head->next->next->val << endl;
	Sol.removeNthFromEnd(head,2);
	Output();

	return 0;
}