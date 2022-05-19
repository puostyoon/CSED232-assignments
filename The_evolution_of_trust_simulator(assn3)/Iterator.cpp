#include"Agent.h"
#include"DoublyLinkedList.h"
#include"Iterator.h"

//�����ڴ� ������Ͽ��� ������
using namespace std;
Iterator::~Iterator() //�Ҹ���
{}
const DoublyLinkedList& Iterator::getDList() const //getter�Լ�
{
	return dList;
}

NodeType* Iterator::getPCurPointer() const //getter�Լ�
{
	return pCurPointer;
}
void Iterator::setPCurPointer(NodeType* a) //setter�Լ�
{
	pCurPointer = a;
}
bool Iterator::NotNull() //���� ��尡 null���� �Ǵ�
{
	return pCurPointer != NULL;
}
bool Iterator::NextNotNull() //���� ��尡 null���� �Ǵ�
{
	return (*pCurPointer).next != NULL;
}
bool Iterator::PrevNotNull() //���� ��尡 null���� �Ǵ�
{
	return pCurPointer->prev != NULL;
}

void Iterator::Next() {  //���� ���� �Űܰ�
	pCurPointer = pCurPointer->next;  //���� ���� �Űܰ�
}
NodeType Iterator::GetCurrentNode() { //iterator�� ���� ����Ű�� ��带 ��ȯ
	return *pCurPointer;
}