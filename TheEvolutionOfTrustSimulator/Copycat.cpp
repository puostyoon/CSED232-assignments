#include"Copycat.h"
#include<iostream>
int Copycat::act(int adH,int curr) {
	if (curr == 1)
	{
		setState(1);
		setHistory(1);
		return 1;
	}
	else
	{
		setState(adH); //round1�� ���� ����, �� �ܿ��� ���� ������ �ൿ copy
		setHistory(adH);
		return adH;
	}
}
void Copycat::reset_without_reward() {
	setState(0);
	setHistory(0);
}