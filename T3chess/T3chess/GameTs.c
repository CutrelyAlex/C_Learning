/*
井字棋初学作业
By D菌
QQ:2470819243
*/


#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1

int input;//菜单选择输入变量
char ret = 0;//对局情况
char board[ROW][COL] = { 0 };//棋盘二维数组数据 ROW行 COL列

//菜单页面显示
void menu ()
{
	printf ("\n******************井字棋************************\n");
	printf ("**** 0. 退出 1. 和自己玩  2.和电脑(傻的)玩 *****\n");  //选择2与电脑玩 选择1与玩家玩
	printf ("*******C语言初学作业--制作人:D菌****************\n");
	printf ("请选择:>");
}

//菜单选择
void menu_chose ()
{
	scanf ("%d", &input);
	switch (input)
	{
	case 2:
	case 1:
		game_start ();//启用游戏
		break;
	case 0:
		printf ("退出游戏\n");
		break;
	default:
		system ("cls");
		printf ("无效命令,请重新输入.\n");
	}
}


//玩家与电脑
void Player_VS_COM ()
{
	while (input == 2)
	{
		//玩家A下棋
		PlayerA_Move (board, ROW, COL);  system ("cls");
		Display_Board (board, ROW, COL);
		ret = IsWin (board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		Computer_Move (board, ROW, COL);  system ("cls");
		Display_Board (board, ROW, COL);
		ret = IsWin (board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	//对局结果判断
	if (ret == 'A')
	{
		printf ("玩家赢\n");
	}
	else if (ret == 'B')
	{
		printf ("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf ("平局\n");
	}
}

//玩家与玩家
void Player_VS_Player ()
{
	while (input == 1)
	{
		//玩家A下棋
		ret = PlayerA_Move (board, ROW, COL);  system ("cls");
		Display_Board (board, ROW, COL);
		ret = IsWin (board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}

		//玩家B下棋
		PlayerB_Move (board, ROW, COL);  system ("cls");
		Display_Board (board, ROW, COL);
		ret = IsWin (board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	//对局结果判断
	if (ret == 'A')
	{
		printf ("玩家A赢\n");
	}
	else if (ret == 'B')
	{
		printf ("玩家B赢\n");
	}
	else if (ret == 'Q')
	{
		printf ("平局\n");
	}
}


//游戏算法实现
void game_start ()
{
	Init_Board (board, ROW, COL); //初始化棋盘
	Display_Board (board, ROW, COL); //打印棋盘(棋盘数组,行,列)
	Player_VS_COM (); //玩家与电脑
	Player_VS_Player ();//玩家与玩家
}

//测试模块
void gamego ()
{
	srand ((unsigned int)time (NULL));
	do
	{
		menu ();//菜单
		menu_chose ();//菜单选择
	} while (input);
}

int main ()
{
	gamego ();
	return 0;
}