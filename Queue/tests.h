//
//  tests.h
//  Queue
//
//  Created by Mitch Campbell on 2023/02/13.
//

#ifndef tests_h
#define tests_h

// L = {a^n b^n}
static void testIsInLanguageLQ()
{
	std::string empty = "";
	std::string a = "a";
	std::string b = "b";
	std::string ab = "ab";
	std::string aab = "aab";
	std::string abb = "abb";
	std::string aabb = "aabb";
	std::string aaaba = "aaaba";
	std::string aaabb = "aaabb";
	std::string aabbb = "aabbb";
	std::string aaabbbb = "aaabbbb";
	std::string aaaabbbbb = "aaaabbbbb";
	std::string aaaabbbbba = "aaaabbbbba";
	std::string aaababbbbb = "aaababbbbb";
	assert(isInLanguageLQ(empty) == false);
	assert(isInLanguageLQ(a) == false);
	assert(isInLanguageLQ(b) == false);
	assert(isInLanguageLQ(ab) == true);
	assert(isInLanguageLQ(aab) == false);
	assert(isInLanguageLQ(abb) == false);
	assert(isInLanguageLQ(aabb) == true);
	assert(isInLanguageLQ(aaaba) == false);
	assert(isInLanguageLQ(aaabb) == false);
	assert(isInLanguageLQ(aabbb) == false);
	assert(isInLanguageLQ(aaabbbb) == false);
	assert(isInLanguageLQ(aaaabbbbb) == false);
	assert(isInLanguageLQ(aaaabbbbba) == false);
	assert(isInLanguageLQ(aaababbbbb) == false);
	
}

// test case: COS2611-06-2020: Q4.1
// L2 = {a^n b^n+1}
static void testIsInLanguageLQ2()
{
	std::string empty = "";
	std::string a = "a";
	std::string b = "b";
	std::string ab = "ab";
	std::string aab = "aab";
	std::string abb = "abb";
	std::string aabb = "aabb";
	std::string aaaba = "aaaba";
	std::string aaabb = "aaabb";
	std::string aabbb = "aabbb";
	std::string aaabbbb = "aaabbbb";
	std::string aaaabbbbb = "aaaabbbbb";
	std::string aaaabbbbba = "aaaabbbbba";
	std::string aaababbbbb = "aaababbbbb";
	assert(isInLanguageLQ2(empty) == false);
	assert(isInLanguageLQ2(a) == false);
	assert(isInLanguageLQ2(b) == false);
	assert(isInLanguageLQ2(ab) == false);
	assert(isInLanguageLQ2(aab) == false);
	assert(isInLanguageLQ2(abb) == true);
	assert(isInLanguageLQ2(aabb) == false);
	assert(isInLanguageLQ2(aaaba) == false);
	assert(isInLanguageLQ2(aaabb) == false);
	assert(isInLanguageLQ2(aabbb) == true);
	assert(isInLanguageLQ2(aaabbbb) == true);
	assert(isInLanguageLQ2(aaaabbbbb) == true);
	assert(isInLanguageLQ2(aaaabbbbba) == false);
	assert(isInLanguageLQ2(aaababbbbb) == false);
	
}

// L = {a^n b^n-1}
static void testIsInLanguageLQ3()
{
	std::string empty = "";
	std::string a = "a";
	std::string b = "b";
	std::string ab = "ab";
	std::string aab = "aab";
	std::string abb = "abb";
	std::string aabb = "aabb";
	std::string aaaba = "aaaba";
	std::string aaabb = "aaabb";
	std::string aabbb = "aabbb";
	std::string aaabbbb = "aaabbbb";
	std::string aaaabbbbb = "aaaabbbbb";
	std::string aaaabbbbba = "aaaabbbbba";
	std::string aaababbbbb = "aaababbbbb";
	assert(isInLanguageLQ3(empty) == false);
	assert(isInLanguageLQ3(a) == true);
	assert(isInLanguageLQ3(b) == false);
	assert(isInLanguageLQ3(ab) == false);
	assert(isInLanguageLQ3(aab) == true);
	assert(isInLanguageLQ3(abb) == false);
	assert(isInLanguageLQ3(aabb) == false);
	assert(isInLanguageLQ3(aaaba) == false);
	assert(isInLanguageLQ3(aaabb) == true);
	assert(isInLanguageLQ3(aabbb) == false);
	assert(isInLanguageLQ3(aaabbbb) == false);
	assert(isInLanguageLQ3(aaaabbbbb) == false);
	assert(isInLanguageLQ3(aaaabbbbba) == false);
	assert(isInLanguageLQ3(aaababbbbb) == false);
	
	
}

static void testIdenticalQueue()
{
	//	Test case 1: both queues are empty
	{
		queueType<int> queue1, queue2;
		bool result = identicalQueue(queue1, queue2);
		assert(result == true);
	}
	
	// Test case 2: One queue is empty
	{
		queueType<int> queue1, queue2;
		queue1.addQueue(10);
		bool result = identicalQueue(queue1, queue2);
		assert(result == false);
	}
	
	// Test case 3: Both queues contain the same elements
	{
		queueType<int> queue1, queue2;
		queue1.addQueue(10);
		queue1.addQueue(20);
		queue1.addQueue(30);
		queue2.addQueue(10);
		queue2.addQueue(20);
		queue2.addQueue(30);
		bool result = identicalQueue(queue1, queue2);
		assert(result == true);
	}
	
	// Test case 4: The queues contain different elements
	{
		queueType<int> queue1, queue2;
		queue1.addQueue(10);
		queue1.addQueue(20);
		queue1.addQueue(30);
		queue2.addQueue(10);
		queue2.addQueue(40);
		queue2.addQueue(30);
		bool result = identicalQueue(queue1, queue2);
		assert(result == false);
	}
	
	// Test case 5: The queues are different sizes
	{
		queueType<int> queue1, queue2;
		queue1.addQueue(10);
		queue1.addQueue(20);
		queue2.addQueue(10);
		bool result = identicalQueue(queue1, queue2);
		assert(result == false);
	}
	
	// Test case 6: Identical queues with char elements
	queueType<char> queue1, queue2;
	queue1.addQueue('a');
	queue1.addQueue('b');
	queue1.addQueue('c');
	queue2.addQueue('a');
	queue2.addQueue('b');
	queue2.addQueue('c');
	bool result = identicalQueue(queue1, queue2);
	assert(result == true);
}

static void testIdenticalQueueIterative()
{
	//	Test case 1: both queues are empty
	{
		queueType<int> queue1, queue2;
		bool result = identicalQueueIterative(queue1, queue2);
		assert(result == true);
	}
	
	// Test case 2: One queue is empty
	{
		queueType<int> queue1, queue2;
		queue1.addQueue(10);
		bool result = identicalQueueIterative(queue1, queue2);
		assert(result == false);
	}
	
	// Test case 3: Both queues contain the same elements
	{
		queueType<int> queue1, queue2;
		queue1.addQueue(10);
		queue1.addQueue(20);
		queue1.addQueue(30);
		queue2.addQueue(10);
		queue2.addQueue(20);
		queue2.addQueue(30);
		bool result = identicalQueueIterative(queue1, queue2);
		assert(result == true);
	}
	
	// Test case 4: The queues contain different elements
	{
		queueType<int> queue1, queue2;
		queue1.addQueue(10);
		queue1.addQueue(20);
		queue1.addQueue(30);
		queue2.addQueue(10);
		queue2.addQueue(40);
		queue2.addQueue(30);
		bool result = identicalQueueIterative(queue1, queue2);
		assert(result == false);
	}
	
	// Test case 5: The queues are different sizes
	{
		queueType<int> queue1, queue2;
		queue1.addQueue(10);
		queue1.addQueue(20);
		queue2.addQueue(10);
		bool result = identicalQueueIterative(queue1, queue2);
		assert(result == false);
	}
	
	// Test case 6: Identical queues with char elements
	queueType<char> queue1, queue2;
	queue1.addQueue('a');
	queue1.addQueue('b');
	queue1.addQueue('c');
	queue2.addQueue('a');
	queue2.addQueue('b');
	queue2.addQueue('c');
	bool result = identicalQueueIterative(queue1, queue2);
	assert(result == true);
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

static void test_replaceEverySecondItem()
{
	// Test case 0: Provided in exam question
//	{
//		queueType<int> myQueue;
//
//		// add elements to	 queue
//		myQueue.addQueue(1);
//		myQueue.addQueue(3);
//		myQueue.addQueue(4);
//		myQueue.addQueue(6);
//		myQueue.addQueue(7);
//		myQueue.addQueue(8);
//		myQueue.addQueue(2);
//
//		std::cout << "My queue before replaceEverySecondItem: ";
//		printQueue(myQueue);
//
//		replaceEverySecondItem(myQueue, 0);
//		std::cout << "My queue after replaceEverySecondItem: ";
//		printQueue(myQueue);
//	}
	
	// Test case 1: Test the function with an empty queue.
	{
		queueType<int> emptyQueue;
		replaceEverySecondItem(emptyQueue, 0);
		assert(emptyQueue.isEmptyQueue());
	}

	// Test case 2: Test the function with a queue containing only one element.
	{
		queueType<int> singleElementQueue;
		singleElementQueue.addQueue(1);
		replaceEverySecondItem(singleElementQueue, 0);
		assert(singleElementQueue.getCount() == 1);
		assert(singleElementQueue.front() == 1);
	}

	// Test case 3: Test the function with a queue containing two elements.
	{
		queueType<int> twoElementQueue;
		twoElementQueue.addQueue(1);
		twoElementQueue.addQueue(2);
		replaceEverySecondItem(twoElementQueue, 0);
		assert(twoElementQueue.getCount() == 2);
		assert(twoElementQueue.front() == 1);
		twoElementQueue.deleteQueue();
		assert(twoElementQueue.front() == 0);
	}

	// Test case 4: Test the function with a queue containing an odd number of elements.
	{
		queueType<int> oddElementQueue;
		oddElementQueue.addQueue(1);
		oddElementQueue.addQueue(2);
		oddElementQueue.addQueue(3);
		replaceEverySecondItem(oddElementQueue, 0);
		assert(oddElementQueue.getCount() == 3);
		assert(oddElementQueue.front() == 1);
		oddElementQueue.deleteQueue();
		assert(oddElementQueue.front() == 0);
		oddElementQueue.deleteQueue();
		assert(oddElementQueue.front() == 3);
	}

	// Test case 5: Test the function with a queue containing an even number of elements.
	{
		queueType<int> evenElementQueue;
		evenElementQueue.addQueue(1);
		evenElementQueue.addQueue(2);
		evenElementQueue.addQueue(3);
		evenElementQueue.addQueue(4);
		replaceEverySecondItem(evenElementQueue, 0);
		assert(evenElementQueue.getCount() == 4);
		assert(evenElementQueue.front() == 1);
		evenElementQueue.deleteQueue();
		assert(evenElementQueue.front() == 0);
		evenElementQueue.deleteQueue();
		assert(evenElementQueue.front() == 3);
		evenElementQueue.deleteQueue();
		assert(evenElementQueue.front() == 0);
	}
	
	// Test case 6: Test the function with a queue containing all the same elements.
	{
		queueType<int> sameElementsQueue;
		sameElementsQueue.addQueue(1);
		sameElementsQueue.addQueue(1);
		sameElementsQueue.addQueue(1);
		replaceEverySecondItem(sameElementsQueue, 0);
		assert(sameElementsQueue.getCount() == 3);
		assert(sameElementsQueue.front() == 1);
		sameElementsQueue.deleteQueue();
		assert(sameElementsQueue.front() == 0);
		sameElementsQueue.deleteQueue();
		assert(sameElementsQueue.front() == 1);
		sameElementsQueue.deleteQueue();
//		assert(sameElementsQueue.front() == NULL);
	}
	
	// Test case 7: Test the function with a queue containing all different elements.
	{
		queueType<int> differentElementsQueue;
		differentElementsQueue.addQueue(1);
		differentElementsQueue.addQueue(2);
		differentElementsQueue.addQueue(3);
		replaceEverySecondItem(differentElementsQueue, 0);
		assert(differentElementsQueue.getCount() == 3);
		assert(differentElementsQueue.front() == 1);
		differentElementsQueue.deleteQueue();
		assert(differentElementsQueue.front() == 0);
		differentElementsQueue.deleteQueue();
		assert(differentElementsQueue.front() == 3);
	}

	// Test case 8: Test the function with a queue containing a mix of different elements.
	{
		queueType<int> mixElementsQueue;
		mixElementsQueue.addQueue(1);
		mixElementsQueue.addQueue(2);
		mixElementsQueue.addQueue(2);
		mixElementsQueue.addQueue(3);
		replaceEverySecondItem(mixElementsQueue, 0);
		assert(mixElementsQueue.getCount() == 4);
		assert(mixElementsQueue.front() == 1);
		mixElementsQueue.deleteQueue();
		assert(mixElementsQueue.front() == 0);
		mixElementsQueue.deleteQueue();
		assert(mixElementsQueue.front() == 2);
		mixElementsQueue.deleteQueue();
		assert(mixElementsQueue.front() == 0);
	}

	// Test case 9: Test the function with a queue containing a mix of different elements and the new item value equal to the minimum value.
	{
		queueType<int> mixElementsMinQueue;
		mixElementsMinQueue.addQueue(1);
		mixElementsMinQueue.addQueue(2);
		mixElementsMinQueue.addQueue(2);
		mixElementsMinQueue.addQueue(3);
		replaceEverySecondItem(mixElementsMinQueue, std::numeric_limits<int>::min());
		assert(mixElementsMinQueue.getCount() == 4);
		assert(mixElementsMinQueue.front() == 1);
		mixElementsMinQueue.deleteQueue();
		assert(mixElementsMinQueue.front() == std::numeric_limits<int>::min());
		mixElementsMinQueue.deleteQueue();
		assert(mixElementsMinQueue.front() == 2);
		mixElementsMinQueue.deleteQueue();
		assert(mixElementsMinQueue.front() == std::numeric_limits<int>::min());
	}

	// Test case 10: Test the function with a queue containing a mix of different elements and the new item value equal to the maximum value.
	{
		queueType<int> mixElementsMaxQueue;
		mixElementsMaxQueue.addQueue(1);
		mixElementsMaxQueue.addQueue(2);
		mixElementsMaxQueue.addQueue(2);
		mixElementsMaxQueue.addQueue(3);
		replaceEverySecondItem(mixElementsMaxQueue, std::numeric_limits<int>::max());
		assert(mixElementsMaxQueue.getCount() == 4);
		assert(mixElementsMaxQueue.front() == 1);
		mixElementsMaxQueue.deleteQueue();
		assert(mixElementsMaxQueue.front() == std::numeric_limits<int>::max());
		mixElementsMaxQueue.deleteQueue();
		assert(mixElementsMaxQueue.front() == 2);
		mixElementsMaxQueue.deleteQueue();
		assert(mixElementsMaxQueue.front() == std::numeric_limits<int>::max());
	}
}


#endif /* tests_h */
