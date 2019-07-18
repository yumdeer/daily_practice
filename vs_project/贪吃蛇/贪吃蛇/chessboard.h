#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#define H 22
#define W 22
using namespace std;

class chessboard
{
public:
	char qp[H][W];
	int i, j, x1, y1;
	chessboard();
	//~chessboard();
	void food();
	void prt(int grade, int score, int gamespeed);
};

#endif