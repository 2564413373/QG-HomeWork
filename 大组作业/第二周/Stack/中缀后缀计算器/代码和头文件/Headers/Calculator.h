#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
///////////////////  ջ 
typedef struct StackNode {
	char data;
	struct StackNode* next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack {
	LinkStackPtr top;
	int count; ///////// ���� 
}LinkStack;
///////////////// ����
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode,*QueuePtr; 

typedef struct LinkQueue {
	QueuePtr head;
	QueuePtr tail;
}LinkQueue;
///// �ж��Ƿ�Ϊ��
bool isEmpty(LinkStack*);

///// ��ջ������ջ��ֵ 
char popStack_Headvalue(LinkStack*);

///// ����ջ��ֵ��������
char Headvalue(LinkStack*); 

///// ��ջ
void push_LinkStack(LinkStack*,int);

//// ��ʼ��ջ
LinkStack* init_LinkStack();

///// ���㺯��
int Calculator(char,char,char); ///// ����ʱ���������ǰ��ǰ����ں� 

///// ���ȼ�����
int Higher_Compare(char x);

///// ��׺ת��׺
int InfixtoPostfix(char*,LinkStack*);

////// ��׺������ս��
void PostfixToResult();
