#include "Pair.h"
typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine :private PairArray, private string
{
private:
	int	yrs;
public:
	Wine(){}
	Wine(const char *l, int y, const int yr[], const int bot[]);
	Wine(const char *l, int y);
	void GetBottles();
	string& Label();
	void Show()const;
	int sum()const;
};

