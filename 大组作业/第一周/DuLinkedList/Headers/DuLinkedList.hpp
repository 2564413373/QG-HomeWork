#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct DuLNode {
	int data;
	struct DuLNode* front;
	struct DuLNode* next;
};

////// ��ʼ������
DuLNode* initLinkedList();

////// ����n���Լ�ָ�������������������
void addLNode(DuLNode*);

////// ɾ����n�����
void deleteLNode(DuLNode*);

////// �޸ĵ�n������ֵ
void updateLNode(DuLNode*);

///// ��ѯ��n����Ž���ֵ
int searchLNode(DuLNode*);

///// ������������
void showLinkedList(DuLNode* head);

