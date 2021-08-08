#include "Game.h"
#include <graphics.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
//多媒体接口
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define SNAKE_MAXSIZE 500 //蛇最大节数
#define HEIGHT  1440   //窗口高度
#define WIDTH  860   //窗口宽度

//结构体蛇
struct ASnake
{
	int size;//节数值
	int dir;//方向
	int speed;//速度
	POINT coor[SNAKE_MAXSIZE];//蛇坐标	坐标结构体 x,y
}snake;

//结构体点数
struct Point
{
	int x;
	int y;
	int r; //半径
	bool flag; //点数是否被获取
}point;

enum DIR
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
};

void GameInit ()
{
	//播放bgm   路径:./res/a.mp3
	mciSendString ( "open ./res/a.mp3 alias BGM", 0, 0, 0 );
	mciSendString ( "play BGM repeat", 0, 0, 0 );
	srand (GetTickCount()+(int)time(NULL));//随机数种子,开机时间tick+time(NULL)
	//初始化graph
	initgraph ( HEIGHT, WIDTH/*,SHOWCONSOLE*/ );
	//蛇
	snake.size = 3;
	snake.speed = 12;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		//下标0为蛇头
		snake.coor[i].x = 40 - 15 * i ;
		snake.coor[i].y = 10;
	}
	//在画面随机位置生成点数
	makePoint ();
}

//生成点数
void makePoint ()
{
	//在画面随机位置生成点数
	point.x = rand () % 1440;
	point.y = rand () % 860;
	point.r = 10;
	point.flag = true;
}

//绘制蛇
void GameSnake ()
{
	//双缓冲
	BeginBatchDraw ();
	//背景
	setbkcolor ( WHITE );
	cleardevice ();
	//绘制蛇
	setfillcolor ( GREEN );
	for (int i = 0; i < snake.size; i++)
	{
		solidcircle ( snake.coor[i].x, snake.coor[i].y, 6 );//画蛇，蛇身由实心圆构成
	}
	//绘制点数
	setfillcolor ( RED );
	if (point.flag == true)
	{
		solidcircle ( point.x, point.y, point.r );
	}
	//双缓冲结束
	EndBatchDraw ();
}

//蛇移动
void SnakeMove ()
{
	for (int i = snake.size - 1; i > 0; i--)
	{
		snake.coor[i] = snake.coor[i - 1];  //让蛇的一节和它前一节一起移动
	}
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y -= snake.speed;
		if (snake.coor[0].y <= 2)
			snake.coor[0].y = HEIGHT-550;
		break;
	case DOWN:
		snake.coor[0].y += snake.speed;
		if (snake.coor[0].y  >= HEIGHT-550)
			snake.coor[0].y = 0; 
		break;
	case LEFT:
		snake.coor[0].x -= snake.speed;
		if (snake.coor[0].x+10 <= 0)
			snake.coor[0].x = WIDTH+600; 
		break;
	case RIGHT:
		snake.coor[0].x += snake.speed;
		if (snake.coor[0].x +10>= WIDTH+600)
			snake.coor[0].x = 0;
		break;
	}
}

//判断是否获取点数
void getpoint ()
{
	if (snake.coor[0].x >= point.x-point.r&&snake.coor[0]. x<= point.x+point.r&&
		snake.coor[0].y>=point.y-point.r&&snake.coor[0].y<=point.y+point.r&&point.flag==true)
	{
		point.flag = false;
		snake.size++;
	}
	//重新生成食物
	if (point.flag == false)
	{
		makePoint ();
	}
}

//键盘控制函数
void GetCon ()
{
	if (_kbhit ())//检测有无按下键盘则返回真
	{
		//方向
		switch (_getch ())
		{
		case 'w':
		case 'W':
			if(snake.dir != DOWN)
			snake.dir = UP;
			break;
		case 'a':
		case 'A':
			if(snake.dir != RIGHT)
			snake.dir = LEFT;
			break;
		case 's':
		case 'S':
			if(snake.dir!=UP)
			snake.dir = DOWN;
			break;
		case 'd':
		case 'D':
			if(snake.dir!=LEFT)
			snake.dir = RIGHT;
			break;
		case 27:
			while (1)
			{
				if (_getch () == 27)
					return;
			}
			break;
		}
	}
}

