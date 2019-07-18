#include "highfink.h"

highfink::highfink() :abstr_emp(), manager(), fink()
{

}

highfink::highfink(const string &fn, const string &ln,const string &j, const string &rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn,ln, j, rpo)
{

}

highfink::highfink(const abstr_emp &e, const string &rpo, int ico) : abstr_emp(e), manager(e, ico),fink(e, rpo)
{

}

highfink::highfink(const fink &f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{

}

highfink::highfink(const manager &m, const string &rpo) : abstr_emp(m), manager(m), fink(m,rpo)
{
	
}

highfink::highfink(const highfink&h) : abstr_emp(h), manager(h), fink(h)
{

}

void highfink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout<< "InChargeOf: " << manager::InChargeOf() <<endl;
	cout<< "ReportsTo: " << fink::ReportsTo() <<endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	manager::getInCharge();
	fink::getReportsTo();
}