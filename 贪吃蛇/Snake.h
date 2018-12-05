#pragma once
#include"stdafx.h"
class Snake//用链表，不需要知道每个蛇神的位置，断开连接方便
{
public:
	Snake();
	~Snake();
	void ClearSnake();
	SnakeNode const* GetSnakeHead() const { return pHead; }
	SnakeDir GetSnakeDir() const { return m_SnakeDir; }
	void InitSnake(short arr[],int &len);//引用，因为要改变它的值
	void SnakeMove();//移动法则，断开尾部到前面
	void SetSnakeDir(SnakeDir const& dir);
	
	
private:
	SnakeNode *pHead;//头结点
	SnakeNode *pEnd;//描述蛇
	SnakeDir m_SnakeDir;//蛇的方向

};
Snake::Snake()
{
	pHead = NULL;
	pEnd = NULL;
}
Snake::~Snake()
{
	ClearSnake();
}
void Snake::ClearSnake()//删除链表的接口
{
	while (pHead)//删除过程中尾指针没用，所以不再另外设置工作指针；
	{
		pEnd = pHead;
		pHead = pHead->pNext;
		delete pEnd;
	}
	pEnd = NULL;
}
void Snake::InitSnake(short arr[], int &len)
{
	m_SnakeDir = s_right;
	//头插法
	for (int i = 0; i <SNAKE_NUM; ++i)//头插尾插：尾插：如果数据进来是有先后顺序的，必须用尾插
	{
		DeleteArrVal(arr, len, 2*MAP_COL + 3 + i);
		SnakeNode *insertNode = new SnakeNode;
		insertNode->SnakePos.row = 2;
		insertNode->SnakePos.col = 3 + i;
		insertNode->pNext = pHead;
		insertNode->pFront = NULL;
		if (pHead)
		{
			pHead->pFront = insertNode;

		}
		else
		
			pEnd = insertNode;
			pHead = insertNode;
		
	}
}
void Snake::SnakeMove()
{
	SnakeNode *temNode = pEnd;
	pEnd = pEnd->pFront;
	pEnd->pNext = NULL;
	temNode->pFront = NULL;//做完这个后它变成了单独节点
	switch (m_SnakeDir)
	{
	case s_up:
		temNode->SnakePos.row = pHead->SnakePos.row - 1;
		temNode->SnakePos.col = pHead->SnakePos.col;
		break;
	case s_down:
		temNode->SnakePos.row = pHead->SnakePos.row +1;
		temNode->SnakePos.col = pHead->SnakePos.col;
		break;
	case s_left:
		temNode->SnakePos.row = pHead->SnakePos.row;
		temNode->SnakePos.col = pHead->SnakePos.col-1;
		break;
	case s_right:
		temNode->SnakePos.row = pHead->SnakePos.row;
		temNode->SnakePos.col = pHead->SnakePos.col+1;
		break;

	}//接下来把临时接地安装在蛇头上
	temNode->pNext = pHead;
	pHead->pFront = temNode;
	pHead = temNode;

}
void Snake::SetSnakeDir(SnakeDir const& dir)
{
	m_SnakeDir = dir;
}






