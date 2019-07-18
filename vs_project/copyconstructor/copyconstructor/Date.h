#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
    Date(int y, int m, int d);  // 构造函数 
   // Date(const Date &date1);   // 拷贝构造函数                                                                                  
    void showDate();

private:
    int year;
    int month;
    int day;
};


