#include "Game.h"
#include <graphics.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
//��ý��ӿ�
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define SNAKE_MAXSIZE 500 //��������
#define HEIGHT  1440   //���ڸ߶�
#define WIDTH  860   //���ڿ��

//�ṹ����
struct ASnake
{
	int size;//����ֵ
	int dir;//����
	int speed;//�ٶ�
	POINT coor[SNAKE_MAXSIZE];//������	����ṹ�� x,y
}snake;

//�ṹ�����
struct Point
{
	int x;
	int y;
	int r; //�뾶
	bool flag; //�����Ƿ񱻻�ȡ
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
	//����bgm   ·��:./res/a.mp3
	mciSendString ( "open ./res/a.mp3 alias BGM", 0, 0, 0 );
	mciSendString ( "play BGM repeat", 0, 0, 0 );
	srand (GetTickCount()+(int)time(NULL));//���������,����ʱ��tick+time(NULL)
	//��ʼ��graph
	initgraph ( HEIGHT, WIDTH/*,SHOWCONSOLE*/ );
	//��
	snake.size = 3;
	snake.speed = 12;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		//�±�0Ϊ��ͷ
		snake.coor[i].x = 40 - 15 * i ;
		snake.coor[i].y = 10;
	}
	//�ڻ������λ�����ɵ���
	makePoint ();
}

//���ɵ���
void makePoint ()
{
	//�ڻ������λ�����ɵ���
	point.x = rand () % 1440;
	point.y = rand () % 860;
	point.r = 10;
	point.flag = true;
}

//������
void GameSnake ()
{
	//˫����
	BeginBatchDraw ();
	//����
	setbkcolor ( WHITE );
	cleardevice ();
	//������
	setfillcolor ( GREEN );
	for (int i = 0; i < snake.size; i++)
	{
		solidcircle ( snake.coor[i].x, snake.coor[i].y, 6 );//���ߣ�������ʵ��Բ����
	}
	//���Ƶ���
	setfillcolor ( RED );
	if (point.flag == true)
	{
		solidcircle ( point.x, point.y, point.r );
	}
	//˫�������
	EndBatchDraw ();
}

//���ƶ�
void SnakeMove ()
{
	for (int i = snake.size - 1; i > 0; i--)
	{
		snake.coor[i] = snake.coor[i - 1];  //���ߵ�һ�ں���ǰһ��һ���ƶ�
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

//�ж��Ƿ��ȡ����
void getpoint ()
{
	if (snake.coor[0].x >= point.x-point.r&&snake.coor[0]. x<= point.x+point.r&&
		snake.coor[0].y>=point.y-point.r&&snake.coor[0].y<=point.y+point.r&&point.flag==true)
	{
		point.flag = false;
		snake.size++;
	}
	//��������ʳ��
	if (point.flag == false)
	{
		makePoint ();
	}
}

//���̿��ƺ���
void GetCon ()
{
	if (_kbhit ())//������ް��¼����򷵻���
	{
		//����
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

