#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3//行数
#define COL 3//列数

//开始游戏声明
void game_start ();

//棋盘初始化函数声明
void Init_Board (char board[ROW][COL], int row, int col);

//棋盘显示声明
void Display_Board (char board[ROW][COL], int row, int col);

//玩家A下棋
char PlayerA_Move (char board[ROW][COL], int row, int col);

//玩家B下棋
char PlayerB_Move (char board[ROW][COL], int row, int col);

//电脑下棋
char Computer_Move (char board[ROW][COL], int row, int col);

//判断输赢,返回赢,输,平,继续
//A赢:返回'A' 
//B赢/电脑赢:返回'B'
//平局返回'Q'
//继续返回'C'
char IsWin (char board[ROW][COL], int row, int col);
char IsWin_2 (char board[ROW][COL], int row, int col,int x,int y);