#include "../Headers/LinkStack.h"
 
bool isEmpty(LinkStack* temp) {
	return (temp == NULL);
}

LinkStack* init_LinkStack() {
    LinkStack* temp = (LinkStack*)malloc(sizeof(LinkStack));
	temp->top = NULL;
	temp->count = 0;
	printf("链栈初始化成功！\n");
	return temp;
}

void push_LinkStack(LinkStack* temp) {
    if (isEmpty(temp)) {
    	printf("链栈为空，请回去初始化链栈！\n");
	} else {
		int id;
		printf("请输入你要添加的新值：");
		scanf("%d",&id);
		LinkStackPtr new_temp = (LinkStackPtr)malloc(sizeof(StackNode));
		new_temp->data = id;
		new_temp->next = temp->top;
		temp->top = new_temp;
		++temp->count; 
		printf("添加成功\n");
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

void pop_LinkStack(LinkStack* temp) {
	if (isEmpty(temp)) {
	   	printf("链栈为空，请回去初始化链栈！\n");
	   	return;
	}
    if (temp && temp->top == NULL) {
    	printf("刚初始化，还没有栈点可以出，操作失败！\n");
    	return;
	}
	 /////// 临时指针，指向要出栈的结点
	LinkStackPtr temp1 = temp->top;
	--temp->count;
	temp->top = temp->top->next;
	free(temp1);
	printf("出栈成功！");
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
		printf("链栈销毁成功！\n");
		return;
	} else if (temp && temp->top == NULL) {  /////// 初始化链栈状态
	    printf("链栈销毁成功！\n"); 
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
	LinkStack* head; ///// tail : 全程指着栈底 
	int choice;
	while (loop) {
		printf("请输入操作编号：\n 1.初始化链栈\n 2.入栈\n 3.退出\n 4.遍历\n 5.出栈\n 6.返回栈顶值\n 7.销毁栈\n 8.返回栈长度\n");
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
				printf("栈顶值为：%d， （返回-1代表链栈没栈顶值）\n",get_Headvalue(head));
				break;
			case 7:
				destroy_LinkStack(head);
				break;
			case 8:
				printf("栈长度为：%d\n",Length_Stack(head));
				break;
			default:
			    printf("该选择无效，请重新选择！\n"); 
		}
	}
	printf("\n");
    system("pause");
	return 0;
}
