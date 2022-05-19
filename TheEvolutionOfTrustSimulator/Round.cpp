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

	int temphistory1, temphistory2; //history를 저장해놓을 임시 변수, 

		temphistory1 = ptr1->act(history2,curRound); //각 agent들을 행동시킴, 그리고 반환된 history를 저장함
		temphistory2 = ptr2->act(history1,curRound);//각 agent들을 행동시킴, 그리고 반환된 history를 저장함
		history1 = temphistory1;
		history2 = temphistory2; //history값들을 새로 얻은 값으로 바꿈
		if (temphistory1 == 0 && temphistory2 == 0)
		{
			//둘 다 배신하면 아무런 reward의 변동없음
		}
		if (temphistory1 == 0 && temphistory2 == 1) //한쪽만 배신한 경우
		{
			ptr1->plusReward(3);
			ptr2->minusReward(1);
		}
		if (temphistory1 == 1 && temphistory2 == 0) //한쪽만 배신한 경우
		{
			ptr2->plusReward(3);
			ptr1->minusReward(1);
		}
		if (temphistory1 == 1 && temphistory2 == 1) //양쪽 다 협력한 경우
		{
			ptr1->plusReward(2);
			ptr2->plusReward(2);
		}
		curRound++;
}