#include"Detective.h"

int Detective::act(int adH, int curr) {
	if (curr > 1)
		cheathistory += (adH - 1); //2�������, ������ history�� ���� ��밡 ����� �� �մ��� Ȯ��
	if (curr == 1)
	{
		setState(1);
		setHistory(1);
		return 1; //ó������  ����
	}
	else if(curr==2)
	{
		setState(0);
		setHistory(0);
		return 0; //�ι�°�� ���
	}
	else if (curr == 3)
	{
		setState(1);
		setHistory(1);
		return 1; //�� ��°�� ����
	}
	else if (curr == 4)
	{
		setState(1);
		setHistory(1);
		return 1; //4��°��  ����
	}
	if (curr == 5) //4���� ���� ����, ��������ó�� �ൿ����, �����ó���ൿ���� ���Ѵ�
	{
		if (cheathistory != 0)
			identity = COPYCAT;
		else
			identity = CHEATER;
	}
	if(curr>4) //4���� ������ ����
	{
		if (identity == COPYCAT)
		{
			setState(adH);
			setHistory(adH);
			return adH; //��������
		}
		else
		{
			setState(0);
			setHistory(0);
			return 0; //cheater
		}
	}
}
void Detective::reset_without_reward() {
	setState(0);
	setHistory(0);
	cheathistory = 0;
	identity = 0; //State,History,Reward�� ��ӹ��� Agent�� private�̶� ���� �� ���� ��������, cheathistory, identity�� ��ӹ����� �ƴϹǷ� ������
}