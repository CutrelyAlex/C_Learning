#include "game.h"


//���̳�ʼ��
void Init_Board (char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)  //������ÿ���ʼ��Ϊһ��Ԫ��
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' '; //��ʼ������Ԫ��
		}
	}
}

//��ӡ����
void Display_Board (char board[ROW][COL], int row, int col) 
{
	int i,j;
	printf ("\n");
	for (i = 0; i < row; i++)//��i��
	{
		for (j = 0; j < col; j++)//��j��
		{
			printf (" %c ", board[i][j]);//��ʼ����i�е�j�е���������
			if (j < col - 1)
				printf ("|");//�����һ�����ӡ|
		}
		printf ("\n");
		if (i < row - 1)//�����һ��
		{
			for (j = 0; j < col; j++)//��i�л��к��ӡ�ָ���
			{
				printf ("---");
				if(j<col-1)
					printf ("|");
			}
		}
		printf ("\n");
	}

}


//���A����
char PlayerA_Move (char board[ROW][COL], int row, int col)
{
	int x, y;
	char ret;//�Ծֽ���ж�
	ag:
	printf ("\n--���A��--\n");
	printf ("\n--����Ҫ�µ�����x--\n");
	scanf ("%d", &x);
	printf ("\n--����Ҫ�µ�����y--\n");
	scanf ("%d", &y);
	if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж�����Ϸ���
	{
		if (board[x - 1][y - 1] == ' ')//�ж��Ƿ��ѱ��¹�
		{
			board[x - 1][y - 1] = 'A';
		}
		else
		{
			system ("cls");
			printf ("�������ѱ�ռ��,����������!\n");
			Display_Board (board, ROW, COL);
			goto ag;
		}
	}
	else
	{
		system ("cls");
		printf ("���ڷǷ�����,����������\n");
		Display_Board (board, ROW, COL);
		goto ag;
	}
}

//���B����
char PlayerB_Move (char board[ROW][COL], int row, int col)
{
	int x, y;
ag:
	printf ("\n--���B��--\n");
	printf ("\n--����Ҫ�µ�����x--\n");
	scanf ("%d", &x);
	printf ("\n--����Ҫ�µ�����y--\n");
	scanf ("%d", &y);
	if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж�����Ϸ���
	{
		if (board[x - 1][y - 1] == ' ')//�ж��Ƿ��ѱ��¹�
		{
			board[x - 1][y - 1] = 'B';
		}
		else
		{
			system ("cls");
			printf ("�������ѱ�ռ��,����������!\n");
			Display_Board (board, ROW, COL);
			goto ag;
		}
	}
	else
	{
		system ("cls");
		printf ("���ڷǷ�����,����������\n");
		Display_Board (board, ROW, COL);
		goto ag;
	}
}

//��������
char Computer_Move (char board[ROW][COL], int row, int col)
{
	int x, y;
	printf ("--��������--");
	ag:
	x = rand () % row;
	y = rand () % col;
	if (board[x][y] != ' ')
		board[x][y] = 'B';
	else
		goto ag;
}


//�Ծ����ж�
//���˷���1  û������0
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
//�Ծ��ж�
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


//�Ծ��ж�2
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