#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;

class BogoSorter {
public:
	std::vector<int>* bogoSort(std::vector<int>* a);
	std::vector<int> shuffle(std::vector<int> a);
	void shufftest();
};


vector<int>* BogoSorter::bogoSort(vector<int>* a) {

	if (a->empty()) {
		return a;
	}

	while (true) {
		bool sorted = false;
		for (int i = 1; i < a->size(); i++) {
			if (a->at(i) < a->at(i - 1)) {
				*a = shuffle(*a);
				break;
			}
			if (i == a->size() - 1) {
				sorted = true;
			}
		}
		if (sorted) {
			break;
		}
	}

	return a;
}

void BogoSorter::shufftest() {
	vector<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;

	a = shuffle(a);
	a = shuffle(a);

	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
}

vector<int> BogoSorter::shuffle(vector<int> a) {

	vector<int> b(a.size());
	vector<bool> c(a.size());

	c.at(0) = false;

	for (int i = 0; i < a.size(); i++) {
		c[i] = false;
	}

	random_device rd;

	int count = 0;
	bool allset = false;

	while (true) {
		int roll = rd() % a.size();
		//cout << "Rand: " << roll << endl;
		if (!c[roll]) {
			b[count++] = a[roll];
			c[roll] = true;
		}
		else {
			//cout << "New check" << endl;
			for (int i = 0; i < c.size(); i++) {
				//cout << "i: " << i << " c[i]: " << c[i] << " b[i]: " << b[i] << " count: " << count << endl;
				if (!c[i]) {
					//cout << "inne i allsetne" << endl;
					allset = true;
				}
			}
			if (!allset) {
				//cout << "prover a breake" << endl;
				break;
			}
			allset = false;
		}
	}
	//cout << "Returning from shuffle" << endl;
	return b;
}

int main(int argc, const char * argv[])
{
    BogoSorter a;
    vector<int> b{2, 1, 3, 6, 5, 7};
    vector<int> *c;
    
    cout << "Clocks per sec: " << CLOCKS_PER_SEC << endl;
    
    clock_t start = clock();
    
    c = a.bogoSort(&b);
    
    double end = (double)(clock() - start)/CLOCKS_PER_SEC;
    
    
    for(int i = 0; i < b.size(); i++){
        cout << c->at(i) << " ";
    }
	cout << endl;
    
    cout << "Sorted the array of " << b.size() << " elements in " << end << " seconds." << endl;
    
    return 0;
}