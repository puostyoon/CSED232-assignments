#include<iostream>
#include"Game.h"
int main()
{
	Game g1; //���� object
	while (1) //4���� ���� ���θ޴����� ���� ���� �ϱ� ������ ��� ���� ������
	{
		g1.showMenu();
		g1.runGame();
	}
	return 0;
}