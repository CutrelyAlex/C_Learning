/*
��ҵ:̰������Ϸ
2021��8��8��
ByD��
QQ:2470819243.
*/
#include"Game.h"
#define HEIGHT  1440  //���ڸ߶�
#define WIDTH  960   //���ڿ��

extern void GameInit ();
extern void GameSnake ();
extern void SnakeMove ();
extern void GetCon ();
extern void getpoint ();
void PlayGame ();

//�˵�
int Menu ()
{
	MOUSEMSG mouse;//������
	initgraph ( HEIGHT, WIDTH );
	setbkcolor ( WHITE );//������ɫ
	cleardevice ();
	setfillcolor ( LIGHTBLUE );//����ѡ��򱳾���ɫ
	fillrectangle ( 200, 320, 650, 400 );
	setbkmode ( TRANSPARENT );
	settextstyle ( 14, 0, "����" );//���ִ�С
	outtextxy ( 250, 322, "̰������Ϸ,ByD��" );
	outtextxy ( 250, 340, "��ҵ��ʵ�ʱ߽��봰�ڴ�С��ͬ(����Windowsϵͳ�Զ�����)" );
	fillrectangle ( 200, 140, 600, 160 );
	fillrectangle ( 200, 440, 600, 460 );
	settextstyle ( 15, 0, "����" );//���ִ�С
	outtextxy ( 250, 142, "��ʼ��Ϸ(���ESC��ͣ)" );
	outtextxy ( 250, 442, "�˳���Ϸ" );
	while (1)
	{
		ExMessage mouse = getmessage ();//��ȡ�������
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
	int ret = Menu ();//�˵�
	if (ret == 1)
	{
		GameInit ();//��ʼ����Ϸ
		PlayGame ();//������Ϸ
	}
}
void PlayGame ()
{
	while (1)
	{
		SnakeMove (); //�ƶ���
		GameSnake ();  //�����ߺ͵���
		GetCon ();    //��ȡ���̿���
		getpoint ();
		Sleep ( 20 );
	}
}
int main ()
{
	GameStart (); //������Ϸģ��
	return 0;
}
