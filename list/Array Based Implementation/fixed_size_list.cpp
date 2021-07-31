#include<iostream>
using namespace std;

#define MaxList 100
template<class T>
class List {
private:
	T entry[MaxList];
	int size;	
public:
	List() {
		size = 0;
	}
	bool listEmpty() {
		return !size;
	}
	bool listFull() {
		return size == MaxList;
	}
	int listSize() {
		return size;
	}

	void clearList() {
		size = 0;
	}
	int insertList(int pos,T e){
		for (int i = size; i > pos; i--) {
			entry[i] = entry[i - 1];
	}
		entry[pos] = e;
		size++;
		return 1;
	}

	void deleteList(int pos, T *pe) {
		*pe = entry[pos];
		for (int i = pos; i < size; i++) {
			entry[i] = entry[i + 1];
		}
		size--;
	}

	void retrieveList(int pos,T *pe) {
		*pe = entry[pos];
	}

	void traverseList(void(*pf)(T)) {
		for (int i = 0; i < size; i++) {
			(*pf)(entry[i]);
		}
	}

	void replaceList(int pos, T e) {
		entry[pos] = e;
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