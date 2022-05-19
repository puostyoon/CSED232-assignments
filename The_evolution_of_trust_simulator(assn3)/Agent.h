#pragma once

enum{COPYCAT,CHEATER,COOPERATOR,GRUDGER,DETECTIVE};
class Agent {
private:
	int reward=0; //점수, default로 0
	int history; //이전에 했던 행동
	int state;//cheating을 했는지, 협력을 했는지 표시
	//0이면 cheating 1이면 협력
	int id; //직업을 표시
public:
	virtual int act(int,int) = 0; //match를 진행하는 상대의 history, round 수를 받아와 행동함
	virtual void reset_without_reward() = 0; //reward를 제외한 변수(identity, history, state등)초기화
	int getHistory() const; 
	void setHistory(int a);
	void setReward(int input);
	int getReward() const;
	int getState() const;
	int getId() const;
	void setId(int);
	void setState(int);
	void minusReward(int arg); //argument로 받은 값만큼 reward감소시킴
	void plusReward(int arg); //argument로 받은 값만큼 reward증가시킴
	Agent() { reward = 0; history = 0; state = 0; id = 0; } //기본 생성자
	virtual ~Agent() {} //소멸자
};
