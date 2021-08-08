/*
作业:贪吃蛇游戏
2021年8月8日
ByD菌
QQ:2470819243.
*/
#include"Game.h"
#define HEIGHT  1440  //窗口高度
#define WIDTH  960   //窗口宽度

extern void GameInit ();
extern void GameSnake ();
extern void SnakeMove ();
extern void GetCon ();
extern void getpoint ();
void PlayGame ();

//菜单
int Menu ()
{
	MOUSEMSG mouse;//鼠标变量
	initgraph ( HEIGHT, WIDTH );
	setbkcolor ( WHITE );//背景颜色
	cleardevice ();
	setfillcolor ( LIGHTBLUE );//设置选项框背景颜色
	fillrectangle ( 200, 320, 650, 400 );
	setbkmode ( TRANSPARENT );
	settextstyle ( 14, 0, "楷体" );//文字大小
	outtextxy ( 250, 322, "贪吃蛇游戏,ByD菌" );
	outtextxy ( 250, 340, "作业，实际边界与窗口大小不同(由于Windows系统自动调整)" );
	fillrectangle ( 200, 140, 600, 160 );
	fillrectangle ( 200, 440, 600, 460 );
	settextstyle ( 15, 0, "楷体" );//文字大小
	outtextxy ( 250, 142, "开始游戏(点击ESC暂停)" );
	outtextxy ( 250, 442, "退出游戏" );
	while (1)
	{
		ExMessage mouse = getmessage ();//获取鼠标数据
		if (mouse.x >= 200 && mouse.x <= 600 && mouse.y >= 140 && mouse.y <= 160)
		{
			if(mouse.message==WM_LBUTTONDOWN)
				return 1;
		}
		else if (mouse.x >= 200 && mouse.x <= 600 && mouse.y >= 400 && mouse.y <= 460)
		{
			if (mouse.message == WM_LBUTTONDOWN)
				return 0;
		}
	}
}

void GameStart ()
{
	int ret = Menu ();//菜单
	if (ret == 1)
	{
		GameInit ();//初始化游戏
		PlayGame ();//载入游戏
	}
}
void PlayGame ()
{
	while (1)
	{
		SnakeMove (); //移动蛇
		GameSnake ();  //绘制蛇和点数
		GetCon ();    //获取键盘控制
		getpoint ();
		Sleep ( 20 );
	}
}
int main ()
{
	GameStart (); //启动游戏模块
	return 0;
}
