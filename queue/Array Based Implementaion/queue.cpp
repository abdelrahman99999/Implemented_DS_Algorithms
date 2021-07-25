#include<iostream>
using namespace std;
#define MaxQueue 100

template<class T>
class Queue {
private:
	int front;
	int rear;
	int size;
	T entry[MaxQueue];
public:
	Queue() {
		front = 0;
		rear = -1; //so when add element we increase rear so when there is one element rear=front
		size = 0;
	}

	void append(T e) {
		/*
		if(rear==(MaxQueue-1))rear=0;
		else rear++;
		*/
		//or using this ,will do the same
		rear = (rear + 1) % MaxQueue;
		entry[rear] = e;
		size++;
	}

	bool queueFull() {
		return size == MaxQueue;
	}


	void serve(T *pe) {
		//get first element and remove it (user think)
		*pe = entry[front];
		front = (front + 1) % MaxQueue;
		/*
		if(front== MaxQueue-1)front=0;
		else front++;
		*/
		size--;
	}
	void queuefirst(T *pe) {
		//to get first element without remove it (user think)
		*pe =entry[front];
	}


	bool queueEmpty() {
		return !size;
	}

	int queueSize() {
		return size;
	}

	void clearQueue() {
		//same as stack,the implementation here is like implementaion of initQueue(constructor) but the user doesn't know this
		//as we know in linked based stack ,implementaion of clear not like as implementaion of init(constructor),so we will here make 2 functions
		// to make interface of array based like interface of linked based
		front = 0;
		rear = -1;
		size = 0;
	}

	//to access every element and make a function to deal with it,this function can change queue values as i pass ( &entry[pos] )
	void traverseQueue(void(*pf)(T *e)) {
		int pos = front;
		for (int s = 0; s < size; s++) {
			(*pf)(&entry[pos]);
			pos = (pos + 1) % MaxQueue;
		}
	}
	//to access every element and make a function to deal with it,this function can not change queue values as i pass (entry[pos] )
	void traverseQueue2(void(*pf)(T e)) {
		int pos = front;
		for (int s = 0; s < size; s++) {
			(*pf)(entry[pos]);
			pos = (pos + 1) % MaxQueue;
		}
	}


};


template<class T>
void add2(T *e) {
	*e += 2;
}

template<class T>
void display(T e) {
	cout<<e<<" ";
}

int main() {
	//test
	Queue<float>q1;
	cout<<"is queue empty? "<< q1.queueEmpty()<<"\n";
	cout<<"the size of queue: "<< q1.queueSize()<<"\n";
	if (!q1.queueFull())q1.append(5);
	if (!q1.queueFull())q1.append(10);
	if (!q1.queueFull())q1.append(15);
	if (!q1.queueFull())q1.append(20);
	if (!q1.queueFull())q1.append(25);
	cout<<"is queue empty? "<< q1.queueEmpty()<<"\n";
	cout<<"the size of stack: "<< q1.queueSize()<<"\n";
	q1.traverseQueue2(&display<float>);
	printf("\n");
	float x = 3;
	if (!q1.queueEmpty())q1.serve(&x);
	cout<<"x value after changing: "<< x<<"\n";
	cout<<"the size of queue: "<< q1.queueSize()<<"\n";
	q1.queuefirst(&x);
	cout<<"x value after changing: "<< x<<"\n";
	q1.traverseQueue(&add2<float>);
	q1.traverseQueue2(&display<float>);
	printf("\n");
	return 0;
}
