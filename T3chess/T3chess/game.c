#include "game.h"


//棋盘初始化
void Init_Board (char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)  //将棋盘每格初始化为一个元素
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' '; //初始化棋盘元素
		}
	}
}

//打印棋盘
void Display_Board (char board[ROW][COL], int row, int col) 
{
	int i,j;
	printf ("\n");
	for (i = 0; i < row; i++)//第i行
	{
		for (j = 0; j < col; j++)//第j列
		{
			printf (" %c ", board[i][j]);//初始化第i行第j列的棋盘数据
			if (j < col - 1)
				printf ("|");//除最后一列外打印|
		}
		printf ("\n");
		if (i < row - 1)//除最后一行
		{
			for (j = 0; j < col; j++)//第i行换行后打印分隔线
			{
				printf ("---");
				if(j<col-1)
					printf ("|");
			}
		}
		printf ("\n");
	}

}


//玩家A下棋
char PlayerA_Move (char board[ROW][COL], int row, int col)
{
	int x, y;
	char ret;//对局结果判断
	ag:
	printf ("\n--玩家A走--\n");
	printf ("\n--输入要下的坐标x--\n");
	scanf ("%d", &x);
	printf ("\n--输入要下的坐标y--\n");
	scanf ("%d", &y);
	if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标合法性
	{
		if (board[x - 1][y - 1] == ' ')//判断是否已被下过
		{
			board[x - 1][y - 1] = 'A';
		}
		else
		{
			system ("cls");
			printf ("该坐标已被占用,请重新输入!\n");
			Display_Board (board, ROW, COL);
			goto ag;
		}
	}
	else
	{
		system ("cls");
		printf ("存在非法坐标,请重新输入\n");
		Display_Board (board, ROW, COL);
		goto ag;
	}
}

//玩家B下棋
char PlayerB_Move (char board[ROW][COL], int row, int col)
{
	int x, y;
ag:
	printf ("\n--玩家B走--\n");
	printf ("\n--输入要下的坐标x--\n");
	scanf ("%d", &x);
	printf ("\n--输入要下的坐标y--\n");
	scanf ("%d", &y);
	if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标合法性
	{
		if (board[x - 1][y - 1] == ' ')//判断是否已被下过
		{
			board[x - 1][y - 1] = 'B';
		}
		else
		{
			system ("cls");
			printf ("该坐标已被占用,请重新输入!\n");
			Display_Board (board, ROW, COL);
			goto ag;
		}
	}
	else
	{
		system ("cls");
		printf ("存在非法坐标,请重新输入\n");
		Display_Board (board, ROW, COL);
		goto ag;
	}
}

//电脑下棋
char Computer_Move (char board[ROW][COL], int row, int col)
{
	int x, y;
	printf ("--电脑在走--");
	ag:
	x = rand () % row;
	y = rand () % col;
	if (board[x][y] != ' ')
		board[x][y] = 'B';
	else
		goto ag;
}


//对局满判断
//满了返回1  没满返回0
int IsFull (char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//对局判断
char IsWin (char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i=0;i<col;i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
	{
		return board[2][0];
	}
	if (1 == IsFull (board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}


//对局判断2
//char IsWin_2 (char board[ROW][COL], int row, int col, int x, int y)
//{
//	char whoPlaced = board[x][y];
//	if (board[x][y] == board[x + 1][y] && board[x][y] == board[x + 2][y] && board[x][y] == board[x + 3][y] && board[x][y] == board[x + 4][y])
//		return whoPlaced;
//	else if (board[x][y] == board[x - 1][y] && board[x][y] == board[x - 2][y] && board[x][y] == board[x - 3][y] && board[x][y] == board[x - 4][y])
//		return whoPlaced;
//	else if (board[x][y] == board[x][y + 1] && board[x][y] == board[x][y + 2] && board[x][y] == board[x][y + 3] && board[x][y] == board[x][y + 4])
//		return whoPlaced;
//	else if (board[x][y] == board[x + 1][y + 1] && board[x][y] == board[x + 2][y + 2] && board[x][y] == board[x + 3][y + 3] && board[x][y] == board[x + 4][y + 4])
//		return whoPlaced;
//	else if (board[x][y] == board[x][y - 1] && board[x][y] == board[x][y - 2] && board[x][y] == board[x][y - 3] && board[x][y] == board[x][y - 4])
//		return whoPlaced;
//	else if (board[x][y] == board[x - 1][y - 1] && board[x][y] == board[x - 2][y - 2] && board[x][y] == board[x - 3][y - 3] && board[x][y] == board[x - 4][y - 4])
//}