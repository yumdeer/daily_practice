#include <iostream>
#include "player.h"
#include "chessboard.h"

using namespace std;

int main()
{
	ChessBoard board;
	Player playerA;
	playerA.SetInfo(1);
	playerA.attachToBoard(&board);
	Player playerB;
	playerB.SetInfo(2);
	playerB.attachToBoard(&board);
	board.show();
	while (1) {
		//玩家1放下一粒棋子
		playerA.SetChess();
		if (playerA.isWin()) {
			//board.show();
			cout << playerA.WinName() << " Winner! Game Over!!\n";
			break;
		}
		//显示当前棋盘中所有棋子的位置。
		board.show();

		//玩家2放下一粒棋子
		playerB.SetChess();
		if (playerB.isWin()) {
			cout << playerB.WinName() << " Winner! Game Over!!\n";
			break;
		}
		board.show();
	}
	//运行出错
	return 1;
}
