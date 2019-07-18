#include <iostream>
#include <string>

using namespace std;

class A {
public:
    void func1(string prefix) {
        cout << prefix << "A::func1" << endl;
    }
    void func2(string prefix) {
        cout << prefix << "A::func2" << endl;
        func1(prefix + "  ");
    }
    void func3(string prefix) {
        cout << prefix << "A::func3" << endl;
    }
};

class B: public A {
public:
    void func1(string prefix) {
        cout << prefix << "B::func1" << endl;
    }
    void func3(string prefix) {
        cout << prefix << "B::func3" << endl;
        A::func3(prefix + "  ");
        func1(prefix + "  ");
        func2(prefix + "  ");
    }
};

int main() {
    B b;

    b.func3("");
}