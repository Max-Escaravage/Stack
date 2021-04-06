#pragma once
#include <cassert>
#include <iostream>

template <class Type>
class stackADT
{
public:
	virtual void initializeStack() = 0;

	virtual bool isEmptyStack() const = 0;

	virtual bool isFullStack() const = 0;

	virtual void push(Type) = 0;

	virtual void pop() = 0;

	virtual Type top() const = 0;
};