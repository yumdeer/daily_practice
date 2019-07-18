#pragma once

#include "chessboard.h"
class snake :public chessboard
{
public:
	int zb[2][100];
	long start;
	int head, tail, grade, score, gamespeed, length, timeover, x, y;
	char direction;
	snake();
	void move();
};