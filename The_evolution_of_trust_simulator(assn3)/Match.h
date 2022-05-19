#pragma once
#include"Round.h"
//특정한 갯수만큼의 round를 진행하는 객체
class Match {
private:
	int roundLimit; //진행할 라운드 개수
	int curRound = 1;//현재 라운드 수
	int winner=1;// 1이면 ptr1이 가리키는 agent가 승자,2이면 ptr2가 가리키는 agent가 승자
	Agent* ptr1;
	Agent* ptr2; //match를 돌릴 두 agent를 각각 가리키는 포인터
public:
	void runMatch(int); //roundLimit의 수 만큼 round를 진행함
	Match(Agent*, Agent*, int); 
	Match() {}
	int getWinner(); //승자의 포인터 반환
	void resetAgent(Agent*, Agent*); //포인터들이 가리키는 AGent를 초기화
};