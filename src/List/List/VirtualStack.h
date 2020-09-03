#pragma once
#include"List.h"
template<typename ValType>
class TStack
{
public:
	virtual bool IsFull() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual void Push(ValType) = 0;
	virtual void Pop() = 0;
	virtual ValType Top() const = 0;
};


