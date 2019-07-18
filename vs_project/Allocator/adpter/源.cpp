#include <iostream>
#include <vector>

using namespace std;

template <class Container>
class my_back_insert_iterator {
protected:
	Container* container;
public:
	explicit my_back_insert_iterator(Container& x) : container(&x) {}
	my_back_insert_iterator<Container>&
		operator=(const typename Container::value_type& value) {
		container->push_back(value);
		return *this;
	}
};

int main()
{
	vector<int> vec;
	my_back_insert_iterator< vector<int> > back_insert(vec);

	back_insert = 1;
	back_insert = 2;
	back_insert = 3;
	back_insert = 4;

	vector<int>::iterator iter = vec.begin();
	for (; iter != vec.end(); ++iter)
		cout << *iter << endl;

	return 0;
}
