#include<iostream>
using namespace std;

template<class T>
struct queueNode {
	T entry ;
	struct queueNode<T> *next ;
};

template<class T>
class Queue {
private:
	queueNode<T> *front;
	queueNode<T> *rear;
	int size;
public:
	Queue() {
		front = NULL;
		rear = NULL; 
		size = 0;
	}

	int append(T e) {
		queueNode<T> *pn = (queueNode<T>*)malloc(sizeof(queueNode<T>));
		//or we can use new keyword
		if (!pn)return 0;
		else {
			pn->entry = e;
			pn->next = NULL;
			//special case (in appending first element(node))
			if (!front) { //empty
				front = pn;
			}
			else {
				rear->next = pn; //to connect last node to recenty added node
			}
			rear = pn; //to make rear pointer to the last node
			size++;
			return 1;
		}
		//int return type ,,,used to handle errors in linked based
		//if else used to handle errorr may happen from malloc
	}

	bool queueFull() {
		return 0;
	}


	void serve(T *pe) {
		queueNode<T>  *pn = front;
		*pe = pn->entry;
		front = pn->next;
		free(pn);
		//special case(when serve last element(node))
		if (!front) rear = NULL;
		size--;
	}

	void queuefirst(T *pe) {
		//to get first element without remove it (user think)
		*pe = front->entry;
	}


	bool queueEmpty() {
		return !size;
	}

	int queueSize() {
		return size;
	}

	void clearQueue() {
		while (front) {
			rear = front->next;
			free(front);
			front = rear;
		}
		size = 0;
	}

	//to access every element and make a function to deal with it,this function can change queue values 
	void traverseQueue(void(*pf)(T *e)) {
		for (queueNode<T> *pn = front; pn; pn = pn->next) {
			(*pf)(&pn->entry);
		}
	}
	//to access every element and make a function to deal with it,this function can not change queue values 
	void traverseQueue2(void(*pf)(T e)) {
		for (queueNode<T> *pn = front; pn; pn = pn->next) {
			(*pf)(pn->entry);
		}
	}


};


template<class T>
void add2(T *e) {
	*e += 2;
}

template<class T>
void display(T e) {
	cout << e << " ";
}

int main() {
	//test
	Queue<float>q1;
	cout << "is queue empty? " << q1.queueEmpty() << "\n";
	cout << "the size of queue: " << q1.queueSize() << "\n";
	if (!q1.queueFull())
		if (!q1.append(5))cout << "error happen\n";
	if (!q1.queueFull())
		if (!q1.append(10))cout << "error happen\n";
	if (!q1.queueFull())
		if (!q1.append(15))cout << "error happen\n";
	if (!q1.queueFull())
		if (!q1.append(20))cout << "error happen\n";
	if (!q1.queueFull())
		if (!q1.append(25))cout << "error happen\n";
	cout << "is queue empty? " << q1.queueEmpty() << "\n";
	cout << "the size of stack: " << q1.queueSize() << "\n";
	q1.traverseQueue2(&display<float>);
	printf("\n");
	float x = 3;
	if (!q1.queueEmpty())q1.serve(&x);
	cout << "x value after changing: " << x << "\n";
	cout << "the size of queue: " << q1.queueSize() << "\n";
	q1.queuefirst(&x);
	cout << "x value after changing: " << x << "\n";
	q1.traverseQueue(&add2<float>);
	q1.traverseQueue2(&display<float>);
	printf("\n");
	return 0;
}