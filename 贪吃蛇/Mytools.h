#pragma once
#include "stdafx.h"
template<class T>//ɾ���������ݽṹ����
void MoveArrVal(T arr[], int &len, int index)
{
	for (int m = index; m < len - 1; ++m)
	{
		arr[m] = arr[m + 1];
	}
	len--;
}

void DeleteArrVal(short arr[], int &len, int delVal)//�����ɾ��
{
	for (int i = 0; i<len; i++)
		if (arr[i] == delVal)
		{
			MoveArrVal(arr, len, i);
			/*
			for (int m = i; m < len - 1; ++m)
			{
				arr[m] = arr[m + 1];
			}
			len--;*/
			break;
		}
}
void ChangeArrVal(short arr[], int &len, int srcVal, int destVal)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == destVal)
		{
			arr[i] = srcVal;
			break;
		}
	}
}
