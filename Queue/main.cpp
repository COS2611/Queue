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
	// test case: COS2611-06-2020: Q5b
	std::string a = "aaaabbbbb";
	std::string b = "aaababbbbb";
	std::string c = "aaaabbbbba";
	std::string s1 = isInLanguageLQ2(a) ? " is ACCEPTED" : " is REJECTED";
	std::string s2 = isInLanguageLQ2(b) ? " is ACCEPTED" : " is REJECTED";
	std::string s3 = isInLanguageLQ2(c) ? " is ACCEPTED" : " is REJECTED";
	std::cout << a + s1 << std::endl;
	std::cout << b + s2 << std::endl;
	std::cout << c + s3 << std::endl;
	
	return 0;
}
