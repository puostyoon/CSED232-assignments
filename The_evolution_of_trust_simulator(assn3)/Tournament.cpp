#include"Tournament.h"

void Tournament::setPopulation(Population* arg) {
	pPopulation = arg;
}


void Tournament::runTournament() {
	m.resetAgent(pPopulation->get_ith_Nodeptr(i)->pdata,  pPopulation->get_ith_Nodeptr(j)->pdata);
	//match�� ���� �� agent���� ����
	std::cout << "==========="<<i+1<<" vs "<<j+1<<"==========" << std::endl;
	m.runMatch(10); //��ʸ�Ʈ�� �� ��ġ�� 10round�� �����.
	j++;
	if(j==pPopulation->getLength()) //3���� tournament�� �����ϸ� 1vs2,1vs3, �� ���� 1vs4�� �ƴ�2vs3���� �ϰ� ��
	{
		i++;
		j = i + 1;
	}
	roundT++;
	pPopulation->resetAll_without_reward(); //tournament �� match ���� �� reward�� ������ history,identity���� �ʱ�ȭ�Ѵ�.
}
void Tournament::runTournamentAll() { //�ѹ��� ��� Match�� �����ϴ� �Լ�, repeatedTournament���� ���
	int i = 0;
	int j = 1; //tournament�� ù ��ġ�� 1vs1 �� �ƴ� 1vs2 �̹Ƿ� j=i+1 �ΰ��̴�.
	for (int k = 0; k < (pPopulation->getLength()) * ((pPopulation->getLength()) - 1) / 2 ; k++) //��ʸ�Ʈ�� nC_2 ȸ�� match�� ������
	{
		m.resetAgent(pPopulation->get_ith_Nodeptr(i)->pdata, pPopulation->get_ith_Nodeptr(j)->pdata); //match�� ���� �� agent���� ����
		m.runMatch(10); //match����, match�� 10����� ������
		j++;
		if (j == pPopulation->getLength()) //3���� tournament�� �����ϸ� 1vs2,1vs3 ,�� ���� 1vs4�� �ƴ� 2vs3���� �ϰ� ��
		{
			i++;
			j = i + 1;
		}
		pPopulation->resetAll_without_reward();//tournament�� �Ѱ� match ���� �� history,identity���� �ʱ�ȭ�Ѵ�.
	}
}
Tournament::Tournament(Population* p) {
	pPopulation = p;
}
int Tournament::isEnd() {
return roundT ==(pPopulation->getLength())* ((pPopulation->getLength())-1)/2 +1; //round�� nC_2 +1�� �������� ��ʸ�Ʈ ����
}

void Tournament::resetMember() {
	i = 0;
	j = 1;
	roundT = 1; //������� �ʱ� ������ �ʱ�ȭ
}