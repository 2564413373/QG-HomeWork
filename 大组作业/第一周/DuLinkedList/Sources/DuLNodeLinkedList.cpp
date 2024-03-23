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
	head->data = -1;  //////// ͷ���ֵΪ-1
	head->next = NULL;
	head->front = NULL;
	printf("�����ʼ����ɣ�\n");
	return head;
}

////// ����n���Լ�ָ�������������������
void addLNode(DuLNode* head) {
	int n,LinkedList_count,value_count;
	/////////// �������Ϊ�վͳ�ʼ���������
	if (head == NULL) {
		printf("����δ��ʼ�������ȥ��ʼ������\n");
	} else { 
	    printf("�������ڵڼ�����ӽ���Լ���Ӹ���: \n");
	    scanf("%d %d",&n,&value_count);
	    DuLNode *p;
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
				DuLNode* temp = (struct DuLNode*)malloc(sizeof(struct DuLNode));
				temp->data = value;
				temp->next = p->next;
				/////////// ��Ϊ��� p�Ѿ���β������ôp->next��ǰ��ָ���û�����壬�ᱨ��
				////����Ҫ�����⴦�� 
				if (!(p->next == NULL)) { 
				    p->next->front = temp;	
				}
				p->next = temp;
				temp->front = p;
				p = temp;
				temp = NULL;
			}
			printf("������!\n");
		}
    }
}

////// ɾ����n�����
void deleteLNode(DuLNode* head) {
	if (head == NULL) {
		printf("����δ��ʼ�������ȥ��ʼ������\n");
	} else {
	int value;
	printf("ɾ���ڼ�����\n ");
	scanf("%d",&value);
	DuLNode* p=head;
	if (value <= 0 || value > Length_LinkedList(head)-1) {
		printf("��������ֲ�����Ҫ��ɾ��ʧ�ܣ�\n");
	} else {
		for (int i=0;i<value;i++) {
			p = p->next;
		}
		p->front->next = p->next;
		p->next->front = p->front;
		printf("ɾ���ɹ���\n");
	 }
   }
}

////// �޸ĵ�n������ֵ
void updateLNode(DuLNode* head) {
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
		DuLNode* p=head;
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

///// ������������
void showLinkedList(DuLNode* head) {
	if (head == NULL) {
		printf("����δ��ʼ�������ȥ��ʼ������\n");
	} else {
	int choice;
	printf("ѡ���������(1),���Ƿ������(2)��");
	scanf("%d",&choice);
	if (choice == 1) {
		DuLNode* p = head;
		printf("�������£�  ");
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
		printf("�������£�  ");
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
		printf("��Чѡ��");
	}
   }
}

int main() {
	int id;
	DuLNode* head = NULL;
	bool loop = true;
    while (loop) {
    	printf("�����������ţ�\n 1.��ʼ������\n 2.��ӽڵ�\n 3.չʾ����\n 4.ɾ�����\n 5.�޸Ľ��\n 6.�˳�\n");
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
				printf("���������������˳���\n");
				loop = false;
				break;
			default:
				printf("��ѡ����Ч��\n");
		} 
	}
	return 0;
}
