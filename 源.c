#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
//��������
#define ROW 20
#define COL 20 
//���Ʒ����
int currow = 0;
int curcol = 0;
int who = 1;//1�����1��2:���2
int data[ROW][COL] = { 0 };
int player = 0;
int ���;
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define HERE ' '
void DrawQiPan() {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			printf("��");
		}printf("\n");
	}
}      //���̵Ļ��ƣ�ү�Ѿ�����ˣ��������̺���
void MoveCursor(int row, int col) {
	HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡcmd�ľ��
	COORD co;
	co.X = col * 2;
	co.Y = row;
	SetConsoleCursorPosition(hCmd, co);
}//�ƶ���꺯��
void HereOne() {
	if (data[currow][curcol] == 0) {
		player = who;
		��� = who;
		if (who == 1) {
			printf("��");
			who = 2;
		}
		else {
			printf("��");
			who = 1;
		}	data[currow][curcol] = who;
	}
}//���Ӻ���
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

}//�������ĺ���
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
				}if (n == 4)return 1;//������
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
				}if (n == 4)return 1;//������
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
				}if (n == 4)return 1;//��б���
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
				}if (n == 4)return 1;//��б���
			}
		}
	}

	return 0;
}//�����Ӯ����

int main()
{
	system("color 0A");//�ı�����ɫ
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
				printf("��ϲ���%dʤ����", ���);
				break;
			}
		}
	}


	return 0;
}