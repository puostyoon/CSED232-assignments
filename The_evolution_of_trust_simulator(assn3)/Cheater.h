#pragma once
#include"Agent.h"
//cheater�� Ŭ����
class Cheater :public Agent {
private:
public:
	int act(int, int);
	virtual void reset_without_reward(); 
	Cheater() :Agent() {} //�⺻ ������
	~Cheater() {} //�Ҹ���
};