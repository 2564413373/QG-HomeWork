#include <stdio.h>
#include <iostream>
using namespace std;
////// define the struct of a linkedList
typedef struct LNode {
	int data;  ////// ���� 
	struct LNode* next;
};

int Length_LinkedList(LNode* head) {
	if (head == NULL) {
		return 0;
	}
	LNode* p = head;
	int count = 0;
	while(p) {
		++count;
		p = p->next;
	}
	return count;
}
////// ��ʼ������
LNode* initLinkedList();

////// ����n���Լ�ָ�������������������
void addLNode(LNode*);

////// ɾ����n�����
void deleteLNode(LNode*);

////// �޸ĵ�n������ֵ
void updateLNode(LNode*);

///// ������������
void showLinkedList(LNode*);

//// ��ת����
void reversed_LinkedList(LNode*);

///// �ж�������û�гɻ�
bool isCircle(LNode*);

///// ���ص������е��ֵ
int middle_value(LNode*);

///// ������ż�����Ľ��Ի�
LNode* odd_even(LNode*);  
