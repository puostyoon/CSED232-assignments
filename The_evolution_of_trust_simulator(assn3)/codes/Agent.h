#pragma once

enum{COPYCAT,CHEATER,COOPERATOR,GRUDGER,DETECTIVE};
class Agent {
private:
	int reward=0; //����, default�� 0
	int history; //������ �ߴ� �ൿ
	int state;//cheating�� �ߴ���, ������ �ߴ��� ǥ��
	//0�̸� cheating 1�̸� ����
	int id; //������ ǥ��
public:
	virtual int act(int,int) = 0; //match�� �����ϴ� ����� history, round ���� �޾ƿ� �ൿ��
	virtual void reset_without_reward() = 0; //reward�� ������ ����(identity, history, state��)�ʱ�ȭ
	int getHistory() const; 
	void setHistory(int a);
	void setReward(int input);
	int getReward() const;
	int getState() const;
	int getId() const;
	void setId(int);
	void setState(int);
	void minusReward(int arg); //argument�� ���� ����ŭ reward���ҽ�Ŵ
	void plusReward(int arg); //argument�� ���� ����ŭ reward������Ŵ
	Agent() { reward = 0; history = 0; state = 0; id = 0; } //�⺻ ������
	virtual ~Agent() {} //�Ҹ���
};
