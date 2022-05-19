#include<iostream>
#include"Game.h"
int main()
{
	Game g1; //게임 object
	while (1) //4번을 통해 메인메뉴에서 게임 종료 하기 전까지 계속 게임 진행함
	{
		g1.showMenu();
		g1.runGame();
	}
	return 0;
}