#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

//找规律 a[i][j]与a[n-j-1][i]互换
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int matrix_num = matrix.size();
		vector<vector<int>> matrix_copy (matrix_num,vector<int>(matrix_num)) ;
		matrix_copy.insert(matrix_copy.begin(),matrix.begin(),matrix.end());
			

		for (int i = 0; i < matrix_num; i++)
			for (int j = 0; j < matrix_num; j++)
				matrix[i][j] = matrix_copy[matrix_num - j-1][i];
	}
};

///*四个角互换，然后收缩*/
//void rotate(vector<vector<int>>& matrix) {
//	int n = matrix.size();
//	int a = 0;
//	int b = n - 1;
//	while (a < b) {
//		for (int i = 0; i < (b - a); ++i) {
//			swap(matrix[a][a + i], matrix[a + i][b]);
//			swap(matrix[a][a + i], matrix[b][b - i]);
//			swap(matrix[a][a + i], matrix[b - i][a]);
//		}
//		++a;
//		--b;
//	}
//}

int main()
{
	vector <vector<int>> Rotate = { {1,2,3},
									 {4,5,6},
									 {7,8,9}
									};
	Solution m_Sudoku;
	m_Sudoku.rotate(Rotate);




	return 0;
}