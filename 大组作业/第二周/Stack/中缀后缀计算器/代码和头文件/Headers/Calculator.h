#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
///////////////////  栈 
typedef struct StackNode {
	char data;
	struct StackNode* next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack {
	LinkStackPtr top;
	int count; ///////// 计数 
}LinkStack;
///////////////// 队列
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode,*QueuePtr; 

typedef struct LinkQueue {
	QueuePtr head;
	QueuePtr tail;
}LinkQueue;
///// 判断是否为空
bool isEmpty(LinkStack*);

///// 出栈并返回栈顶值 
char popStack_Headvalue(LinkStack*);

///// 返回栈顶值但不弹出
char Headvalue(LinkStack*); 

///// 入栈
void push_LinkStack(LinkStack*,int);

//// 初始化栈
LinkStack* init_LinkStack();

///// 计算函数
int Calculator(char,char,char); ///// 计算时，后面的在前，前面的在后 

///// 优先级函数
int Higher_Compare(char x);

///// 中缀转后缀
int InfixtoPostfix(char*,LinkStack*);

////// 后缀算出最终结果
void PostfixToResult();
