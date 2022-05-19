#pragma once
#include"Agent.h"
class Grudger:public Agent {
private:
	int cheathistory=0;//상대방이 배신한 적이 없다면 0을 유지
public:
	int act(int, int);
	void reset_without_reward();
	Grudger() :Agent(), cheathistory(0) {}
	~Grudger() {}
};