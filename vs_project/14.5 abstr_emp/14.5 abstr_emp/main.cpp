#include "employee.h"
#include "manager.h"
#include "highfink.h"


int main(void)
{
	employee em("Trip", "Harris", "Thumper");
	cout<< em <<endl;
	em.ShowAll();

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout<<endl;
	cout<< ma <<endl;;
	ma.ShowAll();

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout<<endl;
	cout<< fi <<endl;;
	fi.ShowAll();

	highfink hf(ma,"Curly Kew");
	cout<<endl;
	hf.ShowAll();

	cout<<endl;
	cout<< "Press a key for next phase:\n";
	cin.get();

	highfink hf2;
	cout<<endl;
	hf2.SetAll();
	cout<< "Using an abstr_emp * pointer:\n";

	abstr_emp *tri[4] = { &em, &fi, &hf, &hf2 };
	cout<<endl;
	for (int i = 0; i< 4; i++)
	tri[i]->ShowAll();

	system("pause");
	return 0;
}
