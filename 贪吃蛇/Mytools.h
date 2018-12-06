#pragma once
#include "stdafx.h"

void DeleteArrVal(short arr[], int &len, int delVal)//Êý×éµÄÉ¾³ý
{
	for (int i = 0; i<len; i++)
		if (arr[i] == delVal)
		{
			for (int m = i; m < len - 1; ++m)
			{
				arr[m] = arr[m + 1];
			}
			len--;
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

