#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
	T info;
	Node<T>* next;
	Node()
	{
		next = 0;
	}
	Node(T val)
	{
		info = val;
		next = 0;
	}
	Node(T val, Node* p)
	{
		info = val;
		next = p;
	}
};
template <class T>
class LSLL
{
private:
	Node<T>* head;
public:
	LSLL()
	{
		head = 0;
	}

	// Insertion functions
	void insertAtHead(T val)
	{
		Node<T>* t = new Node<T>(val);
		t->next = head;
		head = t;
	}

	void insertAtTail(T val)
	{
		Node<T>* t = new Node<T>(val);
		if (!head)
		{
			head = t;
			return;
		}
		Node<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
	temp->next = t;
	}

	void insertBefore(T key, T val)
	{
		if (!head)
		{
			return;
		}

		if (head->info == key)
		{
			Node<T>* t = new Node<T>(val);
			t->next = head;
			head = t;
			return;
		}

		Node<T>* temp = head;
		Node<T>* prev = head;
		while (temp!= nullptr)
		{
			if (temp->info == key)
			{
				Node<T>* t = new Node<T>(val);
				t->next = temp;
				prev->next = t;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}

	void insertAfter(T key, T val)
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->info == key)
			{
				Node<T>* t = new Node<T>(val);
				t->next = temp->next;
				temp->next = t;
				return;
			}
			temp = temp->next;
		}
	}

	// Deletion functions
	void removeAtHead()
	{
		if (!head) return;

		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}

	void removeAtTail()
	{
		if (!head) return;
	
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		Node<T>* temp = head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;

	}

	void remove(T val)
	{
		if (!head)
		{
			return;
		}
		if (head->info == val)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node<T>* temp = head;
		Node<T>* prev = head;
		while (temp != nullptr)
		{
			if (temp->info == val)
			{
				prev->next = temp->next;
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	void removeBefore(T val)
	{
		if (!head) return;
		if (head->info == val) return;

		Node<T>* temp = head;
		Node<T>* prev = nullptr;
		Node<T>* prev_p = nullptr;

		while (temp != nullptr)
		{
			if (temp->info == val)
			{
				if (prev_p == nullptr) {
				
					head = temp;
					delete prev;
					return;
				}
				else {
					prev_p->next = temp;
					delete prev;
					return;
				}
			}
			
			prev_p = prev;
			prev = temp;
			temp = temp->next;
		}
	}
	void removeAfter(T val)
	{
		if (!head)
		{
			return;
		}

		Node<T>* temp = head;

		while (temp != nullptr)
		{
			if (temp->info == val && temp->next != nullptr)
			{
				Node<T>* t = temp->next;
				temp->next = t->next;
				delete t;
				return;
			}
			temp = temp->next;
		}
	}

	// Utility functions
	bool search(T key)
	{
		if (!head) return false;
		
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->info == key)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	void update(T key, T val)
	{
		if (!head) return;

		Node<T>* temp = head;
		while (temp != nullptr)
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

		int count = 0;
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	void removeKthNode(int k)
	{
		if (head == 0) return;
		if (k == 1)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		int count = 2;
		Node<T>* temp = head->next;
		Node<T>* prev = head;
		while (temp != 0)
		{
			if (count == k)
			{
				prev->next = temp->next;
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->next;
			count++;
		}
	}

	bool removeKthNode(int k, int& val)
	{
		if (head == 0) return false;
		if (k == 1)
		{
			Node<T>* temp = head;
			val = head->info;
			head = head->next;
			cout << val << endl;
			delete temp;
			return true;
		}
		int count = 2;
		Node<T>* temp = head->next;
		Node<T>* prev = head;
		while (temp != 0)
		{
			if (count == k)
			{
				prev->next = temp->next;
				val = temp->info;
				cout << val << endl;
				delete temp;
				return true;
			}
			prev = temp;
			temp = temp->next;
			count++;
		}
		return false;
	}

	void combine(LSLL& list1, LSLL& list2)
	{
		if (!list1.head && !list2.head) return;

		head = list1.head;
		list1.head = nullptr;
		
		Node<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = list2.head;
		list2.head = nullptr;
	}

	void shuffleMerge(LSLL& list1, LSLL& list2)
	{
		if (!list1.head && !list2.head) return;

		Node<T>* t1 = list1.head;
		list1.head = list1.head->next;
		head = t1;
		t1->next = nullptr;
		Node<T>* temp3 = head;

		Node<T>* t2 = list2.head;
		list2.head = list2.head->next;
		temp3->next = t2;
		temp3 = temp3->next;
		t2->next = nullptr;

		Node<T>* temp1 = list1.head;
		Node<T>* temp2 = list2.head;
		while (temp1 != nullptr || temp2 != nullptr)
		{
			if (temp1 != nullptr)
			{
				Node<T>* t3 = temp1;
				temp1 = temp1->next;
				temp3->next = t3;
				temp3 = temp3->next;
				t3->next = nullptr;
			}


			if (temp2 != nullptr)
			{
				Node<T>* t3 = temp2;
				temp2 = temp2->next;
				temp3->next = t3;
				temp3 = temp3->next;
				t3->next = nullptr;
			}
		}
	}
	void removeDuplicates()
	{
		if (!head) return;

		Node<T>* temp = head->next;
		Node<T>* prev = head;
		Node<T>* tt = head;
		while (tt != nullptr)
		{
			while (temp != nullptr)
			{
				if (tt->info == temp->info)
				{
					Node<T>* t = temp;
					prev->next = temp->next;
					temp = temp->next;
					delete t;
				}
				else {
					prev = temp;
					temp = temp->next;
				}
			}
			tt = tt->next;
			if (tt != nullptr) {
				temp = tt->next;
				prev = tt;
			}
		}
	}

	void reverseList()
	{
		if (!head) return;
		
		Node<T>* temp = head;
		head = head->next;
		temp->next = nullptr;
		while (head != nullptr)
		{
			Node<T>* t = head;
			head = head->next;
			t->next = temp;
			temp = t;

		}
		head = temp;

	}
	void display()
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	~LSLL() // Destructor
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			Node<T>* next_Node = temp->next;
			delete temp;
			temp = next_Node;
		}
		head = nullptr;
	}
};



int main1()
{
	LSLL<int> list;
	// Sample testing (You can add more)
	list.insertAtHead(10);
	list.insertAtTail(20
	);
	list.insertAtTail(30);
	list.insertAfter(20, 25);
	list.insertBefore(10, 5);
	list.display();
	list.remove(25);
	list.removeAtHead();
	list.removeAtTail();
	cout << "After deletions: ";
	list.display();
	list.update(20, 99);
	cout << "After update: ";
	list.display();
	int i = 0;
	bool b = list.removeKthNode(1, i);
	cout << b << endl;
	list.display();
	if (list.search(99))
		cout << "Element 99 found!";
	else
		cout << "Element 99 not found!";
	cout << "Total Nodes: " << list.countNodes();
	return 0;
}

int main2()
{
	LSLL<int> list2;
	list2.insertAtTail(7);
	list2.insertAtTail(3);
	list2.insertAtTail(4);
	list2.insertAtTail(2);
	//list2.display();

	LSLL<int> list3;
	list3.insertAtTail(5);
	list3.insertAtTail(9);
	//list3.display();

	LSLL<int> list4;
	list4.combine(list2, list3);
	list4.display();
	return 0;
}

int main3()
{
	LSLL<int> list2;
	list2.insertAtTail(7);
	list2.insertAtTail(3);
	list2.insertAtTail(4);
	list2.insertAtTail(2);
	list2.reverseList();
	list2.display();

	LSLL<int> list3;
	list3.insertAtTail(5);
	list3.insertAtTail(9);
	list3.insertAtTail(1);
	list3.insertAtTail(0);
	list3.display();

	LSLL<int> list4;
	list4.shuffleMerge(list2, list3);
	list4.display();
	return 0;
}

int main() {
	LSLL<int> list5;
	list5.insertAtTail(23);
	list5.insertAtTail(5);
	list5.insertAtTail(4);
	list5.insertAtTail(23);
	list5.insertAtTail(6);
	list5.insertAtTail(78);
	list5.insertAtTail(4);
	list5.insertAtTail(5);
	list5.removeDuplicates();
	list5.display();
	return 0;
}

