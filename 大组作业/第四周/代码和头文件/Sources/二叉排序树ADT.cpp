#include "../Headers/����������ADT.h"

/////// ��ʼ������������      ��ӽ�㺯��ע��������������-1����ֹ�� 
BSTree* init_SortTree() {
    /////// ��ʼ���ն�����
    BSTree* head;
	BSTree temp = (BSTree)malloc(sizeof(TreeNode));
	printf("�����������ֵ��\n");
	int value;
	scanf("%d",&value);
	temp->left = NULL;
	temp->right = NULL;
	temp->data = value;
	*head = temp;
	printf("������������ʼ���ɹ�������\n");
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

/////// ��ӽ�㵽����������
void add_SortTree(BSTree* head,int value) { 
	////// ���headΪ���򴴽��½��
	if (*head == NULL) {
		BSTree temp = (BSTree)malloc(sizeof(TreeNode));
		temp->data = value;
		temp->left = NULL;
		temp->right = NULL;
		*head = temp;
	} else {
		/////// ����½��ֵС�ڵ�ǰ�����ֵ����ȥ������
		if (value < (*head)->data) { 
			add_SortTree(&((*head)->left),value);
		} else if (value > (*head)->data){
			add_SortTree(&((*head)->right),value);
		} else { ///////  �½���ֵ�͵�ǰ�������ͬ��������� 
			printf("����ӵ��½��ֵ�����Ѵ��ڣ�������ӣ�����\n");
			return;
		}
	}	
} 

//////// ���Ҷ��������� 
bool searchSortTree(BSTree* head,int value) {
	///////// ���Ϊ�գ����ѯʧ�� 
	if (*head == NULL) {
		return false;
	}
	//////// ���ֵ��ȣ����ѯ�ɹ�
	if ((*head)->data == value) {
		return true;
	}
	/////// ���С�ڵ�ǰ���ֵ���ݹ�ȥ��������Ѱ
	if (value < (*head)->data) {
		return searchSortTree(&((*head)->left),value);
	} else {
		return searchSortTree(&((*head)->right),value);
    }
}

////// ɾ������������ָ�����
   /// ���������
     /// 1. ɾ�Ľ����Ҷ�ӣ�ֱ��ɾ
	 /// 2. ɾ�Ľ����������һ����һ�����գ���ֱ���ñ�ɾ���ķǿ����������Լ� 
	 /// 3. ɾ�Ľ�����������Բ��գ��ҵ���ɾ����ֱ��ǰ����Ȼ����ֱ��ǰ����ֵ���Ǳ�ɾ���
	  ////  Ȼ��ɾȥǰ����� 
bool delete_SortTree(BSTree* head,int value) {
    if (*head == NULL) {
    	return false;
	}
	if (value == (*head)->data) {
		/////// ִ��ɾ������
		DeleteNode(head);
		return true; 
	}
	if (value < (*head)->data) {
		return delete_SortTree(&((*head)->left),value);
	} else {
		return delete_SortTree(&((*head)->right),value);
	}
} 

/////// ɾ��������
void DeleteNode(BSTree* p) {
	TreeNode *temp ,*s; ////// head ��ɾ 
	temp = *p;
	if ((*p)->left == NULL) {
		*p = (*p)->right;
		free(temp);
	} else if ((*p)->right == NULL) {
		*p = (*p)->left;
		free(temp);
	} else {  /////// ���߶����� 
		////// �ҵ�ֱ��ǰ��
		s = (*p)->left;
		while (s->right) {
			temp = s;
			s = s->right;
		}
		(*p)->data = s->data;
		if (*p == temp) { /////// ���ֱ��ǰ���Ǳ�ɾ�������� 
			temp->left = s->left;
		} else {
			temp->right = s->left;
		}
		free(s);
	}
} 

////// �ݹ��������
void preOrder(BSTree head) {
	if (head == NULL) {
		//printf("������Ϊ�գ����ܱ���������\n");
		return;
	}
	printf("%d ",head->data);
	preOrder(head->left);
	preOrder(head->right);
} 

////// �ݹ��������
void inOrder(BSTree head) {
	if (head == NULL) {
		//printf("������Ϊ�գ����ܱ���������\n");
		return;
	}
	inOrder(head->left);
	printf("%d ",head->data);
	inOrder(head->right);
} 

////// �ݹ�������
void postOrder(BSTree head) {
	if (head == NULL) {
		//printf("������Ϊ�գ����ܱ���������\n");
		return;
	}
	postOrder(head->left);
	postOrder(head->right);
	printf("%d ",head->data);
} 

/////// ջ�ķǵݹ����
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

//////// ����ǵݹ� 
void preorderTraversal(BSTree root) {
    if (root == NULL) return;

    Stack stack;
    stack.top = NULL;
    push(&stack, root);

    while (!isEmptyStack(&stack)) {
        BSTree current = pop(&stack);
        printf("%d ", current->data);

        // ע�⣺��ѹ���Һ��ӣ���ѹ������
        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

///// ����ǵݹ� 
void inorderTraversal(BSTree root) {	
	if (root == NULL) return;
	
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

///// ����ǵݹ� 
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
		printf("��������Ĳ���ѡ��\n 1.��ʼ��������\n 2.����\n 3.ɾ��\n 4.�ݹ����\n 5.�������\n 6.�ǵݹ��������\n 7.�ǵݹ��������\n 8.�ǵݹ�������\n 9.����ָ��ֵ\n ��������.�˳�\n");
		scanf("%d",&choice);
		if (choice == 1) {
			head = init_SortTree();
			flag = 1;
		} else if (choice == 2) {
			if (flag > 0) {
			int value; /////// ѭ�����룬�䵽-1��ֹͣ 
				while (true) {
					printf("��������һ������ֵ��(����-1�ͽ���)\n");
					scanf("%d",&value);
					if (value == -1) {
						printf("�������������\n");
						break;
					}
					add_SortTree(head,value);
				}
			} else {
				printf("���ȳ�ʼ������������ӣ�����\n");
			}	
		} else if (choice == 3) {
			int value;
			printf("������Ҫɾ����ֵ��");
			scanf("%d",&value);
			if (delete_SortTree(head,value)) {
				printf("ɾ���ɹ�������\n");
			} else {
				printf("ɾ��ʧ�ܣ�����\n");
			}
		} else if (choice == 4) {
			int choice4;
			printf("��������Ҫ����˳�������1.���� 2.���� 3.����\n");
			scanf("%d",&choice4);
			if (choice4 == 1) {
				printf("�������������£�\n");
				preOrder(*head);
				printf("\n");
			} else if (choice4 == 2) {
				printf("�������������£�\n");
				inOrder(*head);
				printf("\n");
			} else if (choice4 == 3) {
				printf("�������������£�\n");
				postOrder(*head);
				printf("\n");
			}
		} else if (choice == 5) {
			printf("�������������£�\n");
			levelOrderTraversal(*head);
			printf("\n");
		} else if (choice == 6) {
			printf("�������������£�\n");
			preorderTraversal(*head);
			printf("\n");
		} else if (choice == 7) {
			printf("�������������£�\n");
			inorderTraversal(*head);
			printf("\n");
		} else if (choice == 8) {
			printf("�������������£�\n");
			postOrderTraversal(*head);
			printf("\n");
		} else if (choice == 9) {
				int data;
				printf("������Ҫ���ҵ����ݣ�\n");
				scanf("%d",&data);
			if (searchSortTree(head,data)) {
				printf("���ҳɹ�������ȷ�д�ֵ������\n");
			} else {
				printf("����ʧ�ܣ�����û�и�ֵ������\n"); 
			}	
		} else {
			printf("����������\n");
			loop = false;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
