#include<iostream>
#include<string>
#include<cmath>
#include"Queue.h"
using namespace std;

template<typename T>
class BinaryTree {
private:
	int height;
	T* data;
	bool* status;
	void preorder(int cur)
	{
		if (cur >= pow(2, height) - 1 || status[cur] == false)
			return;

		cout << data[cur] << " ";
		preorder(2 * cur + 1);
		preorder(2 * cur + 2);
	}
	void postorder(int cur)
	{
		if (cur >= pow(2, height) - 1 || status[cur] == false)
			return;

		postorder(2 * cur + 1);
		postorder(2 * cur + 2);
		cout << data[cur] << " ";
	}
	void inorder(int cur)
	{
		if (cur >= pow(2, height) - 1 || status[cur] == false)
			return;

		inorder(2 * cur + 1);
		cout << data[cur] << " ";
		inorder(2 * cur + 2);
	}
	int height2(int i, int count)
	{
		if (i >= pow(2, height) - 1 || status[i] == false) return 0;

		count++;
		int left = height2(i * 2 + 1, count);
		int right = height2(i * 2 + 2, count);
		return max(left, right) + 1;
	}
	void removesub(int i)
	{
		if (i > pow(2, height) - 1 || status[i] == false) return;

		status[i] = false;
		removesub(2*i+1);
		removesub(2*i+2);
	}
	void ancs(int i)
	{
		if (i <= 0) return;

		cout << data[(i-1)/2] << " ";
		ancs((i - 1) / 2);
	}
	void desc(int i)
	{
		if (i > pow(2, height) - 1 || status[i] == false) return;

		if(status[2*i+1] == true)
			cout << data[2 * i + 1] << " ";
		if(status[2*i+2] == true)
			cout << data[2 * i + 2] << " ";

		desc(2 * i + 1);
		desc(2 * i + 2);
	}
	

	void paran(int cur, int count)
	{
		if (cur >= pow(2, height) - 1 || status[cur] == false)
			return;

		cout << data[cur] << " ";
		if (status[2 * cur + 1] == true || status[2 * cur + 2] == true){
			cout << "( ";
			count++;
		}

		paran(2 * cur + 1,count);
		if (status[2 * cur + 1] != true && status[2 * cur + 2] != true)
			cout << ", ";
		paran(2 * cur + 2,count);

		if (count > 0)
		{
			cout << " )";
			count = count-1;
		}
	}
public:
	BinaryTree()
	{
		height = 0;
		data = new T[0];
		status = new bool[0];
	}
	BinaryTree(int h)
	{

		height = h;
		data = new T[pow(2, h) - 1];
		status = new bool[pow(2, h) - 1];
		for (int i = 0; i < (pow(2, h) - 1); i++)
		{
			status[i] = 0;
		}
	}
	void setroot(T v)
	{
		if (status[0] != true)
		{
			data[0] = v;
			status[0] = true;
		}
	}
	T getRoot()
	{
		if (status[0] == true)
			return data[0];
	}
	void setLeftchild(T P, T v)
	{
		for (int i = 0; i < (pow(2, height) - 1); i++)
		{
			if (status[i] == true && data[i] == P)
			{
				if (2 * i + 1 < (pow(2, height) - 1))
				{
					if (status[2 * i + 1] != true)
					{
						data[2*i+1] = v;
						status[2*i+1] = true;
						return;
					}
				}
			}
		}
	}

	void setRightchild(T P, T v)
	{
		for (int i = 0; i < (pow(2, height) - 1); i++)
		{
			if (status[i] == true && data[i] == P)
			{
				if (2 * i + 2 < (pow(2, height) - 1))
				{
					if (status[2 * i + 2] != true)
					{
						data[2 * i + 2] = v;
						status[2 * i + 2] = true;
						return;
					}
				}
			}
		}
	}
	T getParent(T node)
	{
		for (int i = 0; i < (pow(2, height) - 1); i++)
		{
			if (status[i] == true && data[i] == node)
			{
				return data[(i - 1) / 2];
			}
		}
	}
	void remove(T v)
	{
		for (int i = 0; i < (pow(2, height) - 1); i++)
		{
			if (status[i] == true && data[i] == v)
			{
				removesub(i);
				return;
			}
		}
	}
	void displayAncestors(T node)
	{
		for (int i = 0; i < (pow(2, height) - 1); i++)
		{
			if (status[i] == true && data[i] == node)
			{
				ancs(i);
				cout << endl;
			}
		}
	}
	void displayDescendents(T node)
	{
		for (int i = 0; i < (pow(2, height) - 1); i++)
		{
			if (status[i] == true && data[i] == node)
			{
				desc(i);
				cout << endl;
			}
		}
	}
	int heightOfTree()
	{
		int c = height2(0, 0);
		return c;
	}
	void preOrder()
	{
		preorder(0);
		cout << endl;
	}
	void postOrder()
	{
		postorder(0);
		cout << endl;
	}
	void inOrder()
	{
		inorder(0);
		cout << endl;
	}
	void levelOrder()
	{
		int size = (pow(2, height) - 1);
		for (int i = 0; i < size; i++)
		{
			if (status[i] == true)
			{
				cout << data[i] << " ";
			}
		}
		cout << endl;
	}
	void displayLevel(int levelNo)
	{
		int execute = pow(2, levelNo - 1);
		int i = execute-1;
		for (int j = i; j < (i + execute); j++)
		{
			if (status[j] == true)
				cout << data[j] << " ";
		}
		cout << endl;
	}
	int findLevelOfNode(T node)
	{
		int i;
		for (i = 0; i < (pow(2, height) - 1); i++)
		{
			if (status[i] == true && data[i] == node)
			{
				break;
			}
		}
		int j = 0;
		while (j <= pow(2, height))
		{
			int n = pow(2, j);
			int ex = n - 1;
			if (i >= ex && i < (ex + n))
			{
				return j+1;
			}
			j++;
		}
	}
	void displayParenthesizedView()
	{
		paran(0, 0);
		cout << endl;


	}
};


int main()
{
	BinaryTree<int> b1(4);
	b1.setroot(11);
	b1.setLeftchild(11, 5);
	b1.setRightchild(11, 7);
	b1.setLeftchild(5, 9);
	b1.setRightchild(5, 12);
	b1.setLeftchild(9, 4);
	b1.setRightchild(12, 8);
	b1.setLeftchild(7, 3);

	b1.displayParenthesizedView();


	int n = b1.getParent(3);
	cout << n << endl;

	int z = b1.findLevelOfNode(8);
	cout << z << endl;

	int a = b1.heightOfTree();
	cout << a << endl;
	b1.displayDescendents(5);
	b1.displayAncestors(8);
	b1.displayLevel(4);
	b1.preOrder();
	b1.postOrder();
	b1.inOrder();
	b1.levelOrder();

	b1.remove(5);
	cout << endl;
	a = b1.heightOfTree();
	cout << a << endl;
	b1.levelOrder();
	return 0;
}