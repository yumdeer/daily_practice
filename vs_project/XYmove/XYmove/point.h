#ifndef _POINT_H
#define _POINT_H

class point
{
public:
	point();
	point(int x,int y);
	~point();
	void move(int newX,int newY);
	int getX()const{return x;}
	int getY() const{return y;} 
    static void showCount();
private:
	int x,y;
};

#endif