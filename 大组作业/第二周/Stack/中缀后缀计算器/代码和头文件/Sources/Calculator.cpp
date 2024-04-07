#include "../Headers/Calculator.h"
////////// ����ջʵ�֣��Ƚ���׺���ʽת��Ϊ��׺���ʽ���ٽ��м��㡣
int Calculator(char temp1,char temp2,char value) {
	if (value == '*') {
		return (temp2-'0') * (temp1-'0');
	} else if (value == '+') {
		return (temp2-'0') + (temp1-'0');
	} else if (value == '-') {
		return (temp2-'0') - (temp1-'0');
	} else if (value == '/') {
		return (temp2-'0') / (temp1-'0');
	}
}

bool isEmpty(LinkStack* head) {
	return (head == NULL);
}

char popStack_Headvalue(LinkStack* head) {
	if (!isEmpty(head)) {
	   if (!(head && head->top == NULL)) {
    	char temp_value = head->top->data;
	    LinkStackPtr temp = head->top;
	    head->top = head->top->next;
	    free(temp);
	    --head->count;
	    return temp_value;
	   }
	} else {
		return -1;
	}
}

char Headvalue(LinkStack* head) {
	if (!isEmpty(head)) {
	   if (!(head && head->top == NULL)) {
	char temp_value = head->top->data;
	return temp_value;
      }
    } else {
    	return 1;
	}
}

void push_LinkStack(LinkStack* head,int value) {
	LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(StackNode));
	temp->data = value;
	temp->next = head->top;
	head->top = temp;
	++head->count;
}

LinkStack* init_LinkStack() {
	LinkStack* temp = (LinkStack*)malloc(sizeof(LinkStack));
	temp->count = 0;
	temp->top = NULL;
	return temp;
}

int Higher_Compare(char x) {
	if (x == '(' || x == ')') {
		return 2;
	} else if (x == '*' || x == '/') {
		return 1;
	} else if (x == '+' || x == '-') {
		return 0;
	} else {
		return -1;
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
int InfixtoPostfix(char* a,LinkStack* count_stack) {
	int result = 0;
	LinkStack* stack = init_LinkStack();
	int i = 0;
	while (a[i]!='\0') {
		//////// ����ֱ�Ӵ�ӡ��������ջ
		if (a[i] >= '0' && a[i] <= '9') {
			/////// �����ջ
			while (a[i+1] != '\0' && (a[i+1] >= '0' && a[i+1] <= '9')) {
				int tmp = ((a[i]-'0')*10+(a[i+1]-'0'));
				++i;
				a[i] = tmp+'0';
		    }
			push_LinkStack(count_stack,a[i]);
			//show_LinkStack(count_stack);
			//show_LinkStack(stack);
		} else {  /////////// ��ĸ����� 1.ջ��ֱ����  2.ջ���վͱȽ����ȼ�  3.������������ţ���������ջֱ�������ų���
		//4. ����������ţ�ֱ����ջ�� 
			if (isEmpty(stack)) {
				push_LinkStack(stack,a[i]);
			} else if (a[i] == '(') {
				push_LinkStack(stack,a[i]);
			} else if (a[i] == ')') { 
				while (Headvalue(stack) != '(') {
					//printf("%c ",popStack_Headvalue(stack));
					char temp1 = popStack_Headvalue(count_stack);
					char temp2 = popStack_Headvalue(count_stack);
					push_LinkStack(count_stack,Calculator(temp1,temp2,popStack_Headvalue(stack))+'0'); 
				}
				popStack_Headvalue(stack);
			} else { ///////// ���ȼ��ȽϹ���������������ջ��������ߣ���ֱ����ջ����Ȼ���ȳ�ջ������ջ 
			  /////////////////
			  while (!isEmpty(stack) && (Higher_Compare(a[i])<=Higher_Compare(Headvalue(stack)))) {
			  	   if (Headvalue(stack) != '(') {  /////////// ֻ�������ţ������Ų��ܵ��� 
			  	    char temp1 = popStack_Headvalue(count_stack);
					char temp2 = popStack_Headvalue(count_stack);
					push_LinkStack(count_stack,Calculator(temp1,temp2,popStack_Headvalue(stack))+'0');
			       } else {
			       	  break;
				   }
			  }
			  push_LinkStack(stack,a[i]);	
			}
		}
		++i;
	}
	//////// �������������ջ���գ���ȫ����ջ
	while (!isEmpty(stack) && stack->top) {
		if (!isEmpty(count_stack) && count_stack->top) { /////// ����ջ��������
		//////////////// �������ջֻʣ���һ�������ˣ�ֱ�ӳ�ջ 
		     if (count_stack->count == 1) {
		     	char temp3 = popStack_Headvalue(count_stack);
		     	result = Calculator(temp3,result+'0',popStack_Headvalue(stack));
			 } else {
			 char temp1 = popStack_Headvalue(count_stack);
			 char temp2 = popStack_Headvalue(count_stack);
			 int temp = Calculator(temp1,temp2,popStack_Headvalue(stack));
			 result += temp;
		     }
		}
	}
	return result;
}

void PostfixToResult() {
	char str[80]; ////str1:װ��׺���ʽ
	LinkStack* count_stack = init_LinkStack(); 
    printf("��������ʽ��\n");
	gets(str);
	printf("������Ϊ��%d",InfixtoPostfix(str,count_stack)); 
}

int main() { ////////// ���ֻ��25���ַ�
    PostfixToResult();
    printf("\n");
    system("pause");
	return 0;
} 
