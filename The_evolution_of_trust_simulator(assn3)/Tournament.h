#pragma once
//tournament�� �����ϴ� ��ü
#include"Population.h"
#include"Match.h"
class Tournament {
private:
	int roundT = 1; //���� �� ��° Tournament����
	Match m;
	int i = 0;
	int j=1;//������ ����� match�� �����ϴ� AGent�� ÷�ڵ�.
	Population* pPopulation; //��ʸ�Ʈ�� �����ϰ� �� �༮�� �����͵�
public:
	void runTournament();
	void runTournamentAll(); //�ѹ��� ��� tournament�� �����ϴ� �Լ�
	Tournament(Population*);
	Tournament(){}
	int isEnd();//tournament�� ���������� ��ȯ
	void resetMember();//roundT,i,j�� �ʱ�ȭ��Ŵ
	void setPopulation(Population* arg);
};