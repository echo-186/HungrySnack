#pragma once
#include"stdafx.h"
class Food//用数组，要知道每个的位置
{
public:
	Food();
	~Food();
	void InitFood(short arr[], int &len);
	void ClearFoodNode(int row, int col);
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
	for (int i = 0; i < FOOD_NUM; i++)//此方法中的食物会在地图上找到空余地方生成
	{
		int index = rand() % len;
		int posVal = arr[index];
		DeleteArrVal(arr, len, posVal);//给出一个随机数，然后就删掉
		m_FoodArr[i].row = posVal / MAP_COL;//将一维数组按照二维方式输出，得到行列值
		m_FoodArr[i].col = posVal % MAP_COL;
		m_FoodNum++;
	}

	//	for (int i = 0; i < FOOD_NUM; i++)
	//	{
	//LOGO:		
	//		int row = rand() % (MAP_ROW - 2) + 1; //(1~20)
	//		int col = rand() % (MAP_COL - 2) + 1;//不会到边界上
	//		/*传入蛇的数据
	//		while()
	//		判断食物和食物、蛇有没有重叠
	//		for()
	//		if(重叠)
	//		goto LOGO重新生成随机数
	//		由于此过程循环次数不可控，开销太大放弃
	//		*/
	//		m_FoodArr[i].row = row;
	//		m_FoodArr[i].col = col;
	//	}
}
void Food::ClearFoodNode(int row, int col)//又是数组的删除,这里是MYPOINT数组的删除
{
	for(int i = 0; i < FOOD_NUM; i++)
	{
		if (m_FoodArr[i].row == row && m_FoodArr[i].col == col)
		{
			MoveArrVal(m_FoodArr, m_FoodNum, i);
			break;
		}
}
}