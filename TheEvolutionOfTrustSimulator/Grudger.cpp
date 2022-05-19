#include"Grudger.h"

int Grudger::act(int adH, int curr) {
	if(curr>1)
		cheathistory += (adH - 1); //2라운드부터, 상대방의 history를 통해 상대가 배신한 적 잇는지 확인
	if (curr == 1)
	{
		setState(1);
		setHistory(1);
		return 1; //처음에는  협력
	}
	else
	{
		if (cheathistory == 0)
		{
			setState(1);
			setHistory(1);
			return 1; //배신하지않으면 계속협력
		}
		else
		{
			setState(0);
			setHistory(0);
			return 0; //배신한적있으면 계속배신
		}
	}
}
void Grudger::reset_without_reward() {
	setState(0);
	setHistory(0);
	cheathistory = 0;
}
