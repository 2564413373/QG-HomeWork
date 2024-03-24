#include "../Headers/LinkStack.h"
 
bool isEmpty(LinkStack* temp) {
	return (temp == NULL);
}

LinkStack* init_LinkStack() {
    LinkStack* temp = (LinkStack*)malloc(sizeof(LinkStack));
	temp->top = NULL;
	temp->count = 0;
	printf("��ջ��ʼ���ɹ���\n");
	return temp;
}

void push_LinkStack(LinkStack* temp) {
    if (isEmpty(temp)) {
    	printf("��ջΪ�գ����ȥ��ʼ����ջ��\n");
	} else {
		int id;
		printf("��������Ҫ��ӵ���ֵ��");
		scanf("%d",&id);
		LinkStackPtr new_temp = (LinkStackPtr)malloc(sizeof(StackNode));
		new_temp->data = id;
		new_temp->next = temp->top;
		temp->top = new_temp;
		++temp->count; 
		printf("��ӳɹ�\n");
	}
}

void show_LinkStack(LinkStack* temp) {
	if (isEmpty(temp)) {
		printf("��ջΪ�գ����ȥ��ʼ����ջ��\n");
		return;
	} else if (temp && temp->top == NULL) {
		printf("�����ʱ�����ڳ�ʼ��״̬��û�н��ɱ���\n");
		return;
	} 
	printf("ջ���������£�");
	LinkStackPtr p = temp->top;
	while(p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	free(p); 
}

void pop_LinkStack(LinkStack* temp) {
	if (isEmpty(temp)) {
	   	printf("��ջΪ�գ����ȥ��ʼ����ջ��\n");
	   	return;
	}
    if (temp && temp->top == NULL) {
    	printf("�ճ�ʼ������û��ջ����Գ�������ʧ�ܣ�\n");
    	return;
	}
	 /////// ��ʱָ�룬ָ��Ҫ��ջ�Ľ��
	LinkStackPtr temp1 = temp->top;
	--temp->count;
	temp->top = temp->top->next;
	free(temp1);
	printf("��ջ�ɹ���");
}

int get_Headvalue(LinkStack* temp) {
	if (isEmpty(temp)) {
		return -1;
	} else if (temp && temp->top == NULL) {
		return -1;
	}
	return temp->top->data;
}

void destroy_LinkStack(LinkStack* temp) {
	if (isEmpty(temp)) {
		printf("��ջ���ٳɹ���\n");
		return;
	} else if (temp && temp->top == NULL) {  /////// ��ʼ����ջ״̬
	    printf("��ջ���ٳɹ���\n"); 
		temp = NULL;
		return;
	}
	while (temp->top) {
		LinkStackPtr temp1 = temp->top;
		temp->top = temp->top->next;
		temp1->next = NULL;
		temp1 = NULL;
	}
}

int Length_Stack(LinkStack* temp) {
	if (isEmpty(temp)) {
		return 0;
	} else if (temp && temp->top == NULL) {
		return 0;
	}
	return temp->count;
}

int main() {
	bool loop = true;
	LinkStack* head; ///// tail : ȫ��ָ��ջ�� 
	int choice;
	while (loop) {
		printf("�����������ţ�\n 1.��ʼ����ջ\n 2.��ջ\n 3.�˳�\n 4.����\n 5.��ջ\n 6.����ջ��ֵ\n 7.����ջ\n 8.����ջ����\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				head = init_LinkStack();
				break;
			case 2:
				push_LinkStack(head);
				break;
			case 3:
				loop = false;
				break;
			case 4:
				show_LinkStack(head);
				break;
			case 5:
				pop_LinkStack(head);
				break;
			case 6:
				printf("ջ��ֵΪ��%d�� ������-1������ջûջ��ֵ��\n",get_Headvalue(head));
				break;
			case 7:
				destroy_LinkStack(head);
				break;
			case 8:
				printf("ջ����Ϊ��%d\n",Length_Stack(head));
				break;
			default:
			    printf("��ѡ����Ч��������ѡ��\n"); 
		}
	}
	printf("\n");
    system("pause");
	return 0;
}
