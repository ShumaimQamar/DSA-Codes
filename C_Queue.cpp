#include "C_Queue.h"
#include<iostream>
#include<string>
using namespace std;

template<typename T> 
C_QUEUE<T>::C_QUEUE(int c)
{
	capacity = c;
	NoOfElements = 0;
	front = 0;
	rear = 0;
	data = new T[capacity];
}

template<typename T>
C_QUEUE<T>::C_QUEUE(C_QUEUE& other)
{
	if (other.NoOfElements != 0)
	{
		capacity = other.capacity;
		NoOfElements = other.NoOfElements;
		rear = other.rear;
		front = other.front();
		data = new T[capacity];
		for (int i = 0; i < NoOfElements; i++)
		{
			data[(i+front)%capacity] = other.data[(i + front)%capacity];
		}
	}
	else
	{
		throw ("Copy Constructor cannot be used as the Queue is empty");
	}
}

template<typename T>
C_QUEUE<T>::~C_QUEUE()
{
	delete[] data;
}

template<typename T>
void C_QUEUE<T>::enqueue(int v)
{/*
	if (NoOfElements != capacity)
	{*/
		data[rear] = v;
		rear = (rear + 1) % capacity;
		NoOfElements++;
	/*}
	else
	{
		throw ("Queue is full, cannot add more elements");
	}*/
}

template<typename T>
T C_QUEUE<T>::dequeue()
{
	if (!this->isEmpty())
	{
		int s = data[front];
		front = (front + 1) % capacity;
		NoOfElements--;
		return s;
	}
	else
	{
		throw ("Queue is empty.");
	}
}
template<typename T>
C_QUEUE<T>& C_QUEUE<T>::operator=(const C_QUEUE<T>& other)
{
	if (this != &other)
	{
		delete[] data;
		capacity = other.capacity;
		NoOfElements = other.NoOfElements;
		rear = other.rear;
		front = other.front();
		data = new T[capacity];
		for (int i = 0; i < NoOfElements; i++)
		{
			data[(i + front) % capacity] = other.data[(i + front) % capacity];
		}
	}
	else
	{
		throw ("Assignment cannot be perform as both queues are same");
	}
}

template<typename T>
bool C_QUEUE<T>::isEmpty()
{
	if (NoOfElements == 0)
		return 1;
	else
		return 0;
}

template<typename T>
bool C_QUEUE<T>::isFull()
{
	if (NoOfElements == capacity)
		return 1;
	else
		return 0;
}

template<typename T>
int C_QUEUE<T>::getNoOfElements()
{
	return NoOfElements;
}

template<typename T>
T C_QUEUE<T>::QueueFront()
{
	if (!this->isEmpty())
		return data[front];
	else
		throw ("Queue is Empty");
}
template<typename T>
T C_QUEUE<T>::getFront()
{
	if (!isEmpty()) {
		return data[front];
	}
	else
	{
		throw ("Queue is empty.");
	}
}
template<typename T>
T C_QUEUE<T>::getRear()
{
	if (!isEmpty()) {
		return data[(rear -1)%capacity];
	}
	else
	{
		throw ("Queue is empty.");
	}
}
template<typename T>
void C_QUEUE<T>::resize()
{
	T* data1 = new T[capacity * 2];
	int k = 0; 
	for (int i= 0; i <getNoOfElements(); i++)
	{
		data1[k] = data[(i + front) % capacity];
		k++;
	}
	capacity = capacity * 2;
	front = 0;
	rear = this->NoOfElements;
	delete[] data;
	data = data1;
}

template<typename T>
void C_QUEUE<T>::display()
{
	cout << "Elements in the circular queue are: ";
	for (int i = 0; i < NoOfElements; i++)
	{
		cout << data[(i + front) % capacity] << " ";
		cout << endl;
	}
}

template class C_QUEUE<int>;
template class C_QUEUE<double>;
template class C_QUEUE<float>;
template class C_QUEUE<char>;