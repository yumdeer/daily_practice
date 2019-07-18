#include <iostream>
#include <cstdlib>
#include "player.h"

using namespace std;

bool Player::isInChessBoard(int x, int y) const
{
	if (x < ROW - 1 && x > 0 && y < COL - 1 && y > 0)
		return true;
	else
		return false;
}

void Player::SetInfo(int no)
{
	cout << "Please No." << no << " input your name(q to quit): \n";
	getline(cin, m_name);
	if ("q" == m_name) {
		cout << "Bye Bye!" << endl;
		exit(-1);
	}
	//如果键盘输入有错误，清楚错误标志和环中去，重新输入用户名称
	while (!cin) {
		cin.clear();
		cin.ignore(2048, '\n');  //1024清除缓存区数据
		cout << "Please No." << no << " input your name agin(q to quit): " << endl;
		getline(cin, m_name);
		if ("q" == m_name) { cout << "Bye Bye!" << endl; exit(-1); }
	}
	cout << "Hello! " << this->m_name << ": Please Choose Your Chess Type '*' or '#': " << endl;
	cin >> m_ChessType;
	cin.get();
	//如果用户输入q，则退出程序
	if ('q' == m_ChessType) { cout << "Bye Bye" << endl; exit(-1); }
	//如果键盘输入有误，或者用户输入的棋子团不属于预其设的*或#，则要求用户重新输入
	while (!cin || (m_ChessType != '*' && m_ChessType != '#')) {
		cin.clear();
		cin.sync();
		cout << "Hello! " << this->m_name << ": Please Choose YOur Chess Type '*' or '#'(q to quit): \n";
		cin >> m_ChessType;
		cin.get();
		if ('q' == m_ChessType) { cout << "Bye Bye!" << endl; exit(-1); }
	}
}

//提示用户输入落子的坐标，并判断是否坐标在棋盘上，并把当前玩家选择的棋子图案字符，填充进当前输入的坐标
void Player::SetChess()
{
	char x;
	char y;

	cout << this->m_name << ": Please input Position (x, y) of your Chess. (-, -) to quit" << endl;
	cin >> x >> y;
	if ('-' == x && '-' == y) {
		cout << "Bye Bye!" << endl;
		exit(-1);
	}
#if 1
	if (x >= '0' && x <= '9') {
		m_x = (int)x - 48;
	}
	else if (isupper(x)) {
		m_x = (int)x - 55;
	}
	else if (islower(x)) {
		x = toupper(x);
		m_x = (int)x - 55;
	}
	if (y >= '0' && y <= '9') {
		m_y = (int)y - 48;
	}
	else if (isupper(y)) {
		m_y = (int)y - 55;
	}
	else if (islower(y)) {
		y = toupper(y);
		m_y = (int)y - 55;
	}
	m_x = m_x + (1 * m_x + 1);
	m_y = m_y + (1 * m_y + 1);
#endif
	//如果键盘数据有错误或者输入的坐标已经存在其他棋子
	while (!cin || m_ptBoard->cSquare[m_x][m_y] != ' ') {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << this->m_name << ": Please Input Position (x, y) of Your Chess.(-, -) to quit" << endl;
		cin >> x >> y;
		//根据所输入进来的行、列角标找出相应的落子位置，并将操作玩家所对应的棋子符号填充到该位置（不区分大小写）
		if ('-' == x && '-' == y) {
			cout << "Bye Bye!" << endl;
			exit(-1);
		}
		if (x >= '0' && x <= '9') {
			m_x = (int)x - 48;
		}
		else if (isupper(x)) {
			m_x = (int)x - 55;
		}
		else if (islower(x)) {
			x = toupper(x);
			m_x = (int)x - 55;
		}
		if (y >= '0' && y <= '9') {
			m_y = (int)y - 48;
		}
		else if (isupper(y)) {
			//cout << "m_y" << m_y << endl;
			m_y = (int)y - 55;
			//cout << "m_y" << m_y << endl;
		}
		else if (islower(y)) {
			y = toupper(y);
			m_y = (int)y - 55;
		}
		m_x = m_x + (1 * m_x + 1);
		m_y = m_y + (1 * m_y + 1);
	}
	//填充进当前输入的坐标对应的棋盘的二维数组单元中
	if (isInChessBoard(m_x, m_y)) {
		m_ptBoard->cSquare[m_x][m_y] = m_ChessType;
	}
}

//判断是否在水平方向上形成5子连线
bool Player::HisLine(int x, int y) const
{
	int num = 0;
	for (int i = -8; i <= 8; i += 2) {
		if (isInChessBoard(x, y + i) && m_ptBoard->cSquare[x][y + i] == m_ChessType) {
			num++;
			if (num == 5)
				return true;
		}
		else
			num = 0;
	}
	return false;
}

//判断是否在垂直方向上满足5子连线
bool Player::VisLine(int x, int y) const
{
	int num = 0;
	for (int i = -8; i <= 8; i += 2) {
		//如果当前坐标统一行的其他坐标在棋盘上，且其他坐标的图案和当前玩家的棋子图案相同，计数器雷家
		if (isInChessBoard(x + i, y) && m_ptBoard->cSquare[x + i][y] == m_ChessType) {
			num++;
			//连续同一行有5个坐标点的图案相同时，满足赢棋的条件
			if (num == 5)
				return true;
		}
		else
			num = 0;
	}
	return false;
}

//判断是否在自左上角到右下角的方向上满足5子连线
bool Player::LtoBottomisLine(int x, int y) const
{
	int num = 0;
	for (int i = -8; i <= 8; i += 2) {
		//如果当前坐标沿自左上角到右下角的对角线方向的其他
		if (isInChessBoard(x + i, y + i) && m_ptBoard->cSquare[x + i][y + i] == m_ChessType) {
			num++;
			if (num == 5)
				return true;
		}
		else
			num = 0;
	}
	return false;
}

//判断是否在自左下角到右上角的方向上满足5子连线
bool Player::LtoTopisLine(int x, int y) const
{
	int num = 0;
	for (int i = -8; i <= 8; i += 2) {
		if (isInChessBoard(x - i, y + i) && m_ptBoard->cSquare[x - i][y + i] == m_ChessType) {
			num++;
			if (num == 5)
				return true;
		}
		else
			num = 0;
	}
	return false;
}

bool Player::isWin()const
{
	return (HisLine(m_x, m_y) || VisLine(m_x, m_y) || LtoBottomisLine(m_x, m_y) || LtoTopisLine(m_x, m_y)) ? true : false;
}
