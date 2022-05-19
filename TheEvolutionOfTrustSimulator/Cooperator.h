#pragma once
#include"Agent.h"
//Cooperator의 클래스
class Cooperator :public Agent {
private:
public:
	int act(int, int);
	void reset_without_reward();
	Cooperator() :Agent() {} //기본 생성자
	~Cooperator() {} //소멸자
};
