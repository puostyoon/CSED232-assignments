#pragma once
#include"Agent.h"
class Player :public Agent
{
private:
	int input; //player의 입력
public:
	int act(int,int); 
	void reset_without_reward();
	Player();
	~Player() {}
	int getInput() const;
	void setInput(int a); //getter와 setter
};