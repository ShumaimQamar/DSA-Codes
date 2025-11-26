#ifndef CIRCULAR_QUEUE_CLASS
#define CIRCULAR_QUEUE_CLASS

#include<iostream>
#include<string>
using namespace std;

template<typename T>
class C_QUEUE {
private:
	T* data;
	int capacity;
	int NoOfElements;
	int front;
	int rear;

public:
	C_QUEUE(int c = 10);
	C_QUEUE(C_QUEUE& other);
	~C_QUEUE();
	void enqueue(int v);
	T dequeue();
	C_QUEUE& operator=(const  C_QUEUE& other);
	bool isEmpty();
	bool isFull();
	int getNoOfElements();
	T QueueFront();
	T getFront();
	T getRear();
	void resize();
	void display();
};

#endif
