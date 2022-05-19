#pragma once
#include"Agent.h"
//사용할 자료구조 객체
struct NodeType {
	Agent* pdata;
	NodeType* next;
	NodeType* prev;
}; //Node structure
class DoublyLinkedList {
private:
	NodeType* pFirst; //첫 노드의 주소
	NodeType* pLast;  //마지막 노드의 주소
	int length; //리스트의 크기
public:
	DoublyLinkedList(NodeType*, NodeType*, int);
	DoublyLinkedList();
	virtual ~DoublyLinkedList();
	NodeType* getPFirst() const //getter함수
	{
		return pFirst;
	}
	NodeType* getPLast() const //getter함수
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
	int Add(Agent* item); //item을 받아와서 그것을 data로 갖는 node를 리스트에 추가
	int Delete(); //맨 뒤의 노드 한 개 삭제
};