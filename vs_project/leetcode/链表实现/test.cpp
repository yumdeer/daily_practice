#include<iostream>

class Node
{
public:
	int data;
	Node *next;
	void printNode();

};


void Node::printNode()
{
	std::cout << data << std::endl;
}

class List
{
private:
	Node * m_pList;
	int m_iLength;

public:
	List();
	~List();
	void ClearList();                                    // 清空整个链表
	bool ListEmpty();                                    // 判断链表是否为空
	bool ListInsertHead(Node *pNode);                    // 头部插入一个节点
	bool ListInsertTail(Node *pNode);                    // 尾部插入一个节点
	bool ListInsert(int i, Node *pNode);                 // 从任意位置插入节点
	bool ListDelete(int i, Node *pNode);                 // 从任意位置删除结点
	bool ListGetElem(int i, Node *pNode);                // 查找第i个元素
	int  LocateElem(Node *pNode);                        // 查找结点的位序
	bool PriorElem(Node *pCurrentNode, Node *pPreNode);  // 找指针的前驱指针
	bool NextElem(Node *pCurrentNode, Node *pNextNode);  // 找指针的后继指针
	void ListTraverse();                                 // 链表的遍历
};


List::List()
{
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

bool List::ListEmpty()
{
	if (m_iLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void List::ClearList()
{
	Node *currentNode = m_pList->next; // 指向头指针后第一个元素
	while (currentNode != NULL)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;               // 头指针下一个为空

}

List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->next;            // 头节点后第一个元素
	Node *newNode = new Node;              // 创建一个新的节点
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}

bool List::ListInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
		currentNode = currentNode->next;   // 遍历到尾结点
	Node *newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

bool List::ListInsert(int i, Node *pNode)
{
	if (i<0 || i>m_iLength)
		return false;
	Node *currentNode = m_pList;
	for (int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}

	Node *newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	m_iLength++;
	return true;

}

bool List::ListDelete(int i, Node *pNode)
{
	if (i < 0 || i >m_iLength)
		return false;
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

bool List::ListGetElem(int i, Node *pNode)
{
	if (i < 0 || i >m_iLength)
		return false;
	Node *currentNode = m_pList;
	for (int k = 0; k <= i; k++)
	{
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}

int List::LocateElem(Node *pNode)
{
	Node *currentNode = m_pList;
	int count = 0;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data)
		{
			return count;
		}
		count++;
	}
	return -1;
}

bool List::PriorElem(Node *pCurrentNode, Node *pPreNode)
{
	Node *currentNode = m_pList;
	Node *tempNode = NULL;
	while (currentNode->next != NULL)
	{
		tempNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (tempNode == m_pList)
				return false;
			else
			{
				pPreNode->data = tempNode->data;
				return true;
			}

		}
	}
	return false;
}

bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (currentNode->next == NULL)
			{
				return false;
			}
			else
			{
				pNextNode->data = currentNode->next->data;
				return true;
			}

		}
	}
	return false;
}

void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}

}

using namespace std;

int main()
{
	Node node1;
	node1.data = 3;
	Node node2;
	node2.data = 4;
	Node node3;
	node3.data = 5;
	Node node4;
	node4.data = 6;
	Node node5;
	node5.data = 7;

	Node temp;

	List *pList = new List();
	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListInsertTail(&node3);
	pList->ListInsertTail(&node4);
	pList->ListInsert(1, &node5);
	// pList->ListDelete(1, &temp);
	// pList->ListGetElem(1, &temp);
	pList->NextElem(&node5, &temp);
	pList->ListTraverse();
	cout << "temp=" << temp.data << endl;
	delete pList;
	pList = NULL;
	return 0;
}