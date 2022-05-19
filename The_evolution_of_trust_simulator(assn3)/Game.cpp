#include"Game.h"
#include"iostream"
#include"Round.h"
#include"Player.h"
#include"Match.h"  
#include"Tournament.h"
void showline()//������ Ƚ���� ====�� ����ϱ� ���� ���� �Լ�
{
	std::cout << "===========================" << std::endl;
}
void showline2()//������ Ƚ���� ----�� ����ϱ� ���� ���� �Լ�
{
	std::cout << "---------------------------" << std::endl;
}
void showname(int a)//showreward�κ� ��� �̿��� �Լ�, ���ڷ� �����̸��� �ش��ϴ� ������ �޾� �����̸��� ���
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
	int TNR; //singleMAtch�� ���� Total Round Number
	int Opponent; //��� ������ id ��Ÿ��
	int select; //cooperate����cheat���� �Է¹���
	Player p;
	Agent* pOppo; //Opponent�� �� Agent�� ����Ű�� ������
	std::cout << "Total Round Number: ";
	while (1)
	{
		std::cin >> TNR;
		if (TNR > 0 && TNR<51) //1�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
			break;
		else
			std::cout << "Invalid Input!\n";
	}
	std::cout << "Select an Opponent! Copycat(1), Cheater(2), Cooperator(3), Grudger(4), Detective(5)\n";
	while (1)
	{
		std::cin >> Opponent;
		if (Opponent > 0 && Opponent < 6) //1�̻� 5���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
			break;
		else
			std::cout << "Invalid Input!\n";
	}
	switch (Opponent) //�Է¹��� Opponent�� ���� ���� �� Agent�� ������
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
	Round r(&p, pOppo); //���� ����
	for (int i = 1; i <= TNR; i++) //TNR���� ���带 ����
	{
		r.runRound();
		//�Ʒ����ʹ� ȭ�����
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
	if (p.getReward() > pOppo->getReward())//�������
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
	else //���� ���
		std::cout << "Duce!\n";
	delete pOppo;
}
void Game::singleTournament() {
	Population p;
	int nCopycat, nCheater, nCooperator, nGrudger, nDetective; //�� �������� ����
	std::cout << "Decide Population\n";
	while (1) //��ü �ο��� 2 �̸� �Ǵ� 50 �ʰ��̸� �ٽ� �Է¹���
	{
		std::cout << "Copycat: ";
		while (1)
		{
			std::cin >> nCopycat;
			if (nCopycat >= 0 && nCopycat < 51) //0�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Cheater: ";
		while (1)
		{
			std::cin >> nCheater;
			if (nCheater >= 0 && nCheater < 51) //0�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Cooperator: ";
		while (1)
		{
			std::cin >> nCooperator;
			if (nCooperator >= 0 && nCooperator < 51) //0�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Grudger: ";
		while (1)
		{
			std::cin >> nGrudger;
			if (nGrudger >= 0 && nGrudger < 51) //0�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Detective: ";
		while (1)
		{
			std::cin >> nDetective;
			if (nDetective >= 0 && nDetective < 51) //0�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		if (nCheater + nCooperator + nCopycat + nGrudger + nDetective > 1 && //��ü �ο��� 2 �̸� �Ǵ� 50 �ʰ��̸� �ٽ� �Է¹���
			nCheater + nCooperator + nCopycat + nGrudger + nDetective < 51)
			break;
		else
			std::cout << "Invalid Input!\n";
	}
	showline2();
	p.Alloc(nCopycat, nCheater, nCooperator, nGrudger, nDetective);
	Tournament t(&p);
	int selectinput; // continue, stop���� �Է�
	while(1)//tournament����
	{
		p.showReward();
		showline2();
		std::cout << "Continue(1) or Stop(0)" << std::endl;
		while (1)
		{
			std::cin >> selectinput;
			if (selectinput==1|| selectinput==0) //1,0�� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
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
			p.showReward(); //���� ������ ���� �ѹ� �� show �Ѵ�.
			break;
		}
	}
	if (selectinput == 0) //selectinput==0�̸� ���� reward������� �ʰ� �ٷ� ���۸޴��� ���ư�
		return;
	p.sort(); //���Ľ�Ŵ
	showline();
	p.showReward(); //���ĵȰ� ������
	t.resetMember(); //tournament�� i,j member�� �ʱ�ȭ��
}
void Game::repeatedTournament() {
	Population p;
	int nCopycat, nCheater, nCooperator, nGrudger, nDetective; //�� �������� ����
	int totalNumber;// �� ��ʸ�Ʈ Ƚ��
	std::cout << "Total Tournament Number: ";
	while (1) //��ü �ο��� 6 �̸� �Ǵ� 50 �ʰ��̸� �ٽ� �Է¹���
	{
		std::cin >> totalNumber;
		if (totalNumber >0 && totalNumber < 51) //1�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
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
			if (nCopycat >= 0 && nCopycat < 51) //0�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Cheater: ";
		while (1)
		{
			std::cin >> nCheater;
			if (nCheater >= 0 && nCheater < 51) //0�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Cooperator: ";
		while (1)
		{
			std::cin >> nCooperator;
			if (nCooperator >= 0 && nCooperator < 51) //0�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Grudger: ";
		while (1)
		{
			std::cin >> nGrudger;
			if (nGrudger >= 0 && nGrudger < 51) //0�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		std::cout << "Detective: ";
		while (1)
		{
			std::cin >> nDetective;
			if (nDetective >= 0 && nDetective < 51) //0�̻� 50���ϰ� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		if (nCheater + nCooperator + nCopycat + nGrudger + nDetective > 5 && //��ü �ο��� 6 �̸� �Ǵ� 50 �ʰ��̸� �ٽ� �Է¹���
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
	int selectinput3; //���� tournament ����, eliminate ����, reproduce ������ �Է��� ����
	for (int I = 0; I < totalNumber;I++)//tournament����
	{
		t.setPopulation(&p);  //match ���� Population�� ���빰�� ����Ǿ����� tournament object�� �����Ű�� �� population�� ����� �ɷ� �ٽ� ����Ű����
		p.showReward();
		showline2();
		std::cout << "Continue(1) or Stop(0)" << std::endl;
		while (1)
		{
			std::cin >> selectinput;
			if (selectinput == 0 || selectinput == 1) //0,1�̾ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		if (selectinput == 0)
			break;
		else if (selectinput == 1)
		{
			t.runTournamentAll(); //��� ��ġ�� ��ʸ�Ʈ ����
			p.sort();
			std::cout << "=======Tournament "<<I+1<< "========" << std::endl;
			p.showReward();
			showline2();
			std::cout << "Eliminate(1) or Stop(0)\n";//eliminate �Է�, eliminate����
			while (1)
			{
				std::cin >> selectinput2;
				if (selectinput2 == 0 || selectinput2 == 1) //0,1�̾ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
					break;
				else
					std::cout << "Invalid Input!\n";
			}
			if (selectinput2 == 1)
				p.Eliminate();
			else if (selectinput2 == 0)
				break;
			showline2();
	
			std::cout << "Reproduce(1) or Stop(0)\n"; //reproduce�Է� �� reproduce����
			while (1)
			{
				std::cin >> selectinput3;
				if (selectinput3 == 0 || selectinput3 == 1) //0,1�̾ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
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
		return; //stop�̸� �߰��� showreward���� �ʰ� �ٷ� ���۸޴��� ���ư�
	p.showReward(); //���ĵȰ� ������
}
void Game::runGame()
{
	int reinput;// reinput=0�̸� ���� �Է�, 1�̸� �߸��� �Է�, �ٽ� �Է¹���
	std::cout << "Command: ";
	do
	{
		reinput = 0; //�ϴ��� �����Է¹޾Ҵٰ� ����
		std::cin >> selectMenu;
		switch (selectMenu) //������ �Ϳ� ���� ���ϴ� ���� ����
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