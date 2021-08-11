#include "Menu.h"
#include<stdio.h>
#include<graphics.h> //图形库头文件

//点击转到函数
void menu_choice ( int choice )
{
	if (choice == 0)
		exit ( 1 );
	else if (choice == 1)
		game_start ();
	else if(choice ==2)
		about_menu ();
}


//检查主菜单点击
void check_click ()
{
	ExMessage mouse = getmessage();
	if (mouse.x >= 90 && mouse.x <= 200 && mouse.y <= 350 && mouse.y >= 250 && mouse.message == WM_LBUTTONDOWN)
		menu_choice ( 0 );//点击退出游戏
	if (mouse.x >= 90 && mouse.x <= 200 && mouse.y <= 260 && mouse.y >= 140 && mouse.message == WM_LBUTTONDOWN)
		menu_choice ( 1 );//点击启动游戏
	if (mouse.x >= 90 && mouse.x <= 200 && mouse.y <= 450 && mouse.y >= 350 && mouse.message == WM_LBUTTONDOWN)
		menu_choice ( 2 );//点击关于
}


//主菜单
void main_menu ()
{
		//创建窗口，确定窗口大小
		initgraph ( WIDTH, HEIGHT /*,SHOWCONSOLE */);
		setbkcolor (RGB( 188, 174, 160 ));//设置背景颜色
		cleardevice ();
		settextcolor ( BLACK );
		settextstyle ( 32, 0, "黑体" );
		outtextxy ( 100, 50, "2048游戏作业 （WASD控制）" );
		settextstyle ( 26, 0, "楷体" );
		settextcolor ( BLACK );
		outtextxy ( 100, 200, "开始游戏" );
		outtextxy ( 100, 300, "退出游戏" );
		outtextxy ( 100, 400, "关于" );
		do
		{
			check_click ();
		} while (1);
}

//关于窗口
void about_menu ()
{
	initgraph ( WIDTH, HEIGHT/*, SHOWCONSOLE*/ );
	setbkcolor ( RGB ( 221, 225, 206 ) );//设置背景颜色
	cleardevice ();
	settextcolor ( BLACK );
	settextstyle ( 23, 0, "楷体" );
	outtextxy ( 50, 50, "这是一份C++作业,2021年8月11日制作,QQ:2470819243" );
	outtextxy ( 50, 75, "游戏胜利或失败时候也会转到此处" );
	outtextxy ( 50, 100, "游戏界面的RGB颜色取自其他2048游戏" );
	outtextxy ( 100, 400, "返回" );
	do
	{
		ExMessage mouse = getmessage ();
		if (mouse.x >= 90 && mouse.x <= 150 && mouse.y <= 450 && mouse.y >= 350 && mouse.message == WM_LBUTTONDOWN)
			main_menu();//点击返回,返回主菜单
	} while (1);
}