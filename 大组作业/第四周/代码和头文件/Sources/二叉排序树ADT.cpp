#include "../Headers/二叉排序树ADT.h"

/////// 初始化二叉排序树      添加结点函数注意事项：（如果输入-1则终止） 
BSTree* init_SortTree() {
    /////// 初始化空二叉树
    BSTree* head;
	BSTree temp = (BSTree)malloc(sizeof(TreeNode));
	printf("请输入根结点的值：\n");
	int value;
	scanf("%d",&value);
	temp->left = NULL;
	temp->right = NULL;
	temp->data = value;
	*head = temp;
	printf("二叉排序树初始化成功！！！\n");
	return head; 
}

int isEmptyQueue(Queue *queue) {
    return queue->front == NULL;
}

void enqueue(Queue *queue, TreeNode *node) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (!newNode) {
        perror("Failed to allocate memory for queue node.");
        exit(EXIT_FAILURE);
    }
    newNode->treenode = node;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

TreeNode *dequeue(Queue *queue) {
    if (isEmptyQueue(queue)) {
        return NULL;
    }
    QueueNode *temp = queue->front;
    TreeNode *node = temp->treenode;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return node;
}

void levelOrderTraversal(TreeNode *root) {
    if (root == NULL) return;

    Queue queue;
    queue.front = queue.rear = NULL;
    enqueue(&queue, root);

    while (!isEmptyQueue(&queue)) {
        TreeNode *current = dequeue(&queue);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(&queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(&queue, current->right);
        }
    }
}

/////// 添加结点到二叉排序树
void add_SortTree(BSTree* head,int value) { 
	////// 如果head为空则创建新结点
	if (*head == NULL) {
		BSTree temp = (BSTree)malloc(sizeof(TreeNode));
		temp->data = value;
		temp->left = NULL;
		temp->right = NULL;
		*head = temp;
	} else {
		/////// 如果新结点值小于当前根结点值，就去左子树
		if (value < (*head)->data) { 
			add_SortTree(&((*head)->left),value);
		} else {
			add_SortTree(&((*head)->right),value);
		}
	}	
} 

//////// 查找二叉排序树 
bool searchSortTree(BSTree* head,int value) {
	///////// 如果为空，则查询失败 
	if (*head == NULL) {
		return false;
	}
	//////// 如果值相等，则查询成功
	if ((*head)->data == value) {
		return true;
	}
	/////// 如果小于当前结点值，递归去左子树搜寻
	if (value < (*head)->data) {
		return searchSortTree(&((*head)->left),value);
	} else {
		return searchSortTree(&((*head)->right),value);
    }
}

////// 删除二叉排序树指定结点
   /// 分三种情况
     /// 1. 删的结点是叶子，直接删
	 /// 2. 删的结点左右子树一个空一个不空，则直接让被删结点的非空子树代替自己 
	 /// 3. 删的结点左右子树皆不空，找到被删结点的直接前驱，然后让直接前驱的值覆盖被删结点
	  ////  然后删去前驱结点 
bool delete_SortTree(BSTree* head,int value) {
    if (*head == NULL) {
    	return false;
	}
	if (value == (*head)->data) {
		/////// 执行删除操作
		DeleteNode(head);
		return true; 
	}
	if (value < (*head)->data) {
		return delete_SortTree(&((*head)->left),value);
	} else {
		return delete_SortTree(&((*head)->right),value);
	}
} 

/////// 删除结点操作
void DeleteNode(BSTree* p) {
	TreeNode *temp ,*s; ////// head 不删 
	temp = *p;
	if ((*p)->left == NULL) {
		*p = (*p)->right;
		free(temp);
	} else if ((*p)->right == NULL) {
		*p = (*p)->left;
		free(temp);
	} else {  /////// 两边都不空 
		////// 找到直接前驱
		s = (*p)->left;
		while (s->right) {
			temp = s;
			s = s->right;
		}
		(*p)->data = s->data;
		if (*p == temp) { /////// 如果直接前驱是被删结点的左孩子 
			temp->left = s->left;
		} else {
			temp->right = s->left;
		}
		free(s);
	}
} 

////// 递归先序遍历
void preOrder(BSTree head) {
	if (head == NULL) {
		//printf("二叉树为空，不能遍历！！！\n");
		return;
	}
	printf("%d ",head->data);
	preOrder(head->left);
	preOrder(head->right);
} 

////// 递归中序遍历
void inOrder(BSTree head) {
	if (head == NULL) {
		//printf("二叉树为空，不能遍历！！！\n");
		return;
	}
	inOrder(head->left);
	printf("%d ",head->data);
	inOrder(head->right);
} 

////// 递归后序遍历
void postOrder(BSTree head) {
	if (head == NULL) {
		//printf("二叉树为空，不能遍历！！！\n");
		return;
	}
	postOrder(head->left);
	postOrder(head->right);
	printf("%d ",head->data);
} 

/////// 栈的非递归遍历
int isEmptyStack(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, BSTree node) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for stack node.");
        exit(EXIT_FAILURE);
    }
    newNode->treenode = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

TreeNode *pop(Stack *stack) {
    if (isEmptyStack(stack)) {
        return NULL;
    }
    StackNode *topNode = stack->top;
    TreeNode *node = topNode->treenode;
    stack->top = topNode->next;
    free(topNode);
    return node;
}

//////// 先序非递归 
void preorderTraversal(BSTree root) {
    if (root == NULL) return;

    Stack stack;
    stack.top = NULL;
    push(&stack, root);

    while (!isEmptyStack(&stack)) {
        BSTree current = pop(&stack);
        printf("%d ", current->data);

        // 注意：先压入右孩子，再压入左孩子
        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

///// 中序非递归 
void inorderTraversal(BSTree root) {
    Stack stack;
    stack.top = NULL;
    TreeNode *current = root;

    while (current != NULL || !isEmptyStack(&stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

///// 后序非递归 
void postOrderTraversal(BSTree root) {
    if (root == NULL) return;

    Stack stack1, stack2;
    stack1.top = stack2.top = NULL;
    push(&stack1, root);

    while (!isEmptyStack(&stack1)) {
        TreeNode *node = pop(&stack1);
        push(&stack2, node);

        if (node->left) {
            push(&stack1, node->left);
        }
        if (node->right) {
            push(&stack1, node->right);
        }
    }

    while (!isEmptyStack(&stack2)) {
        TreeNode *node = pop(&stack2);
        printf("%d ", node->data);
    }
}

int main() {
	BSTree* head = NULL;
	int choice;
	bool loop = true;
	int flag = 0;
	while (loop) {
		printf("请输入你的操作选择：\n 1.初始化二叉树\n 2.插入\n 3.删除\n 4.递归遍历\n 5.层序遍历\n 6.非递归先序遍历\n 7.非递归中序遍历\n 8.非递归后序遍历\n 9.查找指定值\n 其他数字.退出\n");
		scanf("%d",&choice);
		if (choice == 1) {
			head = init_SortTree();
			flag = 1;
		} else if (choice == 2) {
			if (flag > 0) {
			int value; /////// 循环输入，输到-1就停止 
				while (true) {
					printf("请输入下一个结点的值：\n");
					scanf("%d",&value);
					if (value == -1) {
						printf("输入结束！！！\n");
						break;
					}
					add_SortTree(head,value);
				}
			} else {
				printf("请先初始化二叉树再添加！！！\n");
			}	
		} else if (choice == 3) {
			int value;
			printf("请输入要删除的值：");
			scanf("%d",&value);
			if (delete_SortTree(head,value)) {
				printf("删除成功！！！\n");
			} else {
				printf("删除失败！！！\n");
			}
		} else if (choice == 4) {
			int choice4;
			printf("请输入你要哪种顺序遍历：1.先序 2.中序 3.后序\n");
			scanf("%d",&choice4);
			if (choice4 == 1) {
				printf("二叉树遍历如下：\n");
				preOrder(*head);
				printf("\n");
			} else if (choice4 == 2) {
				printf("二叉树遍历如下：\n");
				inOrder(*head);
				printf("\n");
			} else if (choice4 == 3) {
				printf("二叉树遍历如下：\n");
				postOrder(*head);
				printf("\n");
			}
		} else if (choice == 5) {
			printf("二叉树遍历如下：\n");
			levelOrderTraversal(*head);
			printf("\n");
		} else if (choice == 6) {
			printf("二叉树遍历如下：\n");
			preorderTraversal(*head);
			printf("\n");
		} else if (choice == 7) {
			printf("二叉树遍历如下：\n");
			inorderTraversal(*head);
			printf("\n");
		} else if (choice == 8) {
			printf("二叉树遍历如下：\n");
			postOrderTraversal(*head);
			printf("\n");
		} else if (choice == 9) {
				int data;
				printf("请输入要查找的数据：\n");
				scanf("%d",&data);
			if (searchSortTree(head,data)) {
				printf("查找成功，树中确有此值！！！\n");
			} else {
				printf("查找失败，树中没有该值！！！\n"); 
			}	
		} else {
			printf("操作结束！\n");
			loop = false;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
