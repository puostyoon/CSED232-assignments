#pragma once
#include"DoublyLinkedList.h"
#include"Agent.h"
#include"Copycat.h"
#include"Cheater.h"
#include "Grudger.h"
#include"Detective.h"
#include"Cooperator.h"
//자료구조를 상속받아 agent들을 관리(sort, elimination등을 진행)하는 객체

class Population :public DoublyLinkedList {
private:
	Agent** arr; //Agent*들의 배열의 시작주소, 자세한건 Alloc구현부분 참고
	int nCopycat; //각 직업들의 개수
	int nCheater;
	int nCooperator;
	int nGrudger;
	int nDetective;
public:
	void Alloc(int,int,int,int,int);//arr에 원하는 직업의 개수만큼 각각할당
	//각각 순서는 copycat,cheater,cooperator,grudger,detective
	void Eliminate(); //패자탈락함수
	void Reproduce(); //승자 재생산 함수
	Population();
	~Population();
	void showReward();//population에 들어있는 agent들을 reward순으로 출력
	void sort(); //match 등으로 인해 reward값이 변경되었을 때, 다시 reward순으로 정렬
	int getNCopycat() { return nCopycat; }
	int getNCheater() { return nCheater; }
	int getNCooperator() { return nCooperator; }
	int getNGrudger() { return nGrudger; }
	int getNDetective() { return nDetective; }
	void setNCopycat(int a) {
		nCopycat = a;
	}
	void setNCheater(int a) { nCheater = a; }
	void setNCooperator(int a) { nCooperator = a; }
	void setNGrudger(int a) { nGrudger = a; }
	void setNDetective(int a) { nDetective = a; }
	void resetAll(); //Agent들의 내용물을 모두 초기화
	void resetAll_without_reward(); //reward를 제외한 agent들의 내용물을 전부 초기화
};