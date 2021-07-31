/*
�������ѧ��ҵ
By D��
QQ:2470819243
*/


#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1

int input;//�˵�ѡ���������
char ret = 0;//�Ծ����
char board[ROW][COL] = { 0 };//���̶�ά�������� ROW�� COL��

//�˵�ҳ����ʾ
void menu ()
{
	printf ("\n******************������************************\n");
	printf ("**** 0. �˳� 1. ���Լ���  2.�͵���(ɵ��)�� *****\n");  //ѡ��2������� ѡ��1�������
	printf ("*******C���Գ�ѧ��ҵ--������:D��****************\n");
	printf ("��ѡ��:>");
}

//�˵�ѡ��
void menu_chose ()
{
	scanf ("%d", &input);
	switch (input)
	{
	case 2:
	case 1:
		game_start ();//������Ϸ
		break;
	case 0:
		printf ("�˳���Ϸ\n");
		break;
	default:
		system ("cls");
		printf ("��Ч����,����������.\n");
	}
}


//��������
void Player_VS_COM ()
{
	while (input == 2)
	{
		//���A����
		PlayerA_Move (board, ROW, COL);  system ("cls");
		Display_Board (board, ROW, COL);
		ret = IsWin (board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//��������
		Computer_Move (board, ROW, COL);  system ("cls");
		Display_Board (board, ROW, COL);
		ret = IsWin (board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	//�Ծֽ���ж�
	if (ret == 'A')
	{
		printf ("���Ӯ\n");
	}
	else if (ret == 'B')
	{
		printf ("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf ("ƽ��\n");
	}
}

//��������
void Player_VS_Player ()
{
	while (input == 1)
	{
		//���A����
		ret = PlayerA_Move (board, ROW, COL);  system ("cls");
		Display_Board (board, ROW, COL);
		ret = IsWin (board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}

		//���B����
		PlayerB_Move (board, ROW, COL);  system ("cls");
		Display_Board (board, ROW, COL);
		ret = IsWin (board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	//�Ծֽ���ж�
	if (ret == 'A')
	{
		printf ("���AӮ\n");
	}
	else if (ret == 'B')
	{
		printf ("���BӮ\n");
	}
	else if (ret == 'Q')
	{
		printf ("ƽ��\n");
	}
}


//��Ϸ�㷨ʵ��
void game_start ()
{
	Init_Board (board, ROW, COL); //��ʼ������
	Display_Board (board, ROW, COL); //��ӡ����(��������,��,��)
	Player_VS_COM (); //��������
	Player_VS_Player ();//��������
}

//����ģ��
void gamego ()
{
	srand ((unsigned int)time (NULL));
	do
	{
		menu ();//�˵�
		menu_chose ();//�˵�ѡ��
	} while (input);
}

int main ()
{
	gamego ();
	return 0;
}