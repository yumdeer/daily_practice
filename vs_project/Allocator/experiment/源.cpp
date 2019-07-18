#include "iostream"
#include "string"
#include "deque"
#include "vector"
#include "iterator"
#include "algorithm"

using namespace std;

void Show(int n)
{
	cout << n << " ";
}

int main()
{
	//int arr[5] = {5,2,3,4,5};
	//sort(arr, arr + 5);
	//for (int x : arr)
	//	cout << x << " ";
	//cout << endl;

	int cast[5] = { 1,2,3,4,5 };
	vector<int> dice(5);
	deque<int>  deque(5);
	copy(cast, cast + 5, dice.begin());
	copy(cast, cast + 5, deque.begin());
	for(int x: dice)
	  cout << x << " ";
	for (int x : deque)
		cout << x << " ";
	cout << endl;

	vector<int>::iterator ri;
	for (ri = dice.begin(); ri != dice.end(); ++ri)
		cout << *ri << " ";
	cout << endl;

	ostream_iterator<int, char> out_iter(cout, " ");
	copy(dice.begin(), dice.end(), out_iter); //将dice容器的整个区间复制到输出流
	cout << endl;

	vector<int>::reverse_iterator ro;
	for (ro = dice.rbegin(); ro != dice.rend(); ++ro)
		cout << *ro << " ";
	cout << endl;
	for_each(dice.rbegin(), dice.rend(), Show);
	cout << endl;



	return 0;
}