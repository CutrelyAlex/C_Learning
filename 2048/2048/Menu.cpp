#include "Menu.h"
#include<stdio.h>
#include<graphics.h> //ͼ�ο�ͷ�ļ�

//���ת������
void menu_choice ( int choice )
{
	if (choice == 0)
		exit ( 1 );
	else if (choice == 1)
		game_start ();
	else if(choice ==2)
		about_menu ();
}


//������˵����
void check_click ()
{
	ExMessage mouse = getmessage();
	if (mouse.x >= 90 && mouse.x <= 200 && mouse.y <= 350 && mouse.y >= 250 && mouse.message == WM_LBUTTONDOWN)
		menu_choice ( 0 );//����˳���Ϸ
	if (mouse.x >= 90 && mouse.x <= 200 && mouse.y <= 260 && mouse.y >= 140 && mouse.message == WM_LBUTTONDOWN)
		menu_choice ( 1 );//���������Ϸ
	if (mouse.x >= 90 && mouse.x <= 200 && mouse.y <= 450 && mouse.y >= 350 && mouse.message == WM_LBUTTONDOWN)
		menu_choice ( 2 );//�������
}


//���˵�
void main_menu ()
{
		//�������ڣ�ȷ�����ڴ�С
		initgraph ( WIDTH, HEIGHT /*,SHOWCONSOLE */);
		setbkcolor (RGB( 188, 174, 160 ));//���ñ�����ɫ
		cleardevice ();
		settextcolor ( BLACK );
		settextstyle ( 32, 0, "����" );
		outtextxy ( 100, 50, "2048��Ϸ��ҵ ��WASD���ƣ�" );
		settextstyle ( 26, 0, "����" );
		settextcolor ( BLACK );
		outtextxy ( 100, 200, "��ʼ��Ϸ" );
		outtextxy ( 100, 300, "�˳���Ϸ" );
		outtextxy ( 100, 400, "����" );
		do
		{
			check_click ();
		} while (1);
}

//���ڴ���
void about_menu ()
{
	initgraph ( WIDTH, HEIGHT/*, SHOWCONSOLE*/ );
	setbkcolor ( RGB ( 221, 225, 206 ) );//���ñ�����ɫ
	cleardevice ();
	settextcolor ( BLACK );
	settextstyle ( 23, 0, "����" );
	outtextxy ( 50, 50, "����һ��C++��ҵ,2021��8��11������,QQ:2470819243" );
	outtextxy ( 50, 75, "��Ϸʤ����ʧ��ʱ��Ҳ��ת���˴�" );
	outtextxy ( 50, 100, "��Ϸ�����RGB��ɫȡ������2048��Ϸ" );
	outtextxy ( 100, 400, "����" );
	do
	{
		ExMessage mouse = getmessage ();
		if (mouse.x >= 90 && mouse.x <= 150 && mouse.y <= 450 && mouse.y >= 350 && mouse.message == WM_LBUTTONDOWN)
			main_menu();//�������,�������˵�
	} while (1);
}