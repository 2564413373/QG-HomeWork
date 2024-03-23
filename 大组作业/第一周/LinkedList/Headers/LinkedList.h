#include <stdio.h>
#include <iostream>
using namespace std;

////// define the struct of a linkedList
struct LNode {
	int data;  ////// 数据 
	struct LNode* next;
};

////// 初始化链表
LNode* initLinkedList();

////// 往第n（自己指定）个结点后面添加数据
void addLNode(LNode*);

////// 删除第n个结点
void deleteLNode(LNode*);

////// 修改第n个结点的值
void updateLNode(LNode*);

///// 查询第n个编号结点的值
int searchLNode(LNode*);

///// 遍历整个链表
void showLinkedList(LNode*);

///// 判断链表有没有成环
bool isCircle(LNode*);

//// 反转链表
void reversed_LinkedList(LNode*);

///// 返回单链表中点的值
int middle_value(LNode*);

///// 链表奇偶索引的结点对换
LNode* odd_even(LNode*);  
