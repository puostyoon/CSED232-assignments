#include"Player.h"
#include<iostream>
void showHalfLine()//������ ���� =�� ����ϱ� ����
{
	std::cout << "==========";
}
int Player::act(int adHistory,int curround) {
	showHalfLine();
	std::cout << "Round "<<curround;
	showHalfLine();
	std::cout << std::endl << "Cooperating(1) or Cheating (0)?" << std::endl;
		while (1)
		{
			std::cin >> input;
			if (input==1||input==0) //1, 0�� �ƴ� �ٸ� ���� ������ �ٽ� �Է¹���
				break;
			else
				std::cout << "Invalid Input!\n";
		}
		setHistory(input);
		setState(input);
	return input;
}
Player::Player() {
	input = 0;
	setHistory(0);
}
int Player::getInput() const {
	return input;
}
void Player::setInput(int a) {
	input = a;
}
void Player::reset_without_reward() {
	;
} //Player type���� reset�� ȣ��� �� �����Ƿ� �׳� ����д�.
