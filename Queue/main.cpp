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
	
	/// test identicalQueue
	QueueType<int> yourQueue;
//	yourQueue = myQueue;
	yourQueue.addQueue(2);
	yourQueue.addQueue(1);
	yourQueue.addQueue(3);
	yourQueue.addQueue(4);
	yourQueue.addQueue(5);
	std::cout << "Your Queue Elements: ";
	yourQueue.printQueue();
	if (identicalQueue(myQueue, yourQueue))
	{
		std::cout << "The queues are identical" << std::endl;
	}
	else
	{
		std::cout << "The queues are different" << std::endl;
	}
	
	return 0;
}
