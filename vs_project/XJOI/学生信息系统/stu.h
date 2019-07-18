#include <iostream>
#include <vector>
#include <string>

using namespace std;

class stu
{
private:
	string name;
	string tel;
	string email;
	string addr;
public:

	void SetName();
	string GetName() const;
	void SetTel();
	string GetTel() const;
	void SetEmail();
	string GetEmail() const;
	void SetAddr();
	string GetAddr() const;

	void insert();
	void show();
};


