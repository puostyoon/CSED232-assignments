#include"DoublyLinkedList.h"
#include"Iterator.h"
using namespace std;

DoublyLinkedList::DoublyLinkedList(NodeType* first, NodeType* last, int leng)  //������
{
	pFirst = first;
	pLast = last;
	length = leng;
}
DoublyLinkedList::DoublyLinkedList() //����Ʈ ������
{
	pFirst = NULL;
	pLast = NULL;
	this->length = 0;
}
DoublyLinkedList::~DoublyLinkedList() //�Ҹ��ڿ��� ��ũ�� ����Ʈ�� ������ ����ֱ� ���� makeempty ȣ����
{
	MakeEmpty();
}
int DoublyLinkedList::getLength() const { //getter�Լ�
	return length;
}
void DoublyLinkedList::setPFirst(NodeType* a) { //setter�Լ�
	pFirst = a;
}
void DoublyLinkedList::setPLast(NodeType* a) { //setter�Լ�
	pLast = a;
}
void DoublyLinkedList::setLength(int a) { //setter�Լ�
	length = a;
}
bool DoublyLinkedList::IsEmpty() { //��ũ�� ����Ʈ�� ����ִ��� Ȯ���ϴ� �Լ�
	return length == 0;
}
void DoublyLinkedList::MakeEmpty() { //��ũ�� ����Ʈ�� ���� �Լ�
	if (length == 0) //�̹� ����������� �ƹ� �ൿ ���� �Լ�����
	{
		return;
	}
	Iterator iter(*this); //iterator ����
	iter.setPCurPointer(pFirst); //iterator �� �ʱ�ȭ
	while (iter.NotNull()) //iter�� cursor�� ������ �Űܰ��鼭 �˻�
	{
		NodeType* temp = iter.getPCurPointer(); //iterator�� ���� ����Ű�� �����͸� ���� ���� �ű�� ������ �����Ϸ��� ����� �ּҰ� ����
		iter.Next(); //iter�� ���� ����Ű�� ��带 �ű�
		delete temp; //���� �����Ϸ��� ��� ������
	}
	pFirst = NULL; //��ũ�� ����Ʈ�� ���� ��� �Ŀ� pFirst, pLast�� null�� ��������
	pLast = NULL;
	length = 0; //length�� 0���� ��������
}


NodeType* DoublyLinkedList::get_ith_Nodeptr(int n) { //i��° ����� ������ ��ȯ
	Iterator iter(*this);
	iter.setPCurPointer(pFirst); //iterator �ʱ�ȭ
	for (int i = 0; i < n; i++)
		iter.Next();
	return iter.getPCurPointer();
}

int DoublyLinkedList::Add(Agent* pAgent) { //��带 �߰��ϴ� �Լ�, �����������������ϸ����
	if (length == 0) { //�� ó�� ��ũ�帮��Ʈ ������ ��
		pFirst = new NodeType; //��� ����
		pLast = pFirst;
		pFirst->pdata = pAgent;
		pFirst->prev = NULL;
		pLast->next = NULL; //������ ����� prev, next ��������
		length++; //����Ʈ ���� ����
		return 1;
	}
	Iterator iter(*this); //�� ó���� �ƴϰ� ��带 ������ ��
	iter.setPCurPointer(pFirst); //iterator �ʱ�ȭ
	while (iter.getPCurPointer()->pdata->getReward() >= pAgent->getReward()) //null �����͸� �����Ϸ��� ������ ��, 
	{
		iter.Next(); //��ũ�� ����Ʈ�� ������ ��ġ�� ã�� ����
		if (iter.getPCurPointer() == NULL)
			//��ũ�� ����Ʈ�� ������ ��ġ�� ã�� ����, null �����͸� �����Ϸ��� ������ �߰�, ���� Ŀ���� �� ����Ʈ��� ���� ���� �����ߴٴ� ���̹Ƿ� �� �̻� ã�� �ʿ� ���� 
			break;  //�� ������ while�� ���ǰ˻�� �ȿ� ���� ���� ����: ������ �����̱⵵ �ϰ�, �׸��� �� ������ while��
		//���ǽĿ� �ִ���, �� ������ ���� �˻��ϴ� ���� iter.~~->data.getReward()�� �����ϸ�  null ptr�� �����ϴ� ���� ���α׷��� ������ ������ 
		//�׷��� �Ǳ⸦ �����ϱ� ���� while �� �ȿ� break���� �־���
	}
	if (iter.getPCurPointer() == NULL) //�������� ������ ��
	{
		NodeType* temp = new NodeType; //��� �� �� ����
		temp->pdata = pAgent;
		temp->prev = pLast; //���� ���� ����� prev����
		temp->next = NULL; //���� ���� ����� next����
		pLast->next = temp; //�����Ϸ��� ���� �ٷ� ���� ���� �����Ϸ��� ��� ����
		pLast = temp; //pLast �缳��
		length++; //����Ʈ ���� ����
		return 1;
	}
	else if (iter.getPCurPointer() == pFirst) //����Ʈ�� �� �տ� ������ ��(pLast,pFirst�� ���ÿ� ��������� �ؼ� ���� ����ó�� ����)
	{
		NodeType* temp = new NodeType; //��� �� �� ����
		temp->pdata = pAgent;
		temp->prev = NULL; //���� ���� ����� prev����
		temp->next = pFirst; //���� ���� ����� next����
		pFirst->prev = temp; //�����Ϸ��� ���� �ٷ� ���� ���� �����Ϸ��� ��� ����
		pFirst = temp; //pFirst �缳��
		length++; //����Ʈ ���� ����
		return 1;
	}

	else //�� ���� ��� (����Ʈ �߰��� ��带 ������ ��)
	{
		NodeType* temp = new NodeType; //��� �� �� ����
		temp->pdata = pAgent;
		temp->prev = iter.getPCurPointer()->prev; //���� ���� ����� prev����(���� iter�� pointer�� ��� ���� ��ġ �ٷ� ������ ��� ����Ŵ)
		temp->next = iter.getPCurPointer();//���� ���� ����� next����
		(iter.getPCurPointer()->prev)->next = temp; //�����Ϸ��� �� ���� ���� �����Ϸ��� ��� ����
		iter.getPCurPointer()->prev = temp; //�����Ϸ��� �� �ٷ� ���� �����prev����
		length++;//����Ʈ ���� ����
		return 1;
	}
}
int DoublyLinkedList::Delete() //�� ���� ��� �ϳ� ����
{
	if (length == 1) //�� ������ ��带 ������ ��.. �� �� ������ ������ �� pLast,pFirst�� ���ÿ� ��������� �ؼ� ���� ����ó������
	{
		pFirst = NULL;
		pLast = NULL; //�޸� �Ҵ� ���� �� pFirst,pLast�� Null�� ����
		length--; //����Ʈ ���� ����
		return 1;
	}
	else //������ ��带 ������ ��
	{
		(pLast->prev)->next = NULL; //������ ���� ��尡 ������ ��尡��
		pLast = pLast->prev; //pLast �缳��
		delete pLast->next; //�޸� �Ҵ� ����
		length--; //����Ʈ ���� ����
		return 1;
	}
}
