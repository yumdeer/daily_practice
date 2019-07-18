#include "person.h"

const int Size=5;

int main ()
{
	Person *per[Size];
	int ct;
	for (ct = 0; ct< Size; ct++)
	{
		char choice;
		cout<< "Enter the Person: \n"
		<< "g: gunslinger p: poker "
		<< "b: bad dude q: quit\n";
		cin>> choice;
		while (strchr("gpbq", choice) == NULL)
		{
			cout<< "Please enter a p,g,o,q: ";
			cin>> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		 case'g':
			per[ct] = new Gunslinger;
			break;
		 case'p':
			per[ct] = new PokerPlayer;
			break;
		 case'b':
			per[ct] = new BadDude;
			break;
		}
		cin.get();
		per[ct]->Set();                  //进入对应的set()函数
	}
	cout<< "\nHere is your staff:\n";
	int i;
	for (i = 0; i<ct; i++)
	{
		cout<<endl;
		per[i]->Show();
	}
	for (i = 0; i<ct; i++)
		delete per[i];
	cout<< "Bye\n";
	system("pause");
	return 0;
}
