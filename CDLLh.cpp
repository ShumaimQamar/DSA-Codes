#include<iostream>
#include<string>
using namespace std;
template <class T>
class DNode
{
public:
	T info;
	DNode<T>* next;
	DNode<T>* prev;
	DNode()
	{
		next = 0;
		prev = 0;
	}
	DNode(T val)
	{
		info = val;
		next = 0;
		prev = 0;
	}
};

template <class T>
class CDLinkedList {
private:
	DNode<T>* head;

public:
	CDLinkedList()
	{
		head = 0;
	}
	void insertAtHead(T val)
	{
		DNode<T>* t = new DNode<T>(val);
		if (!head)
		{
			head = t;
			t->next = t;
			t->prev = t;
			return;
		}
		DNode<T>* tail = head->prev;
		t->next = head;
		t->prev = tail;
		head->prev = t;
		tail->next = t;
		head = t;
	}

	void insertAtTail(T val)
	{
		if (!head) {
			DNode<T>* t = new DNode<T>(val);
			head = t;
			t->next = head;
			t->prev = head;
			return;
		}
		DNode<T>* tail = head->prev;
		DNode<T>* t = new DNode<T>(val);
		t->next = head;
		t->prev = tail;
		tail->next = t;
		head->prev = t;
	}
	void insertBefore(T key, T val)
	{
		if (!head) return;
		DNode<T>* temp = head;
		if (head->info == key)
		{
			DNode<T>* t = new DNode<T>(val);
			DNode<T>* tail = temp->prev;
			t->next = temp;
			t->prev = temp->prev;
			head = t;
			tail->next = t;
			temp->prev = t;
			return;
		}
		do
		{
			if (temp->info == key)
			{
				DNode<T>* t = new DNode<T>(val);
				t->next = temp;
				t->prev = temp->prev;
				temp->prev->next = t;
				temp->prev = t;
				return;
			}
			temp = temp->next;
		} while (temp != head);
	}
	void insertAfter(T key, T val);
	void removeAtHead()
	{
		if (!head) return;
		if (head->next == head)
		{
			delete head;
			head = nullptr;
			return;
		}
		DNode<T>* temp = head;
		DNode<T>* tail = head->prev;
		head = head->next;
		tail->next = head;
		head->prev = tail;
		delete temp;
	}

	void removeAtTail()
	{
		if (!head) return;
		if (head->next == head)
		{
			delete head;
			head = nullptr;
			return;
		}
		DNode<T>* temp = head;
		while (temp->next->next != head)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = head;
		head->prev = temp;
	}

	void remove(T val)
	{
		if (!head) return;
		if (head->info == val)
		{
			removeAtHead();
			return;
		}
		DNode<T>* temp = head;
		temp = temp->next;
		while (temp != head)
		{
			if (temp->info == val)
			{

				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				return;
			}
			temp = temp->next;
		}
	}
	void removeBefore(T val)
	{
		if (!head || head->info == val) return;
		DNode<T>* temp = head;
		if (temp->next->info == val)
		{
			DNode<T>* tail = temp->prev;
			head = temp->next;
			head->prev = tail;
			tail->next = head;
			delete temp;
			return;
		}
		temp = temp->next;
		while (temp != head)
		{
			if (temp->info == val) {
				DNode<T>* t = temp->prev;
				t->prev->next = temp;
				temp->prev = t->prev;
				delete t;
				return;
			}
			temp = temp->next;
		}
	}
	void removeAfter(T val)
	{
		if (!head || head->next == head) return;
		DNode<T>* temp = head;
		while (temp->next != head)
		{
			if (temp->info == val && temp->next != head)
			{
				DNode<T>* t = temp->next;
				temp->next = t->next;
				t->next->prev = temp;
				delete t;
				return;
			}
			temp = temp->next;
		}
	}
	bool search(T key)
	{
		if (!head) return 0;
		DNode<T>* temp = head;
		if (temp->info == key)
		{
			return 1;
		}
		temp = temp->next;
		while (temp != head)
		{
			if (temp->info == key)
			{
				return 1;
			}
			temp = temp->next;
		}
		return 0;
	}

	void update(T key, T val)
	{

		if (!head) return;
		DNode<T>* temp = head;
		if (temp->info == key)
		{
			temp->info = val;
			return;
		}
		temp = temp->next;
		while (temp != head)
		{
			if (temp->info == key)
			{
				temp->info = val;
				return;
			}
			temp = temp->next;
		}
	}

	int countNodes()
	{
		if (!head) return 0;
		DNode<T>* temp = head->next;
		int count = 1;
		while (temp != head)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	bool removeKthNode(int k, int& val)
	{
		if (!head) return 0;
		DNode<T>* temp = head;
		if (head->next == head && k ==1)
		{
			val = head->info;
			delete head;
			head = nullptr;
			return 1;
		}
		if (k == 1)
		{
			DNode<T>* t = temp;
			DNode<T>* tail = temp->prev;
			val = temp->info;
			cout << val << endl;
			head = temp->next;
			tail->next = head;
			head->prev = tail;
			delete t;
			return 1;

		}
		temp = temp->next;
		int count = 2;
		while (temp != head)
		{
			if (count == k)
			{
				DNode<T>* t = temp;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				val = temp->info;
				cout << val << endl;
				delete t;
				return 1;
			}
			temp = temp->next;
			count++;
		}
		return 0;
	}
	void splitList(CDLinkedList& leftHalf, CDLinkedList& rightHalf)
	{
	
		int count = this->countNodes();
		int c = (count+1)/ 2;
		DNode<T>* temp = head;
		leftHalf.head = head;
		for(int i=1; i<c; i++)
		{
			temp = temp->next;
		}
		DNode<T>* midNode = temp->next;
		temp->next = leftHalf.head;
		leftHalf.head->prev = temp;

		DNode<T>* temp3 = midNode;
		while (temp3->next != head)
		{
			temp3 = temp3->next;
		}
		temp3->next = midNode;
		midNode->prev = temp3;
		rightHalf.head = midNode;
		
	}
	void combine(CDLinkedList& list1, CDLinkedList& list2)
	{
		if (!list1.head || !list2.head) return;
		if (!list1.head) {
			head = list2.head;
			return;
		}
		if (!list2.head)
		{
			head = list1.head;
			return;
		}
		head = list1.head;
		DNode<T>* tail = head->prev;
		tail->next = list2.head;
		list2.head->prev->next = head;
		head->prev = list2.head->prev;
		
	}
	void merge(CDLinkedList& list1, CDLinkedList& list2)
	{
		if (list1.head == 0 && list2.head == 0) return;
		if (!list1.head) {
			head = list1.head;
			list1.head = nullptr;
			return;
		}
		if (!list2.head)
		{
			head = list2.head;
			list2.head = nullptr;
			return;
		}

		DNode<T>* t = nullptr;
		DNode<T>* temp1 = list1.head;
		DNode<T>* temp2 = list2.head;

		list1.head->prev->next = nullptr;
		list1.head->prev = nullptr;
		list2.head->prev->next = nullptr;
		list2.head->prev = nullptr;

		if (temp1->info < temp2->info)
		{
			head = t = temp1;
			temp1 = temp1->next;
		}
		else {
			head = t = temp2;
			temp2 = temp2->next;
		}

		while (temp1 != 0 && temp2 != 0)
		{
			if (temp1->info <= temp2->info)
			{
				t->next = temp1;
				temp1->prev = t;
				t = temp1;
				temp1 = temp1->next;
			}
			else {
				t->next = temp2;
				temp2->prev = t;
				t = temp2;
				temp2 = temp2->next;
			}
		}

		if (temp1) {
			t->next = temp1;
			temp1->prev = t;
		}
		if (temp2) {
			t->next = temp2;
			temp2->prev = t;
		}

		while (t->next) t = t->next;
		head->prev = t;
		t->next = head;
	}
	void shuffleMerge(CDLinkedList& list1, CDLinkedList& list2)
	{
		if (!list1.head || !list2.head) return;

		list1.head->prev->next = nullptr;
		list2.head->prev->next = nullptr;
		head = list1.head;
		list1.head->prev = nullptr;
		list1.head = list1.head->next;
		DNode<T>* temp3 = head;


		temp3->next = list2.head;
		list2.head->prev = temp3;
		list2.head = list2.head->next;
		temp3 = temp3->next;

		DNode<T>* temp1 = list1.head;
		DNode<T>* temp2 = list2.head;
		while (temp1 || temp2)
		{
			if (temp1)
			{
				temp3->next = temp1;
				temp1->prev = temp3;
				temp3 = temp1;
				temp1 = temp1->next;
			}
			if (temp2)
			{
				temp3->next = temp2;
				temp2->prev = temp3;
				temp3 = temp2;
				temp2 = temp2->next;
			}
		}

		head->prev = temp3;
		temp3->next = head;

		list1.head = list2.head = nullptr;
	}
	void display()
	{
		if (!head) return;
		DNode<T>* temp = head;
		do
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
		while (temp != head);
		cout << endl;
	}
	~CDLinkedList()
	{
		if (!head) return;

		DNode<T>* t = head->next;
		while (t != head)
		{
			DNode<T>* next_Node = t->next;
			delete t;
			t = next_Node;
		}
		delete head;
		head = nullptr;
	}
};

int main1()
{
	CDLinkedList<int> list;

	cout << "Inserting at head: 10, 20, 30\n";
	list.insertAtHead(10);
	list.insertAtHead(20);
	list.insertAtHead(30);

	cout << "Inserting at tail: 40, 50\n";
	list.insertAtTail(40);
	list.insertAtTail(50);

	cout << "Total nodes: " << list.countNodes() << endl;

	cout << "\nSearching for 20: ";
	cout << (list.search(20) ? "Found" : "Not Found") << endl;

	cout << "Searching for 99: ";
	cout << (list.search(99) ? "Found" : "Not Found") << endl;

	cout << "\nUpdating 20 → 200\n";
	list.update(20, 200);

	cout << "Removing 10 (middle node)\n";
	list.remove(10);

	cout << "Removing head (30)\n";
	list.remove(30);

	cout << "Removing tail (50)\n";
	list.remove(50);

	cout << "\nFinal count of nodes: " << list.countNodes() << endl;

	// Verify remaining data by searching for them
	cout << "Searching for 200: " << (list.search(200) ? "Found" : "Not Found") << endl;
	cout << "Searching for 40: " << (list.search(40) ? "Found" : "Not Found") << endl;

	return 0;
}

int main()
{
	CDLinkedList<int> list;
	list.insertAtHead(4);
	list.insertAtTail(7);
	list.insertAtTail(10);
	list.insertAtTail(12);

	CDLinkedList<int> list2, l1, l2;
	list2.insertAtHead(1);
	list2.insertAtTail(3);
	list2.insertAtTail(6);
	list2.insertAtTail(8);
	list2.insertAtTail(9);
	list2.insertAtTail(15);
	/*list2.splitList(l1, l2);
	l1.display();
	l2.display();*/

	CDLinkedList<int> list3;
	list3.shuffleMerge(list, list2);
	list3.display();
	/*list3.merge(list, list2);
	list3.display();*/

	return 0;
}