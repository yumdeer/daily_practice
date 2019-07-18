#include "employee.h"

employee::employee() :abstr_emp()
{

}

employee::employee(const string &fn, const string &ln,const string &j) : abstr_emp(fn, ln, j)
{

}

void employee::ShowAll()const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}