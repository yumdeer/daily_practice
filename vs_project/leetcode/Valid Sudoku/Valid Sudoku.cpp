#include <iostream>
#include <vector>
using namespace std;

//class Solution
//{
//public:
//	bool isValidSudoku(vector<vector<char> > &board)
//	{
//		int used1[9][9] = { 0 }, used2[9][9] = { 0 }, used3[9][9] = { 0 };
//
//		for (int i = 0; i < board.size(); ++i)
//			for (int j = 0; j < board[i].size(); ++j)
//				if (board[i][j] != '.')
//				{
//					int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
//					if (used1[i][num] || used2[j][num] || used3[k][num])
//						return false;
//					used1[i][num] = used2[j][num] = used3[k][num] = 1;
//				}
//
//		return true;
//	}
//};

auto fast_io = []() {
	std::ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); return 0; 
}();

class Solution
{
public:
	bool isValidSudoku(vector<vector<char> > &board)
	{
		int horizontal_x[9][9] = { 0 }, vertical_y[9][9] = { 0 }, sub_boxes[9][9] = { 0 };
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (board[i][j] != '.')
				{
					int num = board[i][j] - '0'-1;
					int k = i / 3 * 3 + j / 3;
				  if (horizontal_x[i][num] || vertical_y[j][num] || sub_boxes[k][num])
				  {
					  return false; 
				  }

				  horizontal_x[i][num]++;
				  vertical_y[j][num]++;
				  sub_boxes[k][num]++;
				}

			}
		return true;
	}
};

int main()
{
	vector <vector<char>> Sudoku ={ {'5','3','.','.','7','.','.','.','.'},
									{'6','.','.','1','9','5','.','.','.'},
									{'.','9','8','.','.','.','.','6','.'},
									{'8','.','.','.','6','.','.','.','3'},
									{'4','.','.','8','.','3','.','.','1'},
									{'7','.','.','.','2','.','.','.','6'},
	  								{'.','6','.','.','.','.','2','8','.'},
		 							{'.','.','.','4','1','9','.','.','5'},
									{'.','.','.','.','8','.','.','7','9'} };



	Solution m_Sudoku;
	cout << m_Sudoku.isValidSudoku(Sudoku);



	return 0;
}