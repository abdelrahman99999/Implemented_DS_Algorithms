#include<stdio.h>
#include<stdlib.h>
typedef enum { false, true }boolean;

//you need to set queue elements type
#define QueueEntry int
typedef struct queuenode{
	QueueEntry entry;
	struct queuenode *next;
}queueNode;

typedef struct queue{
	queueNode *front;
	queueNode *rear;
	int size;
}Queue;

void initQueue(Queue *pq) {
	pq->front = NULL;
	pq->rear = NULL; //as no nodes (empty queue),front and rear pointer to NULL
	pq->size = 0;
}

int append(QueueEntry e, Queue *pq) {
	queueNode *pn = (queueNode*)malloc(sizeof(queueNode));
	if (!pn)return 0;
	else {
		pn->entry = e;
		pn->next = NULL;
		//special case (in appending first element(node))
		if (!pq->front) { //empty
			pq->front = pn;
		}
		else {
			pq->rear->next = pn; //to connect last node to recenty added node
		}
		pq->rear = pn; //to make rear pointer to the last node
		pq->size++;
		return 1;
	}
	//int return type ,,,used to handle errors in linked based
	//if else used to handle errorr may happen from malloc
}

boolean queueFull(Queue *pq) {
	return 0;
	//as we used linked based implementation, no need to take care about size,when append we add and take from memory
	//if we don't append we save memory 
}

//serve used to take first element and delete it
void serve(QueueEntry *pe, Queue *pq) {
	queueNode *pn = pq->front;
	*pe = pn->entry;
	pq->front = pn->next;
	free(pn);
	//special case(when serve last element(node))
	if (!pq->front) pq->rear = NULL;
	pq->size--;
}

boolean queueEmpty(Queue *pq) {
	return !pq->size;
}

int queueSize(Queue *pq) {
	return pq->size;
}

void queueFirst(QueueEntry *pe, Queue *pq) {
	//to get first element without remove it (user think)
	*pe = pq->front->entry;
}

void clearQueue(Queue *pq) {
	while(pq->front){
		pq->rear=pq->front->next;
		free(pq->front);
		pq->front=pq->rear;
	}
	pq->size = 0;
		
}

//to access every element and make a function to deal with it,this function can change queue values as i pass ( &pq->entry[pos] )
void traverseQueue(Queue *pq, void(*pf)(QueueEntry *e)) {
	for (queueNode *pn = pq->front; pn; pn = pn->next) {
		(*pf)(&pn->entry);
	}	
}
//to access every element and make a function to deal with it,this function can not change queue values as i pass ( pq->entry[pos] )
void traverseQueue2(Queue *pq, void(*pf)(QueueEntry e)) {
	for (queueNode *pn = pq->front; pn; pn = pn->next) {
		(*pf)(pn->entry);
	}
}

void add2(QueueEntry *e) {
	*e += 2;
}

void display(QueueEntry e) {
	printf("%d ", e);
}

int main() {
	//test
	//same interface as array based implementation
	Queue q1;
	initQueue(&q1);
	printf("is queue empty? %d\n", queueEmpty(&q1));
	printf("the size of queue: %d\n", queueSize(&q1));
	if (!queueFull(&q1))
		if(!append(5, &q1))printf("error happen\n");
	if (!queueFull(&q1))
		if (!append(10, &q1))printf("error happen\n");
	if (!queueFull(&q1))
		if (!append(15, &q1))printf("error happen\n");
	if (!queueFull(&q1))
		if (!append(20, &q1))printf("error happen\n");
	if (!queueFull(&q1))
		if (!append(25, &q1))printf("error happen\n");
	printf("is queue empty? %d\n", queueEmpty(&q1));
	printf("the size of stack: %d\n", queueSize(&q1));
	traverseQueue2(&q1, &display);
	printf("\n");
	int x = 3;
	if (!queueEmpty(&q1))serve(&x, &q1);
	printf("x value after changing: %d\n", x);
	printf("the size of queue: %d\n", queueSize(&q1));
	queueFirst(&x, &q1);
	printf("x value after changing: %d\n", x);
	traverseQueue(&q1, &add2);
	traverseQueue2(&q1, &display);
	printf("\n");
	return 0;
}
