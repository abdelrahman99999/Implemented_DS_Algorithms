/*
* file : HashTable_chaining.cpp
* description: Implementaion of Hash Table using Chaining for Resolution of Collisions
* Author: Abdelrahman Elsayed
*/

#include<iostream>
using namespace std;

class LinkedHashNode{
private:
	int key;
	int value;
	LinkedHashNode *next;

public:
	LinkedHashNode(int key, int value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}

	int getKey() {
		return key;
	}

	int getValue() {
		return value;
	}

	void setValue(int value) {
		this->value = value;
	}

	LinkedHashNode *getNext() {
		return next;
	}

	void setNext(LinkedHashNode *next) {
		this->next = next;
	}
};

const int TABLE_SIZE = 100;

class HashTable {

private:
	LinkedHashNode **table;    //pointer To pointer

public:
	HashTable() {
		/*
				table -> array of pointers to LinkedHashNode
		*/
		table = new LinkedHashNode*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++){
			table[i] = NULL; //set all pointers in table for NULL for initialization
		}
	}


	/*
		insert key and value
		if the same kay is inserted before, function updates its value by new value (No Dublications)
	*/
	void put(int key, int value) {

		int hash = (key % TABLE_SIZE);     //sample hashing 
		/*
			if there are not collisions insert directly by make specific pointer of table points to Node  
		*/
		if (table[hash] == NULL){
			table[hash] = new LinkedHashNode(key, value);
		}
		/*
			if there are collisions ,start linked list
		*/
		else {
			/* current is pointer to loop on linked list*/
			LinkedHashNode *current = table[hash];
			/*looping until reaching to free position to put your Entry */
			while (current->getNext() != NULL ){
				/*refresh value of the new key is already inserted before*/
				/*No dublications*/
				if (current->getKey() == key) {
					current->setValue(value);
					return;
				}
				current = current->getNext();
			}
			/*as we not check last node for dublication*/
			if (current->getKey() == key) {
				current->setValue(value);
				return;
			}		
			current->setNext(new LinkedHashNode(key, value));
		}
	}

	/*
		return value if the key is found
		if the key is not found, return -1
	*/
	int get(int key) {
		int hash = (key % TABLE_SIZE);    //sample hashing ,surely you should use the same hash function in put() function
		/*the key is not hashing before */
		if (table[hash] == NULL){
			return -1;
		}
		/*value of hashing is inserted before (may key found or not because of collisions)*/
		else {
			/* current is pointer to loop on linked list*/
			LinkedHashNode *current = table[hash];
			
			/*you will exit while if the end of linked list or you find the same key*/
			while (current != NULL && current->getKey() != key){
				current = current->getNext();
			}
			//if you reach the end of linked list without finding the key
			if (current == NULL)
				return -1;
			else    //if you find the same key
				return current->getValue();
		}
	}

	/*
		remove the node(key,value) by passing the key
	*/
	void remove(int key) {

		int hash = (key % TABLE_SIZE); //sample hashing ,surely you should use the same hash function in put() function

		/*if hashing value inseted before*/
		if (table[hash] != NULL) {
			/*
				the same mechanism to remove a node from linkedlist
			*/

			LinkedHashNode *prev = NULL;
			LinkedHashNode *current = table[hash];

			/*
				you will exit the while if you find desired key or reach to the end of linked list
			*/
			while (current->getNext() != NULL && current->getKey() != key) {
				prev = current;
				current = current->getNext();
			}

			/*if you find desired key, stert operation of removing node from linked list*/
			if (current->getKey() == key) {
				//if you find key in the first node
				if (prev == NULL) {
					LinkedHashNode *temp = current->getNext();
					delete current;
					table[hash] = temp;
				}
				//if you find key in any node, not first
				else {
					LinkedHashNode *temp = current->getNext();
					delete current;
					prev->setNext(temp);
				}
			}
			/*
				you will not doing any thing if you reach end of linked list without finding the key
			*/
		}
	}

	~HashTable() {
		//free all nodes
		for (int i = 0; i < TABLE_SIZE; i++){  //looping in every pointer in Table
			if (table[i] != NULL) {
				LinkedHashNode *prev = NULL;
				LinkedHashNode *entry = table[i];
				while (entry != NULL) {  //looping in linked list
					prev = entry;
					entry = entry->getNext();
					delete prev;
				}
			}
		}
		delete[] table;
	}
};

/*testing*/
int main() {
	HashTable h1;
	h1.put(999, 777);
	h1.put(5, 11);   //hasing of 5 as i make will be 5 (5%100)
	h1.put(105, 44); //hasing of 105 as i make will be 5 (105%100)
	cout << h1.get(5) << " " << h1.get(105) << "\n";

	h1.put(105, 88); //update value of key 105
	cout << h1.get(5) << " " << h1.get(105) << "\n";

	h1.remove(105); //remove key 105 ,so when i get it will return -1
	cout << h1.get(5) << " " << h1.get(105) << "\n";

	cout << h1.get(999) << endl;

	h1.put(0, 1099);
	cout << h1.get(0)<<"\n";
	
	return 0;
}
