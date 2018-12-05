#pragma once
#include"stdafx.h"
class Manage
{
public:
	Manage();
	~Manage();
	void InitGame();//��Ϸ�ر���������������ʼ����Ϸ���������ݣ���������
	void UpdateGame();
	void DrawGame();
	void GetKey();
	
private:
	MyMap *m_pMap;//��һ���Ӷ���ָ��Ƚ����
	Snake *m_pSnake;
	Food *m_pFood;
private:
	void FoodInMap(MapState val);
	void SnakeInMap(MapState mapState);//ͨ�����������ظ����룬����Ҫ���ⲿʹ��,������������û�н����޸ľ���const
	MapState isSnakeMove();//�ж����ܷ��ƶ�
private://�����ߵ��ٶ�
	float m_BeginTime;
	float m_EndTime;
	float m_GameSpeed;
	int m_Key;//׼������ҵĲ�����
private:
	short m_RandArr[MAP_ROW*MAP_COL];//�͵�ͼһ������������,�ѵ�ͼ�����п�λ���±�Ž�����ȷ��ÿ��������������,��short����Ϊ22*32char������
	int m_RandArrlength=0;
};
Manage::Manage()
{
	srand(timeGetTime());//һ�����������
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
	m_pMap = new MyMap;//����ռ�
	m_pMap->InitMap(m_RandArr,m_RandArrlength);//ֻ���Ƶ�ͼ�����ߺ�ʵ��ӳ�����ͼ

	m_pSnake = new Snake;
	m_pSnake->InitSnake(m_RandArr, m_RandArrlength);//���ߴӵ�ͼ��ȥ��
	
	m_pFood = new Food;//���ʳ��
	m_pFood->InitFood(m_RandArr, m_RandArrlength);


	m_BeginTime = timeGetTime() / 1000.f;//c�������и�time�����������windows�ĺ��뼶�������������Եõ������
	m_GameSpeed = 0.3f;//�����ٶ�
}
void Manage::DrawGame()
{
	m_pMap->DrawMap();
}
void Manage::UpdateGame()
{
	GetKey();
	SnakeInMap(map_null);//���ڵ�ͼ��Ϊ��
	m_EndTime = timeGetTime() / 1000.0f;
	if (m_EndTime - m_BeginTime >= m_GameSpeed)//������һ��
	{
		switch (m_Key)//Ҫ����ʱ�����ڣ�����Ļ���ʱ����л��bug
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
	SnakeInMap(map_snake);//���ڵ�ͼΪ�ߣ���һ����������һ�㡣
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
	SnakeNode const *temHead = m_pSnake->GetSnakeHead();//ʹ�߳���
	while (temHead)
	{
		m_pMap->SetMapVal(temHead->SnakePos.row, temHead->SnakePos.col, mapState);
		temHead = temHead->pNext;
	}
}
MapState Manage::isSnakeMove()
{
	SnakeNode const* temSnake = m_pSnake->GetSnakeHead();
	MyPoint pos = temSnake->SnakePos;//�õ��ߵ�λ�ã���Ҫ�ߵķ���
	switch (m_pSnake->GetSnakeDir())//�����ߵķ���Ԥ�ж���һ��λ���ܲ�����
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
		return(MapState) m_pMap->GetMapVal(pos.row,pos.col);//���ص�ͼ״̬
	
}
void Manage::GetKey()
{
	if (_kbhit())
		m_Key = _getch();
}