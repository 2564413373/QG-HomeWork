#include "../Headers/LinkedList.h"

void showLinkedList(LNode* head) {
    if (head == NULL) {
    	printf("����δ��ʼ�������ȥ��ʼ������\n");
	} else {
		LNode* p = head;
		printf("�������£�  ");
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
		printf("����δ��ʼ�������ȥ��ʼ������\n");
    } else {
	int value,new_value;
	printf("�޸ĵڼ����� ");
	scanf("%d",&value);
	if (value == 0) {
		printf("ͷ��㲻���޸ģ�\n");
	} else if (value < 0 || value > Length_LinkedList(head)){
		printf("�޸�ʧ�ܣ�\n");
	} else {
		LNode* p=head;
		for (int i=0;i<value;i++) {
			p = p->next;
		}
		printf("��������ֵ��");
		scanf("%d",&new_value);
		p->data = new_value;
		printf("�޸ĳɹ�!\n");
	}
   }
}

void reversed_LinkedList(LNode* head) {   /////// �ǵݹ鷴ת(ͷ��㲻��ת) 
	if (head == NULL || head->next == NULL) {
		if (head == NULL) {
			printf("����δ��ʼ�������ȥ��ʼ������\n");
		} else {
		printf("��ת��Ч��");
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
		printf("��ת�ɹ�!\n");
	}
}

LNode* initLinkedList() {
	LNode* head = (struct LNode*)malloc(sizeof(struct LNode));
	head->data = -1;  //////// ͷ���ֵΪ-1
	head->next = NULL;
	printf("�����ʼ����ɣ�\n");
	return head;
}

void addLNode(LNode* head) { ///// ͷ���Ĭ���ǵ�0��  
	int n,LinkedList_count,value_count;
	/////////// �������Ϊ�վͳ�ʼ���������
	if (head == NULL) {
		printf("����δ��ʼ�������ȥ��ʼ������\n");
	} else { 
	    printf("�������ڵڼ�����ӽ���Լ���Ӹ���: \n");
	    scanf("%d %d",&n,&value_count);
	    LNode *p;
		if (n < 0 || n > Length_LinkedList(head)-1) { ////// nΪ�������߳��������ȣ���Ӷ�ʧ�� 
			printf("��������ֲ�����Ҫ�����ʧ�ܣ�");
		} else {
			p = head;
			int value; ////// �����ֵ
			for (int i=0;i<n;i++) {
				p = p->next;
			} 
		    for (int i=0;i<value_count;i++) {
		    	printf("������Ҫ��ӵ�ֵ��\n ");
		    	scanf("%d",&value);
				LNode* temp = (struct LNode*)malloc(sizeof(struct LNode));
				temp->data = value;
				temp->next = p->next;
				p->next = temp;
				p = temp;
				temp = NULL;
			}
			printf("������!\n");
		}
    }
}

void deleteLNode(LNode* head) { ///////// ɾ����value��������һ�����
    if (head == NULL) {
    	printf("����δ��ʼ�������ȥ��ʼ������\n");
	}  else  {
	int value;
	printf("�ӵڼ���֮��ʼɾ����\n ");
	scanf("%d",&value);
	LNode* p=head;
	if (value <= 0 || value >= Length_LinkedList(head)-1) {
		printf("��������ֲ�����Ҫ��ɾ��ʧ�ܣ�\n");
	} else {
		for (int i=0;i<value;i++) {
			p = p->next;
		}
		if (!p->next->next) {
			p->next = NULL;
		} else {
			p->next = p->next->next;
		}
		printf("ɾ���ɹ���\n");
	}
   }
}

bool isCircle(LNode* head) {
	if (head == NULL) {
		printf("����δ��ʼ�������ȥ��ʼ������\n");
		return false;
	} else if (head->next == NULL) {
		printf("���������ڻ�!\n");
		return false;
	} else if(head->next == head) {
		printf("��������ڻ�!\n");
		return true;
	}
	LNode *slow,*fast;
	slow = fast = head;
	while (true) {
		if (fast->next == NULL || fast == NULL) {
			printf("���������ڻ�!\n");
			return false;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast) {
			fast = fast->next;
			if (slow == fast) {	
				printf("��������ڻ�!\n");
				return true;
			}
		}
	}
}


LNode* odd_even(LNode* head) { ////// ͷ��㲻����Ի���Χ (ͷ��������Ϲ�)
    if (head == NULL) {
    	printf("����δ��ʼ�������ȥ��ʼ������\n");
    	return NULL;
	} else if (head->next == NULL && head) {
		printf("�޷�ִ�в���\n");
		return head;
	} else if (head->next && head->next->next == NULL) {
		printf("�޷�ִ�в���\n");
		return head;
	}
    LNode*temp,*odd,*even,*even_temp; ////// even_temp ָ���һ�ν����������ͷ��(����ͷ���),����֮��ȫ�����������ӡ� 
    int count = 0;  /////// ������
	temp = head->next;  ////////// temp �����Ի����� 
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
    		/////// ���������ͷ��㣩����Ϊż��������Ҫһ��ָ��ָ�ŵ�һ�ν����������ͷ���������������
    		if (odd->next == NULL) {
    			break;
			}
    		odd = odd->next;
    		even = odd->next;
	}
    head->next = even_temp;
	return head;
}

int middle_value(LNode* head) {
	if (head == NULL) {
		printf("����δ��ʼ�������ȥ��ʼ������\n");
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
    	printf("�����������ţ�\n 1.��ʼ������\n 2.��ӽڵ�\n 3.չʾ����\n 4.ɾ�����\n 5.�޸Ľ��\n 6.��ת\n 7.�˳�\n 8.�ж��Ƿ��л�\n 9.���������м�ֵ\n 10.��ż����\n");
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
				printf("���������������˳���\n");
				loop = false;
				break;
			case 8:
				isCircle(head);
				break;
			case 9:
				if (middle_value(head)) {
					printf("�������м�ֵΪ��%d\n",middle_value(head));
				}
				break;
			case 10:
				odd_even(head);
				if (odd_even(head)) {
					printf("�����ɹ���\n");
				} 
				break;
			default:
				printf("ûѡ�в�����������ѡ�񣡣���\n");
		} 
	}
} 
