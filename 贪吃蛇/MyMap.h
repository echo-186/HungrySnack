#include"stdafx.h"
#pragma once
class MyMap
{
public:
	MyMap();//没有动态内存，不需要析构
	void InitMap(short randArr[],int &len);//数据和渲染分开
	void DrawMap();
	void SetMapVal(int row, int col, int val);//将蛇的坐标渲染进地图
public:
	char GetMapVal(int row, int col)const { return m_MapArr[row][col]; }

private:
	char m_MapArr[MAP_ROW][MAP_COL];//不用int的原因是为了节省空间
};
MyMap::MyMap()
{
	memset(m_MapArr, 0, sizeof(char)*MAP_COL*MAP_ROW);//初始化未知值
}
void MyMap::InitMap(short randArr[], int &len)
{
	for (int i = 0; i < MAP_ROW; ++i)
	{
		for (int j = 0; j < MAP_COL; ++j)
		{
			if (i == 0 || j == 0 || i == MAP_ROW - 1 || j == MAP_COL - 1)
				m_MapArr[i][j] = map_frame;
			
			else
			{
				m_MapArr[i][j] = map_null;
				randArr[len++] = i*MAP_COL + j;//如何二维转为一维
			}

		}
	}
}
void MyMap::DrawMap()
{
	for (int i = 0; i < MAP_ROW; ++i)
	{
		for (int j = 0; j < MAP_COL; ++j)
		{
			switch (m_MapArr[i][j])
			{
			case map_frame:
				printf("*");
				break;
			case map_snake:
				printf("@");
				break;
			case map_food:
				printf("$");
				break;

			case map_null:
				printf(" ");
				break;
			
			}
			
		}printf("\n");
	}
}
void MyMap::SetMapVal(int row, int col, int val)
{
	m_MapArr[row][col] = val;
}