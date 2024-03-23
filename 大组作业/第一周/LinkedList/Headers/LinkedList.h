#include <stdio.h>
#include <iostream>
using namespace std;

////// define the struct of a linkedList
struct LNode {
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
void showLinkedList(LNode*);

///// �ж�������û�гɻ�
bool isCircle(LNode*);

//// ��ת����
void reversed_LinkedList(LNode*);

///// ���ص������е��ֵ
int middle_value(LNode*);

///// ������ż�����Ľ��Ի�
LNode* odd_even(LNode*);  
