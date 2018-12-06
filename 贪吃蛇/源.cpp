#include"stdafx.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Manage *pGame = NULL;
	pGame = new Manage;
	pGame->InitGame();//³õÊ¼»¯ÓÎÏ·
	while (true)
	{
		//if(!pGame->UpdateGame())
		//	break;//ËÀÍö
		if (!pGame->UpdateGame())
			pGame->InitGame();
		pGame->DrawGame();
		system("cls");
	}
	
	delete pGame;
	return 0;
}