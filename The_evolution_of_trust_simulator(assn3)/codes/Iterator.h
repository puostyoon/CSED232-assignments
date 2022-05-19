#pragma once
//DoublyLinkedList에서 이용할, 임의의 노드에 쉽게 접근하게끔 해주는 Iterator class
#ifndef ITERATOR_H_
#define ITERATOR_H_ //이 헤더파일이 한번만 포함되도록
#include <iostream>
#include<string>
#include"DoublyLinkedList.h"
using namespace std;
class Iterator {
private:
	const DoublyLinkedList& dList; //iterator를 작동시킬 링크드 리스트
	NodeType* pCurPointer; //iterator가 현재 가리키는 노드의 주소
public:
	Iterator(const DoublyLinkedList& list) :dList(list) //dList가 reference형이므로 생성과 동시에 초기화하기 위해 멤버 초기화 리스트 이용
	{
		pCurPointer = dList.getPFirst();
	}

	~Iterator();
	const DoublyLinkedList& getDList()const;
	NodeType* getPCurPointer() const;
	void setPCurPointer(NodeType*);
	bool NotNull(); //현재 노드가 NuLL인지 판단
	bool NextNotNull();//다음 노드가 NuLL인지 판단
	bool PrevNotNull();//이전 노드가 NuLL인지 판단
	void Next();//ITerator의 currpointer가 다음노드로 넘어감
	NodeType GetCurrentNode();
};
#endif