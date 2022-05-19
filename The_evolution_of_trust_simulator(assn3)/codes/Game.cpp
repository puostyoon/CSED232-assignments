#include"Game.h"
#include"iostream"
#include"Round.h"
#include"Player.h"
#include"Match.h"  
#include"Tournament.h"
void showline()//일정한 횟수의 ====을 출력하기 위해 만든 함수
{
	std::cout << "===========================" << std::endl;
}
void showline2()//일정한 횟수의 ----을 출력하기 위해 만든 함수
{
	std::cout << "---------------------------" << std::endl;
}
void showname(int a)//showreward부분 등에서 이용할 함수, 인자로 직업이름에 해당하는 정수를 받아 직업이름을 출력
{ 
	switch (a)
	{
	case 1:
		std::cout << "Copycat: ";
		break;
	case 2:
		std::cout << "Cheater: ";
		break;
	case 3:
		std::cout << "Cooperator: ";
		break;
	case 4:
		std::cout << "Grudger: ";
		break;
	case 5:
		std::cout << "Detective: ";
		break;

	}
} 
void Game::showMenu() {
	showline();
	std::cout << "Select Menu" << std::endl;
	showline();
	std::cout << "1. Single Match\n";
	std::cout << "2. Single Tournament\n";
	std::cout << "3. Repeated Tournament\n";
	std::cout << "4. Exit\n";
	showline();
}
void Game::singleMatch() {
	int TNR; //singleMAtch할 때의 Total Round Number
	int Opponent; //상대 직업의 id 나타냄
	int select; //cooperate인지cheat인지 입력받음
	Player p;
	Agent* pOppo; //Opponent가 될 Agent를 가리키는 포인터
	std::cout << "Total Round Number: ";
	while (1)
	{
		std::cin >> TNR;
		if (TNR > 0 && TNR<51) //1이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
			break;
		else
			std::cout << "Invalid Input!\n";
	}
	std::cout << "Select an Opponent! Copycat(1), Cheater(2), Cooperator(3), Grudger(4), Detective(5)\n";
	while (1)
	{
		std::cin >> Opponent;
		if (Opponent > 0 && Opponent < 6) //1이상 5이하가 아닌 다른 값을 받으면 다시 입력받음
			break;
		else
			std::cout << "Invalid Input!\n";
	}
	switch (Opponent) //입력받은 Opponent에 따라 적이 될 Agent를 정해줌
	{
	case 1:
		pOppo = new Copycat;
		break;
	case 2:
		pOppo = new Cheater;
		break;
	case 3:
		pOppo = new Cooperator;
		break;
	case 4:
		pOppo = new Grudger;
		break;
	case 5:
		pOppo = new Detective;
		break;
	default:
		pOppo = NULL;
	}
	Round r(&p, pOppo); //라운드 생성
	for (int i = 1; i <= TNR; i++) //TNR까지 라운드를 돌림
	{
		r.runRound();
		//아래부터는 화면출력
		std::cout << "Player: ";
		if (r.getHistory1() == 0)
			std::cout << " Cheating!" << std::endl;
		else
			std::cout << " Cooperating!" << std::endl;
		showname(Opponent);
		if (r.getHistory2() == 0)
			std::cout << " Cheating!" << std::endl;
		else
			std::cout << " Cooperating!" << std::endl;
		std::cout << "---------------------------\n";
		std::cout << "Total Reward\n";
		std::cout << "1. ";
		if (p.getReward() >= pOppo->getReward())
		{
			std::cout << "Player: " << p.getReward()<<std::endl;
			std::cout << "2. ";
			showname(Opponent);
			std::cout << pOppo->getReward() << std::endl;
		}		
		else
		{
			std::cout << "Player: " << p.getReward() << std::endl;
			std::cout << "2. ";
			showname(Opponent);
			std::cout << pOppo->getReward() << std::endl;
		}
	}
	showline();
	if (p.getReward() > pOppo->getReward())//승자출력
		std::cout << "The winner is Player\n";
	else if (p.getReward() < pOppo->getReward())
	{
		std::cout << "The winner is ";
		switch (Opponent)
		{
		case 1:
			std::cout << "Copycat";
			break;
		case 2:
			std::cout << "Cheater";
			break;
		case 3:
			std::cout << "Cooperator";
			break;
		case 4:
			std::cout << "Grudger";
			break;
		case 5:
			std::cout << "Detective";
			break;
		}
			std::cout << std::endl;
	}
	else //비기는 경우
		std::cout << "Duce!\n";
	delete pOppo;
}
void Game::singleTournament() {
	Population p;
	int nCopycat, nCheater, nCooperator, nGrudger, nDetective; //각 직업들의 개수
	std::cout << "Decide Population\n";
	while (1) //전체 인원이 2 미만 또는 50 초과이면 다시 입력받음
	{
		std::cout << "Copycat: ";
		while (1)
		{
			std::cin >> nCopycat;
			if (nCopycat >= 0 && nCopycat < 51) //0이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Cheater: ";
		while (1)
		{
			std::cin >> nCheater;
			if (nCheater >= 0 && nCheater < 51) //0이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Cooperator: ";
		while (1)
		{
			std::cin >> nCooperator;
			if (nCooperator >= 0 && nCooperator < 51) //0이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Grudger: ";
		while (1)
		{
			std::cin >> nGrudger;
			if (nGrudger >= 0 && nGrudger < 51) //0이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Detective: ";
		while (1)
		{
			std::cin >> nDetective;
			if (nDetective >= 0 && nDetective < 51) //0이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		if (nCheater + nCooperator + nCopycat + nGrudger + nDetective > 1 && //전체 인원이 2 미만 또는 50 초과이면 다시 입력받음
			nCheater + nCooperator + nCopycat + nGrudger + nDetective < 51)
			break;
		else
			std::cout << "Invalid Input!\n";
	}
	showline2();
	p.Alloc(nCopycat, nCheater, nCooperator, nGrudger, nDetective);
	Tournament t(&p);
	int selectinput; // continue, stop할지 입력
	while(1)//tournament실행
	{
		p.showReward();
		showline2();
		std::cout << "Continue(1) or Stop(0)" << std::endl;
		while (1)
		{
			std::cin >> selectinput;
			if (selectinput==1|| selectinput==0) //1,0이 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		if (selectinput == 0)
			break;
		else if (selectinput == 1)
				t.runTournament();

		if (t.isEnd())
		{
			p.showReward(); //게임 끝나고 나서 한번 더 show 한다.
			break;
		}
	}
	if (selectinput == 0) //selectinput==0이면 따로 reward출력하지 않고 바로 시작메뉴로 돌아감
		return;
	p.sort(); //정렬시킴
	showline();
	p.showReward(); //정렬된거 보여줌
	t.resetMember(); //tournament의 i,j member를 초기화함
}
void Game::repeatedTournament() {
	Population p;
	int nCopycat, nCheater, nCooperator, nGrudger, nDetective; //각 직업들의 개수
	int totalNumber;// 총 토너먼트 횟수
	std::cout << "Total Tournament Number: ";
	while (1) //전체 인원이 6 미만 또는 50 초과이면 다시 입력받음
	{
		std::cin >> totalNumber;
		if (totalNumber >0 && totalNumber < 51) //1이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
			break;
		else
			std::cout << "Invalid Input!\n";
	}
	std::cout << "Decide Population\n";
	while (1)
	{
		std::cout << "Copycat: ";
		while (1)
		{
			std::cin >> nCopycat;
			if (nCopycat >= 0 && nCopycat < 51) //0이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Cheater: ";
		while (1)
		{
			std::cin >> nCheater;
			if (nCheater >= 0 && nCheater < 51) //0이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Cooperator: ";
		while (1)
		{
			std::cin >> nCooperator;
			if (nCooperator >= 0 && nCooperator < 51) //0이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Grudger: ";
		while (1)
		{
			std::cin >> nGrudger;
			if (nGrudger >= 0 && nGrudger < 51) //0이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Detective: ";
		while (1)
		{
			std::cin >> nDetective;
			if (nDetective >= 0 && nDetective < 51) //0이상 50이하가 아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		if (nCheater + nCooperator + nCopycat + nGrudger + nDetective > 5 && //전체 인원이 6 미만 또는 50 초과이면 다시 입력받음
			nCheater + nCooperator + nCopycat + nGrudger + nDetective < 51)
			break;
		else
			std::cout << "Invalid Input!\n";
	}
	showline2();
	p.Alloc(nCopycat, nCheater, nCooperator, nGrudger, nDetective);
	Tournament t;
	int selectinput;
	int selectinput2;
	int selectinput3; //각각 tournament 진행, eliminate 진행, reproduce 진행의 입력을 받음
	for (int I = 0; I < totalNumber;I++)//tournament실행
	{
		t.setPopulation(&p);  //match 이후 Population의 내용물이 변경되었으니 tournament object가 진행시키게 될 population을 변경된 걸로 다시 가리키게함
		p.showReward();
		showline2();
		std::cout << "Continue(1) or Stop(0)" << std::endl;
		while (1)
		{
			std::cin >> selectinput;
			if (selectinput == 0 || selectinput == 1) //0,1이아닌 다른 값을 받으면 다시 입력받음
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		if (selectinput == 0)
			break;
		else if (selectinput == 1)
		{
			t.runTournamentAll(); //모든 매치의 토너먼트 진행
			p.sort();
			std::cout << "=======Tournament "<<I+1<< "========" << std::endl;
			p.showReward();
			showline2();
			std::cout << "Eliminate(1) or Stop(0)\n";//eliminate 입력, eliminate과정
			while (1)
			{
				std::cin >> selectinput2;
				if (selectinput2 == 0 || selectinput2 == 1) //0,1이아닌 다른 값을 받으면 다시 입력받음
					break;
				else
					std::cout << "Invalid Input!\n";
			}
			if (selectinput2 == 1)
				p.Eliminate();
			else if (selectinput2 == 0)
				break;
			showline2();
	
			std::cout << "Reproduce(1) or Stop(0)\n"; //reproduce입력 및 reproduce과정
			while (1)
			{
				std::cin >> selectinput3;
				if (selectinput3 == 0 || selectinput3 == 1) //0,1이아닌 다른 값을 받으면 다시 입력받음
					break;
				else
					std::cout << "Invalid Input!\n";
			}
			if (selectinput3 == 1)
			{
				p.Reproduce();
				p.resetAll();
			}
			else if (selectinput3 == 0)
				break;
			showline2();
		}
	}
	if (selectinput == 0 || selectinput2 == 0|| selectinput3 == 0)
		return; //stop이면 추가로 showreward하지 않고 바로 시작메뉴로 돌아감
	p.showReward(); //정렬된거 보여줌
}
void Game::runGame()
{
	int reinput;// reinput=0이면 정상 입력, 1이면 잘못된 입력, 다시 입력받음
	std::cout << "Command: ";
	do
	{
		reinput = 0; //일단은 정상입력받았다고 가정
		std::cin >> selectMenu;
		switch (selectMenu) //선택한 것에 따라 원하는 게임 진행
		{
		case 1:
			singleMatch();
			break;
		case 2:
			singleTournament();
			break;
		case 3:
			repeatedTournament();
			break;
		case 4:
			exit(100);
			break;
		default:
			std::cout << "Invalid Input!\n";
			reinput = 1;
		}
	} while (reinput == 1);
}