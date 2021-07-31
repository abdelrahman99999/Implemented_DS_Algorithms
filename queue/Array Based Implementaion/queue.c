#include<stdio.h>
typedef enum { false, true }boolean;

//you need to set queue size and it's elements type
#define QueueEntry int
#define MaxQueue 100
typedef struct queue {
	int front;
	int rear;
	int size;
	QueueEntry entry[MaxQueue];
}Queue;

void initQueue(Queue *pq) {
	pq->front = 0;
	pq->rear = -1; //so when add element we increase rear so when there is one element rear=front
	pq->size = 0;
}

int append(QueueEntry e, Queue *pq) {
	/*
	if(pq->rear==(MaxQueue-1))pq->rear=0;
	else pq->rear++;
	*/
	//or using this ,will do the same
	pq->rear = (pq->rear + 1) % MaxQueue;
	pq->entry[pq->rear] = e;
	pq->size++;
	return 1;
	//i change return type of function from void to int to make same interface between array based and linked based
	//int return type ,,,used to handle errors in linked based
}

boolean queueFull(Queue *pq) {
	return pq->size == MaxQueue;
}

void serve(QueueEntry *pe, Queue *pq) {
	//get first element and remove it (user think)
	*pe = pq->entry[pq->front];
	pq->front = (pq->front + 1) % MaxQueue;
	/*
	if(pq->front== MaxQueue-1)pq->front=0;
	else pq->front++;
	*/
	pq->size--;
}
void queuefirst(QueueEntry *pe, Queue *pq) {
	//to get first element without remove it (user think)
	*pe = pq->entry[pq->front];
}

boolean queueEmpty(Queue *pq) {
	return !pq->size;
}

int queueSize(Queue *pq) {
	return pq->size;
}

void clearQueue(Queue *pq) {
	//same as stack,the implementation here is like implementaion of initQueue but the user doesn't know this
	//as we know in linked based stack ,implementaion of clear not like as implementaion of init,so we will here make 2 functions
	// to make interface of array based like interface of linked based
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}

//to access every element and make a function to deal with it,this function can change queue values as i pass ( &pq->entry[pos] )
void traverseQueue(Queue *pq, void(*pf)(QueueEntry *e)) {
	int pos = pq->front;
	for (int s = 0; s < pq->size; s++) {
		(*pf)(&pq->entry[pos]);
		pos = (pos + 1) % MaxQueue;
	}
}
//to access every element and make a function to deal with it,this function can not change queue values as i pass ( pq->entry[pos] )
void traverseQueue2(Queue *pq, void(*pf)(QueueEntry e)) {
	int pos = pq->front;
	for (int s = 0; s < pq->size; s++) {
		(*pf)(pq->entry[pos]);
		pos = (pos + 1) % MaxQueue;
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
	queuefirst(&x, &q1);
	printf("x value after changing: %d\n", x);
	traverseQueue(&q1, &add2);
	traverseQueue2(&q1, &display);
	printf("\n");
	return 0;
}