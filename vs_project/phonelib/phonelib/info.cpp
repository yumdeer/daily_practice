#include "info.h"
 
 
vector<Info> per;
int Info::count = 0;
 
 Info::Info()
{
 
}
  
Info::~Info()
{

}

int Info::GetId()
{
    return id;
}
 
 
void Info::SetName()
{
    //cout << "姓名："; 
    cin >> name;
}
string Info::GetName() const
{
    string tmp = name;
    return tmp;
}
 
 
void Info::SetTel()
{
    //cout << "电话：";
    cin >> tel;
}
string Info::GetTel() const
{
    string tmp = tel;
    return tmp;
}
 
void Info::SetAddr()
{
    //cout << "地址：";
    cin >> addr;
}
string Info::GetAddr() const
{
    string tmp = addr;
    return tmp;
}

void Info::SetEmail()
{
    //cout << "邮件：";
    cin >> email;
}
string Info::GetEmail() const
{
    string tmp = email;
    return tmp;
}
 
void Info::insert()
{
    Info tmp;
    vector<Info>::iterator it;
    tmp.SetName();
    tmp.SetTel();
	tmp.SetEmail();
    tmp.SetAddr();    
    per.push_back(tmp);
}

void Info::search()
{
    vector<Info>::iterator it;
    if(per.empty())
    {
        cout << "通讯录暂无联系人！" << endl;
    }
    else
    {
		search_loop:
		string tn; //查找的姓名
		int flag = 0;//查找成功与否标志位

		cout << "请输入查找的姓名：";
		cin >> tn;
		for(it = per.begin(); it != per.end(); ++it)
		 {
			if(!((it->GetName()).compare(tn)))
		    {
			 flag = 1;
			 cout << "你要找的联系人为：" <<endl;
			  //cout << "ID: " << it->GetId() << endl;
			 cout  << it->GetName() << " ";
			 cout  << it->GetTel()<< " " ;
			 cout << it->GetEmail()<< " ";
			 cout << it->GetAddr()<<endl;
			}
		 }

		if(0 == flag)
		{
		 cout << "无找到此联系人" << endl;
		}
		else
		{
		 //cout << "查找成功"  << endl;
		}
    }  
} 
 

