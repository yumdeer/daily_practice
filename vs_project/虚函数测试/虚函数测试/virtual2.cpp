#include <iostream>
using namespace std;
class base
{
public:
	int func() {
		int ret=0;
		cout << "base func" << endl;
		return ret;
	}
	int func(int i) {
		int ret = 0;
		cout << "base func()" << endl;
		return ret;
	}
	virtual int vfunc0(int i) = 0;
	virtual int vfunc1(int i) {
		cout << "base virtual1" << endl;
		return 0;
	}
};

class derived :public base 
{
public:
	virtual int vfunc0(int i) {
		cout << "derived virtual0" << endl;
		return 0;
	}
	virtual int vfunc1(int i) {
		cout << "derived virtual1" << endl;
		return 0;
	}
};

int main() {
	base *bs = new derived();
	int a = bs->func();
	int b = bs->func(a);
	bs->vfunc1(b);
	bs->vfunc0(-1);

	return 0;
}