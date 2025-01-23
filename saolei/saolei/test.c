#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*************************\n");
	printf("********1.play***********\n");
	printf("********0.exit***********\n");
	printf("*************************\n");
}



void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化数组,放置0和*
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');

	//打印棋盘
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);

	setmine(mine, ROW, COL);
    displayboard(mine, ROW, COL);

	findmine(mine,show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("结束游戏");
			break;
		default:
			printf("输入错误,请重试\n");
		}
	} while (input);
	return 0;
}