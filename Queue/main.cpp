#include <iostream>
#include "QueueADT.h"
#include "QueueAsArray.h"
#include "LinkedQueue.h"


int main()
{
	QueueType<int> myQueue;
	myQueue.addQueue(1);
	myQueue.addQueue(2);
	myQueue.addQueue(3);
	myQueue.addQueue(4);
	myQueue.addQueue(5);
	std::cout << "Array Queue Elements: ";
	myQueue.printQueue();
	
	
	LinkedQueueType<int> queue;
	int x, y;

	queue.initializeQueue();
	x = 4;
	y = 5;
	queue.addQueue(x);
	queue.addQueue(y);
	x = queue.front();
	queue.deleteQueue();
	queue.addQueue(x + 5);
	queue.addQueue(16);
	queue.addQueue(x);
	queue.addQueue(y - 3);

	std::cout << "Linked Queue Elements: ";
	queue.printQueue();
	
	return 0;
}
