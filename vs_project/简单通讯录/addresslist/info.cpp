#include "info.h"
 
vector<Info> per;
int Info::count = 0;
 
 
int Info::GetId()
{
    return id;
}
 
 
void Info::SetName()
{
    cout << "姓名："; 
    cin >> name;
}
string Info::GetName() const
{
    string tmp = name;
    return tmp;
}
 
 
void Info::SetTel()
{
    cout << "电话：";
    cin >> tel;
}
string Info::GetTel() const
{
    string tmp = tel;
    return tmp;
}
 
 
void Info::SetAddr()
{
    cout << "地址：";
    cin >> addr;
}
string Info::GetAddr() const
{
    string tmp = addr;
    return tmp;
}
 
 
Info::Info()
{
 
 
}
 
 
Info::~Info()
{
 
 
}
 
 
void Info::insert()
{
    Info tmp;
    vector<Info>::iterator it;
loop:
    count++;
    cout << "ID: " << count << endl;
    tmp.SetName();                                                     //输入姓名
    for(it = per.begin(); it != per.end(); ++it)
    {
        if(!((it->GetName()).compare(tmp.GetName())))
		{
			cout << "与已有联系人重名，请重新输入。" << endl;
			count--;
			goto loop;
		}
    }
    tmp.SetTel();														//输入电话
    tmp.SetAddr();														//输入地址
    tmp.id = count;
    
    per.push_back(tmp);
 
 
    cout << "是否继续添加联系人 y/n ：";
    char ch;
    cin >> ch;
    if('y' == ch || 'Y' == ch)
    {
        goto loop;
    }
   
}
 
 
void Info::show()
{
    vector<Info>::iterator it;
    if(per.empty())
    {
        cout << "通讯录暂无联系人！" << endl;
    }
    else
    {
        for(it = per.begin(); it != per.end(); ++it)
		{
			cout << "ID: " << it->GetId() << endl;
			cout << "姓名：" << it->GetName() << endl;
			cout << "电话：" << it->GetTel() << endl;
			cout << "地址：" << it->GetAddr() << endl;
		}
cout << "请按任意键退出" << endl;
char ch;
cin >> ch;
    }
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
		int tp =  0; //查询方式选择位
		int num = 0; //查找的ID
		string tn; //查找的姓名
		int flag = 0; //查找成功与否标志位
		cout << "查找方式：1.ID 2.姓名" << endl;
		cin >> tp;
		if(1 == tp)
		{
			cout << "请输入查找的ID：";
			cin >> num;
			for(it = per.begin(); it != per.end(); ++it)
		   {
				if(it->GetId() == num)
				{
				 flag = 1;
				 cout << "你要找的联系人为：" <<endl;
				 cout << "ID: " << it->GetId() << endl;
				 cout << "姓名：" << it->GetName() << endl;
				 cout << "电话：" << it->GetTel() << endl;
				 cout << "地址：" << it->GetAddr() << endl;
				}
			}
		 }
		else if(2 == tp)
		{
			 cout << "请输入查找的姓名：";
			 cin >> tn;
			 for(it = per.begin(); it != per.end(); ++it)
			{
			 if(!((it->GetName()).compare(tn)))
				{
				 flag = 1;
				 cout << "你要找的联系人为：" <<endl;
				 cout << "ID: " << it->GetId() << endl;
				 cout << "姓名：" << it->GetName() << endl;
				 cout << "电话：" << it->GetTel() << endl;
				 cout << "地址：" << it->GetAddr() << endl;
				}
			 }
		}
		else
		{
			cout << "查找方式选择错误，请重新选择。" << endl;
			goto search_loop;
		}
 
 
		if(0 == flag)
		{
			cout << "无找到此联系人" << endl;
		}
		else
		{
			 cout << "查找成功"  << endl;
		}
		cout << "请按任意键退出" << endl;
		char ch;
		cin >> ch;
    }   
}
 
 
void Info::delete_info()
{
    vector<Info>::iterator it;
    if(per.empty())
    {
        cout << "通讯录暂无联系人！" << endl;
    }
    else
    {
    delete_loop:
	int tp =  0; //删除方式选择位
	int num = 0; //删除的ID
	string tn; //删除的姓名
	int flag = 0; //删除成功与否标志位
        cout << "删除方式：1.ID 2.姓名" << endl;
        cin >> tp;
        if(1 == tp)
{
   cout << "请输入删除的ID：";
   cin >> num;
     for(it = per.begin(); it != per.end();)
   {
       if(it->GetId() == num)
		{
           flag = 1;
		   cout << "你要删除的联系人为：" <<endl;
           cout << "ID: " << it->GetId() << endl;
           cout << "姓名：" << it->GetName() << endl;
           cout << "电话：" << it->GetTel() << endl;
           cout << "地址：" << it->GetAddr() << endl;
           
		   cout << "确定删除此联系人吗？y/n : ";
           char ch1;
           cin >> ch1;
           if (ch1 == 'y' || ch1 == 'Y')
           {
               it = per.erase(it);
           }
}
else
{
   ++it;
}
   }
}
else if(2 == tp)
{
   cout << "请输入删除的姓名：";
            cin >> tn;
            for(it = per.begin(); it != per.end(); )
   {
       if(!((it->GetName()).compare(tn)))
{
                    flag = 1;
   cout << "你要删除的联系人为：" <<endl;
           cout << "ID: " << it->GetId() << endl;
           cout << "姓名：" << it->GetName() << endl;
           cout << "电话：" << it->GetTel() << endl;
           cout << "地址：" << it->GetAddr() << endl;
   
   cout << "确定删除此联系人吗？y/n : ";
           char ch1;
           cin >> ch1;
           if (ch1 == 'y' || ch1 == 'Y')
           {
               it = per.erase(it);
           }
}
else
{
   ++it;
}
   }
}
else
{
   cout << "删除方式选择错误，请重新选择。" << endl;
   goto delete_loop;
}
 
 
if(0 == flag)
{
   cout << "没有找到此联系人" << endl;
        }
else
{
   cout << "删除成功" << endl;
}
cout << "请按任意键退出" << endl;
char ch;
cin >> ch;
    }
    
}
void Info::modify()
{
    vector<Info>::iterator it;
    if(per.empty())
    {
        cout << "通讯录暂无联系人！" << endl;
    }
    else
    {
    modify_loop:
        string tn;
int flag2 = 0;
int flag = 0; //修改对象查找成功与否标志位
        cout << "请输入你要编辑的人的姓名：" ;
        cin >> tn;
        for(it = per.begin(); it != per.end(); )
{
   if(!((it->GetName()).compare(tn)))
            {
       flag = 1;
cout << "你要修改的联系人为：" <<endl;
       cout << "ID: " << it->GetId() << endl;
       cout << "姓名：" << it->GetName() << endl;
       cout << "电话：" << it->GetTel() << endl;
       cout << "地址：" << it->GetAddr() << endl;
   
cout << "确定修改此联系人吗？y/n : ";
       char ch1;
       cin >> ch1;
char ch2;
       if (ch1 == 'y' || ch1 == 'Y')
       {
           cout << "你要修改的是：1.姓名 2.电话 3.地址：";
   cin >> ch2;
                    switch(ch2)
   {
       case '1':
{
                            it->SetName();
   cout << "修改成功！该联系人信息改为：" << endl;
                   cout << "ID: " << it->GetId() << endl;
                   cout << "姓名：" << it->GetName() << endl;
                   cout << "电话：" << it->GetTel() << endl;
                   cout << "地址：" << it->GetAddr() << endl;
   flag2 = 1;
   break;
}
case '2':
{
   it->SetTel();
   cout << "修改成功！该联系人信息改为：" << endl;
                   cout << "ID: " << it->GetId() << endl;
                   cout << "姓名：" << it->GetName() << endl;
                   cout << "电话：" << it->GetTel() << endl;
                   cout << "地址：" << it->GetAddr() << endl;
   flag2 = 1;
   break;
}
case '3':
{
   it->SetAddr();
   cout << "修改成功！该联系人信息改为：" << endl;
                   cout << "ID: " << it->GetId() << endl;
                   cout << "姓名：" << it->GetName() << endl;
                   cout << "电话：" << it->GetTel() << endl;
                   cout << "地址：" << it->GetAddr() << endl;
   flag2 = 1;
   break;
}
default :
{
   cout << "指令输入错误！" << endl;
   break;
}
   }
       }
else
{
   break;
}
            }
            else
   {
++it;
            }
}
if(0 == flag)
{
   cout << "没有找到此联系人" << endl;
}
if(1 == flag2)
{
   cout << "修改成功!" << endl;
}    
cout << "请按任意键退出" << endl;
char ch3;
cin >> ch3;
    }    
}
 
 
 
 
void Info::exit_info()
{
    cout << "确定退出此通讯录吗？y/n: " ;
    char ch1;
    cin >> ch1;
    if (ch1 == 'y' || ch1 == 'Y')
    {
        exit(1);
    }
 
 
}
 
 
void Info::choose()
{
    char action;
    Info tmp;
    cout << "请输入你要实现的功能(0-4)：" ;
    cin >> action;
 
 
    switch(action)
    {
        case '1':
{
   tmp.insert();
   tmp.interface();
   choose();
   break; 
}
case '2':
{
   tmp.show();
   tmp.interface();
   choose();
   break;
}
case '3':
{
   tmp.delete_info();
   tmp.interface();
   choose();
}
case '4':
{
   tmp.search();
   tmp.interface();
   choose();
   break;
}
case '5':
{
   tmp.modify();
   tmp.interface();
   choose();
   break;
}
case '6':
{
   tmp.exit_info();
   break;
}
default:
{
   cout << "输入指令有误，请重新输入！" << endl;
   choose();
   break;
}
    }
}
 
 
 
 
void Info::interface()
{
    system("clear");
 
 
    printf("\n");
    printf("\n");
    printf("          |***********************************************|\n");
    printf("          |*          多 功 能 电 子 通 讯 录            *|\n");
    printf("          |*                                             *|\n");
    printf("          |*                              版本号：V_1.0.0*|\n");
    printf("          |***********************************************|\n");
    printf("          |*                                             *|\n");
    printf("          |*      功能选择:   1. 添加好友信息            *|\n");
    printf("          |*                  2. 查看好友信息            *|\n");
    printf("          |*                  3. 删除好友信息            *|\n");
    printf("          |*                  4. 搜索好友信息            *|\n");
    printf("          |*                  5. 修改好友信息            *|\n");
    printf("          |***********************************************|\n");
    printf("          |*      请输入你想要实现的功能：               *|\n");
    printf("          |*                                             *|\n");
    printf("          |*    1添加 2查看 3删除 4搜索 5修改 6退出      *|\n");
    printf("          |***********************************************|\n");
 
 
}
