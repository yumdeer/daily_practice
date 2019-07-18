#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


vector<int> powerfulIntegers(int x, int y, int bound) {
	vector<int> vec ;
	int i_x = 0, i_y = 0;int  x_new = x, y_new = y; int sum = 0;
	while (x < bound && x !=1 )
	{
		x *= x_new; i_x++;
	}
	while (y < bound && y != 1)
	{
		y *= y_new; i_y++;
	}
	for (int i = 0; i <= i_x; i++)
		for (int j = 0; j <= i_y; j++)
		{
			if (pow(x_new, i) + pow(y_new, j) <= bound)
			{
				int pop_ = (int ) (pow(x_new, i) + pow(y_new, j));
				vec.push_back(pop_);
			}
		}
	sort(vec.begin(), vec.end());
	vector<int> ::iterator vec_iter =unique(vec.begin(), vec.end());
	vec.erase(vec_iter, vec.end());

	return vec;
}


int main()
{
	powerfulIntegers(1,2,100);

	return 0;
}