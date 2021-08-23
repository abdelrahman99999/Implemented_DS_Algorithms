#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;


void Init(Node **pn) {
	*pn = NULL;
}

void Insert_at_first(int d, Node **pn) {
	Node* link = (Node*)malloc(sizeof(Node));
	link->data = d;
	link->next = *pn;
	*pn = link;
}

void Insert_at_last(int d, Node **pn) {
	Node* ptrNode=(Node*)malloc(sizeof(Node));
	ptrNode->data = d;
	ptrNode->next=NULL;
	if(*pn==NULL){
		*pn=ptrNode;
		return;
	}
	Node* current=*pn;
	while(current->next != NULL){
		current=current->next;
	}
	current->next=ptrNode;


}
void print(Node **pn) {
	Node* ptrNode = *pn;
	while (ptrNode != NULL) {
		printf("%d ", ptrNode->data);
		ptrNode = ptrNode->next;
	}
}




int main(void) {
	//this Implementation not readable and if i want to add some features i will suffer
	Node* head;
	Init(&head);
	Insert_at_first(5, &head);
	Insert_at_first(10, &head);
	Insert_at_first(15, &head);
	Insert_at_first(20, &head);
	print(&head);
	printf("\n");

	Node* head2;
	Init(&head2);
	Insert_at_last(-2,&head2);
	Insert_at_last(-4,&head2);
	Insert_at_last(-8,&head2);
	print(&head2);

	return 0;
}




