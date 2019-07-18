//#include "file1.h"
//
//int main()
//{       extern char* hello;
//        printStr();
//        printf("%s\n", hello);
//        return 0;
//}

#include <iostream>
using namespace  std;

int A1()
{
static int a = 10;
a++;
cout << a << endl;
return a;
}

int main(int argc, const char * argv[]) {
A1();
int a=0;
cout << a <<endl;
A1();
A1();
int a1=A1();
cout << "a1="<< a1 << endl;
return 0; 
}