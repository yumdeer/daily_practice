#pragma once
#ifndef _CHESSBOARD_H_
#define _CHESSBOARD_H_

#include <iostream>

using namespace std;

class ChessBoard    //棋盘
{
public:
	enum { ROW = 31, COL = 31 };    //整个棋盘所占的行数和列数
	char cSquare[ROW + 1][COL + 1];      //定义一个字符数组，用来打印棋盘
public:
	ChessBoard();                //棋盘构造函数
	void show();                 //棋盘的显示
	~ChessBoard() {}              //析构函数
};
#endif

