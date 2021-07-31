/*
Here i used templates and vectors to make size and data type of stack elements (NOT FIXED)

** i still using circular implementaion array
	but i give user a mechanism to change queue size during declaration and after declaration
*/

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Queue {
private:
	int front;
	int rear;
	int size; //used to count number of elements in queue, it's not the total size of Queue
	vector<T> entry;
public:
	Queue(int x) {
		front = 0;
		rear = -1; //so when add element we increase rear so when there is one element rear=front
		size = 0;
		entry.resize(x);
	}

	void changeSize(int n) {
		entry.resize(n);
	}

	int append(T e) {
		int s = entry.size();
		/*
		if(rear==(s-1))rear=0;
		else rear++;
		*/
		//or using this ,will do the same
		rear = (rear + 1) % s;
		entry[rear] = e;
		size++;
		return 1;
		//i change return type of function from void to int to make same interface between array based and linked based
		//int return type ,,,used to handle errors in linked based
	}

	bool queueFull() {
		return size == entry.size();
	}


	void serve(T &pe) {
		//get first element and remove it (user think)
		pe = entry[front];
		front = (front + 1) % entry.size();
		/*
		if(front== (entry.size()-1))front=0;
		else front++;
		*/
		size--;
	}
	void queuefirst(T *pe) {
		//to get first element without remove it (user think)
		*pe = entry[front];
	}


	bool queueEmpty() {
		return !size;
	}

	//return no of elements in queue
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
		int totalSize = entry.size();
		for (int s = 0; s < size; s++) {
			(*pf)(&entry[pos]);
			pos = (pos + 1) % totalSize;
		}
	}
	//to access every element and make a function to deal with it,this function can not change queue values as i pass ( entry[pos] )
	void traverseQueue2(void(*pf)(T e)) {
		int pos = front;
		int totalSize = entry.size();
		for (int s = 0; s < size; s++) {
			(*pf)(entry[pos]);
			pos = (pos + 1) % totalSize;
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
	Queue<float>q1(5); //initialize with size =5
	cout << "is queue empty? " << q1.queueEmpty() << "\n";
	cout << "the no of elements in Queue:  " << q1.queueSize() << "\n";
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

	q1.traverseQueue2(&display<float>);
	printf("\n");

	cout << "is queue empty? " << q1.queueEmpty() << "\n";
	cout << "is queue full? " << q1.queueFull() << "\n";
	cout << "the no of elements in Queue: " << q1.queueSize() << "\n";

	q1.changeSize(10);
	cout << "is queue full? " << q1.queueFull() << "\n";
	cout << "the no of elements in Queue: " << q1.queueSize() << "\n";  //

	q1.traverseQueue2(&display<float>);
	printf("\n");

	float x = 3;
	if (!q1.queueEmpty()) q1.serve(x);   //take value of first element and pop
	cout << "x value after changing: " << x << "\n";

	for (int i = 0; i < 50; i++) {
		if (!q1.queueFull())
			if (!q1.append(0))cout << "error happen\n";
	}
	q1.traverseQueue2(&display<float>);
	printf("\n");

	cout << "the no of elements in Queue:  " << q1.queueSize() << "\n";
	cout << "is queue full? " << q1.queueFull() << "\n";

	q1.queuefirst(&x);
	cout << "x value after changing: " << x << "\n";
	q1.traverseQueue(&add2<float>);

	q1.traverseQueue2(&display<float>);
	printf("\n");
	return 0;
}