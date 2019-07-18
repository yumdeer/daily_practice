#include "Mylist.h"

int main(int argc, const char * argv[])
{

	// insert code here...
	List list;

	list.creat();
	list.print();
	cout << "insert²åÈë²âÊÔ£º" << endl;
	list.insert_head(30);
	list.insert_head(20);
	list.insert_tail(10);
	list.insert_head(40);
	list.insert_pos(10, 5);					//ÔÚ10Ç°Ãæ²åÈë5
	list.print();
	cout << "eraseÉ¾³ı²âÊÔ£º" << endl;
	list.erase(10);                         //É¾³ıÔªËØ10
	list.print();
	cout << "reverse·´×ª²âÊÔ£º" << endl;
	list.reverse();							//·´×ªÁ´±í
	list.print();
	cout << "updataÌæ»»²âÊÔ£º" << endl;
	list.updata(5, 8);						//Ìæ»»ÔªËØ
	list.print();
	list.creat();
	list.print();
	cout << "Ã°ÅİÅÅĞòÊä³ö½á¹û:" << endl;
	//list.select_sort();
	list.bubble_sort();
	list.print();

}