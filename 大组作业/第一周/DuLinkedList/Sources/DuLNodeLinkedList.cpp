#include "../Headers/DuLinkedList.hpp"

int Length_LinkedList(DuLNode* head) {
	if (head == NULL) {
		return 0;
	}
	DuLNode* p = head;
	int count = 0;
	while(p) {
		++count;
		p = p->next;
	}
	return count;
}


DuLNode* initLinkedList() {
	DuLNode* head = (struct DuLNode*)malloc(sizeof(struct DuLNode));
	head->data = -1;  //////// 头结点值为-1
	head->next = NULL;
	head->front = NULL;
	printf("链表初始化完成！\n");
	return head;
}

////// 往第n（自己指定）个结点后面添加数据
void addLNode(DuLNode* head) {
	int n,LinkedList_count,value_count;
	/////////// 如果链表为空就初始化链表结束
	if (head == NULL) {
		printf("链表未初始化，请回去初始化链表！\n");
	} else { 
	    printf("请输入在第几个添加结点以及添加个数: \n");
	    scanf("%d %d",&n,&value_count);
	    DuLNode *p;
		if (n < 0 || n > Length_LinkedList(head)-1) { ////// n为负数或者超过链表长度，添加都失败 
			printf("输入的数字不符合要求，添加失败！");
		} else {
			p = head;
			int value; ////// 输入的值
			for (int i=0;i<n;i++) {
				p = p->next;
			} 
		    for (int i=0;i<value_count;i++) {
		    	printf("请输入要添加的值：\n ");
		    	scanf("%d",&value);
				DuLNode* temp = (struct DuLNode*)malloc(sizeof(struct DuLNode));
				temp->data = value;
				temp->next = p->next;
				/////////// 因为如果 p已经在尾部，那么p->next的前后指针就没有意义，会报错
				////所以要做特殊处理 
				if (!(p->next == NULL)) { 
				    p->next->front = temp;	
				}
				p->next = temp;
				temp->front = p;
				p = temp;
				temp = NULL;
			}
			printf("添加完成!\n");
		}
    }
}

////// 删除第n个结点
void deleteLNode(DuLNode* head) {
	if (head == NULL) {
		printf("链表未初始化，请回去初始化链表！\n");
	} else {
	int value;
	printf("删除第几个：\n ");
	scanf("%d",&value);
	DuLNode* p=head;
	if (value <= 0 || value > Length_LinkedList(head)-1) {
		printf("输入的数字不符合要求，删除失败！\n");
	} else {
		for (int i=0;i<value;i++) {
			p = p->next;
		}
		p->front->next = p->next;
		p->next->front = p->front;
		printf("删除成功！\n");
	 }
   }
}

////// 修改第n个结点的值
void updateLNode(DuLNode* head) {
	if (head == NULL) {
		printf("链表未初始化，请回去初始化链表！\n");
	} else {
	int value,new_value;
	printf("修改第几个： ");
	scanf("%d",&value);
	if (value == 0) {
		printf("头结点不可修改！\n");
	} else if (value < 0 || value > Length_LinkedList(head)){
		printf("修改失败！\n");
	} else {
		DuLNode* p=head;
		for (int i=0;i<value;i++) {
			p = p->next;
		}
		printf("请输入新值：");
		scanf("%d",&new_value);
		p->data = new_value;
		printf("修改成功!\n");
	}
   }
}

///// 遍历整个链表
void showLinkedList(DuLNode* head) {
	if (head == NULL) {
		printf("链表未初始化，请回去初始化链表！\n");
	} else {
	int choice;
	printf("选择正向遍历(1),还是反向遍历(2)：");
	scanf("%d",&choice);
	if (choice == 1) {
		DuLNode* p = head;
		printf("链表如下：  ");
		while(p) {
			printf("%d ",p->data);
			p = p->next;
		}
		printf("\n");
	} else if (choice == 2) {
		DuLNode* p = head;
		while (p->next) {
			p = p->next;
		}
		printf("链表如下：  ");
		printf("%d ",head->data);
		while(p) {
			if (p == head) {
				break;
			}
			printf("%d ",p->data);
			p = p->front;
		}
		printf("\n");
	} else {
		printf("无效选择！");
	}
   }
}

int main() {
	int id;
	DuLNode* head = NULL;
	bool loop = true;
    while (loop) {
    	printf("请输入操作编号：\n 1.初始化链表\n 2.添加节点\n 3.展示链表\n 4.删除结点\n 5.修改结点\n 6.退出\n");
		scanf("%d",&id);
		switch(id) {
			case 1:
				head = initLinkedList();
				break;
			case 2:
				addLNode(head);
				break;
			case 3:
				showLinkedList(head);
				break;
			case 4:
				deleteLNode(head);
				break;
			case 5:
				updateLNode(head);
				break;
			case 6:
				printf("操作结束，程序退出！\n");
				loop = false;
				break;
			default:
				printf("该选择无效！\n");
		} 
	}
	return 0;
}
