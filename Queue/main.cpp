#include <iostream>
#include "QueueADT.h"
#include "QueueAsArray.h"
#include "LinkedQueue.h"

#include <stack>

template <class Type>
void reverseQ(QueueType<Type> &q)
{
	std::stack<Type> localStack;

	// Step 1: deque all elements into the first stack
	while (!q.isEmptyQueue())
	{
		localStack.push(q.front());
		q.deleteQueue();
	}

//	q.initializeQueue();
	while (!localStack.empty())
	{
		q.addQueue(localStack.top());
		localStack.pop();
	}
}


template <class Type>
void printQueue(QueueType<Type> &theQueue)
{
	while (!theQueue.isEmptyQueue())
	{
		std::cout << theQueue.front() << " ";
		theQueue.deleteQueue();
	}
	std::cout << std::endl;
}



int main()
{
	/// test reverseQ with QueueType
	QueueType<char> q;
	q.initializeQueue();
	
	q.addQueue('a');
	q.addQueue('b');
	q.addQueue('c');
	q.addQueue('d');
	
	std::cout << "Queue in original order: ";
	printQueue(q);

	q.addQueue('a');
	q.addQueue('b');
	q.addQueue('c');
	q.addQueue('d');
	
	reverseQ(q);
	std::cout << "Queue after being reversed: ";
	printQueue(q);
	
		
	
	return 0;
}
