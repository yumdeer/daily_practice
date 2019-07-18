#include "snake.h"

snake::snake()
{
	cout << "\n\n\t\tThe game is about to begin!" << endl;
	for (i = 3; i >= 0; i--)
	{
		start = clock();
		while (clock() - start <= 1000);
		system("cls");
		if (i > 0)
			cout << "\n\n\t\tCountdown:" << i << endl;
	}
	for (i = 1; i <= 3; i++)
		qp[1][i] = '*';
	qp[1][4] = '@';
	for (i = 0; i < 4; i++)
	{
		zb[0][i] = 1;
		zb[1][i] = i + 1;
	}
}
void snake::move()
{
	score = 0;
	head = 3, tail = 0;
	grade = 1, length = 4;
	gamespeed = 500;
	direction = 77;
	while (1)
	{
		timeover = 1;
		start = clock();
		while ((timeover = (clock() - start <= gamespeed)) && !_kbhit()); //_kbhit()检查控制台是否有键盘输入,按下返回非0值
		if (timeover)
		{
			_getch();					//从控制台获取一个没有echo的字符，getch() 只能得到可打印字符
			direction = _getch();		//对于上下左右和别的一些扩展键使用getch()会先返回一个0，再使用一次getch()这时返回的才是扫描码
		} 
		switch (direction) //↑↓←→箭头
		{
		case 72: x = zb[0][head] - 1; y = zb[1][head]; break;
		case 80: x = zb[0][head] + 1; y = zb[1][head]; break;
		case 75: x = zb[0][head]; y = zb[1][head] - 1; break;
		case 77: x = zb[0][head]; y = zb[1][head] + 1; break;
		}
		if (x == 0 || x == 21 || y == 0 || y == 21)
		{
			cout << "\tGame over!" << endl; break;
		}
		if (qp[x][y] != ' ' && !(x == x1 && y == y1))
		{
			cout << "\tGame over!" << endl; break;
		}
		if (x == x1 && y == y1)
		{
			length++;
			score = score + 100;
			if (length >= 8)
			{
				length -= 8;
				grade++;
				if (gamespeed >= 200)
					gamespeed = 550 - grade * 50;
			}
			qp[x][y] = '@';
			qp[zb[0][head]][zb[1][head]] = '*';
			head = (head + 1) % 100;
			zb[0][head] = x;
			zb[1][head] = y;
			food();
			prt(grade, score, gamespeed);
		}
		else
		{
			qp[zb[0][tail]][zb[1][tail]] = ' ';
			tail = (tail + 1) % 100;
			qp[zb[0][head]][zb[1][head]] = '*';
			head = (head + 1) % 100;
			zb[0][head] = x;
			zb[1][head] = y;
			qp[zb[0][head]][zb[1][head]] = '@';
			prt(grade, score, gamespeed);
		}
	}
}