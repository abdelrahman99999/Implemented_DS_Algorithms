#include<iostream>
using namespace std;
template<class T>
struct listNode{
	T entry;
	listNode *next;
};

template<class T>
class List {
private:
	listNode<T> *head;
	int size;	
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
	int insertList(int pos,T e){
		listNode<T> *pn;
		listNode<T> *temp=head;
		//if (pn = (listNode<T>*)malloc(sizeof(listNode<T>));
		if (pn = new listNode<T>) {
			pn->entry = e;
			if (pos == 0) {
				pn->next = head;
				head = pn;
			}
			else {
				for (int i = 0; i < pos - 1; i++) {
					temp = temp->next;
				}
				pn->next = temp->next;
				temp->next = pn;
			}
			size++;
			return 1;
		}
		else {
			return 0;
		}
	}

	void deleteList(int pos, T *pe) {
		listNode<T> *pn, *temp;
		if (pos == 0) {
			*pe = head->entry;
			temp = head->next; 
			free(head);        
			head = temp;       
		}
		else {
			pn = head;
			for (int i = 0; i < pos - 1; i++) {
				pn = pn->next;    
			}
			*pe = pn->next->entry;
			temp = pn->next->next;    
			free(pn->next);
			pn->next = temp;
		}
		size--;
	}

	void retrieveList(int pos,T *pe) {
		listNode<T> *pn=head;
		for (int i = 0; i < pos; i++) {
			pn = pn->next;
		}
		*pe = pn->entry;
	}

	void traverseList(void(*pf)(T)) {
		listNode<T> *pn = head;
		while(pn) {
			(*pf)(pn->entry);
			pn = pn->next;
		}
	}

	void replaceList(int pos, T e) {
		listNode<T> *pn = head;
		for (int i = 0; i < pos; i++) {
			pn = pn->next;
		}
		pn->entry=e;
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
	l1.traverseList( &display);
	cout << "\n";
	int x;
	if (!l1.listEmpty())
		l1.deleteList(2, &x);
	cout<<"x after chaanging "<< x <<"\n"; 
	l1.traverseList( &display);
	cout<<"\n";

	return 0;
}