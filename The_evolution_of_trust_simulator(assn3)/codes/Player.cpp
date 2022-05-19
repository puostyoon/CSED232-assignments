#include"Player.h"
#include<iostream>
void showHalfLine()//일정한 수의 =을 출력하기 위함
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
			if (input==1||input==0) //1, 0이 아닌 다른 값을 받으면 다시 입력받음
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
} //Player type에선 reset이 호출될 일 없으므로 그냥 비워둔다.
