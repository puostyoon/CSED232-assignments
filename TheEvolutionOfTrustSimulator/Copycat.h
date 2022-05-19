#pragma once
#include"Agent.h"
//Copycat의 클래스
class Copycat :public Agent {
private:
public:
	int act(int,int);
	void reset_without_reward();
	Copycat() :Agent() {}
	~Copycat() {}
};
