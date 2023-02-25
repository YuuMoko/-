#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
//创建棋盘
#define ROW 20
#define COL 20 
//控制方向键
int currow = 0;
int curcol = 0;
int who = 1;//1：玩家1，2:玩家2
int data[ROW][COL] = { 0 };
int player = 0;
int 玩家;
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define HERE ' '
void DrawQiPan() {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			printf("＋");
		}printf("\n");
	}
}      //棋盘的绘制（爷已经绘好了）创建棋盘函数
void MoveCursor(int row, int col) {
	HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);//获取cmd的句柄
	COORD co;
	co.X = col * 2;
	co.Y = row;
	SetConsoleCursorPosition(hCmd, co);
}//移动光标函数
void HereOne() {
	if (data[currow][curcol] == 0) {
		player = who;
		玩家 = who;
		if (who == 1) {
			printf("●");
			who = 2;
		}
		else {
			printf("○");
			who = 1;
		}	data[currow][curcol] = who;
	}
}//落子函数
void KeyPress(char key) {
	switch (key) {
	case UP:
		--currow;
		MoveCursor(currow, curcol);
		break;
	case DOWN:
		if (currow < ROW - 1)
			++currow;
		MoveCursor(currow, curcol);
		break;

	case LEFT:
		--curcol;
		MoveCursor(currow, curcol);
		break;
	case RIGHT:
		if (curcol < COL - 1)
			++curcol;
		MoveCursor(currow, curcol);
		break;
	case HERE:
		HereOne();
		break;
	}

}//处理按键的函数
int CheckWin(int player)
{
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (data[i][j] == who) {
				int n = 0;
				for (int k = 1; k <= 4; ++k) {
					if (data[i][j] == data[i][j + k]) {
						++n;
					}
				}if (n == 4)return 1;//横向检测
			}

		}
	}
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (data[i][j] == who) {
				int n = 0;
				for (int k = 1; k <= 4; ++k) {
					if (data[i][j] == data[i + k][j]) {
						++n;
					}
				}if (n == 4)return 1;//纵向检测
			}
		}
	}
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (data[i][j] == who) {
				int n = 0;
				for (int k = 1; k <= 4; ++k) {
					if (data[i][j] == data[i + k][j + k]) {
						++n;
					}
				}if (n == 4)return 1;//右斜检测
			}
		}
	}
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (data[i][j] == who) {
				int n = 0;
				for (int k = 1; k <= 4; ++k) {
					if (data[i][j] == data[i + k][j - k]) {
						++n;
					}
				}if (n == 4)return 1;//左斜检测
			}
		}
	}

	return 0;
}//检查输赢函数

int main()
{
	system("color 0A");//改背景颜色
	DrawQiPan();
	MoveCursor(currow, curcol);
	while (666)
	{
		char key = getch();
		KeyPress(key);
		int ret = CheckWin(player);
		if (ret) {
			if (player) {
				MoveCursor(20, 3);
				printf("恭喜玩家%d胜利！", 玩家);
				break;
			}
		}
	}


	return 0;
}