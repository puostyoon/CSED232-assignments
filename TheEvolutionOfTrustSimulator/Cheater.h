#pragma once
#include"Agent.h"
//cheater의 클래스
class Cheater :public Agent {
private:
public:
	int act(int, int);
	virtual void reset_without_reward(); 
	Cheater() :Agent() {} //기본 생성자
	~Cheater() {} //소멸자
};