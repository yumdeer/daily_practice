#ifndef FINK_H_
#define FINK_H_

#include "abstr_emp.h"

class fink :virtual public abstr_emp
{
private:
	string reportsto;
protected:
	const string ReportsTo()const{ return reportsto; }
	string& ReportsTo(){ return reportsto; }
public:
	fink();
	fink(const string &fn, const string &ln,
	const string &j, const string &rpo);
	fink(const abstr_emp &e, const string &rpo);
	fink(const fink &e);
	//virtual void ShowAll()const;
	void ShowAll()const;
	//virtual void SetAll();
	void SetAll();
	void getReportsTo(){
	cout<< "Enter reportsto: ";
	cin>>reportsto;
	}
};

#endif

