#ifndef MANAGER_H_
#define MANAGER_H_

#include "abstr_emp.h"

class manager :virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	int InChargeOf()const { return inchargeof; }
	int&InChargeOf(){ return inchargeof; }
public:
	manager();
	manager(const string &fn, const string &ln,const string &j, int ico = 0);
	manager(const abstr_emp&e, int ico = 0);
	manager(const manager &m, int ico);
	//virtual void ShowAll()const;
	void ShowAll()const;
	//virtual void SetAll();
	void SetAll();
	void getInCharge(){
	cout<< "Enter inchargeof: ";
	cin>>inchargeof;
	}
};

#endif