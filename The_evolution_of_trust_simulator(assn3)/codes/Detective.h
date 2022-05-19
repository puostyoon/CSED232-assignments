#pragma once
#include"Agent.h"


class Detective :public Agent {
private:
	int cheathistory = 0;//상대방이 배신한 적이 없다면 0을 유지
	int identity;  //4라운드 이후 detective의 행동방향 결정
public:
	int act(int, int);
	void reset_without_reward();
	Detective() :Agent(), identity(0), cheathistory(0) {}
	~Detective() {}
};
