#pragma once
#include"stdafx.h"
class Snake//����������Ҫ֪��ÿ�������λ�ã��Ͽ����ӷ���
{
public:
	Snake();
	~Snake();
	void ClearSnake();
	SnakeNode const* GetSnakeHead() const { return pHead; }
	SnakeDir GetSnakeDir() const { return m_SnakeDir; }
	void InitSnake(short arr[],int &len);//���ã���ΪҪ�ı�����ֵ
	void SnakeMove();//�ƶ����򣬶Ͽ�β����ǰ��
	void SetSnakeDir(SnakeDir const& dir);
	
	
private:
	SnakeNode *pHead;//ͷ���
	SnakeNode *pEnd;//������
	SnakeDir m_SnakeDir;//�ߵķ���

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
void Snake::ClearSnake()//ɾ������Ľӿ�
{
	while (pHead)//ɾ��������βָ��û�ã����Բ����������ù���ָ�룻
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
	//ͷ�巨
	for (int i = 0; i <SNAKE_NUM; ++i)//ͷ��β�壺β�壺������ݽ��������Ⱥ�˳��ģ�������β��
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
	temNode->pFront = NULL;//���������������˵����ڵ�
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

	}//����������ʱ�ӵذ�װ����ͷ��
	temNode->pNext = pHead;
	pHead->pFront = temNode;
	pHead = temNode;

}
void Snake::SetSnakeDir(SnakeDir const& dir)
{
	m_SnakeDir = dir;
}






