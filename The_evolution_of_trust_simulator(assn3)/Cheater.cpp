#include"Cheater.h"

int Cheater::act(int adH, int curr) {
	setState(0);
	setHistory(0);
	return 0; //항상 배신한다.
}
void Cheater::reset_without_reward() {
	setState(0);
	setHistory(0);
}
