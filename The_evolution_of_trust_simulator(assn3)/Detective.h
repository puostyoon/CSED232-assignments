#pragma once
#include"Agent.h"


class Detective :public Agent {
private:
	int cheathistory = 0;//������ ����� ���� ���ٸ� 0�� ����
	int identity;  //4���� ���� detective�� �ൿ���� ����
public:
	int act(int, int);
	void reset_without_reward();
	Detective() :Agent(), identity(0), cheathistory(0) {}
	~Detective() {}
};
