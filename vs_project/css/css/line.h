#pragma once

class Point
{
public :
Point(int xx=0,int yy=0){X=xx;Y=yy;}
Point(Point &p);
int GetX() {return X;}
int GetY() {return Y;}
private:
int X,Y;
};


class Line 
{
public:
Line(Point xp1,Point xp2);
Line(Line &);
double GetLen(){return len;}
private:
Point p1,p2;
double len;
};