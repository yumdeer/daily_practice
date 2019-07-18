#ifndef Mylist
#define _MYLIST_

#include <iostream>
using namespace std;

class List {
public:
	List() { create_List(); }
	~List() { clear(); }
	void create_List();									//创建头结点
	void insert_head(const int& data);					//从头部插入，先进后出，倒序
	void insert_tail(const int& data);					//从尾部插入，先进先出，正序
	void creat();										//从尾部连续插入
	void insert_pos(const int& d, const int& d1);		//在指定位置插入
	void erase(const int& d);							//删除指定数据的节点
	void updata(const int& d, const int& d1);			//修改指定数据
	void reverse();										//反转链表函数
	void print();										//打印
	void select_sort();									//链表选择排序(递增)
	void bubble_sort();									//链表冒泡排序(递增)
private:
	struct Node {										//节点结构
		int data;
		Node * next;
		Node(const int& d) :data(d), next(NULL) {}
	};
	Node * head;										//头节点
	void clear();										//清理链表函数
	Node* find(const int& d) {						//查找数据d的上一个节点位置的函数,为了方便后面删除操作
		Node * p = head;
		for (; p; p = p->next) {
			if (p->next->data == d)
				break;
		}
		return p;
	}	
};

void List::clear() {									//清理链表函数
	Node * p = head;
	//从头节点开始循环删除
	while (p) {
		Node * q = p->next;
		delete p;
		p = q;
	}
}

void List::create_List()								//创建头结点
{
	head = new Node(0);
}


void List::insert_head(const int& data)					//从头部插入一个节点，head->p2->p1
{
	Node * tmpNode = new Node(data);
	tmpNode->next = head->next;
	head->next = tmpNode;
	
	tmpNode = NULL;
}

void List::insert_tail(const int& data)					//从尾部插入一个节点，heap->p1->p2
{
	Node * tmpNode = new Node(data);
	tmpNode->next = NULL;

	Node * p = NULL;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;           //将p移到尾部
	}

	p->next = tmpNode;

	//delete tmpNode;
	tmpNode = NULL;
	//delete p;
	p = NULL;
}

void List::creat()										//从尾部连续插入
{
	Node *p = head;
	while (p->next != NULL)
	{
		p = p->next;           //将p移到尾部
	}

	int x, cycle = 1;
	cout << "creat插入测试 (输入0停止) : ";
	while (cycle)
	{
		cin >> x;

		if (x != 0)
		{
			Node *s = new Node(x);
			p->next = s;
			p = s;		
		}
		else
		{
			cycle = 0;
			//cout << "Input done! Output Result: " << endl;
		}
	}

	p->next = NULL;

}

void List::print()									//打印函数
{
	cout << "-----------------------链表内的元素：";
	for (Node * p = head->next; p; p = p->next) {
		cout <<p->data << " ";
	}
	cout << endl;
}

void List::insert_pos(const int& d, const int& d1)	//在d位置之前插入d1
{
	Node * p = find(d);
	Node * q = new Node(d1);
	q->next = p->next;
	p->next = q;
}


void List::erase(const int& d)						//删除
{
	Node * p = find(d);
	Node *q = p->next;								//因为p是上一个节点的位置，用q来保存要删除的节点的地址											
	p->next = p->next->next;						//通过将上一个节点的next指针指向要删除节点的next指针志向的节点实现断开要删除节点的目的
		
	delete q;										//删除要删除的节点q
}

void List::updata(const int& d, const int& d1)		//修改指定数据
{
	Node * p = find(d);
	p->next->data = d1;
}

void List::reverse()								//反转链表
{
	Node * p = head->next;							//头结点之后的第1个节点
	Node * q = head->next->next;					//头结点之后的第2节点
	Node * m = head->next->next->next;				//头结点之后的第3个节点
	p->next = NULL;									//将头接点之后的第1个节点的next指针置为空
													//根据m是否为空来判断 以此逆序每一个节点
	while (m) {
		q->next = p;
		p = q;
		q = m;
		m = m->next;
	}
	q->next = p;									//将最后一个节点逆序
	head->next = q;									//将头从新指向新的的第1个节点(之前的最后一个节点)
	
}

void List::bubble_sort()							//冒泡排序
{
	Node *p;
	int temp;

	int flag;
	while (true)
	{
		flag = 0;
		for (p = head; p->next != NULL; p = p->next)
		{
			if (p->data > p->next->data)
			{
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void List::select_sort()								//选择排序
{
	Node * p, *q;
	int temp;

	for (p = head; p != NULL; p = p->next)
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->data > q->data)
			{
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
}
				
#endif // Mylist
