#pragma once
#include"DoublyLinkedList.h"
#include"Agent.h"
#include"Copycat.h"
#include"Cheater.h"
#include "Grudger.h"
#include"Detective.h"
#include"Cooperator.h"
//�ڷᱸ���� ��ӹ޾� agent���� ����(sort, elimination���� ����)�ϴ� ��ü

class Population :public DoublyLinkedList {
private:
	Agent** arr; //Agent*���� �迭�� �����ּ�, �ڼ��Ѱ� Alloc�����κ� ����
	int nCopycat; //�� �������� ����
	int nCheater;
	int nCooperator;
	int nGrudger;
	int nDetective;
public:
	void Alloc(int,int,int,int,int);//arr�� ���ϴ� ������ ������ŭ �����Ҵ�
	//���� ������ copycat,cheater,cooperator,grudger,detective
	void Eliminate(); //����Ż���Լ�
	void Reproduce(); //���� ����� �Լ�
	Population();
	~Population();
	void showReward();//population�� ����ִ� agent���� reward������ ���
	void sort(); //match ������ ���� reward���� ����Ǿ��� ��, �ٽ� reward������ ����
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
	void resetAll(); //Agent���� ���빰�� ��� �ʱ�ȭ
	void resetAll_without_reward(); //reward�� ������ agent���� ���빰�� ���� �ʱ�ȭ
};