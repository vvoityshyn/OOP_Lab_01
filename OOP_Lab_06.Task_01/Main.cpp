#include "Queue.h"
#include <iostream>

using namespace std;

int main()
{
	Queue<int>* queue = new Queue<int>();

	int item;
	int size;

	size = queue->Size();
	cout << "After creating: size = " << size << endl;

	item = 1;
	queue->Push(item);
	size = queue->Size();
	cout << "Push: " << item << " (size = " << size << ")" << endl;
	
	item = 2;
	queue->Push(item);
	size = queue->Size();
	cout << "Push: " << item << " (size = " << size << ")" << endl;

	item = 3;
	queue->Push(item);
	size = queue->Size();
	cout << "Push: " << item << " (size = " << size << ")" << endl;


	item = queue->Pop();
	size = queue->Size();
	cout << "Pop: " << item << " (size = " << size << ")" << endl;

	item = queue->Pop();
	size = queue->Size();
	cout << "Pop: " << item << " (size = " << size << ")" << endl;

	item = queue->Pop();
	size = queue->Size();
	cout << "Pop: " << item << " (size = " << size << ")" << endl;

	size = queue->Size();
	cout << "Before deleting: size = " << size << endl;

	delete queue;
	system("pause");
	return 0;
}