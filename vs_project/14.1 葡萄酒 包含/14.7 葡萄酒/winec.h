#include "Pair.h"
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;

class Wine                     //名字和 种类
{
private:
	PairArray yb;
	string fullname;
	int yrs;
public:
	Wine(){}
	Wine(const char *l, int y, const int yr[], const int bot[]);
	Wine(const char *l, int y);
	void GetBottles();
	string& Label();
	void Show()const;
	int sum()const;
};