// secref.cpp -- defining and using a reference
#include <iostream>
using namespace std;

class cs
{
    public:
        cs(int i): i_(i)  { cout << "cs(" << i <<") constructor!" << endl; }
        ~cs() { cout << "cs destructor,i(" << i_ << ")" << endl; }

        cs& operator=(const cs& other)
        {
            i_ = other.i_;
            cout << "cs operator=()" << endl;
            return *this;
        }

        int get_i() const { return i_; }
        void change(int i)  { i_ = i; }

    private:
        int i_;
};

cs get_cs()
{
    static int i = 0;
    return cs(i++);
}

int main()
{
     // ºÏ·¨
    (get_cs() = cs(2)).change(323);
    get_cs() = cs(2);// operator=()
    get_cs().change(32);

    return 0;
}