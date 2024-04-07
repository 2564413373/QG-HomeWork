#include <stdio.h>
#include <iostream>
using namespace std;

/////  树节点 
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode,*BSTree;

/////  链栈
typedef struct StackNode {
    TreeNode *treenode;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
}Stack;

/////  链队
typedef struct QueueNode {
    BSTree treenode;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

////// 初始化二叉排序树
BSTree* init_SortTree();

////// 插入
void add_SortTree(BSTree*,int); 

////// 查找
bool searchSortTree(BSTree*,int); 

/////  删除 
bool delete_SortTree(BSTree*,int);

void DeleteNode(BSTree*);

////// 递归先序遍历
void preOrder(BSTree);

/////  递归中序遍历
void inOrder(BSTree);

/////  递归后序遍历
void postOrder(BSTree);

/////  层序遍历
void layerOrder(BSTree*);

BSTree searchSortTree_layer(BSTree*,int);

/////  进队列
void enqueue(Queue*,BSTree);

/////  出队列
BSTree dequeue(Queue *queue);

///// 判断队列是否为空
int isEmptyQueue(Queue*);

//// 层序遍历
void levelOrderTraversal(BSTree); 


///// 栈 函数 
int isEmptyStack(Stack*);

void push(Stack*,BSTree);

BSTree pop(Stack *stack);

BSTree createNode(int);

///// 先序非递归 
void preorderTraversal(BSTree);

//// 中序非递归
void inorderTraversal(BSTree);

//// 后序非递归 
void postOrderTraversal(BSTree); 
