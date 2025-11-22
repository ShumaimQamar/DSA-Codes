#include<iostream>
#include<cstring>
using namespace std;

class HashTable {
private:
	string* table;
	int S; 
	int n; 
public:
	HashTable(int size)
	{
		S = size;
		n = 0;
		table = new string[S];
		for (int i = 0; i < S; i++)
		{
			table[i] = "Empty";
		}
	}
	~HashTable()
	{
		delete[] table;
	}
	bool isEmpty()
	{
		if (n == 0)
			return true;
		return false;
	}
	bool isFull()
	{
		if (n == S)
			return true;
		return false;
	}
	double loadFactor()
	{
		return n / S;
	}
	int getHashValue(string name)
	{
		int c = 0;
		for (int i = 0; i < name.length(); i++)
		{
			c += int(name[i]);
		}
		return c%S;
	}
	bool insert(string name)
	{
		if (isFull())
		{
			return false;
		}
		int index = getHashValue(name);
		cout << index;
		if (table[index] == "Empty")
		{
			table[index] = name;
			n++;
			cout << endl;
			return true;
		}
		if (table[index] == name)
		{
			return true;
		}
		for (int i = 0; i < S; i++)
		{
			index = (index + 1) % S;
			cout << " -> " << index;
			if (table[index] == "Empty")
			{
				table[index] = name;
				n++;
				cout << endl;
				return true;
			}
		}
		cout << endl;
		return false;
		
	}
	bool search(string name)
	{
		if (isEmpty()) return false;
		int index = getHashValue(name);
		cout << index;
		if (table[index] == name)
		{
			cout << endl;
			return true;
		}
		for (int i = 0; i < S; i++)
		{
			index = (index + 1) % S;
			cout << " -> " << index;
			if (table[index] == name)
			{
				cout << endl;
				return true;
			}
		}
		cout << endl;
		return false;
			
	}
	bool remove(string name)
	{
		if (isEmpty()) return false;
		int index = getHashValue(name);
		if (table[index] == name)
		{
			table[index] = "Empty";
			return true;
		}
		for (int i = 0; i < S; i++)
		{
			index = (index + 1) % S;
			if (table[index] == name)
			{
				table[index] = "Empty";
				return true;
			}
		}
		return false;

	}
	void display()
	{
		if (isEmpty()) return;

		for (int i = 0; i < S; i++)
		{
			if (table[i] != "Empty")
				cout << i << ": " << table[i] << endl;
			else
				cout << i << ": " << "EMPTY" << endl;
		}
	}
};

int main()
{
	int n;
	cout << "Enter the size of HashTable :";
	cin >> n;
	HashTable h1(n);

	int choice;
	string name;
	cout << "1. Insert a name \n 2. Search for a name \n 3. Remove a name \n 4. Display the Hash Table \n 5. Display Load Factor of the table \n 6. Exit \n \n Enter your choice : ";
	do
	{ 
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter name to insert: ";
			cin >> name;
			cout << h1.insert(name) << endl;
			break;
		case 2:
			cout << "Enter name to search: ";
			cin >> name;
			cout << h1.search(name) << endl;
			break;
		case 3:
			cout << "Enter name to remove: ";
			cin >> name;
			cout << h1.remove(name) << endl;
			break;
		case 4:
			h1.display();
			break;
		case 5:
			h1.loadFactor();
			break;
		default:
			cout << "Exit";
			break;
		}
	} while (choice > 0 && choice < 6);
	return 0;
}