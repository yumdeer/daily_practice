#ifndef HIGHFINK_H_
#define HIGHFINK_H_

#include "manager.h"
#include "fink.h"

class highfink :public manager, public fink
{
public:
	highfink();
	highfink(const string &fn, const string &ln,const string &j, const string &rpo, int ico = 0);
	highfink(const abstr_emp &e, const string &rpo, int ico = 0);
	highfink(const fink &f, int ico = 0);
	highfink(const manager &m, const string &rpo);
	highfink(const highfink &h);
	//virtual void ShowAll()const;
	void ShowAll()const;
	//virtual void SetAll();
	void SetAll();
};

#endif
