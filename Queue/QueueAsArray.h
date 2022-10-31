#ifndef H_QueueAsArray
#define H_QueueAsArray
 
#include <iostream>
#include <cassert>
#include "QueueADT.h"




template <class Type>
class QueueType: public QueueADT<Type>
{
public:
	
    const QueueType<Type>& operator=(const QueueType<Type>&);
      //Overload the assignment operator.
	
    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty.
      //Postcondition: Returns true if the queue is empty,
      //    otherwise returns false.

    bool isFullQueue() const;
      //Function to determine whether the queue is full.
      //Postcondition: Returns true if the queue is full,
      //    otherwise returns false.

    void initializeQueue();
      //Function to initialize the queue to an empty state.
      //Postcondition: The queue is empty

    Type front() const;
      //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program
      //    terminates; otherwise, the first element of the
      //    queue is returned.

    Type back() const;
      //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program
      //    terminates; otherwise, the last element of the queue
      //    is returned.

    void addQueue(const Type& queueElement);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement is
      //    added to the queue.

    void deleteQueue();
      //Function to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first element
      //    is removed from the queue.
	
	void printQueue();
	// Print each element in the queue.
	
	
    QueueType(int queueSize = 100);
      //Constructor

    QueueType(const QueueType<Type>& otherQueue);
      //Copy constructor

    ~QueueType();
      //Destructor

private:
    int maxQueueSize; //variable to store the maximum queue size
    int count;        //variable to store the number of
                      //elements in the queue
    int queueFront;   //variable to point to the first
                      //element of the queue
    int queueRear;    //variable to point to the last
                      //element of the queue
    Type *list;       //pointer to the array that holds
                      //the queue elements
};


template <class Type>
void QueueType<Type>::printQueue()
{
	for (size_t i = 0; i < count; i++)
	{
		std::cout << *list + i << " ";
	}
	std::cout << std::endl;
}

template <class Type>
bool QueueType<Type>::isEmptyQueue() const
{
    return (count == 0);
} //end isEmptyQueue

template <class Type>
bool QueueType<Type>::isFullQueue() const
{
    return (count == maxQueueSize);
} //end isFullQueue

template <class Type>
void QueueType<Type>::initializeQueue()
{
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
} //end initializeQueue

template <class Type>
Type QueueType<Type>::front() const
{
    assert(!isEmptyQueue());
    return list[queueFront]; 
} //end front

template <class Type>
Type QueueType<Type>::back() const
{
    assert(!isEmptyQueue());
    return list[queueRear];
} //end back

template <class Type>
void QueueType<Type>::addQueue(const Type& newElement)
{
    if (!isFullQueue())
    {   
        queueRear = (queueRear + 1) % maxQueueSize; //use mod
                            //operator to advance queueRear  
                            //because the array is circular
        count++;
        list[queueRear] = newElement;
    }
    else
        std::cout << "Cannot add to a full queue." << std::endl; 
} //end addQueue

template <class Type>
void QueueType<Type>::deleteQueue()
{
    if (!isEmptyQueue())
    {   
        count--;
        queueFront = (queueFront + 1) % maxQueueSize; //use the
                        //mod operator to advance queueFront 
                        //because the array is circular 
    }
    else
        std::cout << "Cannot remove from an empty queue" << std::endl;
} //end deleteQueue



    //Constructor
template <class Type>
QueueType<Type>::QueueType(int queueSize)
{
    if (queueSize <= 0)
    {
        std::cout << "Size of the array to hold the queue must "
             << "be positive." << std::endl;
        std::cout << "Creating an array of size 100." << std::endl;

        maxQueueSize = 100;
    }
    else
        maxQueueSize = queueSize;   //set maxQueueSize to
                                    //queueSize

    queueFront = 0;                 //initialize queueFront
    queueRear = maxQueueSize - 1;   //initialize queueRear
    count = 0;
    list = new Type[maxQueueSize];  //create the array to
                                    //hold the queue elements
} //end constructor

    //Destructor
template <class Type>
QueueType<Type>::~QueueType()
{
    delete [] list;
} //end destructor

template <class Type>
const QueueType<Type>& QueueType<Type>::operator= (const QueueType<Type>& otherQueue)
{
    std::cout << "Write the definition of the function "
         << "to overload the assignment operator." << std::endl;
} //end assignment operator

template <class Type>
QueueType<Type>::QueueType(const QueueType<Type>& otherQueue)
{
    std::cout << "Write the definition of the copy constructor."
         << std::endl;
} //end copy constructor


template <class Type>
bool identicalQueue(QueueType<Type> &queue1, QueueType<Type> &queue2)
// checks whether two queues are identical.
// Postcondition: returns true if queues are identical
// otherwise returns false.
{
	if (queue1.isEmptyQueue() && queue2.isEmptyQueue())	// both queues are empty
	{
		return true;
	}

	else if (queue1.isEmptyQueue() || queue2.isEmptyQueue())	// only one queue is empty
	{
		return false;
	}

	else // both queues are not empty
	{
		if (queue1.front() != queue2.front())	// the first elements differ
		{
			return false;
		}

		// remove first element in each queue & recursive call
		queue1.deleteQueue();
		queue2.deleteQueue();
		return identicalQueue(queue1, queue2);
	}
}



#endif
