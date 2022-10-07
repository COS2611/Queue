#include <iostream>
#include "QueueADT.h"
#include "QueueAsArray.h"


int main()
{
	QueueType<int> myQueue;
	myQueue.addQueue(1);
	myQueue.addQueue(2);
	myQueue.addQueue(3);
	myQueue.addQueue(4);
	myQueue.addQueue(5);
	myQueue.printQueue();
	
	return 0;
}
