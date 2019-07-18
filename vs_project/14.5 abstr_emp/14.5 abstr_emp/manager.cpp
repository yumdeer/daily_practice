#include "manager.h"

manager::manager() :abstr_emp()
{

}

manager::manager(const string &fn, const string &ln,const string &j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{

}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico)
{

}

manager::manager(const manager &m, int ico) : abstr_emp(m),inchargeof(ico)
{
	
}

void manager::ShowAll()const
{
	abstr_emp::ShowAll();
	cout<< "Inchargeof: " <<InChargeOf() <<endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout<< "Enter inchargeof: ";
	( cin>>inchargeof ).get();
}