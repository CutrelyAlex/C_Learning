/*
2048项目
外部库:EasyX图形编程库
*/
#include "define.h"
#include "Game.h"
#include "Menu.h"
#include<stdio.h>
extern void game_draw ();
extern int check ();
void game_start ()
{
	init_game ();//游戏初始化
	init_num ();//初始化数字
	game_draw ();
	int flag = 1;
	int button = 0;
	while (flag != -1)
	{
		button = key_con ();
		if (button != -1)
		{
			flag = check ();
			blockGenerate ( flag );
			game_draw ();
		}
	}
	about_menu ();
}
int main ()
{
	main_menu ();//主菜单
	//格子,数字绘制
	return 0;
}