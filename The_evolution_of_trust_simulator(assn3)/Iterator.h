#pragma once
//DoublyLinkedList���� �̿���, ������ ��忡 ���� �����ϰԲ� ���ִ� Iterator class
#ifndef ITERATOR_H_
#define ITERATOR_H_ //�� ��������� �ѹ��� ���Եǵ���
#include <iostream>
#include<string>
#include"DoublyLinkedList.h"
using namespace std;
class Iterator {
private:
	const DoublyLinkedList& dList; //iterator�� �۵���ų ��ũ�� ����Ʈ
	NodeType* pCurPointer; //iterator�� ���� ����Ű�� ����� �ּ�
public:
	Iterator(const DoublyLinkedList& list) :dList(list) //dList�� reference���̹Ƿ� ������ ���ÿ� �ʱ�ȭ�ϱ� ���� ��� �ʱ�ȭ ����Ʈ �̿�
	{
		pCurPointer = dList.getPFirst();
	}

	~Iterator();
	const DoublyLinkedList& getDList()const;
	NodeType* getPCurPointer() const;
	void setPCurPointer(NodeType*);
	bool NotNull(); //���� ��尡 NuLL���� �Ǵ�
	bool NextNotNull();//���� ��尡 NuLL���� �Ǵ�
	bool PrevNotNull();//���� ��尡 NuLL���� �Ǵ�
	void Next();//ITerator�� currpointer�� �������� �Ѿ
	NodeType GetCurrentNode();
};
#endif