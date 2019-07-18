#include <iostream>  
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>>  v1(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cin >> v1[i][j];
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cout << v1[i][j] << endl;
	return 0;
}




#include <iostream>
#include <string>
#include <vector>


int main() {

	int N, M;
	std::vector<std::vector<int>> array(M, std::vector<int>(N));
	N = 3, M = 3;


	std::vector<int> vec0 = {
		1,2,3,4
	};
	for (auto n : vec0)
		std::cout << n << " ";

	std::cout << std::endl;

	std::vector<std::vector<int>> vec = {
	{1, 1},
	{3, 3},
	{2, 2}
	};

	for (int i = 0; i < 3; i++)
		for (int ji = 0; j < 3; ji++)
			std::cout << vec[i][j] << " ";

	std::cout << std::endl;
}