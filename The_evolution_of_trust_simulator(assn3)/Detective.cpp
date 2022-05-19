#include"Detective.h"

int Detective::act(int adH, int curr) {
	if (curr > 1)
		cheathistory += (adH - 1); //2라운드부터, 상대방의 history를 통해 상대가 배신한 적 잇는지 확인
	if (curr == 1)
	{
		setState(1);
		setHistory(1);
		return 1; //처음에는  협력
	}
	else if(curr==2)
	{
		setState(0);
		setHistory(0);
		return 0; //두번째에 배신
	}
	else if (curr == 3)
	{
		setState(1);
		setHistory(1);
		return 1; //세 번째에 협력
	}
	else if (curr == 4)
	{
		setState(1);
		setHistory(1);
		return 1; //4번째에  협력
	}
	if (curr == 5) //4라운드 진행 이후, 따라쟁이처럼 행동할지, 배신자처럼행동할지 정한다
	{
		if (cheathistory != 0)
			identity = COPYCAT;
		else
			identity = CHEATER;
	}
	if(curr>4) //4라운드 이후의 진행
	{
		if (identity == COPYCAT)
		{
			setState(adH);
			setHistory(adH);
			return adH; //따라쟁이
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
	identity = 0; //State,History,Reward는 상속받은 Agent의 private이라 직접 값 대입 못하지만, cheathistory, identity는 상속받은거 아니므로 가능함
}