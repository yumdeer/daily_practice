#include<iostream>
#include<cmath>
#include "line.h"

using namespace std;

Line::Line(Point xp1,Point xp2)
:p1(xp1),p2(xp2)
{
cout<<"Line构造函数被调用"<<endl;
double x=double(p1.GetX()-p2.GetX());
double y=double(p1.GetX()-p2.GetY());
len=sqrt(x*x+y*y);
}
//组合类的拷贝构造函数
Line::Line(Line &L):p1(L.p1),p2(L.p2)
{
cout<<"Line 拷贝构造函数被调用"<<endl;
len=L.len;
}


//line::~line(void)
//{
//	;
//}


Point::Point(Point &p) //拷贝函数的实现
{
X=p.X;
Y=p.Y;
cout<<"Point拷贝函数被调用"<<endl;
}


