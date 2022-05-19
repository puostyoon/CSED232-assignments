#pragma once
//tournament를 진행하는 객체
#include"Population.h"
#include"Match.h"
class Tournament {
private:
	int roundT = 1; //현재 몇 번째 Tournament인지
	Match m;
	int i = 0;
	int j=1;//다음에 진행될 match에 참가하는 AGent의 첨자들.
	Population* pPopulation; //토너먼트에 참가하게 될 녀석의 데이터들
public:
	void runTournament();
	void runTournamentAll(); //한번에 모든 tournament를 실행하는 함수
	Tournament(Population*);
	Tournament(){}
	int isEnd();//tournament가 끝났는지를 반환
	void resetMember();//roundT,i,j를 초기화시킴
	void setPopulation(Population* arg);
};