#include"Match.h"
void Match::runMatch(int lim) {
	Round r(ptr1, ptr2); //round ��ü ����
	for (int i = 1; i <= lim; i++) //lim��ŭ round����
	{
		r.runRound();
	}
}
Match::Match(Agent* a, Agent* b, int c) :ptr1(a), ptr2(b), roundLimit(c) {}
int Match::getWinner() {
	return winner;
}
void Match::resetAgent(Agent* p1, Agent* p2) {
	ptr1 = p1;
	ptr2 = p2;
}