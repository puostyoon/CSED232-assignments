#pragma once
#include"Agent.h"
//Cooperator�� Ŭ����
class Cooperator :public Agent {
private:
public:
	int act(int, int);
	void reset_without_reward();
	Cooperator() :Agent() {} //�⺻ ������
	~Cooperator() {} //�Ҹ���
};
