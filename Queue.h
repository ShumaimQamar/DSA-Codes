#ifndef QUEUE_CLASS
#define QUEUE_CLASS

#include<iostream>
using namespace std;

template<typename T>
class QUEUE {
private:
	T *data;
	int capacity;
	int NoOfElements;

public:
	QUEUE(int c =10);
	QUEUE(const QUEUE<T>& other);
	~QUEUE();
	void enqueue(T v);
	T dequeue();
	QUEUE& operator=(const QUEUE<T>& other);
	bool isEmpty();
	bool isFull();
	int getNoOfElements();
	T QueueFront();
};

#endif