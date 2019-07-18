// rvref.cpp -- simple uses of rvalue references
#include <iostream>

inline double f(double tf) {return 5.0*(tf-32.0)/9.0;};
int main()
{
    using namespace std;
    double tc = 21.5;
    double && rd1 = 7.07;									//double a=7.7;
															//double & rd1 = a;
    double && rd2 = 1.8 * tc + 32.0;						//double b=1.8 * tc + 32.0;
															// double & rd2 = b;
    double && rd3 = f(rd2);									//double c=f(rd2);
															//double & rd3 = c;			
    cout << " tc value and address: " << tc <<", " << &tc << endl;
    cout << "rd1 value and address: " << rd1 <<", " << &rd1 << endl;
    cout << "rd2 value and address: " << rd2 <<", " << &rd2 << endl;
    cout << "rd3 value and address: " << rd3 <<", " << &rd3 << endl;
    // cin.get();
    return 0;
}
