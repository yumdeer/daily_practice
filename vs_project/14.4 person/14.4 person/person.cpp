#include "person.h"

void Person::Data()const
{
	cout<< "First name is : " <<firstname<<endl;
	cout<< "Last name is : " <<lastname<<endl;
}
void Person::Get()
{
	cout<< "Enter first name: \n";
	getline(cin, firstname);
	cout<< "Enter last name: \n";
	getline(cin, lastname);
}
void Person::Show()const
{
	Data();
}
void Person::Set()
{
	Get();
}

void Gunslinger::Data()const
{
	cout<< "Nick is :" <<numsk<<endl;
	cout<< "The time of get the gun :" << Gunslinger::Draw() <<endl;
}
void Gunslinger::Get()
{
	cout<< "Enter Nick: \n";
	cin>>numsk;
}
void Gunslinger::Set()
{
	cout<< "Enter Guns name: \n";
	Person::Get();
	Get();
}
void Gunslinger::Show()const
{
	cout<< "Gunslinger: \n";
	Person::Data();
	Data();
}
double Gunslinger::Draw()const
{
	return rand() % 3 + 1;
}

int PokerPlayer::Draw()const
{
	return rand() % 52 + 1;
}
void PokerPlayer::Data()const
{
	cout<< "The cards :" << Draw() <<endl;
}
void PokerPlayer::Show()const
{
	cout<< "PokerPlayer :\n";
	Person::Data();
	Data();
}

double BadDude::Gdraw()const
{
	return Gunslinger::Draw();
}
int BadDude::Cdraw()const
{
	return PokerPlayer::Draw();
}
void BadDude::Data()const
{
	Gunslinger::Data();
	PokerPlayer::Data();
	cout<< "The next cards: " <<Cdraw() <<endl;
	cout<< "The time of BadDude get the gun: " <<Gdraw() <<endl;
}
void BadDude::Get()
{
	Gunslinger::Get();
}
void BadDude::Set()
{
	cout<< "Enter BadDude name: \n";
	Person::Get();
	Get();
}
void BadDude::Show()const
{
	cout<< "BadDude: \n";
	Person::Data();
	Data();
}
