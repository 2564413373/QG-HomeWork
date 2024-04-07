#include <stdio.h>
#include <iostream>
using namespace std;

/////  ���ڵ� 
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode,*BSTree;

/////  ��ջ
typedef struct StackNode {
    TreeNode *treenode;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
}Stack;

/////  ����
typedef struct QueueNode {
    BSTree treenode;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

////// ��ʼ������������
BSTree* init_SortTree();

////// ����
void add_SortTree(BSTree*,int); 

////// ����
bool searchSortTree(BSTree*,int); 

/////  ɾ�� 
bool delete_SortTree(BSTree*,int);

void DeleteNode(BSTree*);

////// �ݹ��������
void preOrder(BSTree);

/////  �ݹ��������
void inOrder(BSTree);

/////  �ݹ�������
void postOrder(BSTree);

/////  �������
void layerOrder(BSTree*);

BSTree searchSortTree_layer(BSTree*,int);

/////  ������
void enqueue(Queue*,BSTree);

/////  ������
BSTree dequeue(Queue *queue);

///// �ж϶����Ƿ�Ϊ��
int isEmptyQueue(Queue*);

//// �������
void levelOrderTraversal(BSTree); 


///// ջ ���� 
int isEmptyStack(Stack*);

void push(Stack*,BSTree);

BSTree pop(Stack *stack);

BSTree createNode(int);

///// ����ǵݹ� 
void preorderTraversal(BSTree);

//// ����ǵݹ�
void inorderTraversal(BSTree);

//// ����ǵݹ� 
void postOrderTraversal(BSTree); 
