#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "abstr_emp.h"

class employee :public abstr_emp
{
public:
	employee();
	employee(const string &fn, const string &ln,
	const string &j);
	virtual void ShowAll()const;
	virtual void SetAll();
};

#endif