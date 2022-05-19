#include"Tournament.h"

void Tournament::setPopulation(Population* arg) {
	pPopulation = arg;
}


void Tournament::runTournament() {
	m.resetAgent(pPopulation->get_ith_Nodeptr(i)->pdata,  pPopulation->get_ith_Nodeptr(j)->pdata);
	//match를 돌릴 두 agent들을 넣음
	std::cout << "==========="<<i+1<<" vs "<<j+1<<"==========" << std::endl;
	m.runMatch(10); //토너먼트의 각 매치는 10round로 진행됨.
	j++;
	if(j==pPopulation->getLength()) //3개가 tournament를 진행하면 1vs2,1vs3, 그 이후 1vs4가 아닌2vs3으로 하게 됨
	{
		i++;
		j = i + 1;
	}
	roundT++;
	pPopulation->resetAll_without_reward(); //tournament 한 match 진행 후 reward를 제외한 history,identity등을 초기화한다.
}
void Tournament::runTournamentAll() { //한번에 모든 Match를 실행하는 함수, repeatedTournament에서 사용
	int i = 0;
	int j = 1; //tournament의 첫 매치는 1vs1 이 아닌 1vs2 이므로 j=i+1 인것이다.
	for (int k = 0; k < (pPopulation->getLength()) * ((pPopulation->getLength()) - 1) / 2 ; k++) //토너먼트는 nC_2 회의 match로 구성됨
	{
		m.resetAgent(pPopulation->get_ith_Nodeptr(i)->pdata, pPopulation->get_ith_Nodeptr(j)->pdata); //match를 돌릴 두 agent들을 넣음
		m.runMatch(10); //match진행, match는 10라운드로 구성됨
		j++;
		if (j == pPopulation->getLength()) //3개가 tournament를 진행하면 1vs2,1vs3 ,그 이후 1vs4가 아닌 2vs3으로 하게 됨
		{
			i++;
			j = i + 1;
		}
		pPopulation->resetAll_without_reward();//tournament의 한개 match 진행 후 history,identity등을 초기화한다.
	}
}
Tournament::Tournament(Population* p) {
	pPopulation = p;
}
int Tournament::isEnd() {
return roundT ==(pPopulation->getLength())* ((pPopulation->getLength())-1)/2 +1; //round가 nC_2 +1와 같아지면 토너먼트 끝남
}

void Tournament::resetMember() {
	i = 0;
	j = 1;
	roundT = 1; //멤버들을 초기 값으로 초기화
}