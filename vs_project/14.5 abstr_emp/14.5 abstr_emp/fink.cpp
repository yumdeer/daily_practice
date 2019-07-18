#include "fink.h"

fink::fink() :abstr_emp()
{

}

fink::fink(const string &fn, const string &ln,const string &j, const string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{

}

fink::fink(const abstr_emp &e, const string &rpo) : abstr_emp(e), reportsto(rpo)
{

}

fink::fink(const fink &e) : abstr_emp(e)
{

}

void fink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout<< "Reportsto: " <<ReportsTo() <<endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout<< "Enter reportsto: ";
	cin>>reportsto;
}