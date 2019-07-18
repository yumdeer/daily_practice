#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//节点结构
struct node
{
	int val;
	struct node * next;
};
typedef struct node node, *list; // *list = node node,list指针指向node默认对象

//打印函数
void printList(list mylist);
////排序函数

////插入排序
void insertSort(list mylist);
////冒泡排序
void bubbleSort(list mylist);
////简单选择
void selectSort(list mylist);
////快速排序
void quickSort(list mylist);

int main(void)
{
	int arr[] = { 8, 5, 1, 7, 4, 2, 9, 6, 3, 8 };
	//程序都是针对有头结点的单向链表
	//list mylist = (list)malloc(sizeof(node));
	//list mylist=new list[sizeof(node)];
	node *mylist = new node[sizeof(node)];
	mylist->val = 0;
	mylist->next = NULL;
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	node * cur = mylist; 
	while (i < len)
	{
		//node * newNode = (node *)malloc(sizeof(node));   //另外创建了一个node,将数据复制到mylist第二位地址
		node *newNode = new node[sizeof(node)];            //使得mylist第一位不储存数据，用来存放prep2指针
		newNode->val = arr[i];
		newNode->next = NULL;
		cur->next = newNode;
		cur = cur->next;
		i++;
	}
	insertSort(mylist);
	//bubbleSort(mylist);
	//selectSort(mylist);
	//quickSort(mylist);
	printList(mylist);

	return 0;
}

void printList(list mylist)
{
	node * cur = mylist->next;
	while (cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

//=============插入排序====================
void insertSort(list mylist)
{
	if ((mylist->next == NULL) || (mylist->next->next == NULL))
	{
		return;
	}

	node * head, *p1, *prep1, *p2, *prep2, *temp;
	head = mylist;
	prep1 = head->next;
	p1 = prep1->next;
	//prep1和p1是否需要手动后移
	bool flag;

	while (p1 != NULL)
	{
		flag = true;
		temp = p1;
		//由于是单向链表，所以只能从头部开始检索
		for (prep2 = head, p2 = prep2->next; p2 != p1; prep2 = prep2->next, p2 = p2->next)
		{
			//发现第一个较大值
			if (p2->val > p1->val)
			{
				p1 = p1->next;
				prep1->next = p1;
				prep2->next = temp;
				temp->next = p2;
				flag = false;
				break;
			}
		}
		//手动后移prep1和p1
		if (flag)
		{
			prep1 = prep1->next;
			p1 = p1->next;
		}
	}
}

//=============冒泡排序====================    有Bug

void bubbleSort(list mylist)
{
	if ((mylist->next == NULL) || (mylist->next->next == NULL))
	{
		return;
	}

	node *head, *pre, *cur, *next, *end, *temp;
	head = mylist;
	end = NULL;
	//从链表头开始将较大值往后沉
	while (head->next != end)
	{
		for (pre = head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			//相邻的节点比较
			if (cur->val > next->val)
			{
				cur->next = next->next;
				pre->next = next;
				next->next = cur;
				temp = next;
				next = cur;
				cur = temp;
			}
		}
		end = cur;
	}
}

//=============简单选择排序================
void selectSort(list mylist)
{
	if ((mylist->next == NULL) || (mylist->next->next == NULL))
	{
		return;
	}

	node * head, *prep1, *p1, *prep2, *p2, *premin, *min, *temp;
	head = mylist;
	for (prep1 = head, p1 = prep1->next; p1->next != NULL; prep1 = prep1->next, p1 = prep1->next)
	{
		//保存最小节点
		premin = prep1;
		min = p1;
		for (prep2 = p1, p2 = prep2->next; p2 != NULL; prep2 = prep2->next, p2 = prep2->next)
		{
			if (min->val > p2->val)
			{
				premin = prep2;
				min = p2;
			}
		}

		if (p1 != min)
		{
			//一定要注意这个情况
			if (p1->next == min)
			{
				temp = min->next;
				prep1->next = min;
				min->next = p1;
				p1->next = temp;
			}
			else {
				temp = min->next;
				prep1->next = min;
				min->next = p1->next;
				premin->next = p1;
				p1->next = temp;
			}
		}
	}
}

//=============快速排序====================

//交换节点
void swap(node * a, node * b)
{
	int temp = a->val;
	a->val = b->val;
	b->val = temp;
}

//求中间点
node * partion(node * start, node * end)
{
	if (start == end || start->next == end)
	{
		return start;
	}
	//取第一个元素作为基准元素
	node * p = start, *q = start, *refer = start;
	//从start开始向后进行一次遍历(因为是单链表，无法按从左右向中间遍历的方法)
	while (q != end)
	{
		if (q->val < refer->val)
		{
			p = p->next;
			swap(p, q);
		}
		q = q->next;
	}
	swap(p, refer);
	return p;
}
//递归
void quick_sort(node * start, node * end)
{
	if (start == end || start->next == end)
	{
		return;
	}
	node * mid = partion(start, end);
	quick_sort(start, mid);
	quick_sort(mid->next, end);
}

void quickSort(list mylist)
{
	if ((mylist->next == NULL) || (mylist->next->next == NULL))
	{
		return;
	}
	node * start = mylist->next;
	node * end = NULL;
	quick_sort(start, end);
}

