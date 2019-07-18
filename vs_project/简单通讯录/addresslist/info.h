#ifndef _PERSON_H_
#define _PERSON_H_
 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
class Info
{
private:
    int id;
    string name;
    string tel;
    string addr;
public:
    Info();
    ~Info();
    static int count; //记录通讯录中的人数
    int GetId();
    void SetName();
    string GetName() const;
    void SetTel();
    string GetTel() const;
    void SetAddr();
    string GetAddr() const;
    void choose();
    void insert();
    void show();
    void search();
    void interface();
    void delete_info();
    void exit_info();
    void modify();
};
 
#endif
