#pragma once
#include<stdio.h>
#include<tchar.h>
#include<memory.h>
#include<stdlib.h>
#include<Windows.h>
#include<mmsystem.h>
#include <conio.h>
#pragma comment(lib,"winmm.lib")//timeҪ����Ŀ��ļ�

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
//�ڴ����ó�������Ҫ�ĵ�����ͷ�ļ�
struct MyPoint
{
	int row, col;
};
struct SnakeNode//�ߵ����ݽṹ��˫������
{
	MyPoint SnakePos;
	SnakeNode *pFront;
	SnakeNode *pNext;
};
#include"Mytools.h"
#include "MyMap.h"
#include"Snake.h"
#include"Food.h"
#include"Manage.h"//ͷ�ļ�����Ҳ����˳��ģ����Թ�����Ҫ�ں���
