#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct StackNode {
	int data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack {
	LinkStackPtr top; ///// ջ��ָ��
	int count; /// ջ��Ԫ�ظ��� 
}LinkStack;

/////// ��ʼ����ջ
LinkStack* init_LinkStack();

/////// �ж���ջ�Ƿ�Ϊ��
bool isEmpty(LinkStack*); 

//////  ��ջ����
void push_LinkStack(LinkStack*);

//////  ��ջ����
void pop_LinkStack(LinkStack*);

////// ����
void show_LinkStack(LinkStack*);

///// ��ȡջ��Ԫ��
int get_Headvalue(LinkStack*);

///// ����ջ
void destroy_LinkStack(LinkStack*);

////// ���ջ����
int Length_Stack(LinkStack*);
