#pragma once
#include"Agent.h"
class Grudger:public Agent {
private:
	int cheathistory=0;//������ ����� ���� ���ٸ� 0�� ����
public:
	int act(int, int);
	void reset_without_reward();
	Grudger() :Agent(), cheathistory(0) {}
	~Grudger() {}
};