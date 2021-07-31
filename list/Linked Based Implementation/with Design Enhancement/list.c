/*
	Design enhancement:
		keep tracking the last element visited and save its position,
		if i will visit another element following it ,i will be benifit from position of last visited element
		--> so i improved complexity

		-*- of course, this will not help if the new element is preceding the last element visited
*/

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

	//Design enhancement
	ListNode *current;    
	int currentpos;
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
			//Design enhancement
			pl->currentpos = 0;
			pl->current = pl->head;
		}
		else {
			if (pos <= pl->currentpos) {
				pl->currentpos = 0;
				pl->current = pl->head;
			}
			
			for (; pl->currentpos != (pos-1); pl->currentpos++) {
				pl->current = pl->current->next; 
			}

			pn->next = pl->current->next;
			pl->current->next = pn;
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

	ListNode *temp;
	//position =0 is special case as there is not node before it  
	if (pos == 0) {
		//destroy first node
		*pe = pl->head->entry;
		pl->current = pl->head->next; //current points to second node
		free(pl->head);        //destroy first node
		pl->head = pl->current;       //make pl->head points to second node (now it is the first node) 
		pl->currentpos = 0;
	}
	else {
		if (pos <= pl->currentpos) {
			pl->currentpos = 0;
			pl->current = pl->head;
		}
		
		for (; pl->currentpos!= (pos-1); pl->currentpos++) {
			pl->current = pl->current->next;    
		}
		*pe = pl->current->next->entry;
		temp = pl->current->next->next;    //at (pos+1)
		free(pl->current->next);
		pl->current->next = temp;
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
	for (ListNode *pn = pl->head; pn; pn = pn->next) {
		(*pf)(pn->entry);
	}
}

//to retrieve value of element in specific position (without deleting it)
void retrieveList(int pos, ListEntry *pe, List *pl) {
	if (pos == 0) {
		*pe = pl->head->entry;
		pl->current = pl->head;
		pl->currentpos = 0;
	}
	else{

		if (pos <= pl->currentpos) {
			pl->current = pl->head;
			pl->currentpos = 0;
		}
		for (; pl->currentpos != pos; pl->currentpos++) {
				pl->current = pl->current->next;
		}
		*pe = pl->current->entry;
	}
}

//to replace value of element in specific position with another  element value passed as argument
void replaceList(int pos, ListEntry e, List *pl) {
	if (pos == 0) {
		 pl->head->entry = e;
		pl->current = pl->head;
		pl->currentpos = 0;
	}
	else {

		if (pos <= pl->currentpos) {
			pl->current = pl->head;
			pl->currentpos = 0;
		}
		for (; pl->currentpos != pos; pl->currentpos++) {
			pl->current = pl->current->next;
		}
		pl->current->entry = e;
	}
	
}



void display(ListEntry e) {
	printf("%d ", e);
}

int main() {
	//test
	List l1;
	initList(&l1);
	if (!listFull(&l1))
		if (!insertList(0, 3, &l1)) printf("error happen\n");
	if (!listFull(&l1))
		if (!insertList(1, 5, &l1))printf("error happen\n");
	if (!listFull(&l1))
		if (!insertList(2, 7, &l1))printf("error happen\n");
	if (!listFull(&l1))
		if (!insertList(3, 9, &l1))printf("error happen\n");

	traverseList(&l1, &display);
	printf("\n");

	if (!listFull(&l1))
		if (!insertList(1, -3, &l1))printf("error happen\n");
	traverseList(&l1, &display);
	printf("\n");

	int x;
	if (!listEmpty(&l1))
		deleteList(2, &x, &l1);
	printf("x after chaanging %d\n", x);
	traverseList(&l1, &display);
	printf("\n");

	replaceList(2, 77, &l1);
	replaceList(1, -66, &l1);
	traverseList(&l1, &display);
	printf("\n");

	return 0;
}