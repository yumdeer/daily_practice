#include<iostream>
#include<cmath>
#include"line.h"
using namespace std;

int main()
{
Point myp1(1,1),myp2(4,5); //建立Point类的对象
Line line(myp1,myp2); //建立Line类的对象
Line line2(line); //利用拷贝构造函数建立一个新对象
cout<<"The length of the line is :";
cout<<line.GetLen()<<endl;
cout<<"The length of the line2 is :";
cout<<line2.GetLen()<<endl;
}