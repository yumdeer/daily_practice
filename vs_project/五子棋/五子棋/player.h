#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <string>
#include "chessboard.h"

using namespace std;

class Player
{
private:
	string m_name;
	char m_ChessType;
	int m_x;
	int m_y;
	ChessBoard * m_ptBoard;
public:
	enum { ROW = 31, COL = 31 };
	Player() :m_name("no_name"), m_ChessType('?'), m_x(0), m_y(0), m_ptBoard(NULL) {}
	void attachToBoard(ChessBoard* ptBoard) { m_ptBoard = ptBoard; }
	bool isInChessBoard(int x, int y) const;  //棋子是否罗在棋盘内
	bool HisLine(int x, int y) const;   //判断水平方向是否连够5个棋子
	bool VisLine(int x, int y) const;   //判断竖直方向是否连够5个棋子
	bool LtoBottomisLine(int x, int y) const;  //判断自左上角到右下角是否连够5个棋子
	bool LtoTopisLine(int x, int y) const;     //判断子右上角到左下角是否连够5个棋子
	bool isWin() const;                //是否赢
	string WinName() const { return m_name; }     //赢者姓名
	void SetInfo(int no);
	void SetChess();              //把玩家所选的符号放进所选为值
	~Player() {}
};

#endif
