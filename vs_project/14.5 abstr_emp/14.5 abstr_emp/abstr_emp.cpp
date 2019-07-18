#include "abstr_emp.h"

abstr_emp::abstr_emp() :fname("no one"), lname("no one"), job("no job")
{

}

abstr_emp::abstr_emp(const string &fn, const string &ln,const string &j) : fname(fn), lname(ln), job(j)
{
	
}

void abstr_emp::ShowAll()const
{
	cout<< "Firstname: " <<fname<<endl;
	cout<< "Lastname: " <<lname<<endl;
	cout<< "Job is: " << job <<endl;
	//cout<<endl;
}

void abstr_emp::SetAll()
{
	cout<< "Enter firstname: ";
	getline(cin, fname);
	cout<< "Enter lastname: ";
	getline(cin, lname);
	cout<< "Enter position: ";
	getline(cin, job);
}

ostream &operator<<(ostream&os, const abstr_emp &e)
{
	os<<e.fname<< " " <<e.lname<< ", " <<e.job;
	return os;
}

abstr_emp::~abstr_emp()
{

}