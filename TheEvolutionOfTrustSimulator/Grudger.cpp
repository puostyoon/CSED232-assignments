#include"Grudger.h"

int Grudger::act(int adH, int curr) {
	if(curr>1)
		cheathistory += (adH - 1); //2�������, ������ history�� ���� ��밡 ����� �� �մ��� Ȯ��
	if (curr == 1)
	{
		setState(1);
		setHistory(1);
		return 1; //ó������  ����
	}
	else
	{
		if (cheathistory == 0)
		{
			setState(1);
			setHistory(1);
			return 1; //������������� �������
		}
		else
		{
			setState(0);
			setHistory(0);
			return 0; //������������� ��ӹ��
		}
	}
}
void Grudger::reset_without_reward() {
	setState(0);
	setHistory(0);
	cheathistory = 0;
}
