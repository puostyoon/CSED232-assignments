#include"Population.h"
#include<iostream>

/*Alloc
각 직업의 개수만큼에 해당하는 Agent들을 생성하여 list에 집어넣는다.
*/
Population::~Population() //소멸자
{
	for (int i = 0; i < nCheater + nCooperator + nCopycat + nGrudger + nDetective; i++)
		delete arr[i]; //arr에 들어있는 Agent pointer들을 할당 해제
	delete[] arr; //마지막으로 arr 본인을 할당하제
}
void Population::Alloc(int nCopycat, int nCheater,int nCooperator, int nGrudger,int nDetective) {
	arr = new Agent * [nCheater + nCooperator + nCopycat + nGrudger + nDetective]; //동적할당된 Agent의 주소들을 담을 배열 생성
	this->nCopycat = nCopycat;
	this->nCheater = nCheater;
	this->nCooperator = nCooperator;
	this->nGrudger = nGrudger;
	this->nDetective = nDetective; // 각 직업의 개수를 나타내는 멤버 변수 초기화
	int i;
	for (i=0; i < nCopycat; i++)  //각 직업의 개수만큼을 동적할당하여 생성하고 그 주소들을 arr에 넣는다.
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
		Add(arr[i]); //List에, 할당받은 것들을 추가한다.

}
void Population::Eliminate() { //패자탈락함수

	for (int i = 0; i < 5; i++) //패자 탈락 시 맨 뒤의 5개 Node 제거함
	{
		switch (getPLast()->pdata->getId()) //맨 마지막 AGent의 id를 얻어놓는다.
		{
		case COPYCAT: //삭제할 Agent의 id에 따라 nCopycat과 같은 agent의 개수를 나타내는 변수의 값을 변경해줌.
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
	Agent** newarr = new Agent * [5]; //새로 생성할 Agent의 주소들을 담을 배열

	switch (getPFirst()->pdata->getId()) //1등의 직업을 찾음
	{
	case COPYCAT:
		for (int i = 0; i < 5; i++) //1등을 5개 복제해서 동적할당해서 생성시키고 newarr에담아둠
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
		Add(newarr[i]); //List에, 복제한 내용물을 넣음.
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
	NodeType* pointer=getPFirst();//현재 출력할 노드를 가리키는 포인터, 맨 처음에는 first로 초기화시킴

	for (int i = 0; i < getLength(); i++) //agent들과 점수들을 출력함
	{
		std::cout << i+1 << ". "; showID(pointer->pdata->getId()); std::cout << pointer->pdata->getReward() << std::endl;
		pointer = pointer->next;
	}
}
void Population::sort() { //sort 과정: Agent의 포인터를 담는 arr를 만들고 내용물을 복사해서 넣어둠, 
	//원래 list를 삭제함, 복사한 내용들을 list에add함
	
	Agent** newarr = new Agent * [getLength()];  //Agent의 포인터를 담는 배열
	NodeType* ptr = getPFirst(); //노드에 접근하기 위한 포인터
	for (int i = 0; i < getLength(); i++)
	{
		newarr[i] = ptr->pdata; //내용물을 복사해서 넣어둠
		ptr = ptr->next; 
	}
	
	MakeEmpty(); //리스트 비움
	for (int i = 0; i < nCheater + nCooperator + nCopycat + nGrudger + nDetective; i++)
		Add(newarr[i]); //List에, 복사한 내용을 추가함.
}

void Population::resetAll() { //모든 agent들의 내용물(reward포함)을 0으로 초기화 
	NodeType* pointer = getPFirst();//현재 reset시킬 노드를 가리키는 포인터
	for (int i = 0; i < nCheater + nCooperator + nCopycat + nGrudger + nDetective; i++)
	{
		pointer->pdata->reset_without_reward();
		pointer->pdata->setReward(0);
		pointer = pointer->next;
	}
}

void Population::resetAll_without_reward(){//reward를 제외한 history, identity등을 초기화
	NodeType* pointer = getPFirst();//현재 reset시킬 노드를 가리키는 포인터
	for (int i = 0; i < nCheater + nCooperator + nCopycat + nGrudger + nDetective; i++)
	{
		pointer->pdata->reset_without_reward();
		pointer = pointer->next;
	}
}
