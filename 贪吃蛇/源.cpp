#include"stdafx.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Manage *pGame = NULL;
	pGame = new Manage;
	pGame->InitGame();//��ʼ����Ϸ
	while (true)
	{
		pGame->UpdateGame();
		
		pGame->DrawGame();
		system("cls");
	}
	
	delete pGame;
	return 0;
}