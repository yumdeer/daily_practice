#include <iostream>
#include <string>
using namespace std;

#define testt(aa, bb, cc) \
{ \
    aa, bb, cc \
}

struct test {
    int a;
    char b;
    string c;
};

int main()
{
    test t = { 1, 'q', "hello" };
    cout << t.a << t.b << t.c << endl;

    static const test tt = testt(1, 'q', "hello");
    cout << tt.a << tt.b << tt.c << endl;
};