#pragma once
#define WIDTH 640 //窗口宽度
#define HEIGHT 480  //窗口高度
#define GRID_W 100 //格子像素宽度
#define INTERVAL 15 //格子间的像素间距
#define ROW 4 //行数
#define COL 4 //列数
#define WIN_SIZE ROW*GRID_W+INTERVAL*(ROW+1)  //窗口宽度,高度=行数*格子宽度+(间隔宽度)*(行+1)