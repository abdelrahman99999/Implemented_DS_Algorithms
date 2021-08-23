/*
Doubly linked list is a variation of Linked List in which navigation is  possible in both ways, either forward and backward
easily compared to single Linked List
*/

#include<stdio.h>
#include<stdlib.h>
typedef enum bool{ false,true }boolean;

//you should set your data type of list elements
#define ListEntry int

typedef struct listnode {
	ListEntry entry;
	struct listnode *next;
	struct listnode *prev;
}ListNode;

typedef struct doublylist {
	ListNode *head;
	int size;
}DoublyList;

//initialize list
void initList(DoublyList *pl) {
	pl->size = 0;
	pl->head = NULL;
}

//check if list is full or not full
//as we use linked Implementation , always return 0
boolean listFull(DoublyList *pl) {
	return 0;
}

//check if list is empty or not empty
boolean listEmpty(DoublyList *pl) {
	return !pl->size;      //return !pl->head
}

//insert element at specific position
int insertList(int pos, ListEntry e, DoublyList *pl) {

	ListNode *pn;
	if (pn = (ListNode*)malloc(sizeof(ListNode))) {
		pn->entry = e;
		pn->next = NULL;
		pn->prev = NULL;
		if (pos == 0) {
			pn->next = pl->head;
			pl->head = pn;
		}
		
		else {
			ListNode *pn2 = pl->head;
			for (int i = 0; i < pos - 1; i++) {
				pn2 = pn2->next;  //after exit for loop the pn2 points to node before desired position (pos-1)
			}
			pn->next = pn2->next;
			pn->prev = pn2;
			pn2->next = pn;
			if(pos != pl->size)  (pn->next)->prev = pn;   //check for last element or not
		}
		pl->size++;
		return 1;
	}
	else {
		return 0;
	}
}

//to delete element in specific position and retrieve its value too
void deleteList(int pos, ListEntry *pe, DoublyList *pl) {

	ListNode *pn, *temp;
	
	if (pos == 0) {
		
		*pe = pl->head->entry;
		temp = pl->head->next; //temp points to second node
		free(pl->head);        //destroy first node
		pl->head = temp;       //make pl->head points to second node (now it is the first node) 
		pl->head->prev = NULL;
	}
	else {
		/*here i will use 2 pointers
		1-first pointer points to node before desired deleted node ( pos-1 )  pn
		2-second pointer points to node after desired deleted node  (pos+1 )  temp
		*/
		pn = pl->head;
		for (int i = 0; i < pos - 1; i++) {
			pn = pn->next;    //after exit for loop the pn2 points to node before desired position (pos-1)
		}

		*pe = pn->next->entry;
		temp = pn->next->next;    //at (pos+1)
		free(pn->next);
		pn->next = temp;
		if (pos != pl->size-1) temp->prev = pn;
	}
	pl->size--;
}

int listSize(DoublyList *pl) {
	return pl->size;
}

void clearList(DoublyList *pl) {
	ListNode *pn = pl->head;
	while (pl->head) {
		pn = pn->next;
		free(pl->head);
		pl->head = pn;
	}
	pl->size = 0;
}

void forward_traverseList(DoublyList *pl, void(*pf)(ListEntry e)) {
	for (ListNode *pn = pl->head; pn; pn = pn->next) {
		(*pf)(pn->entry);
	}
}

void backward_traverseList(DoublyList *pl, void(*pf)(ListEntry e)) {
	ListNode *pn = pl->head;
	for (; pn->next!=NULL ; pn = pn->next);
	for (; pn; pn = pn->prev) {
		(*pf)(pn->entry);
	}

}

//to retrieve value of element in specific position (without deleting it)
void retrieveList(int pos, ListEntry *pe, DoublyList *pl) {
	ListNode *pn = pl->head;
	for (int i = 0; i < pos; i++) {
		pn = pn->next;
	}
	*pe = pn->entry;
}

//to replace value of element in specific position with another  element value passed as argument
void replaceList(int pos, ListEntry e, DoublyList *pl) {
	ListNode *pn = pl->head;
	for (int i = 0; i < pos; i++) {
		pn = pn->next;
	}
	pn->entry = e;
}



void display(ListEntry e) {
	printf("%d ", e);
}

int main() {
	//test
	DoublyList l1;
	initList(&l1);
	
	if (!insertList(0, 3, &l1)) printf("error happen\n");
	if (!insertList(1, 5, &l1))printf("error happen\n");
	if (!insertList(2, 7, &l1))printf("error happen\n");
	if (!insertList(3, 9, &l1))printf("error happen\n");

	forward_traverseList(&l1, &display);  printf("\n");
	backward_traverseList(&l1, &display);  printf("\n");
	printf("size: %d\n", listSize(&l1));

	replaceList(0, -99, &l1);
	replaceList(3, -100, &l1);

	forward_traverseList(&l1, &display);  printf("\n");
	backward_traverseList(&l1, &display);  printf("\n");
	printf("size: %d\n", listSize(&l1));

	int x;
	if (!listEmpty(&l1))deleteList(0, &x, &l1);
	if (!listEmpty(&l1))deleteList(2, &x, &l1);
	forward_traverseList(&l1, &display);  printf("\n");
	backward_traverseList(&l1, &display);  printf("\n");
	printf("size: %d\n", listSize(&l1));

	clearList(&l1);
	listEmpty(&l1) ? printf("list is empty\n") : printf("list is not empty\n");


	return 0;
}