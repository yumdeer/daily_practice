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
vector<stu> per;

void stu::SetName()
{
	//cout << "姓名：";
	cin >> name;
}
string stu::GetName() const
{
	string tmp = name;
	return tmp;
}


void stu::SetTel()
{
	//cout << "电话：";
	cin >> tel;
}
string stu::GetTel() const
{
	string tmp = tel;
	return tmp;
}

void stu::SetEmail()
{
	//cout << "email：";
	cin >> email;
}
string stu::GetEmail() const
{
	string tmp = email;
	return tmp;
}


void stu::SetAddr()
{
	//cout << "地址：";
	getline(cin,addr);
}
string stu::GetAddr() const
{
	string tmp = addr;
	return tmp;
}


void stu::insert()
{
	stu tmp;
	vector<stu>::iterator it;

	tmp.SetName();
	tmp.SetTel();
	tmp.SetEmail();
	tmp.SetAddr();                                                     

	per.push_back(tmp);

}

void stu::show()
{
	vector<stu>::iterator it;

	string tn;  //需要查找的姓名
	cin >> tn;
	int flag=0;
	for(it = per.begin(); it != per.end(); ++it)
	{
		if(!((it->GetName()).compare(tn)))
		{
			flag=1;
			cout << it->GetName()  << " ";
			cout << it->GetTel()   << " ";
			cout << it->GetEmail() << " ";
			cout << it->GetAddr()  << endl;
		}

	}
	if(0 == flag)
	{
		cout << "not found" << endl;
	}

}

int main()
{
	int n ;
	cin >> n;
	stu m_stu;

	for(int i=0;i<n;i++)
		m_stu.insert();

	int m;
	cin >> m;
	for(int i=0;i<m;i++)
		m_stu.show();




	return 0;
}