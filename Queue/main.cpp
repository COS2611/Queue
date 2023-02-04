#include <iostream>
#include "queueADT.h"
#include "QueueAsArray.h"
#include "LinkedQueue.h"

#include <stack>

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
		localStack.pop();
	}
}


template <class Type>
void printQueue(queueType<Type> &theQueue)
{
	while (!theQueue.isEmptyQueue())
	{
		std::cout << theQueue.front() << " ";
		theQueue.deleteQueue();
	}
	std::cout << std::endl;
}


// test case: COS2611-06-2020: Q5b
static void testIsInLanguageLQ2()
{
	std::string a = "abb";
	std::string b = "aabbb";
	std::string c = "aaaabbbbb";
	std::string d = "aaaabbbbba";
	std::string e = "aaaabbbbb";
	std::string f = "aaababbbbb";	// FIXME: this string should be rejected
	std::string g = "aaaabbbbba";
	std::string s1 = isInLanguageLQ2(a) ? " is ACCEPTED" : " is REJECTED";
	std::string s2 = isInLanguageLQ2(b) ? " is ACCEPTED" : " is REJECTED";
	std::string s3 = isInLanguageLQ2(c) ? " is ACCEPTED" : " is REJECTED";
	std::string s4 = isInLanguageLQ2(d) ? " is ACCEPTED" : " is REJECTED";
	std::string s5 = isInLanguageLQ2(e) ? " is ACCEPTED" : " is REJECTED";
	std::string s6 = isInLanguageLQ2(f) ? " is ACCEPTED" : " is REJECTED";
	std::string s7 = isInLanguageLQ2(g) ? " is ACCEPTED" : " is REJECTED";
	std::cout << a + s1 << std::endl;
	std::cout << b + s2 << std::endl;
	std::cout << c + s3 << std::endl;
	std::cout << d + s4 << std::endl;
	std::cout << e + s1 << std::endl;
	std::cout << f + s2 << std::endl;
	std::cout << g + s3 << std::endl;
}

static void testIdenticalQ() {
	queueType<int> q1;
	queueType<int> q2;
	
	q1.addQueue(1);
	q1.addQueue(2);
	q1.addQueue(3);

	q2.addQueue(1);
	q2.addQueue(2);
	q2.addQueue(3);
	
	if (identicalQueue(q1, q2))
	{
		std::cout << "The queues are identical" << std::endl;
	}
	else
	{
		std::cout << "The queues are not identical" << std::endl;
	}
}

static void test_replaceItem()
{
	queueType<int> myQueue;
	
	myQueue.addQueue(1);
	myQueue.addQueue(2);
	myQueue.addQueue(2);
	myQueue.addQueue(10);
	myQueue.addQueue(22);
	
	std::cout << "My queue before replaceItem: ";
	myQueue.printQueue();
	std::cout << std::endl;
	
	replaceItem(myQueue, 2, 8);
	
	std::cout << "My queue after replaceItem: ";
	myQueue.printQueue();
	std::cout << std::endl;
}

void test_replaceEverySecondItem()
{
	// Test case 0: Provided in exam question
	queueType<int> myQueue;
	
	// add elements to queue
	myQueue.addQueue(1);
	myQueue.addQueue(3);
	myQueue.addQueue(4);
	myQueue.addQueue(6);
	myQueue.addQueue(7);
	myQueue.addQueue(8);
	myQueue.addQueue(2);
	
	std::cout << "My queue before replaceEverySecondItem: ";
	myQueue.printQueue();
	
	replaceEverySecondItem(myQueue, 0);
	std::cout << "My queue after replaceEverySecondItem: ";
	myQueue.printQueue();
	
	// Test case 1: Test the function with an empty queue.
	queueType<int> q;
	replaceEverySecondItem(q, 0);
	assert(q.count == 0);

	// Test case 2: Test the function with a queue containing only one element.
	q.addQueue(1);
	replaceEverySecondItem(q, 0);
	assert(q.count == 1);
	assert(q.front() == 1);

	// Test case 3: Test the function with a queue containing two elements.
	q.addQueue(2);
	replaceEverySecondItem(q, 0);
	assert(q.count == 2);
	assert(q.front() == 1);
	q.deleteQueue();
	assert(q.front() == 0);

	// FIXME: Test case 4 causes replaceEverySecondItem to fail
	// Test case 4: Test the function with a queue containing an odd number of elements.
	q.addQueue(3);
	q.addQueue(4);
	q.addQueue(5);
	replaceEverySecondItem(q, 0);
	assert(q.count == 5);
	assert(q.front() == 1);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 4);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 5);


	// Test case 5: Test the function with a queue containing an even number of elements.
	q.addQueue(6);
	q.addQueue(7);
	q.addQueue(8);
	q.addQueue(9);
	replaceEverySecondItem(q, 0);
	assert(q.count == 8);
	assert(q.front() == 1);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 4);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 5);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 8);
	q.deleteQueue();
	assert(q.front() == 0);

	// Test case 6: Test the function with a queue containing all the same elements.
	q.addQueue(9);
	q.addQueue(9);
	q.addQueue(9);
	q.addQueue(9);
	replaceEverySecondItem(q, 0);
	assert(q.count == 8);
	assert(q.front() == 9);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 9);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 9);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 9);
	q.deleteQueue();
	assert(q.front() == 0);

	// Test case 7: Test the function with a queue containing all different elements.
	q.addQueue(1);
	q.addQueue(2);
	q.addQueue(3);
	q.addQueue(4);
	replaceEverySecondItem(q, 0);
	assert(q.count == 8);
	assert(q.front() == 1);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 3);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 4);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 1);
	q.deleteQueue();
	assert(q.front() == 0);
	
	// Test case 8: Test the function with a queue containing a mix of different elements.
	q.addQueue(5);
	q.addQueue(6);
	q.addQueue(7);
	q.addQueue(8);
	replaceEverySecondItem(q, 0);
	assert(q.count == 8);
	assert(q.front() == 5);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 7);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 8);
	q.deleteQueue();
	assert(q.front() == 0);
	q.deleteQueue();
	assert(q.front() == 5);
	q.deleteQueue();
	assert(q.front() == 0);

	// Test case 9: Test the function with a queue containing a mix of different elements and the new item value equal to the minimum value.
	q.addQueue(1);
	q.addQueue(2);
	q.addQueue(3);
	q.addQueue(4);
	replaceEverySecondItem(q, std::numeric_limits<int>::min());
	assert(q.count == 8);
	assert(q.front() == 1);
	q.deleteQueue();
	assert(q.front() == std::numeric_limits<int>::min());
	q.deleteQueue();
	assert(q.front() == 3);
	q.deleteQueue();
	assert(q.front() == std::numeric_limits<int>::min());
	q.deleteQueue();
	assert(q.front() == 4);
	q.deleteQueue();
	assert(q.front() == std::numeric_limits<int>::min());
	q.deleteQueue();
	assert(q.front() == 1);
	q.deleteQueue();
	assert(q.front() == std::numeric_limits<int>::min());

	// Test case 10: Test the function with a queue containing a mix of different elements and the new item value equal to the maximum value.
	q.addQueue(1);
	q.addQueue(2);
	q.addQueue(3);
	q.addQueue(4);
	replaceEverySecondItem(q, std::numeric_limits<int>::max());
	assert(q.count == 8);
	assert(q.front() == 1);
	q.deleteQueue();
	assert(q.front() == std::numeric_limits<int>::max());
	q.deleteQueue();
	assert(q.front() == 3);
	q.deleteQueue();
	assert(q.front() == std::numeric_limits<int>::max());
	q.deleteQueue();
	assert(q.front() == 4);
	q.deleteQueue();
	assert(q.front() == std::numeric_limits<int>::max());
	q.deleteQueue();
	assert(q.front() == 1);
	q.deleteQueue();
	assert(q.front() == std::numeric_limits<int>::max());
	
	std::cout << "All test cases passed for replaceEverySecondItem!\n";
}


int main()
{
//	test_replaceEverySecondItem();
	testIsInLanguageLQ2();
	
	return 0;
}
