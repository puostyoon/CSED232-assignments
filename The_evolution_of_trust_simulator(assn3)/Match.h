#pragma once
#include"Round.h"
//Ư���� ������ŭ�� round�� �����ϴ� ��ü
class Match {
private:
	int roundLimit; //������ ���� ����
	int curRound = 1;//���� ���� ��
	int winner=1;// 1�̸� ptr1�� ����Ű�� agent�� ����,2�̸� ptr2�� ����Ű�� agent�� ����
	Agent* ptr1;
	Agent* ptr2; //match�� ���� �� agent�� ���� ����Ű�� ������
public:
	void runMatch(int); //roundLimit�� �� ��ŭ round�� ������
	Match(Agent*, Agent*, int); 
	Match() {}
	int getWinner(); //������ ������ ��ȯ
	void resetAgent(Agent*, Agent*); //�����͵��� ����Ű�� AGent�� �ʱ�ȭ
};