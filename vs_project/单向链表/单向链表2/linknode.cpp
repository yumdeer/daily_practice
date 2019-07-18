#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>

/**
* cstdio是将stdio.h的内容用C++头文件的形式表示出来。
*stdio.h是C标准函数库中的头文件，即：standard buffered input&output。
*提供基本的文字的输入输出流操作（包括屏幕和文件等）。
*/

/**
*conio是Console Input/Output（控制台输入输出）的简写，其中定义了通过控制台进行数据输入和数据输出的函数，
*主要是一些用户通过按键盘产生的对应操作，比如getch()()函数等等。
*/

using namespace std;

struct node
{
	int data;
	node *next;
};
typedef struct node node, *list;

// 创建单链表
node *creat()
{
	node *head, *p;
	head = new node;
	p = head;

	int x, cycle = 1;
	while (cycle)
	{
		cout << "Please input the data for single linker : ";
		cin >> x;

		if (x != 0)
		{
			node *s = new node;
			s->data = x;
			cout << "Input data : " << x << endl;

			p->next = s;
			p = s;
		}
		else
		{
			cycle = 0;
			cout << "Input done! " << endl;
		}
	}

	head = head->next;
	p->next = NULL;
	//cout << "\nFirst data of single linker is " << head->data << endl;

	return head;
}

// 单链表测长
int length(node *head)
{
	int n = 0;
	node *p = head;

	while (p != NULL)
	{
		p = p->next;
		n++;
	}

	return n;
}

// 单链表打印
void printL(node *head)
{
	node *p = head;

	while (p != NULL)
	{
		cout << "Single Linker data is " << p->data << endl;
		p = p->next;
	}
}

// 单链表插入
node *insert(node *head, int num)
{
	node *p0, *p1, *p2;
	p1 = head;

	p2 = new node;
	p0 = new node; // 插入节点
	p0->data = num;// 插入数据

	while (p0->data > p1->data && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;// p0,p1和p2位置: p2->p1->p0
	}

	if (p0->data <= p1->data)
	{
		if (p1 == head)
		{// 头部前段插入 p0和p1位置: p0->p1->...
			head = p0;
			p0->next = p1;
		}
		else
		{// 插入中间节点 p0,p1和p2位置: p2-> p0 -> p1
			p2->next = p0;
			p0->next = p1;
		}
	}
	else
	{   // 尾部插入节点 p0,p1和p2位置: p2->p1->p0->NULL
		p1->next = p0;
		p0->next = NULL;
	}
	return head;
}

// 单链表删除
node *del(node *head, int num)
{
	node *p1, *p2;
	p2 = new node;
	p1 = head;

	while (num != p1->data && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;// p1和p2位置: p2->p1		
	}

	if (num == p1->data)
	{
		if (p1 == head)// 删除头节点
		{
			head = p1->next;
			delete p1;
		}
		else
		{
			p2->next = p1->next;
			delete p1;
		}
	}
	else
	{
		cout << num << " could not been found in the current single linker!" << endl;
	}
	return head;
}

//=============插入排序====================
node *insertSort( node *head )
{
	node  *p1, *prep1, *p2, *prep2, *temp;
	prep1 = head->next;
	p1 = prep1->next;
	//prep1和p1是否需要手动后移
	bool flag;

	while (p1 != NULL)
	{
		flag = true;
		temp = p1;
		//由于是单向链表，所以只能从头部开始检索
		for (prep2 = head, p2 = head->next; p2 != p1; prep2 = prep2->next, p2 = p2->next)
		{
			//发现第一个较大值
			if (p2->data > p1->data)
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
	return head;
}

////插入排序
//node *insertionSortList(node *head) {
//	// IMPORTANT: Please reset any member data you declared, as
//	// the same Solution instance will be reused for each test case.
//	if (head == NULL || head->next == NULL)return head;
//	node *p = head->next, *pstart = new node(0), *pend = head;
//	pstart->next = head; //为了操作方便，添加一个头结点
//	while (p != NULL)
//	{
//		node *tmp = pstart->next, *pre = pstart;
//		while (tmp != p && p->data >= tmp->data) //找到插入位置
//		{
//			tmp = tmp->next; pre = pre->next;
//		}
//		if (tmp == p)pend = p;
//		else
//		{
//			pend->next = p->next;
//			p->next = tmp;
//			pre->next = p;
//		}
//		p = pend->next;
//	}
//	head = pstart->next;
//	delete pstart;
//	return head;
//}


int main()
{
	cout << "***创建单链表***" << endl;
	node *head = creat();
	cout << endl;

	cout << "***计算链表长***" << endl;
	int n = length(head);
	cout << "The length of input single linker is " << n << "." << endl;
	cout << endl;

	cout << "***打印单链表***" << endl;
	printL(head);
	cout << endl;

	cout << "****插入节点****" << endl;
	cout << "Please input the data for inserting operate : ";
	int inData;
	cin >> inData;
	head = insert(head, inData);
	printL(head);
	cout << endl;

	cout << "****删除节点****" << endl;
	cout << "Please input the data for deleting operate : ";
	int outData;
	cin >> outData;
	head = del(head, outData);
	printL(head);
	cout << endl;

	cout << "****进行排序****" << endl;
	//第一位地址可以存放指示器，从第二位开始保存数据
	node *mylist = new node[sizeof(node)];
	mylist->data = 0;
	mylist->next = NULL;

	int len = length(head);
	int i = 0;
	node * cur = mylist;


	node *headcopy = head;
	while (len--)
	{
		//node * newNode = (node *)malloc(sizeof(node));   
		node *newNode = new node[sizeof(node)];            
		newNode->data = headcopy->data;
		newNode->next = NULL;
		cur->next = newNode;
		cur = cur->next;
		headcopy=headcopy->next;
	}

	head = insertSort(mylist);
	head = del(head, 0);
	//node *insertionSortList(node *head);
	printL(head);

	return 0;
}

