#include"Cooperator.h"

int Cooperator::act(int adH, int curr) {
	setState(1);
	setHistory(1);
	return 1; //�׻� �����Ѵ�.
}
void Cooperator::reset_without_reward() {
	setState(0);
	setHistory(0);
}