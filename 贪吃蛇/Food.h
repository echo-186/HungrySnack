#pragma once
#include"stdafx.h"
class Food//�����飬Ҫ֪��ÿ����λ��
{
public:
	Food();
	~Food();
	void InitFood(short arr[],int &len);
public:
	MyPoint const* GetFoodHead()const { return m_FoodArr; }
	int GetFoodNum()const { return m_FoodNum; }
private:
	MyPoint m_FoodArr[FOOD_NUM];
	int m_FoodNum;
};

Food::Food()

{
	memset(m_FoodArr, 0, sizeof(MyPoint)*FOOD_NUM);
	m_FoodNum = 0;
}
void Food::InitFood(short arr[], int &len)
{
	for (int i = 0; i < FOOD_NUM; i++)//�˷����е�ʳ����ڵ�ͼ���ҵ�����ط�����
	{
		int index = rand() % len;
		int posVal=arr[index];
		DeleteArrVal(arr, len, posVal);//����һ���������Ȼ���ɾ��
		m_FoodArr[i].row = posVal / MAP_COL;//��һά���鰴�ն�ά��ʽ������õ�����ֵ
		m_FoodArr[i].col = posVal%MAP_COL;
		m_FoodNum++;
}

//	for (int i = 0; i < FOOD_NUM; i++)
//	{
//LOGO:		
//		int row = rand() % (MAP_ROW - 2) + 1; //(1~20)
//		int col = rand() % (MAP_COL - 2) + 1;//���ᵽ�߽���
//		/*�����ߵ�����
//		while()
//		�ж�ʳ���ʳ�����û���ص�
//		for()
//		if(�ص�)
//		goto LOGO�������������
//		���ڴ˹���ѭ���������ɿأ�����̫�����
//		*/
//		m_FoodArr[i].row = row;
//		m_FoodArr[i].col = col;
//	}
}