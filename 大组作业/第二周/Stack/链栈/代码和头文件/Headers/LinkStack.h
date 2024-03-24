#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct StackNode {
	int data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack {
	LinkStackPtr top; ///// 栈顶指针
	int count; /// 栈中元素个数 
}LinkStack;

/////// 初始化链栈
LinkStack* init_LinkStack();

/////// 判断链栈是否为空
bool isEmpty(LinkStack*); 

//////  入栈操作
void push_LinkStack(LinkStack*);

//////  出栈操作
void pop_LinkStack(LinkStack*);

////// 遍历
void show_LinkStack(LinkStack*);

///// 获取栈顶元素
int get_Headvalue(LinkStack*);

///// 销毁栈
void destroy_LinkStack(LinkStack*);

////// 检测栈长度
int Length_Stack(LinkStack*);
