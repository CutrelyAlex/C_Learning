#include "Game.h"
#include"Menu.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<conio.h>
#define MAX_SIZE ROW
//画面格子数组
int map[ROW][COL];
//格子颜色枚举
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

//随机第一回数字
int init_rand ()
{
	srand ( (unsigned)time ( NULL ) + clock () );
	if (rand () % 6 == 0) //处理显示4或2的概率
		return 4;
	else
		return 2;
}

//初始化数据
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

//游戏格子,数字绘制
void game_draw ()
{
	setfillcolor ( RGB ( 206, 194, 182 ) );
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//计算格子左上角的坐标
			int x = j * GRID_W + (j + 1)*INTERVAL;
			int y = i * GRID_W + (i + 1)*INTERVAL;
			//计算当前数字以2为底的对数
			int index = (int)log2 ( (double)map[i][j] );
			//格子颜色
			COLORREF textcolor = colorarr[index];
			setfillcolor ( textcolor );
			//绘制格子
			solidroundrect ( x, y, x + GRID_W, y + GRID_W, 10, 10 );
			//格子数字
			if (map[i][j] != 0) //如果格子是0则不显示
			{
				settextstyle ( 50, 0, "黑体" );
				//将数字转为字符串
				char str[10] = "";
				sprintf_s ( str, "%d", map[i][j] );
				settextcolor ( BLACK );
				setbkmode ( TRANSPARENT );
				//在格子上居中显示数字
				int textw = textwidth ( str );
				int texth = textheight ( str );
				int textx = (GRID_W - textw) / 2;
				int texty = (GRID_W - texth) / 2;
				outtextxy ( x + textx, y + texty, str );
			}
			//控制台显示数字
			printf ( "%d ", map[i][j] );
		}
		//控制台显示数字用
		printf ( "\n" ); 
	}
}

//游戏窗口初始化
void init_game ()
{
	//初始化窗口
	initgraph ( WIN_SIZE, WIN_SIZE/*, SHOWCONSOLE */);
	setbkcolor ( RGB ( 188, 174, 160 ) );
	cleardevice ();
}



//键盘控制
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
	//列
	for (int i = 0; i < MAX_SIZE; i++)
	{

		int temp = MAX_SIZE - 1;
		//行
		for (int begin = MAX_SIZE - 2; begin >= 0; begin--)
		{
			//遍历除了每列最后一个数外的一整行,若均为零，没有操作
			if (map[begin][i] != 0)
			{
				if (map[temp][i] == 0)
				{
					//将下面有数字上移
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])
				{
					//数字相同合并
					map[temp][i] += map[begin][i];
					map[begin][i] = 0;
					//temp向上移动一位
					temp--;
				}
				else
				{
					//“测试的最下面”不为零，也不与有数字的格子数字相同，则向下移动
					//将有数字的格子内容赋值给“测试的最下面”的上一个
					map[temp - 1][i] = map[begin][i];
					if ((temp - 1) != begin)
					{
						//两个格子不相邻，则上面格子数字消失
						map[begin][i] = 0;
					}
					//else 两个格子相邻，则上面格子数字没有变化，因为是他本身
					//temp向上移动一位
					temp--;
				}
			}
		}

	}
}
void moveLeft ()
{
	//行
	for (int i = 0; i < MAX_SIZE; i++)
	{

		int temp = 0;
		//列
		for (int begin = 1; begin < MAX_SIZE; begin++)
		{
			//遍历除了每行第一数外的一整列,若均为零，没有操作
			if (map[i][begin] != 0)
			{
				if (map[i][temp] == 0)
				{
					//将右面有数字左移
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])
				{
					//数字相同合并
					map[i][temp] += map[i][begin];
					map[i][begin] = 0;
					//temp向右移动一位
					temp++;
				}
				else
				{
					//“测试的最左面”不为零，也不与有数字的格子数字相同，则向左移动
					//将有数字的格子内容赋值给“测试的最左面”的右一个
					map[i][temp + 1] = map[i][begin];
					if ((temp + 1) != begin)
					{
						//两个格子不相邻，则右面格子数字消失
						map[i][begin] = 0;
					}
					//else 两个格子相邻，则右面格子数字没有变化，因为是他本身
					//temp向右移动一位
					temp++;
				}
			}
		}

	}

}
void moveRight ()
{
	//行
	for (int i = 0; i < MAX_SIZE; i++)
	{

		int temp = MAX_SIZE - 1;
		//列
		for (int begin = MAX_SIZE - 2; begin >= 0; begin--)
		{
			//遍历除了每行最后一个数外的一整行,若均为零，没有操作
			if (map[i][begin] != 0)
			{
				if (map[i][temp] == 0)
				{
					//将左面有数字右移
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])
				{
					//数字相同合并
					map[i][temp] += map[i][begin];
					map[i][begin] = 0;
					//temp向左移动一位
					temp--;
				}
				else
				{
					//“测试的最右面”不为零，也不与有数字的格子数字相同，则向右移动
					//将有数字的格子内容赋值给“测试的最右面”的左一个
					map[i][temp - 1] = map[i][begin];
					if ((temp - 1) != begin)
					{
						//两个格子不相邻，则左面格子数字消失
						map[i][begin] = 0;
					}
					//else 两个格子相邻，则左面格子数字没有变化，因为是他本身
					//temp向左移动一位
					temp--;
				}
			}
		}

	}
}

//胜利判断
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
	//若判断游戏已经结束，便退出
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