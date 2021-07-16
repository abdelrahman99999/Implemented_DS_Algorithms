#include <iostream>
using namespace std;

const int Max_size = 100;

template <typename T>        //typename or class keywords for templates
class Stack {
private:
	int top;
	T item[Max_size];
public:
	Stack() {
		top = 0;
	}

	bool stackEmpty() {
		return !top;
	}

	bool stackFull() {
		return top == Max_size;
	}

	void pop(T *pe) {
		top--;
		*pe = item[top];
	}
	void push(int element) {
		item[top] = element;
		top++;
	}
	
	void TraverseStack ( void (*pf)(T) ) {
		for (int i = top; i > 0; i--) {
			(*pf)(item[i - 1]);
		}
	}

	int stackSize() {
			return top;
	}

	T stackTop() {
		return item[top-1];
	}

};
template <typename T>
void display(T e) {
	cout << e << " ";
}

int main(){
	//test
	Stack<int>s1;
	cout << "the size of stack: " << s1.stackSize() << "\n";
	s1.push(5);
	s1.push(10);
	s1.push(15);
	s1.push(20);
	s1.push(25);
	cout << "the size of stack: " << s1.stackSize() << "\n";
	int x = 3;
	s1.pop(&x);
	cout << "x value after changing is: " << x << "\n";
	x=s1.stackTop();
	cout << "x value after changing is: " << x << "\n";
	cout << "the size of stack: " << s1.stackSize() << "\n";
	cout << "stack elements: ";
	s1.TraverseStack(&display);
	cout << "\n";

	return 0;
}