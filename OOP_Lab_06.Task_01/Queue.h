#pragma once
#include "QueueItem.h"
#include <iostream>

using namespace std;

template<typename T> class Queue
{
private:
	int size;
	QueueItem<T> * first;
	QueueItem<T> * last;

	void RemoveAllItems();
public:
	Queue();
	~Queue();

	void Push(T value);
	T Pop();
	void Clean();
	int Size() const;
};

template<typename T> void Queue<T>::RemoveAllItems()
{
	QueueItem<T>* item = this->first;
	while (item)
	{
		this->first = item->GetNext();

		delete item;
		this->size -= 1;

		item = this->first;
	}
	this->last = 0;
}

template<typename T> Queue<T>::Queue()
{
	cout << "Queue()" << endl;
	this->first = 0;
	this->last = 0;
	this->size = 0;
}

template<typename T> Queue<T>::~Queue()
{
	this->RemoveAllItems();
	cout << "~Queue()" << endl;
}

template<typename T> void Queue<T>::Push(T value)
{
	QueueItem<T> * item = new QueueItem<T>(value, 0);
	if (0 == this->size)
	{
		this->first = item;
	}
	else
	{
		this->last->SetNext(item);
	}
	this->last = item;
	
	this->size += 1;
}

template<typename T> T Queue<T>::Pop()
{
	if (0 == this->size)
	{
		throw "The queue is empty";
	}
	T item = this->first->GetItem();

	this->size -= 1;

	this->first = this->first->GetNext();

	if (0 == this->size)
	{
		this->last = 0;
	}

	return item;
}

template<typename T> void Queue<T>::Clean()
{
	this->RemoveAllItems();
}

template<typename T> int Queue<T>::Size() const
{
	return this->size;
}
