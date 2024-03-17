#include <stdio.h>
#include <iostream>
using namespace std;

////// define the struct of a linkedList
typedef struct LNode {
	int data;  ////// ���� 
	struct LNode* next;
};

////// ��ʼ������
LNode* initLinkedList();

////// ����n���Լ�ָ�������������������
void addLNode(LNode*);

////// ɾ����n�����
void deleteLNode(LNode*);

////// �޸ĵ�n������ֵ
void updateLNode(LNode*);

///// ��ѯ��n����Ž���ֵ
int searchLNode(LNode*);

///// ������������
void showLinkedList(LNode* head);

///// �ж�������û�гɻ�
bool isCircle(LNode* head);

//// ��ת����
LNode* reverseLinkedList(LNode* head);

///// ���ص������е��ֵ
int middle_Value(LNode* head);

///// ������ż�����Ľ��Ի�
LNode* odd_even(LNode* head);  
