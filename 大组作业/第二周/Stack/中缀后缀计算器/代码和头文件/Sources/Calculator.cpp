#include "../Headers/Calculator.h"
////////// 以链栈实现，先将中缀表达式转换为后缀表达式，再进行计算。
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
		printf("链栈为空，请回去初始化链栈！\n");
		return;
	} else if (temp && temp->top == NULL) {
		printf("链表此时还处于初始化状态，没有结点可遍历\n");
		return;
	} 
	printf("栈中数据如下：");
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
		//////// 数字直接打印，不能入栈
		if (a[i] >= '0' && a[i] <= '9') {
			/////// 入计算栈
			while (a[i+1] != '\0' && (a[i+1] >= '0' && a[i+1] <= '9')) {
				int tmp = ((a[i]-'0')*10+(a[i+1]-'0'));
				++i;
				a[i] = tmp+'0';
		    }
			push_LinkStack(count_stack,a[i]);
			//show_LinkStack(count_stack);
			//show_LinkStack(stack);
		} else {  /////////// 字母情况： 1.栈空直接入  2.栈不空就比较优先级  3.如果输入右括号，则连续出栈直到左括号出现
		//4. 如果是左括号，直接入栈。 
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
			} else { ///////// 优先级比较规则：如果新运算符比栈顶运算符高，则直接入栈；不然就先出栈顶再入栈 
			  /////////////////
			  while (!isEmpty(stack) && (Higher_Compare(a[i])<=Higher_Compare(Headvalue(stack)))) {
			  	   if (Headvalue(stack) != '(') {  /////////// 只有右括号，左括号才能弹出 
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
	//////// 最后输入完后，如果栈不空，则全部出栈
	while (!isEmpty(stack) && stack->top) {
		if (!isEmpty(count_stack) && count_stack->top) { /////// 计算栈还有数字
		//////////////// 如果计算栈只剩最后一个数字了，直接出栈 
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
	char str[80]; ////str1:装后缀表达式
	LinkStack* count_stack = init_LinkStack(); 
    printf("请输入表达式：\n");
	gets(str);
	printf("计算结果为：%d",InfixtoPostfix(str,count_stack)); 
}

int main() { ////////// 最多只能25个字符
    PostfixToResult();
    printf("\n");
    system("pause");
	return 0;
} 
