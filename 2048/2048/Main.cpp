/*
2048��Ŀ
�ⲿ��:EasyXͼ�α�̿�
*/
#include "define.h"
#include "Game.h"
#include "Menu.h"
#include<stdio.h>
extern void game_draw ();
extern int check ();
void game_start ()
{
	init_game ();//��Ϸ��ʼ��
	init_num ();//��ʼ������
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
	main_menu ();//���˵�
	//����,���ֻ���
	return 0;
}