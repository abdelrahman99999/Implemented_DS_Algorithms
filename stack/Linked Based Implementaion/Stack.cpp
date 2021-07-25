#include<iostream>
using namespace std;

template<class T>
struct stacknode {
	T entry;
	stacknode<T> *next;
};

template<class T>
class Stack {
private:
	int size;
	stacknode<T> *top;
public:
	Stack() {
		top = NULL;
		size = 0;
	}
	bool stackEmpty() {
		return top == NULL;
	}

	bool stackFull() {
		return 0;
	}

	int push(int element) {
		//stacknode<T> *pn = (stacknode<T>*)malloc(sizeof(stacknode<T>));
		stacknode<T> *pn = new stacknode<T>;
		if (!pn)return 0;
		else {
			pn->entry = element;
			pn->next = top;
			top = pn;
			size++;
			return 1;
		}
		//using if else to handle error may happen whaen using new or malloc
	}
	void pop(T *pe) {
		*pe = top->entry;
		stacknode<T> *pn = top;
		top = top->next;
		free(pn);
		size--;
	}

	void TraverseStack(void(*pf)(T)) {

		for (stacknode<T> *pn = top; pn; pn = pn->next)(*pf)(pn->entry);
	}

	int stackSize() {
		return size;
	}

	T stackTop() {
		return top->entry;
	}
};

template <typename T>
void display(T e) {
	cout << e << " ";
}

int main() {

	//test
	Stack<int>s1;
	cout << "the size of stack: " << s1.stackSize() << "\n";
	if (!s1.stackFull())
		if(!s1.push(5))cout<<"errr happen\n";       
	if (!s1.stackFull())
		if (!s1.push(10))cout << "errr happen\n";
	if (!s1.stackFull())
		if (!s1.push(15))cout << "errr happen\n";
	if (!s1.stackFull())
		if (!s1.push(20))cout << "errr happen\n";
	if (!s1.stackFull())
		if (!s1.push(25))cout << "errr happen\n";
	cout << "the size of stack: " << s1.stackSize() << "\n";
	int x = 3;
	if (!s1.stackEmpty())s1.pop(&x);
	cout << "x value after changing is: " << x << "\n";
	x = s1.stackTop();
	cout << "x value after changing is: " << x << "\n";
	cout << "the size of stack: " << s1.stackSize() << "\n";
	cout << "stack elements: ";
	s1.TraverseStack(&display);
	cout << "\n";

	return 0;
}
