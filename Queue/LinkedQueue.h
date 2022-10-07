#ifndef H_LinkedQueue
#define H_LinkedQueue
 
#include <iostream>
#include <cassert>
#include "QueueADT.h"

//Definition of the node
template <class Type>
struct NodeType
{
    Type info;
    NodeType<Type> *link;
};

template <class Type>
class LinkedQueueType: public QueueADT<Type>
{
public:
    const LinkedQueueType<Type>& operator=
                    (const LinkedQueueType<Type>&); 
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
      //Postcondition: queueFront = NULL; queueRear = NULL

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
      //    terminates; otherwise, the last element of the
      //    queue is returned.

    void addQueue(const Type& queueElement);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement is
      //    added to the queue.

    void deleteQueue();
      //Function  to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first element
      //    is removed from the queue.
	
	void printQueue();
	// Prints each element in the queue.

    LinkedQueueType(); 
      //Default constructor

    LinkedQueueType(const LinkedQueueType<Type>& otherQueue); 
      //Copy constructor

    ~LinkedQueueType(); 
      //Destructor

private:
    NodeType<Type> *queueFront; //pointer to the front of the queue
    NodeType<Type> *queueRear;  //pointer to the rear of the queue
};


template <class Type>
void LinkedQueueType<Type>::printQueue()
{
	while (!isEmptyQueue())
	{
		std::cout << front() << " ";
		deleteQueue();
	}
	std::cout << std::endl;
}

    //Default constructor
template<class Type>
LinkedQueueType<Type>::LinkedQueueType() 
{
    queueFront = NULL; //set front to null
    queueRear = NULL;  //set rear to null
} //end default constructor

template<class Type>
bool LinkedQueueType<Type>::isEmptyQueue() const
{
    return(queueFront == NULL);
} //end 

template<class Type>
bool LinkedQueueType<Type>::isFullQueue() const
{
    return false;
} //end isFullQueue

template <class Type>
void LinkedQueueType<Type>::initializeQueue()
{
    NodeType<Type> *temp;

    while (queueFront!= NULL)  //while there are elements left
                               //in the queue
    {
        temp = queueFront;  //set temp to point to the 
                            //current node
        queueFront = queueFront->link;  //advance first to  
                                        //the next node
        delete temp;    //deallocate memory occupied by temp
    }

    queueRear = NULL;  //set rear to NULL
} //end initializeQueue


template <class Type>
void LinkedQueueType<Type>::addQueue(const Type& newElement)
{
    NodeType<Type> *newNode;

    newNode = new NodeType<Type>;   //create the node

    newNode->info = newElement; //store the info
    newNode->link = NULL;  //initialize the link field to NULL

    if (queueFront == NULL) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}//end addQueue

template <class Type>
Type LinkedQueueType<Type>::front() const
{
    assert(queueFront != NULL);
    return queueFront->info; 
} //end front

template <class Type>
Type LinkedQueueType<Type>::back() const
{
    assert(queueRear!= NULL);
    return queueRear->info;
} //end back

template <class Type>
void LinkedQueueType<Type>::deleteQueue()
{
    NodeType<Type> *temp;
   
    if (!isEmptyQueue())
    {
        temp = queueFront;  //make temp point to the 
                            //first node
        queueFront = queueFront->link; //advance queueFront 

        delete temp;    //delete the first node

        if (queueFront == NULL) //if after deletion the 
                                //queue is empty
            queueRear = NULL;   //set queueRear to NULL
    }
    else
        std::cout << "Cannot remove from an empty queue" << std::endl;
}//end deleteQueue


    //Destructor
template <class Type>
LinkedQueueType<Type>::~LinkedQueueType() 
{
    //Write the definition of the destructor
} //end destructor

template <class Type>
const LinkedQueueType<Type>& LinkedQueueType<Type>::operator=
                    (const LinkedQueueType<Type>& otherQueue)
{
    //Write the definition of to overload the assignment operator

} //end assignment operator

	//copy constructor
template <class Type>
LinkedQueueType<Type>::LinkedQueueType
                 (const LinkedQueueType<Type>& otherQueue) 
{
    //Write the definition of the copy constructor
}//end copy constructor

#endif
