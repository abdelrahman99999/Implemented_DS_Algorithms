/*
Design enhancement:
keep tracking the last element visited and save its position,
if i will visit another element following it ,i will be benifit from position of last visited element
--> so i improved complexity

-*- of course, this will not help if the new element is preceding the last element visited
*/

#include<iostream>
using namespace std;

template<class T>
struct listNode {
	T entry;
	listNode *next;
};

template<class T>
class List {
private:
	listNode<T> *head;
	int size;
	//Design enhancement
	listNode<T> *current;
	int currentpos;
public:
	List() {
		size = 0;
		head = NULL;
	}
	bool listEmpty() {
		return !size;
	}
	bool listFull() {
		return 0;
	}
	int listSize() {
		return size;
	}

	void clearList() {
		listNode<T> *pn = head;
		while (head) {
			pn = pn->next;
			free(head);
			head = pn;
		}
		size = 0;
	}
	int insertList(int pos, T e) {
		listNode<T> *pn;
		//if (pn = (listNode<T>*)malloc(sizeof(listNode<T>));
		if (pn = new listNode<T>) {
			pn->entry = e;
			pn->next = NULL;
			//position =0 is special case as there is not node before it  
			if (pos == 0) {
				pn->next = head;
				head = pn;
				//Design enhancement
				currentpos = 0;
				current = head;
			}
			else {
				if (pos <= currentpos) {
					currentpos = 0;
					current = head;
				}

				for (; currentpos != (pos - 1); currentpos++) {
					current = current->next;
				}

				pn->next = current->next;
				current->next = pn;
			}
			size++;
			return 1;
		}
		else {
			return 0;
		}
	}

	void deleteList(int pos, T *pe) {
		listNode<T> *temp;
		//position =0 is special case as there is not node before it  
		if (pos == 0) {
			//destroy first node
			*pe = head->entry;
			current = head->next; //current points to second node
			free(head);        //destroy first node
			head = current;       //make head points to second node (now it is the first node) 
			currentpos = 0;
		}
		else {
			if (pos <= currentpos) {
				currentpos = 0;
				current = head;
			}

			for (; currentpos != (pos - 1); currentpos++) {
				current = current->next;
			}
			*pe = current->next->entry;
			temp = current->next->next;    //at (pos+1)
			free(current->next);
			current->next = temp;
		}
		size--;
	}

	void retrieveList(int pos, T *pe) {
		if (pos == 0) {
			*pe = head->entry;
			current = head;
			currentpos = 0;
		}
		else {

			if (pos <= currentpos) {
				current = head;
				currentpos = 0;
			}
			for (; currentpos != pos; currentpos++) {
				current = current->next;
			}
			*pe = current->entry;
		}
	}

	void traverseList(void(*pf)(T)) {
		listNode<T> *pn = head;
		while (pn) {
			(*pf)(pn->entry);
			pn = pn->next;
		}
	}

	void replaceList(int pos, T e) {
		if (pos == 0) {
			head->entry = e;
			current = head;
			currentpos = 0;
		}
		else {

			if (pos <= currentpos) {
				current = head;
				currentpos = 0;
			}
			for (; currentpos != pos;currentpos++) {
				current = current->next;
			}
			current->entry = e;
		}
	}

};

void display(int x) {
	cout << x << " ";
}
int main() {
	//test
	List<int>l1;

	if (!l1.listFull())
		if (!l1.insertList(0, 3))cout << "error happen\n";
	if (!l1.listFull())
		if (!l1.insertList(1, 5))cout << "error happen\n";
	if (!l1.listFull())
		if (!l1.insertList(2, 7))cout << "error happen\n";
	if (!l1.listFull())
		if (!l1.insertList(3, 9))cout << "error happen\n";

	l1.traverseList(&display);
	cout << "\n";

	if (!l1.listFull())
		if (!l1.insertList(1, 0))cout << "error happen\n";
	l1.traverseList(&display);
	cout << "\n";

	int x;
	if (!l1.listEmpty())
		l1.deleteList(2, &x);
	cout << "x after chaanging " << x << "\n";
	l1.traverseList(&display);
	cout << "\n";

	l1.replaceList(0, -8);
	l1.traverseList(&display);
	cout << "\n";

	return 0;
}