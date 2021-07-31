/*
Here i used templates and vectors to make size and data type of stack elements (NOT FIXED)

**i don't give user mechanism to change stack size,it increase auto if it need

*/


#include <iostream>
#include<vector>
using namespace std;

template <typename T>        //typename or class keywords for templates
class Stack {
private:
	int top;
	vector<T> item;
public:
	Stack() {
		top = 0;
		item.resize(10);
	}

	bool stackEmpty() {
		return !top;
	}

	bool stackFull() {
		return 0;
	}

	void pop(T &pe) {
		
		top--;
		pe = item[top];
	}
	int push(int element) {
		if (top == item.size()) item.resize(item.size()+10);
		item[top] = element;
		top++;
		return 1;
		//i change return type of function from void to int to make same interface between array based and linked based
		//int return type ,,,used to handle errors in linked based
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
	for(int i=0;i<3;i++){
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
	}
	cout << "the size of stack: " << s1.stackSize() << "\n";
	int x = 3;
	if (!s1.stackEmpty())s1.pop(x);
	cout << "x value after changing is: " << x << "\n";
	x = s1.stackTop();
	cout << "x value after changing is: " << x << "\n";
	cout << "the size of stack: " << s1.stackSize() << "\n";
	cout << "stack elements: ";
	s1.TraverseStack(&display);
	cout << "\n";


	return 0;
}