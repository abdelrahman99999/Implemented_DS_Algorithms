#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct linkedlist{ //this is better if you want to add other fields or features without changing the prototype of functions
	Node* head;
}LinkedList;

void Init(LinkedList* ps) {
	ps->head = NULL;
}

void Insert_at_first(int d,LinkedList* ps) {
	Node* link = (Node*)malloc(sizeof(Node));
	link->data = d;
	link->next =ps->head;
	ps->head = link;
}

void Insert_at_last(int d,LinkedList* ps) {
	Node* ptrNode=(Node*)malloc(sizeof(Node));
	ptrNode->data = d;
	ptrNode->next=NULL;
	if(ps->head == NULL){
		ps->head = ptrNode;
		return;
	}
	Node* current=ps->head;
	while(current->next != NULL){
		current=current->next;
	}
	current->next=ptrNode;


}
void print(LinkedList* ps) {
	Node* ptrNode = ps->head;
	while (ptrNode != NULL) {
		printf("%d ", ptrNode->data);
		ptrNode = ptrNode->next;
	}
}




int main(void) {
	LinkedList l1;
	Init(&l1);
	Insert_at_first(5, &l1);
	Insert_at_first(10, &l1);
	Insert_at_first(15, &l1);
	Insert_at_first(20, &l1);
	print(&l1);
	printf("\n");
	LinkedList l2;
	Init(&l2);
	Insert_at_last(-2,&l2);
	Insert_at_last(-4,&l2);
	Insert_at_last(-8,&l2);
	print(&l2);

	return 0;
}