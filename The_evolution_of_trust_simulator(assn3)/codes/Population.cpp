#include"Population.h"
#include<iostream>

/*Alloc
�� ������ ������ŭ�� �ش��ϴ� Agent���� �����Ͽ� list�� ����ִ´�.
*/
Population::~Population() //�Ҹ���
{
	for (int i = 0; i < nCheater + nCooperator + nCopycat + nGrudger + nDetective; i++)
		delete arr[i]; //arr�� ����ִ� Agent pointer���� �Ҵ� ����
	delete[] arr; //���������� arr ������ �Ҵ�����
}
void Population::Alloc(int nCopycat, int nCheater,int nCooperator, int nGrudger,int nDetective) {
	arr = new Agent * [nCheater + nCooperator + nCopycat + nGrudger + nDetective]; //�����Ҵ�� Agent�� �ּҵ��� ���� �迭 ����
	this->nCopycat = nCopycat;
	this->nCheater = nCheater;
	this->nCooperator = nCooperator;
	this->nGrudger = nGrudger;
	this->nDetective = nDetective; // �� ������ ������ ��Ÿ���� ��� ���� �ʱ�ȭ
	int i;
	for (i=0; i < nCopycat; i++)  //�� ������ ������ŭ�� �����Ҵ��Ͽ� �����ϰ� �� �ּҵ��� arr�� �ִ´�.
	{
		arr[i] = new Copycat();
		arr[i]->setId(COPYCAT);
	}
	for (; i <nCopycat + nCheater; i++)
	{
		arr[i] = new Cheater();
		arr[i]->setId(CHEATER);
	}
	
	for (; i < nCopycat+nCheater+nCooperator; i++)
	{
		arr[i] = new Cooperator();
		arr[i]->setId(COOPERATOR);
	}
	for (; i < nCheater + nCooperator + nCopycat + nGrudger; i++)
	{
		arr[i] = new Grudger();
		arr[i]->setId(GRUDGER);
	}
	for (; i < nCheater + nCooperator + nCopycat + nGrudger + nDetective; i++)
	{
		arr[i] = new Detective();
		arr[i]->setId(DETECTIVE);
	}

	for(int i=0;i< nCheater + nCooperator + nCopycat + nGrudger + nDetective;i++)
		Add(arr[i]); //List��, �Ҵ���� �͵��� �߰��Ѵ�.

}
void Population::Eliminate() { //����Ż���Լ�

	for (int i = 0; i < 5; i++) //���� Ż�� �� �� ���� 5�� Node ������
	{
		switch (getPLast()->pdata->getId()) //�� ������ AGent�� id�� �����´�.
		{
		case COPYCAT: //������ Agent�� id�� ���� nCopycat�� ���� agent�� ������ ��Ÿ���� ������ ���� ��������.
			this->nCopycat = nCopycat - 1;
			break;
		case CHEATER:
			this->nCheater = nCheater - 1;
			break;
		case COOPERATOR:
			this->nCooperator = nCooperator - 1;
			break;
		case GRUDGER:
			this->nGrudger = nGrudger - 1;
			break;
		case DETECTIVE:
			this->nDetective = nDetective - 1;
			break;
		}
		Delete();  
	}

}
void Population::Reproduce() {
	Agent** newarr = new Agent * [5]; //���� ������ Agent�� �ּҵ��� ���� �迭

	switch (getPFirst()->pdata->getId()) //1���� ������ ã��
	{
	case COPYCAT:
		for (int i = 0; i < 5; i++) //1���� 5�� �����ؼ� �����Ҵ��ؼ� ������Ű�� newarr����Ƶ�
		{
			newarr[i] = new Copycat();
			newarr[i]->setId(COPYCAT);
			newarr[i]->setReward(getPFirst()->pdata->getReward());
			nCopycat=nCopycat+1;
		}
		break;
	case CHEATER:
		for (int i = 0; i < 5; i++)
		{
			newarr[i] = new Cheater();
			newarr[i]->setId(CHEATER);
			newarr[i]->setReward(getPFirst()->pdata->getReward());
			nCheater=nCheater +1;
		}
		break;
	case COOPERATOR:
		for (int i = 0; i < 5; i++)
		{
			newarr[i] = new Cooperator();
			newarr[i]->setId(COOPERATOR);
			newarr[i]->setReward(getPFirst()->pdata->getReward());
			nCooperator= nCooperator +1;
		}
		break;
	case GRUDGER:
		for (int i = 0; i < 5; i++)
		{
			newarr[i] = new Grudger();
			newarr[i]->setId(GRUDGER);
			newarr[i]->setReward(getPFirst()->pdata->getReward());
			nGrudger= nGrudger +1;
		}
		break;
	case DETECTIVE:
		for (int i = 0; i < 5; i++)
		{
			newarr[i] = new Detective();
			newarr[i]->setId(DETECTIVE);
			newarr[i]->setReward(getPFirst()->pdata->getReward());
			nDetective= nDetective +1;
		}
		break;
	}
	for (int i = 0; i < 5; i++)
	{
		Add(newarr[i]); //List��, ������ ���빰�� ����.
	}
}
Population::Population(){}

void showID(int arg) {
	switch (arg)
	{
	case 0:
		std::cout << "Copycat: ";
		break;
	case 1:
		std::cout << "Cheater: ";
		break;
	case 2:
		std::cout << "Cooperator: ";
		break;
	case 3:
		std::cout << "Grudger: ";
		break;
	case 4:
		std::cout << "Detective: ";
		break;
	}
}

void Population::showReward() {
	NodeType* pointer=getPFirst();//���� ����� ��带 ����Ű�� ������, �� ó������ first�� �ʱ�ȭ��Ŵ

	for (int i = 0; i < getLength(); i++) //agent��� �������� �����
	{
		std::cout << i+1 << ". "; showID(pointer->pdata->getId()); std::cout << pointer->pdata->getReward() << std::endl;
		pointer = pointer->next;
	}
}
void Population::sort() { //sort ����: Agent�� �����͸� ��� arr�� ����� ���빰�� �����ؼ� �־��, 
	//���� list�� ������, ������ ������� list��add��
	
	Agent** newarr = new Agent * [getLength()];  //Agent�� �����͸� ��� �迭
	NodeType* ptr = getPFirst(); //��忡 �����ϱ� ���� ������
	for (int i = 0; i < getLength(); i++)
	{
		newarr[i] = ptr->pdata; //���빰�� �����ؼ� �־��
		ptr = ptr->next; 
	}
	
	MakeEmpty(); //����Ʈ ���
	for (int i = 0; i < nCheater + nCooperator + nCopycat + nGrudger + nDetective; i++)
		Add(newarr[i]); //List��, ������ ������ �߰���.
}

void Population::resetAll() { //��� agent���� ���빰(reward����)�� 0���� �ʱ�ȭ 
	NodeType* pointer = getPFirst();//���� reset��ų ��带 ����Ű�� ������
	for (int i = 0; i < nCheater + nCooperator + nCopycat + nGrudger + nDetective; i++)
	{
		pointer->pdata->reset_without_reward();
		pointer->pdata->setReward(0);
		pointer = pointer->next;
	}
}

void Population::resetAll_without_reward(){//reward�� ������ history, identity���� �ʱ�ȭ
	NodeType* pointer = getPFirst();//���� reset��ų ��带 ����Ű�� ������
	for (int i = 0; i < nCheater + nCooperator + nCopycat + nGrudger + nDetective; i++)
	{
		pointer->pdata->reset_without_reward();
		pointer = pointer->next;
	}
}
