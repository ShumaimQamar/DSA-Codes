#include<iostream>
#include "Queue.h"
#include<string>
#include<cmath>
using namespace std;

template<typename T>
class Node {
public:
	T info;
	Node<T>* left;
	Node<T>* right;
	Node()
	{
		info = 0;
		left = 0;
		right = 0;
	}
	Node(T v)
	{
		info = v;
		left = 0;
		right = 0;
	}
};

template<typename T>
class BinaryTree {
private:
	Node<T>* root;
	Node<T>* search(Node<T>* cur, T v)
	{
		if (cur == 0) return 0;
		if (cur->info == v) return cur;
		Node<T>* t;
		t = search(cur->left, v);
		if (!t)
			t = search(cur->right, v);
		return t;
	}
	Node<T>* searchP(Node<T>* cur, T v)
	{
		if (cur == 0) return 0;
		if (cur->left->info == v) return cur;
		if (cur->right->info == v) return cur;
		Node<T>* t;
		t = searchP(cur->left, v);
		if (!t)
			t = searchP(cur->right, v);
		return t;
	}
	void remove(Node<T>* cur)
	{
		if (cur == 0) return;
		remove(cur->left);
		remove(cur->right);
		delete cur;
	}
	void PreOrder(Node<T>* cur)
	{
		if (cur == 0) return;
		cout << cur->info << " ";
		PreOrder(cur->left);
		PreOrder(cur->right);
	}
	void postOrder(Node<T>* cur)
	{
		if (cur == 0) return;
		postOrder(cur->left);
		postOrder(cur->right);
		cout << cur->info << " ";
	}
	void Inorder(Node<T>* cur)
	{
		if (cur == 0) return;
		Inorder(cur->left);
		cout << cur->info << " ";
		Inorder(cur->right);
	}
	int height2(Node<T>* cur, int count)
	{
		if (cur == nullptr) return 0;

		count++;
		int left1 = height2(cur->left, count);
		int right1 = height2(cur->right, count);
		return max(left1, right1) + 1;
	}
	void displayLevel(Node<T>* node, int levelNo) {
		if (node == nullptr)
			return;

		if (levelNo == 1)
			cout << node->info << " ";
		else {
			displayLevel(node->left, levelNo - 1);
			displayLevel(node->right, levelNo - 1);
		}
	}
	void mirror(Node<T>* cur)
	{
		if (cur == nullptr) return;
		swap(cur->left, cur->right);
		mirror(cur->left);
		mirror(cur->right);
	}
	void destructor(Node<T>* cur)
	{
		if (cur == nullptr) return;
		destructor(cur->left);
		destructor(cur->right);
		delete cur;
	}
	Node<T>* copyTree(Node<T>* cur)
	{
		if (cur == nullptr) return nullptr;
		Node<T>* n = new Node<T>;
		n->info = cur->info;
		n->left = copyTree(cur->left);
		n->right = copyTree(cur->right);
		return n;
	}
	void paran(Node<T>* cur)
	{
		if (cur == 0) return;

		if (cur->left != nullptr || cur->right != nullptr) {
			cout << cur->info << " ";
			cout << "( ";
			paran(cur->left);
			cout << ", ";
			paran(cur->right);
			cout << ") ";
		}
		else {
			cout << cur->info << " ";
		}

	}
public:
	BinaryTree()
	{
		root = 0;
	}
	void setRoot(T v)
	{
		if (!root)
		{
			root = new Node<T>(v);
		}
	}
	void getRoot()
	{
		return root->info;
	}
	void setLeftChild(T p, T v)
	{
		Node<T>* n = search(root,p);
		if (n->left == 0)
		{
			n->left = new Node<T>(v);
		}
	}
	void setRightChild(T p, T v)
	{
		Node<T>* n = search(root, p);
		if (n->right == 0)
		{
			n->right = new Node<T>(v);
		}
	}
	BinaryTree(BinaryTree<T>& b2)
	{
		this->root = this->copyTree(b2.root);
	}
	T getParent(T node)
	{
		Node<T>* n = searchP(root, node);
		return n->info;
	}
	BinaryTree<T> operator = (BinaryTree<T>& b)
	{
		if (this != &b)
		{
			destructor(this->root);
			this->root = this->copyTree(b.root);
			return *this;
		}
	}
	void remove(T v)
	{
		Node<T>* n = searchP(root, v);
		if (n)
		{
			if (n->left->info == v)
			{
				remove(n->left);
				n->left = 0;
			}
			else
			{
				remove(n->right);
				n->right = 0;
			}
		}
	}
	bool isInternalNode(T node)
	{
		Node<T>* n = search(root, node);
		if (n->left == nullptr && n->right == nullptr) return 1;
		else return 0;
	}
	bool isExternalNode(T node)
	{
		Node<T>* n = search(root, node);
		if (n->left == nullptr && n->right == nullptr) return 0;
		else return 1;
	}
	void displayDescendents(T node)
	{
		Node<T>* n = search(root,node);
		PreOrder(n->left);
		PreOrder(n->right);
	}
	T findNodeSiblings(T node)
	{
		Node<T>* n = searchP(root, node);
		if (n->info == node) return -1;
		else if (n->left->info != node)
			return n->left->info;
		else if (n->right->info != node)
			return n->right->info;
		else
			return -1;
	}
	void preorder()
	{
		PreOrder(root);
		cout << endl;
	}
	void postorder()
	{
		postOrder(root);
		cout << endl;
	}
	void inorder()
	{
		Inorder(root);
		cout << endl;
	}
	int heightOfTree()
	{
		int c = height2(root, 0);
		cout << c << endl;
		return c;
	}
	void displayLevell(int levelNo)
	{
		displayLevel(root, levelNo);
		cout << endl;
	}
	void levelorder()
	{
		QUEUE<Node<T>*> Q(50);
		Q.enqueue(root);
		while (!Q.isEmpty())
		{
			Node<T>* cur = Q.dequeue();
			cout << cur->info << " ";
			if (cur->left) 
				Q.enqueue(cur->left);
			if (cur->right) 
				Q.enqueue(cur->right);
		}
		cout << endl;
	}
	BinaryTree<T> getMirrorImage()
	{
		mirror(root);
		return *this;
	}
	~BinaryTree()
	{
		destructor(root);
	}
	void displayParenthesizedView()
	{
		paran(root);
		cout << endl;
	}
};

int main()
{
	BinaryTree<int> b1;
	b1.setRoot(11);
	b1.setLeftChild(11, 5);
	b1.setRightChild(11, 7);
	b1.setLeftChild(5, 9);
	b1.setRightChild(5, 12);
	b1.setLeftChild(9, 4);
	b1.setRightChild(12, 8);
	b1.setLeftChild(7, 3);

	b1.displayLevell(3);
	cout << "Current height of tree: ";
	b1.heightOfTree();
	cout << "Preorder Traversal: ";
	b1.preorder();
	cout << "PostOrder Traversal: ";
	b1.postorder();
	cout << "Inorder Traversal: ";
	b1.inorder();
	cout << "Level Order Traversal: ";
	b1.levelorder();

	cout << "Copy constructor called -----> ";
	BinaryTree<int> b2(b1);
	cout << "Level order Traversal call for second object: " << endl;
	b2.levelorder();
	cout << "Parent of node 9: ";
	cout << b2.getParent(9) << endl;
	cout << "Removing node 5: ";
	b2.remove(5);
	cout << "Height of tree after removing node 5: ";
	b2.heightOfTree();
	b2.levelorder();

	cout << b1.isInternalNode(7) << endl;
	cout << b1.isExternalNode(7) << endl;
	cout << b1.findNodeSiblings(12) << endl;
	cout << "Displaying descendents: ";
	b1.displayDescendents(5);
	cout << endl;

	BinaryTree<int> b3;
	cout << "Assignment Operator used: ";
	b3 = b2;
	b2.levelorder();

	cout << "Tree is Mirrored: ";
	b3 = b1.getMirrorImage();
	b3.levelorder();

	cout << "Parenthesized view of tree: ";
	b3.displayParenthesizedView();
	return 0;
}