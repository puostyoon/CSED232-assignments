#pragma once
class Game {
private:
	int selectMenu;//메뉴화면에서 뭘 선택했는지(command)
public:
	void showMenu(); //메뉴 화면 출력
	void runGame();  //selectmenu값에 따라 원하는 게임 함수 실행
	void singleMatch(); //single match 진행함수
	void singleTournament(); //single tournament 진행 함수
	void repeatedTournament(); //repeated tournament 진행 함수
};
