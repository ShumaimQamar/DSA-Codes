#include "Queue.h"
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Node {
public:
	T info;
	Node<T>* left;
	Node<T>* right;
	Node(T v)
	{
		info = v;
		left = 0;
		right = 0;
	}
};
template<typename T>
QUEUE<T>::QUEUE(int c)
{
	capacity = c;
	NoOfElements = 0;
	data = new T[capacity];
}

template<typename T>
QUEUE<T>::QUEUE(const QUEUE& other)
{
	if (other.NoOfElements != 0)
	{
		capacity = other.capacity;
		NoOfElements = other.NoOfElements;
		data = new T[capacity];
		for (int i = 0; i < NoOfElements; i++)
		{
			data[i] = other.data[i];
		}
	}
	else
	{
		throw ("Copy Constructor cannot be used as the Queue is empty");
	}
}

template<typename T>
QUEUE<T>::~QUEUE()
{
	delete[] data;
}

template<typename T>
void QUEUE<T>::enqueue(T v)
{
	if (!this->isFull())
	{
		data[NoOfElements] = v;
		NoOfElements++;
	}
	else
	{
		throw ("Queue is full, cannot add more elements");
	}
}

template<typename T>
T QUEUE<T>::dequeue()
{
	if (!this->isEmpty())
	{
		T s = data[0];
		for (int i = 1; i < NoOfElements; i++)
		{
			data[i-1] = data[i];
		}
		NoOfElements--;
		return s;
	}
	else
	{
		throw ("Queue is empty.");
	}
}
template<typename T>
QUEUE<T>& QUEUE<T>::operator=(const QUEUE<T>& other)
{
	if (this != &other)
	{
		delete[] data;
		capacity = other.capacity;
		NoOfElements = other.NoOfElements;
		data = new T[capacity];
		for (int i = 0; i < NoOfElements; i++)
		{
			data[i] = other.data[i];
		}
	}
	else
	{
		throw ("Assignment cannot be perform as both queues are same");
	}
	return *this;
}

template<typename T>
bool QUEUE<T>::isEmpty()
{
	if (NoOfElements == 0)
		return 1;
	else
		return 0;
}

template<typename T>
bool QUEUE<T>::isFull()
{
	if (NoOfElements == capacity)
		return 1;
	else
		return 0;
}

template<typename T>
int QUEUE<T>::getNoOfElements()
{
	return NoOfElements;
}

template<typename T>
T QUEUE<T>::QueueFront()
{
	if (!this->isEmpty())
		return data[0];
	else
		throw ("Queue is Empty");
}


template class QUEUE<Node<int>*>;
template class QUEUE<Node<char>*>;
template class QUEUE<Node<float>*>;
template class QUEUE<Node<double>*>;