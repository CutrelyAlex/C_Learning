#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3//����
#define COL 3//����

//��ʼ��Ϸ����
void game_start ();

//���̳�ʼ����������
void Init_Board (char board[ROW][COL], int row, int col);

//������ʾ����
void Display_Board (char board[ROW][COL], int row, int col);

//���A����
char PlayerA_Move (char board[ROW][COL], int row, int col);

//���B����
char PlayerB_Move (char board[ROW][COL], int row, int col);

//��������
char Computer_Move (char board[ROW][COL], int row, int col);

//�ж���Ӯ,����Ӯ,��,ƽ,����
//AӮ:����'A' 
//BӮ/����Ӯ:����'B'
//ƽ�ַ���'Q'
//��������'C'
char IsWin (char board[ROW][COL], int row, int col);
char IsWin_2 (char board[ROW][COL], int row, int col,int x,int y);