#include<stdio.h>
#include<stdlib.h>
typedef enum bool{ false,true }boolean;

//you should set your data type of list elements
#define ListEntry int

typedef struct listnode {
	ListEntry entry;
	struct listnode *next;
}ListNode;

typedef struct list {
	ListNode *head;
	int size;
}List;

void initList(List *pl) {
	pl->size = 0;
	pl->head = NULL;
}

boolean listFull(List *pl) {
	return 0;
}

boolean listEmpty(List *pl) {
	return !pl->size;      //return !pl->head
}

int insertList(int pos, ListEntry e, List *pl) {
	//this algorithm depend on reaching node before desired position
	/*preconditions:user level take care about it before using function
	1-list is initialized
	2-    0 <= pos <= size
	3- list is not full
	*/
	ListNode *pn;
	if (pn = (ListNode*)malloc(sizeof(ListNode))) {
		pn->entry = e;
		pn->next = NULL;
		//position =0 is special case as there is not node before it  
		if (pos == 0) {
			pn->next = pl->head;     
			pl->head = pn;							
		}
		else {
			ListNode *pn2=pl->head;
			for (int i = 0; i < pos - 1; i++) {
				pn2 = pn2->next;  //after exit for loop the pn2 points to node before desired position (pos-1)
			}
			pn->next = pn2->next;
			pn2->next = pn;
		}
		pl->size++;
		return 1;
	}
	else {
		return 0;
	}
}
//to delete element in specific position and retrieve its value too
void deleteList(int pos, ListEntry *pe, List *pl) {
	//this algorithm depend on reaching node before desired position

	/*preconditions:user level take care about it before using function
	1-list is initialized
	2-  0 <= pos <= size-1
	3- list is not empty
	*/

	ListNode *pn,*temp ;
	//position =0 is special case as there is not node before it  
	if (pos == 0) {
		//destroy first node
		*pe = pl->head->entry;
		temp = pl->head->next; //temp points to second node
		free(pl->head);        //destroy first node
		pl->head = temp;       //make pl->head points to second node (now it is the first node) 
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
	}
	pl->size--;
}

int listSize(List *pl) {
	return pl->size;
}

void clearList(List *pl) {
	ListNode *pn = pl->head;
	while (pl->head) {
		pn = pn->next;
		free(pl->head);
		pl->head = pn;
	}
	pl->size = 0;
}

void traverseList(List *pl, void(*pf)(ListEntry e)) {
	for (ListNode *pn = pl->head; pn ; pn=pn->next) {
		(*pf)(pn->entry);
	}
}

//to retrieve value of element in specific position (without deleting it)
void retrieveList(int pos, ListEntry *pe, List *pl) {
	ListNode *pn=pl->head;
	for (int i = 0; i < pos; i++) {
		pn = pn->next;
	}
	*pe = pn->entry;
}

//to replace value of element in specific position with another  element value passed as argument
void replaceList(int pos, ListEntry e, List *pl) {
	ListNode *pn = pl->head;
	for (int i = 0; i < pos; i++) {
		pn = pn->next;
	}
	pn->entry=e;
}



void display(ListEntry e) {
	printf("%d ", e);
}

int main() {
	//test
	List l1;
	initList(&l1);
	if (!listFull(&l1))
		if(!insertList(0, 3, &l1)) printf("error happen\n");
	if (!listFull(&l1))
		if(!insertList(1, 5, &l1))printf("error happen\n");
	if (!listFull(&l1))
		if(!insertList(2, 7, &l1))printf("error happen\n");
	if (!listFull(&l1))
		if(!insertList(3, 9, &l1))printf("error happen\n");

	traverseList(&l1, &display);
	printf("\n");
	if (!listFull(&l1))
		if(!insertList(1, 0, &l1))printf("error happen\n");
	traverseList(&l1, &display);
	printf("\n");
	int x;
	if (!listEmpty(&l1))
		deleteList(2, &x, &l1);
	printf("x after chaanging %d\n", x);
	traverseList(&l1, &display);
	printf("\n");
	return 0;
}