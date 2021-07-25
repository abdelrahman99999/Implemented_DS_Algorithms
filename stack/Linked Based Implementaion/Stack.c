#include <stdio.h>
#include<stdlib.h>    //for using NULL

//set your stack elements type
#define StackEntry int

typedef enum bool{ false,true }boolean;

typedef struct stacknode {
	StackEntry entry;
	struct stacknode *next;
}StackNode;

typedef struct stack {
	StackNode *top;
	int size;
}Stack;


void initStack(Stack *ps) {             //initialize stack
	ps->top = NULL;
	ps->size = 0;
}

int push(StackEntry e, Stack *ps) {
	//pre_conditions: stack is initalized , no condition of not full as in linked implementaion the stack can not full
	StackNode *pn;
	pn = (StackNode*)malloc(sizeof(StackNode)); //or we can do in one line ( StackNode *pn=(StackNode*)malloc(sizeof(StackNode)); )
	if (!pn)return 0;
	else {
		pn->entry = e;
		pn->next = ps->top;
		ps->top = pn;
		ps->size++;
		return 1;
	}
	//if and else used to handle error may happen in malloc
}

boolean stackFull(Stack *ps) {
	return 0; //stack can not be full //we use same interface of array based implementation
}

void pop(StackEntry *pe, Stack *ps) {
	//pre_conditions: stack is initalized and is not empty
	*pe = ps->top->entry;
	StackNode *pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
	//free doesn't remove pn but it make the place for operating system to take control
	//(may another program uses or same program used it say for declaration of variable for example)
	//so data in linked implemntaion it's no available to use 
	ps->size--;
}

boolean stackEmpty(Stack *ps) {
	return ps->top == NULL;        //OR return !ps->size;

								   //two reason to use call by ref
								   //(1)to be like interface of array based implementaion
								   //(2)array based -- here we don't change any values inside stack
								   //(2)array based -- using call by ref as it's efficient (no waste for memory or time of copying)
}

void stackTop(StackEntry *pe, Stack *ps) {
	//pre_conditions: stack is not empty -- same as pop
	*pe = ps->top->entry;
	//two reason to use call by ref
	//(1)to be like interface of array based implementaion
	//(2)array based -- here we don't change any values inside stack
	//(2)array based -- using call by ref as it's efficient (no waste for memory or time of copying)
}

int stackSize(Stack *ps) {
	//pre_conditions: stack is initiaized
	return ps->size;          //θ(1)
							  //using call by ref as it's efficient (no waste for memory or time of copying)

	/*
	another way if there is not size field but it's complexity is θ(N)
	StackNode *pn = ps->top;
	int i;
	for(i=0;pn;pn=pn->next)i++;
	return i;
	}
	*/

}

void clearStack(Stack *ps) {
	StackNode *pn = ps->top;
	while (pn) {
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
	ps->size = 0;
}

//passing function as a parameter
// we write 1-return type of function 2-pointer to function 3-type of parameter of function
void traverseStack(Stack *ps, void(*pf)(StackEntry)) {
	//pre_conditions: stack is initalized
	//passed function with one parameter and must return void
	for (StackNode *pn = ps->top; pn; pn = pn->next) {
		(*pf)(pn->entry);
	}
}

void dispaly(StackEntry e) {
	printf("%d ", e);
}


int main() {
	//same main when using array based
	//test
	Stack s1;
	initStack(&s1);
	printf("is stack empty? %d\n", stackEmpty(&s1));
	printf("the size of stack: %d\n", stackSize(&s1));
	if (!stackFull(&s1))
		if(!push(5, &s1))printf("error happen \n");//due to malloc
	if (!stackFull(&s1))
		if (!push(10, &s1))printf("error happen \n");
	if (!stackFull(&s1))
		if (!push(15, &s1))printf("error happen \n");
	if (!stackFull(&s1))
		if (!push(20, &s1))printf("error happen \n");
	if (!stackFull(&s1))
		if (!push(25, &s1))printf("error happen \n");
	printf("is stack empty? %d\n", stackEmpty(&s1));
	printf("the size of stack: %d\n", stackSize(&s1));
	int x = 3;
	if (!stackEmpty(&s1))pop(&x, &s1);
	printf("x value after changing: %d\n", x);
	printf("the size of stack: %d\n", stackSize(&s1));
	stackTop(&x, &s1);
	printf("x value after changing: %d\n", x);
	traverseStack(&s1, &dispaly);
	printf("\n");

	return 0;
}
