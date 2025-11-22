#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node* next;
	Node() {
		data = 0;
		next = 0;
	}
	Node(T val) {
		data = val;
		next = 0;
	}
};

template<typename T>
class List {
private:
	Node<T>* head;
public:
	List()
	{
		head = 0;
	}
	void insert(T val) {
		Node<T>* newNode = new Node<T>(val);

		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		Node<T>* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = newNode;
	}
	bool search(T val)
	{
		if (head == nullptr)
		{
			return false;
		}

		Node<T>* temp = head;
		while (temp != nullptr) {
			if (temp->data == val)
				return true;
			temp = temp->next;
		}

		return false;
	}
	void display() {
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
	}
};


class HashTable {
private:
	List<int>* table;
	int size;
public:
	HashTable(int s) {
		size = s;
		table = new List<int>[size];
	}
	int hashFunction(int key) {
		return key % size;
	}
	void insert(int key) {
		int index = hashFunction(key);
		table[index].insert(key);
	}
	bool search(int key)
	{
		int index = hashFunction(key);
		return table[index].search(key);
	}
	void display() {
		for (int i = 0; i < size; i++)
		{
			cout << i << ": ";
			table[i].display();
			cout << "NULL\n";
		}
	}
};
int main1() {
		int arr[] = { 23, 31, 45, 12, 31, 18, 23, 31, 45 };
		int n = 9;

		const int SIZE = 20;
		int keys[SIZE];
		int count[SIZE];
		bool used[SIZE];

		// initialize
		for (int i = 0; i < SIZE; i++) {
			used[i] = false;
			count[i] = 0;
		}

		// insert elements
		for (int i = 0; i < n; i++) {
			int key = arr[i];
			int index = key % SIZE;

			while (used[index] && keys[index] != key) {
				index = (index + 1) % SIZE;
			}

			if (!used[index]) {
				keys[index] = key;
				used[index] = true;
				count[index] = 1;
			}
			else {
				count[index]++;
			}
		}

		// display result
		for (int i = 0; i < SIZE; i++) {
			if (used[i]) {
				cout << keys[i] << "-" << count[i] << endl;
			}
		}

		return 0;
	}


int main() {
	HashTable ht(7);
	ht.insert(15);
	ht.insert(11);
	ht.insert(27);
	ht.insert(8);
	ht.insert(12);
	ht.display();
	return 0;
}