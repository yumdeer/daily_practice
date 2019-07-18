#include <iostream>
#include "point.h"
using namespace std;

point::point():x(0),y(0){
cout << "Default Constructor Called" << endl;
}
point::point(int x,int y):x(x),y(y)
{
	cout << "Constructor Called" << endl;
}
point::~point(){
cout << "Destructor Called" << endl;
}

void point::move(static int newX,static int newY)
{
	cout << "Moving the point to (" << newX << "," << newY << ")" << endl;
	x=newX;
	y=newY;
}
