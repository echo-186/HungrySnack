#pragma once
#include<stdio.h>
#include<tchar.h>
#include<memory.h>
#include<stdlib.h>
#include<Windows.h>
#include<mmsystem.h>
#include <conio.h>
#pragma comment(lib,"winmm.lib")//time要导入的库文件

#define MAP_ROW 22
#define MAP_COL 32
#define SNAKE_NUM 3
#define FOOD_NUM 5
enum  MapState
{
	map_null, map_snake, map_frame, map_food
};
enum SnakeDir
{
	s_up,s_down,s_left,s_right
};
//在此引用程序所需要的的其他头文件
struct MyPoint
{
	int row, col;
};
struct SnakeNode//蛇的数据结构：双向链表
{
	MyPoint SnakePos;
	SnakeNode *pFront;
	SnakeNode *pNext;
};
#include"Mytools.h"
#include "MyMap.h"
#include"Snake.h"
#include"Food.h"
#include"Manage.h"//头文件引用也是有顺序的，所以管理类要在后面
