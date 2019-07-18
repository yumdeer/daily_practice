#include "queuetp.h"

class Worker
{
private:
	string fullname;
	long id;
public:
	Worker() :fullname("no one"), id(0L){}
	Worker(const string &s, long n) :fullname(s), id(n){}
	~Worker();
	void Set();
	void Show()const;
};


Worker::~Worker(){}
void Worker::Show()const
{
	cout<< "Name: " <<fullname<<endl;
	cout<< "Employee ID: " << id <<endl;
}
void Worker::Set()
{
	cout<< "Enter worker's name: ";
	getline(cin, fullname);
	cout<< "Enter worker's ID: ";
	cin>> id;
	while (cin.get() != '\n')
		continue;
}
