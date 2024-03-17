#include "../Headers/LinkedList.h"

int Length_LinkedList(LNode* head) {
	if (head == NULL) {
		return 0;
	}
	LNode* p = head;
	int count = 0;
	while(p) {
		++count;
		p = p->next;
	}
	return count;
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
		initLinkedList();
		printf("��ʼ������ɹ����������˴ν���!");
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

void showLinkedList(LNode* head) {
    if (head == NULL) {
    	printf("����Ϊ�գ��޷�չʾ��\n");
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

void deleteLNode(LNode* head) {
	int value;
	printf("�ӵڼ���֮��ʼɾ����\n ");
	scanf("%d",&value);
	LNode* p=head;
	if (value <= 0 || value > Length_LinkedList(head)-1) {
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

void updateLNode(LNode* head) {
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

void reversed_LinkedList(LNode* head) {   /////// �ǵݹ鷴ת(ͷ��㲻��ת) 
	if (head == NULL || head->next == NULL) {
		printf("��ת��Ч��");
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

bool isCircle(LNode* head) {
	if (head == NULL || head->next == NULL) {
		return false;
	} else if(head->next == head) {
		return true;
	}
	LNode *slow,*fast;
	slow = fast = head;
	while (true) {
		if (fast->next == NULL || fast == NULL) {
			return false;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast) {
			fast = fast->next;
			if (slow == fast) {
				return true;
			}
		}
	}
}

int middle_value(LNode* head) {
	if (head == NULL) {
		printf("�޷�����ֵ��\n");
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
	LNode* head = initLinkedList();
	bool loop = true;
    while (loop) {
    	printf("�����������ţ�\n 1.��ӽڵ�\n 2.չʾ����\n 3.ɾ�����\n 4.�޸Ľ��\n 5.��ת\n 6.�˳�\n 7.�ж��Ƿ��л�\n 8.���������м�ֵ\n");
		scanf("%d",&id);
		switch(id) {
			case 1:
				addLNode(head);
				break;
			case 2:
				showLinkedList(head);
				break;
			case 3:
				deleteLNode(head);
				break;
			case 4:
				updateLNode(head);
				break;
			case 5:
				reversed_LinkedList(head);
				break;
			case 6:
				printf("���������������˳���");
				loop = false;
				break;
			case 7:
				if (isCircle(head)) {
					printf("��������ڻ�!\n");
				} else {
					printf("���������ڻ�!\n");
				}
			case 8:
				printf("�������м�ֵΪ��%d\n",middle_value(head));
				break;
		} 
	}
} 
