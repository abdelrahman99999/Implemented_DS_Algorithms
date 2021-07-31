#include<stdio.h>

//you should set data type and size of List elements
#define ListEntry int
#define MaxList 100

typedef enum bool{ false,true }boolean;

typedef struct list {
	ListEntry entry[MaxList];
	int size;
}List;

void initList(List *pl){
	pl->size = 0;
}

boolean listFull(List *pl){
//as we say before,although i will not change in list but i use call by reference to save time& memory of copying(call by value) 
	return pl->size == MaxList;
}
boolean listEmpty(List *pl){
	return !pl->size;          //pl->size==0;
}

int listSize(List *pl) {
	return pl->size;
}

void clearList(List *pl) {
	pl->size = 0;
	/*as we say before, from (User level) the list is cleared ,but in fact(implementaion level) all elements are still 
		inside array but i change size so (depending on overriding elements)i will override old elements
	*/
}
//to insert element in specific position
int insertList(int pos, ListEntry e, List *pl) {
	/*preconditions:user level take care about it before using function
		1-list is initialized
		2-    0 <= pos <= size 
		3- list is not full
	*/
	for (int i = pl->size; i > pos; i--) {
		//complexity here is θ(n) but has probabilities depend on position(probabilistic algorithm)
		pl->entry[i] = pl->entry[i - 1];
	}
	pl->entry[pos] = e;
	pl->size++;
	return 1;
}
 //to delete element in specific position and retrieve its value too
void deleteList(int pos, ListEntry *pe, List *pl) {
	/*preconditions:user level take care about it before using function
		1-list is initialized
		2-  0 <= pos <= size-1
		3- list is not empty
	*/
	*pe = pl->entry[pos];
	for (int i = pos; i < (pl->size - 1); i++) {     //complexity here is θ(n) but has probabilities depend on position
		pl->entry[i] = pl->entry[i + 1];
	}
	pl->size--;
}

//to retrieve value of element in specific position (without deleting it)
void retrieveList(int pos, ListEntry *pe, List *pl) {
	*pe = pl->entry[pos];
}

//to replace value of element in specific position with another  element value passed as argument
void replaceList(int pos, ListEntry e, List *pl) {
	pl->entry[pos] = e;
}

//to traverse(visit) every element in list
void traverseList(List *pl, void (*pf)(ListEntry e) ){
	for (int i = 0; i < pl->size; i++) {
		(*pf)(pl->entry[i]);
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