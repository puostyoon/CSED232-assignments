#pragma once
#include"Agent.h"
#include<iostream>

//���带 ����� ���õ� ��ü
class Round {
private:
	int curRound=1;//���� ���� ��
	int history1;
	int history2;//���带 ������ �� agent���� history
	Agent* ptr1;
	Agent* ptr2; //match�� ���� �� agent�� ������
public:
	Round(int, int,int,Agent*,Agent*);
	Round() {
		curRound = 0; history1 = 0; history2 = 0;
		ptr1 = NULL; ptr2 = NULL;
	}
	Round(Agent*, Agent*);
	int getHistory1()const;
	int getHistory2()const;
	int getCurRound() const;
	void runRound(); //�� agent��� round ����
};