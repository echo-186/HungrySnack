#pragma once
#include"stdafx.h"
class Manage
{
public:
	Manage();
	~Manage();
	void InitGame();//游戏必备，基础操作，初始化游戏，更新数据，绘制数据
	void UpdateGame();
	void DrawGame();
	void GetKey();
	
private:
	MyMap *m_pMap;//给一个子对象，指针比较灵活
	Snake *m_pSnake;
	Food *m_pFood;
private:
	void FoodInMap(MapState val);
	void SnakeInMap(MapState mapState);//通过函数减少重复代码，不需要在外部使用,如果自身的数据没有进行修改就用const
	MapState isSnakeMove();//判断蛇能否移动
private://控制蛇的速度
	float m_BeginTime;
	float m_EndTime;
	float m_GameSpeed;
	int m_Key;//准备做玩家的操作了
private:
	short m_RandArr[MAP_ROW*MAP_COL];//和地图一样大的随机数组,把地图上所有空位的下标放进来，确保每生成随机数不会变,用short是因为22*32char不够了
	int m_RandArrlength=0;
};
Manage::Manage()
{
	srand(timeGetTime());//一个随机数生成
	m_pMap = NULL;
	m_pSnake = NULL;
	m_BeginTime = 0.0;
	m_EndTime = 0.0;
	m_GameSpeed = 0.0;
}


Manage::~Manage()
{
	if (m_pMap)
		delete m_pMap;
	if (m_pSnake)
		delete m_pSnake;
}
void Manage::InitGame()
{
	memset(m_RandArr, 0, sizeof(short)*MAP_ROW*MAP_COL);
	m_RandArrlength = 0;
	m_pMap = new MyMap;//分配空间
	m_pMap->InitMap(m_RandArr,m_RandArrlength);//只绘制地图，把蛇和实物映射进地图

	m_pSnake = new Snake;
	m_pSnake->InitSnake(m_RandArr, m_RandArrlength);//把蛇从地图中去掉
	
	m_pFood = new Food;//添加食物
	m_pFood->InitFood(m_RandArr, m_RandArrlength);


	m_BeginTime = timeGetTime() / 1000.f;//c语言中有个time函数，这个是windows的毫秒级函数。这样可以得到随机数
	m_GameSpeed = 0.3f;//控制速度
}
void Manage::DrawGame()
{
	m_pMap->DrawMap();
}
void Manage::UpdateGame()
{
	GetKey();
	SnakeInMap(map_null);//蛇在地图里为空
	m_EndTime = timeGetTime() / 1000.0f;
	if (m_EndTime - m_BeginTime >= m_GameSpeed)//让蛇慢一点
	{
		switch (m_Key)//要放在时间轴内，在外的话，时间差中会出bug
		{
		case 'w':
		case'W':
			if (m_pSnake->GetSnakeDir() != s_down)
				m_pSnake->SetSnakeDir(s_up);
			break;
		case 's':
			if (m_pSnake->GetSnakeDir() != s_up)
				m_pSnake->SetSnakeDir(s_down);
			break;
		case 'a':
			if (m_pSnake->GetSnakeDir() != s_right)
				m_pSnake->SetSnakeDir(s_left);
			break;
		case 'd':
			if (m_pSnake->GetSnakeDir() != s_left)
				m_pSnake->SetSnakeDir(s_right);
			break;
		}
		switch (isSnakeMove())
		{case map_null:
			m_pSnake->SnakeMove();
			break;
		case map_food:
			break;
		}
		m_BeginTime = m_EndTime;
	}
	FoodInMap(map_food);
	SnakeInMap(map_snake);//蛇在地图为蛇，下一步，让蛇慢一点。
}
void Manage::FoodInMap(MapState val)
{
	MyPoint const *tempFood = m_pFood->GetFoodHead();
	for (int i = 0; i < m_pFood->GetFoodNum(); ++i)
	{
		m_pMap->SetMapVal((tempFood + i)->row, (tempFood + i)->col, val);
	}
}
void Manage::SnakeInMap(MapState mapState)
{
	SnakeNode const *temHead = m_pSnake->GetSnakeHead();//使蛇出现
	while (temHead)
	{
		m_pMap->SetMapVal(temHead->SnakePos.row, temHead->SnakePos.col, mapState);
		temHead = temHead->pNext;
	}
}
MapState Manage::isSnakeMove()
{
	SnakeNode const* temSnake = m_pSnake->GetSnakeHead();
	MyPoint pos = temSnake->SnakePos;//得到蛇的位置，再要蛇的方向
	switch (m_pSnake->GetSnakeDir())//根据蛇的方向预判断下一个位置能不能走
	{
	case s_up:
		pos.row--;
		break;
	case s_down:
		pos.row++;
		break;
	case s_left:
		pos.col--;
		break;
	case s_right:
		pos.col++;
		break;
	}
		return(MapState) m_pMap->GetMapVal(pos.row,pos.col);//返回地图状态
	
}
void Manage::GetKey()
{
	if (_kbhit())
		m_Key = _getch();
}