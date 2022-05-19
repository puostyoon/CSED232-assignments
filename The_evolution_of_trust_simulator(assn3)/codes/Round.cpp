#include"Round.h"
#include"iostream"
Round::Round(int cur, int his1,int his2, Agent* P1, Agent*P2) {
	curRound = cur;
	history1 = his1;
	history2 = his2;
	ptr1 = P1;
	ptr2 = P2;
}
Round::Round(Agent* p1, Agent* p2)
{
	curRound = 1;
	history1 = 0;
	history2 = 0;
	ptr1 = p1;
	ptr2 = p2;
}
int Round::getHistory1()const {
	return history1;
}
int Round::getHistory2()const {
	return history2;
}
int Round::getCurRound() const {
	return curRound;
}
void Round::runRound() {

	int temphistory1, temphistory2; //history�� �����س��� �ӽ� ����, 

		temphistory1 = ptr1->act(history2,curRound); //�� agent���� �ൿ��Ŵ, �׸��� ��ȯ�� history�� ������
		temphistory2 = ptr2->act(history1,curRound);//�� agent���� �ൿ��Ŵ, �׸��� ��ȯ�� history�� ������
		history1 = temphistory1;
		history2 = temphistory2; //history������ ���� ���� ������ �ٲ�
		if (temphistory1 == 0 && temphistory2 == 0)
		{
			//�� �� ����ϸ� �ƹ��� reward�� ��������
		}
		if (temphistory1 == 0 && temphistory2 == 1) //���ʸ� ����� ���
		{
			ptr1->plusReward(3);
			ptr2->minusReward(1);
		}
		if (temphistory1 == 1 && temphistory2 == 0) //���ʸ� ����� ���
		{
			ptr2->plusReward(3);
			ptr1->minusReward(1);
		}
		if (temphistory1 == 1 && temphistory2 == 1) //���� �� ������ ���
		{
			ptr1->plusReward(2);
			ptr2->plusReward(2);
		}
		curRound++;
}