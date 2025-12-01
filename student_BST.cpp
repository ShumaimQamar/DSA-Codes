#include<iostream>
#include<string>
using namespace std;

class StudentNode {
public:
	int rollNo;
	string name; 
	double cgpa;
	StudentNode* left;
	StudentNode* right;
	StudentNode(int rn, string n, double c)
	{
		rollNo = rn;
		name = n;
		cgpa = c;
		left = nullptr;
		right = nullptr;
	}
};
class StudentBST {
private:

	StudentNode* root;
	bool HelperSearch(StudentNode* node, int rollno)
	{
		if (node == nullptr) return false;
		else if (node->rollNo == rollno) return true;
		else if (rollno < node->rollNo)
			return HelperSearch(node->left, rollno);
		else
			return HelperSearch(node->right, rollno);
	}
	void destroy(StudentNode* node) {
		if (!node) return;
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
	void InOrder(StudentNode* s)
	{
		if (s != nullptr) {
			InOrder(s->left);
			cout << s->rollNo << ", " << s->name << ", " << s->cgpa << endl;
			InOrder(s->right);
		}
	}
	StudentNode* findMin(StudentNode* node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}
	StudentNode* deleteNode(StudentNode* root, int rn)
	{
		if (root == nullptr) {
			return root;
		}

		if (rn < root->rollNo) {
			root->left = deleteNode(root->left, rn);
		}
		else if (rn > root->rollNo) {
			root->right = deleteNode(root->right, rn);
		}
		else {
			if (root->left == nullptr) {
				StudentNode* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				StudentNode* temp = root->left;
				delete root;
				return temp;
			}
			
			StudentNode* temp = findMin(root->right);
			root->rollNo= temp->rollNo;

			root->right = deleteNode(root->right, temp->rollNo);
		}
		return root;
	}
	void InOrder2(StudentNode* s, double start, double end)
	{
		if (s != nullptr) {
			InOrder2(s->left, start, end);
			if(s->cgpa >= start && s->cgpa <= end)
				cout << s->rollNo << ", " << s->name << ", " << s->cgpa << endl;
			InOrder2(s->right, start, end);
		}
	}
public:

	StudentBST()
	{
		root = nullptr;
	}
	bool insert(int roll, string name, double cgpa)
	{
		StudentNode* newNode = new StudentNode(roll, name, cgpa);

		if (root == nullptr) {
			root = newNode;
			return 1;
		}
		StudentNode* current = root;
		StudentNode* parent = nullptr;

			while (current != nullptr) {
				parent = current;
				if (roll == current->rollNo) return 0;
				else if (roll < current->rollNo) {
					current = current->left;
				}
				else {
					current = current->right;
				}
			}
				if (roll < parent->rollNo) {
					parent->left = newNode;
					return 1;
				}
				else {
					parent->right = newNode;
					return 1;
				}

		return 0;
	}
	bool search(int roll)
	{
		StudentNode* current = root;
		while (current != nullptr) {
			if (current->rollNo == roll) {
				cout << current->rollNo << ", " << current->name << ", " << current->cgpa << endl;
				return true;
			}
			else if (roll < current->rollNo) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
		return false;
	}
	bool remove(int rn)
	{
			if (root->rollNo == rn && root->left == nullptr && root->right == nullptr)
			{
				delete root;
				return 1;
			}
			StudentNode* parent = root;
			StudentNode* current = root;

			while (current != nullptr && current->rollNo != rn)
			{
				parent = current;
				if (rn < current->rollNo) current = current->left;
				else current = current->right;
			}

			if (current != nullptr)
			{
				if (current->left == nullptr && current->right == nullptr)
				{
					if (parent->left == current) parent->left = 0;
					else parent->right = 0;
					delete current;
					return 1;
				}
				else if ((current->right != nullptr && current->left == nullptr) || (current->right == nullptr && current->left != nullptr))
				{
					if (parent->left == current)
					{
						if (current->left != nullptr) parent->left = current->left;
						else parent->left = current->right;
					}
					else
					{
						if (current->left != nullptr) parent->right = current->left;
						else parent->right = current->right;
					}
					delete current;
					return 1;
				}
				else
				{
					StudentNode* successor = findMin(current->right);
					current->rollNo = successor->rollNo;
					StudentNode* succParent = current;
					StudentNode* temp = current->right;

					while (temp != successor) {
						succParent = temp;
						temp = temp->left;
					}
					if (succParent->left == successor) succParent->left = successor->right;
					else succParent->right = successor->right;

					delete successor;
					return 1;
				}
			}
			return 0;
	}
	void displayInRange(double cgpaStart, double cgpaEnd)
	{
		InOrder2(root, cgpaStart, cgpaEnd);
	}
	~StudentBST()
	{
		destroy(root);
	}
	void InOrder()
	{
		InOrder(root);
	}

};

int main()
{
	StudentBST B1;
	int choice;
	string name;
	int rollno;
	double cgpa;
	cout << "1. Insert a new student \n 2. Search for a student \n 3. Remove a Student \n 4. See the list of students \n 5. Quit \n \n ";
	do
	{
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter rollno, name and cgpa to insert: ";
			cin >> rollno >> name >> cgpa;
			cout << B1.insert(rollno, name, cgpa) << endl;
			break;
		case 2:
			cout << "Enter rollno to search: ";
			cin >> rollno;
			cout << B1.search(rollno) << endl;
			break;
		case 3: 
			cout << "Enter rollno to remove: ";
			cin >> rollno;
			cout << B1.remove(rollno) << endl;
			break;
		case 4:
			double start, end;
			cout << "Enter cgpa start and end: ";
			cin >> start >> end;
			B1.displayInRange(start, end);
			break;
		case 5:
			cout << "List of students: \n ";
			B1.InOrder();
			break;
		default:
			cout << "Quit";
			break;
		}
	} while (choice > 0 && choice < 6);

	B1.~StudentBST();
	B1.InOrder();
	return 0;
}