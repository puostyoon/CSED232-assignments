#pragma once
#include"Agent.h"
//����� �ڷᱸ�� ��ü
struct NodeType {
	Agent* pdata;
	NodeType* next;
	NodeType* prev;
}; //Node structure
class DoublyLinkedList {
private:
	NodeType* pFirst; //ù ����� �ּ�
	NodeType* pLast;  //������ ����� �ּ�
	int length; //����Ʈ�� ũ��
public:
	DoublyLinkedList(NodeType*, NodeType*, int);
	DoublyLinkedList();
	virtual ~DoublyLinkedList();
	NodeType* getPFirst() const //getter�Լ�
	{
		return pFirst;
	}
	NodeType* getPLast() const //getter�Լ�
	{
		return pLast;
	}
	NodeType* get_ith_Nodeptr(int);
	int getLength() const;
	void setPFirst(NodeType* a);
	void setPLast(NodeType* a);
	void setLength(int a);
	bool IsEmpty();
	void MakeEmpty();
	int Add(Agent* item); //item�� �޾ƿͼ� �װ��� data�� ���� node�� ����Ʈ�� �߰�
	int Delete(); //�� ���� ��� �� �� ����
};