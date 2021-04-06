#pragma once
#include "stackADT.h"

template <class Type>
class myStack
{
private:
	Type* list;
	int stackTop;
	int maxSize;

public:
	// Constructor
	myStack(int);

	// Copy Constructor
	myStack(const myStack&);

	// Destructor
	~myStack();

	void initializeStack();
	// Initializes stack to an empty state.
	// Postcondition: Sets stackTop = 0

	bool isEmptyStack() const;
	// Postcondition: 

	bool isFullStack() const;
	// Postcondition: 

	void print();
	// Postcondition: 

	void push(const Type&);
	// Postcondition: 

	void pop();
	// Postcondition: 

	Type top() const;
	// Postcondition: 

	void reverseStack(myStack<Type>&);

	const myStack<Type>& operator=
		(const myStack<Type>&);
};

template <class Type>
myStack<Type>::myStack(int size)
{
	if (size <= 0)
	{
		maxSize = 100;
	}

	maxSize = size;
	stackTop = 0;

	list = new Type[maxSize];
}

template <class Type>
myStack<Type>::myStack(const myStack& otherStack)
{
	delete[] list;

	maxSize = otherStack.maxSize;
	stackTop = otherStack.stackTop;

	list = new Type[maxSize];

	for (int count = 0; count < stackTop; count++)
		*(list + count) = *(otherStack.list + count);
}

template <class Type>
myStack<Type>::~myStack()
{
	delete[] list;
}

template <class Type>
void myStack<Type>::initializeStack()
{
	stackTop = 0;
}

template <class Type>
bool myStack<Type>::isEmptyStack() const
{
	return stackTop == 0;
}

template <class Type>
bool myStack<Type>::isFullStack() const
{
	return stackTop == maxSize;
}

template <class Type>
void myStack<Type>::print()
{
	for (int count = 0; count < stackTop; count++)
		std::cout << *(list + count) << std::endl;
}

template <class Type>
void myStack<Type>::push(const Type& item)
{
	if (stackTop == maxSize)
	{
		std::cout << "ERROR: Stack is full!\n";
	}
	else
	{
		*(list + stackTop) = item;
		stackTop++;
	}
}

template <class Type>
void myStack<Type>::pop()
{
	if (isEmptyStack())
	{
		std::cout << "ERROR: Stack is empty!\n";
	}
	else
	{
		stackTop--;
	}
}

template <class Type>
Type myStack<Type>::top() const
{
	//assert(stackTop != 0);
	return *(list + stackTop - 1);
}

template <class Type>
void myStack<Type>::reverseStack(myStack<Type>& otherStack)
{
	delete[] otherStack.list;

	otherStack.maxSize = maxSize;
	otherStack.stackTop = stackTop;

	for (int count = 0; count < stackTop; count++)
	{
		*(otherStack.list + count) = *(list + stackTop - count - 1);
	}
}

template <class Type>
const myStack<Type>& myStack<Type>::operator= (const myStack<Type>& otherStack)
{
	delete[] list;

	maxSize = otherStack.maxSize;
	stackTop = otherStack.stackTop;

	list = new Type[maxSize];

	for (int count = 0; count < stackTop; count++)
		*(list + count) = *(otherStack.list + count);

	return *this;
}