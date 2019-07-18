#include <string>
#include <iostream>

typedef int ElementType;					//定义数据类型为整型 

struct Node									//定义结点 
{
	ElementType data;
	Node * next;
};

class Link									//带头结点链表 
{
public:
	Link();
	~Link();

	void select_sort();						//选择排序 
	void bubble_sort();						//冒泡排序
	void insert_head(ElementType data);		//头部插入 
	void insert_tail(ElementType data);		//尾部插入 
	int find(ElementType data);				//查找结点,返回序号，如果不存在返回-1
	bool delete_node(int pos);				//删除结点 
	void reverse();							//逆置 
	void display();							//打印链表 
	void printhelp();						//打印提示信息
	int size();								//返回长度
private:
	Node * pHead;							//头结点指针 
	size_t iSize;							//链表长度 
};

Link::Link() :pHead(NULL), iSize(0)
{
	pHead = new Node;
	pHead->next = NULL;
}

Link::~Link()
{
	Node * tmpNode = NULL;
	Node * p = pHead->next;
	while (p != NULL)
	{
		tmpNode = p->next;
		delete p;
		p = tmpNode;
	}
	delete tmpNode;
	tmpNode = NULL;

	delete pHead;
	p = NULL;

	iSize = 0;
}

/**********************************
   链表选择排序(递增)
***********************************/
void Link::select_sort()
{
	Node * p, *q;
	int temp;

	for (p = pHead; p != NULL; p = p->next)
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

/**********************************
   链表冒泡排序(递增)
***********************************/
void Link::bubble_sort()
{
	Node *p;
	int temp;

	/************************************************************************/
	/*       冒泡排序是每次从头开始比较相邻的两个数，大小相反则交换，结束的 */
	/*        条件是这一轮中没有发生交换，flag用来记录是否发生了交换          */
	/************************************************************************/
	int flag;
	while (true)
	{
		flag = 0;
		for (p = pHead; p->next != NULL; p = p->next)
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

/********************************
   链表头部插入
*****************************/
void Link::insert_head(ElementType data)
{
	Node * tmpNode = new Node;
	tmpNode->data = data;

	tmpNode->next = pHead->next;
	pHead->next = tmpNode;

	iSize++;

	tmpNode = NULL;
}

/********************************
   链表尾部插入
*****************************/
void Link::insert_tail(ElementType data)
{
	Node * tmpNode = new Node;
	tmpNode->data = data;
	tmpNode->next = NULL;

	Node * p = NULL;
	p = pHead;
	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = tmpNode;
	iSize++;

	//delete tmpNode;
	tmpNode = NULL;
	//delete p;
	p = NULL;
}

/********************************
   打印链表
*****************************/
void Link::display()
{
	int count = 1;
	Node * tmpNode = NULL;

	tmpNode = pHead->next;
	while (tmpNode != NULL)
	{
		std::cout << tmpNode->data << " ";
		tmpNode = tmpNode->next;

		/********************************
		*  输出格式控制，每行10个
		**********************************/
		if (count % 10 == 0)
		{
			std::cout << std::endl;
		}
		count++;
	}
	std::cout << std::endl;
	tmpNode = NULL;
}

/********************************
   查找结点
*****************************/
int Link::find(ElementType data)
{
	int pos = 0;
	Node * tmpNode = NULL;

	tmpNode = pHead->next;
	while (tmpNode != NULL)
	{
		if (tmpNode->data == data)
		{
			return pos;
		}
		tmpNode = tmpNode->next;
		pos++;
	}

	tmpNode = NULL;
	return -1;
}

/********************************
   删除结点
*****************************/
bool Link::delete_node(int pos)
{
	//序号超过链表范围则报错退出
	if (pos > iSize - 1)
	{
		return false;
	}
	else
	{
		int k = 0;
		Node * tmpNode = NULL;
		tmpNode = pHead;
		while (k < pos)
		{
			tmpNode = tmpNode->next;
			k++;
		}
		Node * p = NULL;
		p = tmpNode->next;

		tmpNode->next = tmpNode->next->next;
		delete p;
		p = NULL;
		iSize--;
		return true;
	}
}

/********************************
   返回链表的长度
*****************************/
int Link::size()
{
	return iSize;
}

/********************************
   链表的逆置
*****************************/
void Link::reverse()
{
	Node * preNode = NULL;
	Node * curNode = NULL;
	Node * afterNode = NULL;

	if (iSize == 1 || iSize == 0)
	{
		return;
	}
	else if (iSize >= 2)
	{
		preNode = pHead->next;
		curNode = preNode->next;
		afterNode = curNode->next;

		preNode->next = NULL;

		while (afterNode != NULL)
		{
			curNode->next = preNode;

			preNode = curNode;
			curNode = afterNode;

			afterNode = afterNode->next;
		}

		/********************************************************************
		* 将当前结点的next置为前一个结点的过程是在每一次循环的开始，而最后一次
		* 循环后无法进入下一次循环，需要补一次设置curNode的next的过程
		*********************************************************************/
		curNode->next = preNode;

		pHead->next = curNode;
	}
	preNode = NULL;
	curNode = NULL;
	afterNode = NULL;
}

void Link::printhelp()
{
	std::cout << "*****************************************\n";
	std::cout << "当前链表为:" << std::endl;
	if (iSize == 0)
		std::cout << "NULL" << std::endl;
	else
		display();
	std::cout << "输入你的选择:\n"
		"0.从头部插入结点\n"
		"1.从尾部插入结点\n"
		"2.逆置链表\n"
		"3.打印链表\n"
		"4.删除结点\n"
		"5.输出链表长度\n"
		"6.查找结点\n"
		"7.选择排序\n"
		"8.冒泡排序\n"
		"9.退出" << std::endl;
	std::cout << "*****************************************\n";
}

int main(int argc, char * argv[])
{
	Link myLink;
	int pos;
	char choice;
	ElementType find_num = 3;
	int delchoice;

	for (int i = 0; i < 48; i++)
	{
		myLink.insert_head(rand() % 100);
	}

	myLink.printhelp();
	std::cout << "请选择:";
	while (std::cin >> choice)
	{
		switch (choice)
		{
		case '0':
		case '1':
			std::cout << "\n暂无此功能!\n";
			break;
		case '2':
			myLink.reverse();
			std::cout << "\n逆置成功!\n";
			break;
		case '3':
			myLink.display();
			std::cout << "\n打印成功!\n";
			break;
		case '4':
			std::cout << "\n输入要删除的节点序号:";
			std::cin >> delchoice;
			if (myLink.delete_node(delchoice) == true)
			{
				std::cout << "\n删除成功!\n";
			}
			else
			{
				std::cout << "\n删除失败!\n";
			}
			break;
		case '5':
			std::cout << "链表长为:" << myLink.size() << std::endl;
			break;
		case '6':
			goto exit;
			break;
		case '7':
			myLink.select_sort();
			break;
		case '8':
			myLink.bubble_sort();
			break;
		case '9':
			goto exit;
			break;
		default:
			break;
		}
		myLink.printhelp();
		std::cout << "请选择:";
	}

exit:
	system("pause");
	return 0;
}