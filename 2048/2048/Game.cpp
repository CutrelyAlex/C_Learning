#include "Game.h"
#include"Menu.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<conio.h>
#define MAX_SIZE ROW
//�����������
int map[ROW][COL];
//������ɫö��
enum Color
{
	zero = RGB ( 205, 193, 180 ),
	twoe1 = RGB ( 238, 228, 218 ),
	twoe2 = RGB ( 237, 224, 200 ),
	twoe3 = RGB ( 242, 177, 121 ),
	twoe4 = RGB ( 245, 149, 99 ),
	twoe5 = RGB ( 246, 124, 95 ),
	twoe6 = RGB ( 246, 94, 59 ),
	twoe7 = RGB ( 242, 177, 121 ),
	twoe8 = RGB ( 237, 204, 96 ),
	twoe9 = RGB ( 255, 0, 128 ),
	twoe10 = RGB ( 145, 0, 72 ),
	twoe11 = RGB ( 242, 17, 158 ),
};
Color colorarr[13] = { zero,twoe1,twoe2,twoe3,twoe4,twoe5,twoe6 ,twoe7,twoe8,twoe9,twoe10,twoe11 };

//�����һ������
int init_rand ()
{
	srand ( (unsigned)time ( NULL ) + clock () );
	if (rand () % 6 == 0) //������ʾ4��2�ĸ���
		return 4;
	else
		return 2;
}

//��ʼ������
void init_num ()
{
	int i = 0;
	while (i < 2)
	{
		int r = rand () % ROW;
		int c = rand () % COL;
		if (map[r][c] == 0)
		{
			map[r][c] = init_rand ();
			i++;
		}
	}
}

//��Ϸ����,���ֻ���
void game_draw ()
{
	setfillcolor ( RGB ( 206, 194, 182 ) );
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//����������Ͻǵ�����
			int x = j * GRID_W + (j + 1)*INTERVAL;
			int y = i * GRID_W + (i + 1)*INTERVAL;
			//���㵱ǰ������2Ϊ�׵Ķ���
			int index = (int)log2 ( (double)map[i][j] );
			//������ɫ
			COLORREF textcolor = colorarr[index];
			setfillcolor ( textcolor );
			//���Ƹ���
			solidroundrect ( x, y, x + GRID_W, y + GRID_W, 10, 10 );
			//��������
			if (map[i][j] != 0) //���������0����ʾ
			{
				settextstyle ( 50, 0, "����" );
				//������תΪ�ַ���
				char str[10] = "";
				sprintf_s ( str, "%d", map[i][j] );
				settextcolor ( BLACK );
				setbkmode ( TRANSPARENT );
				//�ڸ����Ͼ�����ʾ����
				int textw = textwidth ( str );
				int texth = textheight ( str );
				int textx = (GRID_W - textw) / 2;
				int texty = (GRID_W - texth) / 2;
				outtextxy ( x + textx, y + texty, str );
			}
			//����̨��ʾ����
			printf ( "%d ", map[i][j] );
		}
		//����̨��ʾ������
		printf ( "\n" ); 
	}
}

//��Ϸ���ڳ�ʼ��
void init_game ()
{
	//��ʼ������
	initgraph ( WIN_SIZE, WIN_SIZE/*, SHOWCONSOLE */);
	setbkcolor ( RGB ( 188, 174, 160 ) );
	cleardevice ();
}



//���̿���
int key_con ()
{
	int flag = 0;
	char key = _getch ();
	switch (key)
	{
	case 'w':
	case 'W':
		moveUp ();
		break;
	case 's':
	case 'S':
		moveDown ();
		break;
	case 'a':
	case 'A':
		moveLeft ();;
		break;
	case 'd':
	case 'D':
		moveRight ();
		break;
	default:
		flag = -1;
		break;
	}
	return flag;
}

void moveUp ()
{
	for (int i = 1; i < COL; i++)
	{
		int temp = 0;
		for (int begin = 1; begin< ROW; begin++)
		{
			if (map[begin][i] != 0)
			{
				if (map[temp][i] == 0)
				{
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])
				{
					map[temp][i] += map[begin][i];
					map[begin][i] = 0;
					temp++;
				}
				else
				{
					map[temp + 1][i] = map[begin][i];
					if (temp + 1 != begin)
					{
						map[begin][i] = 0;
					}
					temp++;
				}
			}
		}
	}
}
void moveDown ()
{
	//��
	for (int i = 0; i < MAX_SIZE; i++)
	{

		int temp = MAX_SIZE - 1;
		//��
		for (int begin = MAX_SIZE - 2; begin >= 0; begin--)
		{
			//��������ÿ�����һ�������һ����,����Ϊ�㣬û�в���
			if (map[begin][i] != 0)
			{
				if (map[temp][i] == 0)
				{
					//����������������
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])
				{
					//������ͬ�ϲ�
					map[temp][i] += map[begin][i];
					map[begin][i] = 0;
					//temp�����ƶ�һλ
					temp--;
				}
				else
				{
					//�����Ե������桱��Ϊ�㣬Ҳ���������ֵĸ���������ͬ���������ƶ�
					//�������ֵĸ������ݸ�ֵ�������Ե������桱����һ��
					map[temp - 1][i] = map[begin][i];
					if ((temp - 1) != begin)
					{
						//�������Ӳ����ڣ����������������ʧ
						map[begin][i] = 0;
					}
					//else �����������ڣ��������������û�б仯����Ϊ��������
					//temp�����ƶ�һλ
					temp--;
				}
			}
		}

	}
}
void moveLeft ()
{
	//��
	for (int i = 0; i < MAX_SIZE; i++)
	{

		int temp = 0;
		//��
		for (int begin = 1; begin < MAX_SIZE; begin++)
		{
			//��������ÿ�е�һ�����һ����,����Ϊ�㣬û�в���
			if (map[i][begin] != 0)
			{
				if (map[i][temp] == 0)
				{
					//����������������
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])
				{
					//������ͬ�ϲ�
					map[i][temp] += map[i][begin];
					map[i][begin] = 0;
					//temp�����ƶ�һλ
					temp++;
				}
				else
				{
					//�����Ե������桱��Ϊ�㣬Ҳ���������ֵĸ���������ͬ���������ƶ�
					//�������ֵĸ������ݸ�ֵ�������Ե������桱����һ��
					map[i][temp + 1] = map[i][begin];
					if ((temp + 1) != begin)
					{
						//�������Ӳ����ڣ����������������ʧ
						map[i][begin] = 0;
					}
					//else �����������ڣ��������������û�б仯����Ϊ��������
					//temp�����ƶ�һλ
					temp++;
				}
			}
		}

	}

}
void moveRight ()
{
	//��
	for (int i = 0; i < MAX_SIZE; i++)
	{

		int temp = MAX_SIZE - 1;
		//��
		for (int begin = MAX_SIZE - 2; begin >= 0; begin--)
		{
			//��������ÿ�����һ�������һ����,����Ϊ�㣬û�в���
			if (map[i][begin] != 0)
			{
				if (map[i][temp] == 0)
				{
					//����������������
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])
				{
					//������ͬ�ϲ�
					map[i][temp] += map[i][begin];
					map[i][begin] = 0;
					//temp�����ƶ�һλ
					temp--;
				}
				else
				{
					//�����Ե������桱��Ϊ�㣬Ҳ���������ֵĸ���������ͬ���������ƶ�
					//�������ֵĸ������ݸ�ֵ�������Ե������桱����һ��
					map[i][temp - 1] = map[i][begin];
					if ((temp - 1) != begin)
					{
						//�������Ӳ����ڣ����������������ʧ
						map[i][begin] = 0;
					}
					//else �����������ڣ��������������û�б仯����Ϊ��������
					//temp�����ƶ�һλ
					temp--;
				}
			}
		}

	}
}

//ʤ���ж�
int check ()
{
	int flag = 0;
	int boom = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (map[i][j] != 0)
			{
				flag++;
				if (map[i][j] == 2048)
				{
					boom = 2048;
					break;
				}
			}
		}
		if (boom == 2048)break;
	}
	if (flag == MAX_SIZE * MAX_SIZE || boom == 2048)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

void blockGenerate ( int flag )
{
	//���ж���Ϸ�Ѿ����������˳�
	if (flag == -1) return;
	while (1)
	{
		int r = rand () % MAX_SIZE;
		int c = rand () % MAX_SIZE;
		if (map[r][c] == 0)
		{
			map[r][c] = init_rand ();
			break;
		}
	}
}