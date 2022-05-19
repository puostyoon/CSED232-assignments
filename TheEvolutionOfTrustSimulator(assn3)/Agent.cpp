#include"Agent.h"
void Agent::setReward(int input) {
	reward = input;
}
int Agent::getReward() const
{
	return reward;
}
void Agent::minusReward(int arg) {
	reward -= arg;
}
void Agent::plusReward(int arg) {
	reward += arg;
}
int Agent::getHistory() const {
	return history;
}
int Agent::getId() const {
	return id;
}
void Agent::setId(int arg) {
	id = arg;
}
void Agent::setHistory(int a) {
	history = a;
}
int Agent::getState() const {
	return state;
}
void Agent::setState(int a) {
	state = a;
}
