#include"Agent.h"
#include"DoublyLinkedList.h"
#include"Iterator.h"

//생성자는 헤더파일에서 구현함
using namespace std;
Iterator::~Iterator() //소멸자
{}
const DoublyLinkedList& Iterator::getDList() const //getter함수
{
	return dList;
}

NodeType* Iterator::getPCurPointer() const //getter함수
{
	return pCurPointer;
}
void Iterator::setPCurPointer(NodeType* a) //setter함수
{
	pCurPointer = a;
}
bool Iterator::NotNull() //현재 노드가 null인지 판단
{
	return pCurPointer != NULL;
}
bool Iterator::NextNotNull() //다음 노드가 null인지 판단
{
	return (*pCurPointer).next != NULL;
}
bool Iterator::PrevNotNull() //이전 노드가 null인지 판단
{
	return pCurPointer->prev != NULL;
}

void Iterator::Next() {  //다음 노드로 옮겨감
	pCurPointer = pCurPointer->next;  //다음 노드로 옮겨감
}
NodeType Iterator::GetCurrentNode() { //iterator가 현재 가리키는 노드를 반환
	return *pCurPointer;
}