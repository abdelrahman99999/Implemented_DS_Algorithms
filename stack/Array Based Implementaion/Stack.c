#include <stdio.h>
#define MaxStack 100

typedef enum bool{ fale,true }boolean;

//you should to define your type of tye elements of stack
typedef int StackEntry ; //int elements

typedef struct stack {
	int top;    //to point for the top of stack
	StackEntry entry[MaxStack];      //array(entry) will contain n=MaxStack elements of type entryType 
}Stack;

void initStack(Stack *ps) {             //initialize stack
	ps->top = 0; //*ps.top=0
}

void push(StackEntry e, Stack *ps) {
	//pre_conditions: stack is initalized and is not full
	ps->entry[ps->top] = e;
	ps->top++;
	//or we can do at one line 	( ps->entry[ps->top++]=e; )
}

boolean stackFull(Stack *ps) {
	return ps->top == MaxStack; //we can use ( >= )
								//using call by ref as it's efficient more (no waste for memory or time of copying)
}

void pop(StackEntry *pe, Stack *ps) {
	//pre_conditions: stack is initalized and is not empty
	ps->top--;
	*pe = ps->entry[ps->top];
	//or we can do at one line 	( *pe=ps->entry[-- ps->top]; )
	//the topelement is distroyed(the user think is distroyed)(but data still in the memory)
	//in linked stack when pop we will distroy the data finally from memory) 
}

boolean stackEmpty(Stack *ps) {
	//pre_conditions: stack is not empty -- same as pop
	return !ps->top;
	//using call by ref as it's efficient (no waste for memory or time of copying)
}

void stackTop(StackEntry *pe, Stack *ps) {
	*pe = ps->entry[ps->top - 1];
	//here we don't change any values inside stack
	//using call by ref as it's efficient (no waste for memory or time of copying)
}

int stackSize(Stack *ps) {
	//pre_conditions: stack is initiaized
	return ps->top;
	//using call by ref as it's efficient (no waste for memory or time of copying)
}

void clearStack(Stack *ps) {
	ps->top = 0;
	//the elements is distroyed(the user think is distroyed)(but data still in the memory)
	//in linked stack when clear we will distroy the data finally from memory)
}

//passing function as a parameter
// we write 1-return type of function 2-pointer to function 3-type of parameter of function
void traverseStack(Stack *ps, void(*pf)(StackEntry)) {
	//pre_conditions: stack is initalized
	//passed function with one parameter and must return void
	for (int i = ps->top; i>0; i--) {
		(*pf)(ps->entry[i - 1]);
	}
}

void dispaly(StackEntry e) {
	printf("%d ", e);
}

int main(){
	//test
	Stack s1;
	initStack(&s1);
	printf("is stack empty? %d\n", stackEmpty(&s1));
	printf("the size of stack: %d\n", stackSize(&s1));
	if(!stackFull(&s1))push(5, &s1);
	if (!stackFull(&s1))push(10, &s1);
	if (!stackFull(&s1))push(15, &s1);
	if (!stackFull(&s1))push(20, &s1);
	if (!stackFull(&s1))push(25, &s1);
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
