
 #include <iostream>
 #include "Date.h"
 using namespace std;


int main()
{
    Date d1(2018, 5, 20);

    d1.showDate();

    Date d2 = d1;

    d2.showDate();

    return 0;
}