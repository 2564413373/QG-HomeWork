#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct DuLNode {
	int data;
	struct DuLNode* front;
	struct DuLNode* next;
};

////// 初始化链表
DuLNode* initLinkedList();

////// 往第n（自己指定）个结点后面添加数据
void addLNode(DuLNode*);

////// 删除第n个结点
void deleteLNode(DuLNode*);

////// 修改第n个结点的值
void updateLNode(DuLNode*);

///// 查询第n个编号结点的值
int searchLNode(DuLNode*);

///// 遍历整个链表
void showLinkedList(DuLNode* head);

