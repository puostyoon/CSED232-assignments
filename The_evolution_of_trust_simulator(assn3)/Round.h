#pragma once
#include"Agent.h"
#include<iostream>

//라운드를 진행과 관련된 객체
class Round {
private:
	int curRound=1;//현재 라운드 수
	int history1;
	int history2;//라운드를 돌리는 두 agent들의 history
	Agent* ptr1;
	Agent* ptr2; //match를 돌릴 두 agent의 포인터
public:
	Round(int, int,int,Agent*,Agent*);
	Round() {
		curRound = 0; history1 = 0; history2 = 0;
		ptr1 = NULL; ptr2 = NULL;
	}
	Round(Agent*, Agent*);
	int getHistory1()const;
	int getHistory2()const;
	int getCurRound() const;
	void runRound(); //두 agent들로 round 진행
};
