#include"DoublyLinkedList.h"
#include"Iterator.h"
using namespace std;

DoublyLinkedList::DoublyLinkedList(NodeType* first, NodeType* last, int leng)  //생성자
{
	pFirst = first;
	pLast = last;
	length = leng;
}
DoublyLinkedList::DoublyLinkedList() //디폴트 생성자
{
	pFirst = NULL;
	pLast = NULL;
	this->length = 0;
}
DoublyLinkedList::~DoublyLinkedList() //소멸자에서 링크드 리스트를 완전히 비워주기 위해 makeempty 호출함
{
	MakeEmpty();
}
int DoublyLinkedList::getLength() const { //getter함수
	return length;
}
void DoublyLinkedList::setPFirst(NodeType* a) { //setter함수
	pFirst = a;
}
void DoublyLinkedList::setPLast(NodeType* a) { //setter함수
	pLast = a;
}
void DoublyLinkedList::setLength(int a) { //setter함수
	length = a;
}
bool DoublyLinkedList::IsEmpty() { //링크드 리스트가 비어있는지 확인하는 함수
	return length == 0;
}
void DoublyLinkedList::MakeEmpty() { //링크드 리스트를 비우는 함수
	if (length == 0) //이미 비어져있으면 아무 행동 없이 함수종료
	{
		return;
	}
	Iterator iter(*this); //iterator 생성
	iter.setPCurPointer(pFirst); //iterator 값 초기화
	while (iter.NotNull()) //iter의 cursor를 끝까지 옮겨가면서 검사
	{
		NodeType* temp = iter.getPCurPointer(); //iterator가 현재 가르키는 포인터를 다음 노드로 옮기기 이전에 삭제하려는 노드의 주소값 저장
		iter.Next(); //iter가 현재 가르키는 노드를 옮김
		delete temp; //원래 삭제하려던 노드 삭제함
	}
	pFirst = NULL; //링크드 리스트를 전부 비운 후에 pFirst, pLast를 null로 설정해줌
	pLast = NULL;
	length = 0; //length도 0으로 설정해줌
}


NodeType* DoublyLinkedList::get_ith_Nodeptr(int n) { //i번째 노드의 포인터 반환
	Iterator iter(*this);
	iter.setPCurPointer(pFirst); //iterator 초기화
	for (int i = 0; i < n; i++)
		iter.Next();
	return iter.getPCurPointer();
}

int DoublyLinkedList::Add(Agent* pAgent) { //노드를 추가하는 함수, 내림차순으로정렬하며삽입
	if (length == 0) { //맨 처음 링크드리스트 생성할 때
		pFirst = new NodeType; //노드 생성
		pLast = pFirst;
		pFirst->pdata = pAgent;
		pFirst->prev = NULL;
		pLast->next = NULL; //생성된 노드의 prev, next 설정해줌
		length++; //리스트 길이 증가
		return 1;
	}
	Iterator iter(*this); //맨 처음이 아니고 노드를 삽입할 때
	iter.setPCurPointer(pFirst); //iterator 초기화
	while (iter.getPCurPointer()->pdata->getReward() >= pAgent->getReward()) //null 포인터를 참조하려면 에러가 뜸, 
	{
		iter.Next(); //링크드 리스트를 삽입할 위치를 찾는 과정
		if (iter.getPCurPointer() == NULL)
			//링크드 리스트를 삽입할 위치를 찾는 과정, null 포인터를 참조하려면 에러가 뜨고, 현재 커서가 널 포인트라는 것은 끝에 도달했다는 뜻이므로 더 이상 찾을 필요 없음 
			break;  //이 구문을 while의 조건검사식 안에 넣지 않은 이유: 가독성 때문이기도 하고, 그리고 이 구문을 while의
		//조건식에 넣더라도, 그 이전에 조건 검사하던 도중 iter.~~->data.getReward()를 실행하며  null ptr를 참조하는 순간 프로그램이 터지기 때문에 
		//그렇게 되기를 방지하기 위해 while 문 안에 break문을 넣어줌
	}
	if (iter.getPCurPointer() == NULL) //마지막에 삽입할 때
	{
		NodeType* temp = new NodeType; //노드 한 개 생성
		temp->pdata = pAgent;
		temp->prev = pLast; //새로 만든 노드의 prev설정
		temp->next = NULL; //새로 만든 노드의 next설정
		pLast->next = temp; //삽입하려는 곳의 바로 이전 노드와 삽입하려는 노드 연결
		pLast = temp; //pLast 재설정
		length++; //리스트 길이 증가
		return 1;
	}
	else if (iter.getPCurPointer() == pFirst) //리스트의 맨 앞에 삽입할 때(pLast,pFirst를 동시에 설정해줘야 해서 따로 예외처리 해줌)
	{
		NodeType* temp = new NodeType; //노드 한 개 생성
		temp->pdata = pAgent;
		temp->prev = NULL; //새로 만든 노드의 prev설정
		temp->next = pFirst; //새로 만든 노드의 next설정
		pFirst->prev = temp; //삽입하려는 곳의 바로 이후 노드와 삽입하려는 노드 연결
		pFirst = temp; //pFirst 재설정
		length++; //리스트 길이 증가
		return 1;
	}

	else //그 외의 경우 (리스트 중간에 노드를 삽입할 때)
	{
		NodeType* temp = new NodeType; //노드 한 개 생성
		temp->pdata = pAgent;
		temp->prev = iter.getPCurPointer()->prev; //새로 만든 노드의 prev설정(현재 iter의 pointer는 노드 삽입 위치 바로 다음의 노드 가르킴)
		temp->next = iter.getPCurPointer();//새로 만든 노드의 next설정
		(iter.getPCurPointer()->prev)->next = temp; //삽입하려는 곳 이전 노드와 삽입하려는 노드 연결
		iter.getPCurPointer()->prev = temp; //삽입하려는 곳 바로 다음 노드의prev설정
		length++;//리스트 길이 증가
		return 1;
	}
}
int DoublyLinkedList::Delete() //맨 뒤의 노드 하나 지움
{
	if (length == 1) //한 개남은 노드를 삭제할 때.. 한 개 남은걸 삭제할 땐 pLast,pFirst를 동시에 설정해줘야 해서 따로 예외처리해줌
	{
		pFirst = NULL;
		pLast = NULL; //메모리 할당 해제 및 pFirst,pLast를 Null로 해줌
		length--; //리스트 길이 감소
		return 1;
	}
	else //마지막 노드를 삭제할 때
	{
		(pLast->prev)->next = NULL; //마지막 이전 노드가 마지막 노드가됨
		pLast = pLast->prev; //pLast 재설정
		delete pLast->next; //메모리 할당 해제
		length--; //리스트 길이 감소
		return 1;
	}
}
