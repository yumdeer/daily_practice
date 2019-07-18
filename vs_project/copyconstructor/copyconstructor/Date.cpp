#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
    cout << "调用构造函数" << endl;
}

//Date::Date(const Date &date1)
//{
//    year = date1.year;
//    month = date1.month;
//    day = date1.day;
//    cout << "调用拷贝构造函数" << endl;
//}

void Date::showDate()
{
    cout << year << "." << month << "." << day << endl;
} 