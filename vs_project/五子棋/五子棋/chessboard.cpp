#include <iostream>
#include <cstdlib>
#include "chessboard.h"

using namespace std;

//构造函数
ChessBoard::ChessBoard()
{
	for (int i = 1; i <= ROW - 2; i += 2) {     //将棋盘隔行放入‘-’.
		for (int j = 1; j <= COL - 2; j += 2) {
			cSquare[i][j] = ' ';
			cSquare[i][j + 1] = '|';
			cSquare[i + 1][j] = '-';
			cSquare[i + 1][j + 1] = '-';
		}
	}
	//围出棋盘的四周
	for (int j = 0; j < COL; j++)
		cSquare[0][j] = cSquare[ROW - 1][j] = '-';
	for (int i = 0; i < ROW; i++)
		cSquare[i][0] = cSquare[i][COL - 1] = '|';

	//空处棋盘落子空间
	cSquare[ROW][0] = ' ';
	cSquare[0][COL] = ' ';
	//在最后以行打印出行、列下标0，1,2 ... A，B，C ...
	for (int i = 1; i < 20; i += 2) {
		cSquare[i][COL] = i / 2 + 48;
		cSquare[i + 1][COL] = ' ';
		cSquare[ROW][i] = i / 2 + 48;
		cSquare[ROW][i + 1] = ' ';
	}
	for (int j = 21; j < COL; j += 2) {
		cSquare[ROW][j] = j / 2 + 55;
		cSquare[ROW][j + 1] = ' ';
	}
	for (int j = 21; j < ROW; j += 2) {
		cSquare[j][COL] = j / 2 + 55;
		cSquare[j + 1][COL] = ' ';
	}
}
void ChessBoard::show()
{
	system("clear");       //清除缓存区数据
	//显示棋盘
	for (int i = 0; i <= ROW; ++i) {
		for (int j = 0; j <= COL; ++j)
			cout << cSquare[i][j] << ' ';
		cout << endl;
	}
}
