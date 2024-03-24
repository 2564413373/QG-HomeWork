#include "../Headers/LinkedList.h"

void showLinkedList(LNode* head) {
    if (head == NULL) {
    	printf("链表未初始化，请回去初始化链表！\n");
	} else {
		LNode* p = head;
		printf("链表如下：  ");
		while(p) {
			printf("%d ",p->data);
			p = p->next;
		}
		printf("\n");
		free(p);
	}	
}

void updateLNode(LNode* head) {
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
		LNode* p=head;
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

void reversed_LinkedList(LNode* head) {   /////// 非递归反转(头结点不反转) 
	if (head == NULL || head->next == NULL) {
		if (head == NULL) {
			printf("链表未初始化，请回去初始化链表！\n");
		} else {
		printf("反转无效！");
	    }
	} else {
		LNode *p,*q,*temp; 
		p = head;
		q = head->next;
		head->next = NULL;
		temp = q;
		while (q) {
			q = q->next;
			temp->next = NULL;
			temp->next = p->next;
			p->next = temp;
			temp = q;
		}
		printf("反转成功!\n");
	}
}

LNode* initLinkedList() {
	LNode* head = (struct LNode*)malloc(sizeof(struct LNode));
	head->data = -1;  //////// 头结点值为-1
	head->next = NULL;
	printf("链表初始化完成！\n");
	return head;
}

void addLNode(LNode* head) { ///// 头结点默认是第0个  
	int n,LinkedList_count,value_count;
	/////////// 如果链表为空就初始化链表结束
	if (head == NULL) {
		printf("链表未初始化，请回去初始化链表！\n");
	} else { 
	    printf("请输入在第几个添加结点以及添加个数: \n");
	    scanf("%d %d",&n,&value_count);
	    LNode *p;
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
				LNode* temp = (struct LNode*)malloc(sizeof(struct LNode));
				temp->data = value;
				temp->next = p->next;
				p->next = temp;
				p = temp;
				temp = NULL;
			}
			printf("添加完成!\n");
		}
    }
}

void deleteLNode(LNode* head) { ///////// 删除第value个结点的下一个结点
    if (head == NULL) {
    	printf("链表未初始化，请回去初始化链表！\n");
	}  else  {
	int value;
	printf("从第几个之后开始删除：\n ");
	scanf("%d",&value);
	LNode* p=head;
	if (value <= 0 || value >= Length_LinkedList(head)-1) {
		printf("输入的数字不符合要求，删除失败！\n");
	} else {
		for (int i=0;i<value;i++) {
			p = p->next;
		}
		if (!p->next->next) {
			p->next = NULL;
		} else {
			p->next = p->next->next;
		}
		printf("删除成功！\n");
	}
   }
}

bool isCircle(LNode* head) {
	if (head == NULL) {
		printf("链表未初始化，请回去初始化链表！\n");
		return false;
	} else if (head->next == NULL) {
		printf("该链表不存在环!\n");
		return false;
	} else if(head->next == head) {
		printf("该链表存在环!\n");
		return true;
	}
	LNode *slow,*fast;
	slow = fast = head;
	while (true) {
		if (fast->next == NULL || fast == NULL) {
			printf("该链表不存在环!\n");
			return false;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast) {
			fast = fast->next;
			if (slow == fast) {	
				printf("该链表存在环!\n");
				return true;
			}
		}
	}
}


LNode* odd_even(LNode* head) { ////// 头结点不纳入对换范围 (头结点稳如老狗)
    if (head == NULL) {
    	printf("链表未初始化，请回去初始化链表！\n");
    	return NULL;
	} else if (head->next == NULL && head) {
		printf("无法执行操作\n");
		return head;
	} else if (head->next && head->next->next == NULL) {
		printf("无法执行操作\n");
		return head;
	}
    LNode*temp,*odd,*even,*even_temp; ////// even_temp 指向第一次交换后的链表头部(不计头结点),方便之后全部交换完连接。 
    int count = 0;  /////// 计数器
	temp = head->next;  ////////// temp 辅助对换操作 
    odd = head->next;
    even = odd->next;
    head->next = NULL;     
    while (true) {
    	if (even == NULL) {
    		break;
		}
    	++count;
    		odd->next = even->next;
    		even->next = odd;
    		if (count == 1) {
    			even_temp = even;
			}
    		if (count > 1) {
    		temp->next = even;
    	    }
    		temp = odd;
    		/////// 如果链表（除头结点）长度为偶数，还需要一个指针指着第一次交换后的链表头部，方便后续连接
    		if (odd->next == NULL) {
    			break;
			}
    		odd = odd->next;
    		even = odd->next;
	}
    head->next = even_temp;
    printf("执行成功！");
	return head;
}

int middle_value(LNode* head) {
	if (head == NULL) {
		printf("链表未初始化，请回去初始化链表！\n");
		return 0;
	} else {
	LNode *fast ,*slow;
	fast = slow = head;
	while (true) {
		if(fast->next == NULL || fast == NULL) {
			break;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast->next) {
			fast = fast->next;
		}
	}
	return slow->data;
   }
}

int main() {
	int id;
	bool loop = true;
	LNode *head = NULL;
    while (loop) {
    	printf("请输入操作编号：\n 1.初始化链表\n 2.添加节点\n 3.展示链表\n 4.删除结点\n 5.修改结点\n 6.反转\n 7.退出\n 8.判断是否有环\n 9.返回链表中间值\n 10.奇偶操作\n");
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
				reversed_LinkedList(head);
				break;
			case 7:
				printf("操作结束，程序退出！\n");
				loop = false;
				break;
			case 8:
				isCircle(head);
				break;
			case 9:
				if (middle_value(head)) {
					printf("该链表中间值为：%d\n",middle_value(head));
				}
				break;
			case 10:
				odd_even(head);
				break;
			default:
				printf("没选中操作，请重新选择！！！\n");
		} 
	}
	printf("\n");
    system("pause");
} 
