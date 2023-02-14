#include <iostream>
#include <stack>
#include "queueADT.h"
#include "QueueAsArray.h"
#include "LinkedQueue.h"
#include "tests.h"


template <class Type>
void reverseQ(queueType<Type> &q)
{
	std::stack<Type> localStack;

	// Step 1: deque all elements into the first stack
	while (!q.isEmptyQueue())
	{
		localStack.addQueue(q.front());
		q.deleteQueue();
	}

//	q.initializeQueue();
	while (!localStack.empty())
	{
		q.addQueue(localStack.top());
		localStack.deleteQueue();
	}
}


template <class Type>
static void printQueue(queueType<Type> theQueue)
{
	// TODO: Copy constructor needs to be defined to print as an accessor function
	while (!theQueue.isEmptyQueue())
	{
		std::cout << theQueue.front() << " ";
		theQueue.deleteQueue();
	}
	std::cout << std::endl;
}



int main()
{
//	testIsInLanguageLQ2();
	testIdenticalQueue();
	testIdenticalQueueIterative();
//	test_replaceItem();
//	test_replaceEverySecondItem();
	
	return 0;
}
