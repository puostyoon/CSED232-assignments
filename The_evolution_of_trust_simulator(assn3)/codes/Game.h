#pragma once
class Game {
private:
	int selectMenu;//�޴�ȭ�鿡�� �� �����ߴ���(command)
public:
	void showMenu(); //�޴� ȭ�� ���
	void runGame();  //selectmenu���� ���� ���ϴ� ���� �Լ� ����
	void singleMatch(); //single match �����Լ�
	void singleTournament(); //single tournament ���� �Լ�
	void repeatedTournament(); //repeated tournament ���� �Լ�
};
