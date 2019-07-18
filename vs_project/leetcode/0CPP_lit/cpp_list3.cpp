//
//  List.cpp
//  List
//
//  Created by scandy_yuan on 13-1-6.
//  Copyright (c) 2013年 Sam. All rights reserved.
//

#include <iostream>
using namespace std;

class List {
public:
	List() { create_List(); }
	~List() { clear(); }
	//创建头结点
	void create_List();
	//插入函数
	void insert(const int& d);
	//在指定位置插入
	void insert_pos(const int& d, const int& d1);
	//删除指定数据的节点
	void erase(const int& d);
	//修改指定数据
	void updata(const int& d, const int& d1);
	//反转链表函数
	void reverse();
	//打印
	void print();
private:
	//节点结构
	struct Node {
		int data;
		Node * next;
		Node(const int& d) :data(d), next(NULL) {}
	};
	Node * head;//头节点
	//清理链表函数
	void clear() {
		Node * p = head;
		//从头节点开始循环删除
		while (p) {
			Node * q = p->next;
			delete p;
			p = q;
		}
	}
	//查找数据d的上一个节点位置的函数
	//为了方便后面删除操作
	Node* find(const int& d) {
		Node * p = head;
		for (; p; p = p->next) {
			if (p->next->data == d)
				break;
		}
		return p;
	}
};

//创建头结点
void List::create_List()
{
	head = new Node(0);
}
//从头插入一个节点
void List::insert(const int& d)
{
	Node *p = new Node(d);
	p->next = head->next;
	head->next = p;
}
//打印函数
void List::print()
{
	for (Node * p = head->next; p; p = p->next) {
		cout << p->data << endl;
	}
}
//在d位置之前插入d1
void List::insert_pos(const int& d, const int& d1)
{
	Node * p = find(d);
	Node * q = new Node(d1);
	q->next = p->next;
	p->next = q;
}

//删除
void List::erase(const int& d)
{
	Node * p = find(d);
	//因为p是上一个节点的位置，用q来保存
	//要删除的节点的地址
	Node *q = p->next;
	//通过将上一个节点的next指针指向要删除节点的next指
	//针志向的节点实现断开要删除节点的目的
	p->next = p->next->next;
	//删除要删除的节点q
	delete q;
}

//修改指定数据
void List::updata(const int& d, const int& d1)
{
	Node * p = find(d);
	p->next->data = d1;
}

//反转链表
void List::reverse()
{
	Node * p = head->next;//头结点之后的第1个节点
	Node * q = head->next->next;//头结点之后的第2节点
	Node * m = head->next->next->next;//头结点之后的第3个节点
	p->next = NULL;//将头接点之后的第1个节点的next指针置为空
	//根据m是否为空来判断 以此逆序每一个节点
	while (m) {
		q->next = p;
		p = q;
		q = m;
		m = m->next;
	}
	//将最后一个节点逆序
	q->next = p;
	//将头从新指向新的的第1个节点(之前的最后一个节点)
	head->next = q;
}

int main(int argc, const char * argv[])
{

	// insert code here...
	List list;
	list.insert(30);
	list.insert(20);
	list.insert(10);
	list.insert_pos(10, 5);
	list.print();
	cout << "---------------------" << endl;
	list.erase(10);
	list.print();
	cout << "---------------------" << endl;
	list.reverse();
	list.print();
	cout << "---------------------" << endl;
	list.updata(5, 8);
	list.print();
	return 0;
}