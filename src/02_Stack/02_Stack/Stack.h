#pragma once
template <class ValType>
class TStack
{
public:
	int size;
	ValType * elements;
	int top;
public:
	TStack(int _size = 15);
	TStack(const TStack&);
	~TStack();
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(ValType);
	void Pop();
	ValType Top() const;
	TStack& operator =(const TStack&);
	bool operator == (const TStack&) const;
};

template <class ValType>
TStack <ValType> ::TStack(int _size)
{
	size = _size;
	top = -1;
	elements = new ValType[size];
	for (int i = 0; i < size; i++)
		elements[i] = 0;
}
template <class ValType>
TStack <ValType> ::TStack(const TStack& a)
{
	size = a.size;
	top = a.top;
	elements = new ValType[size];
	for (int i = 0; i < size; i++)
		elements[i] = a.elements[i];
}
template <class ValType>
TStack<ValType>::~TStack()
{
	size = 0;
	top = -1;
	delete[] elements;
}
template <class ValType>
bool TStack<ValType>::IsFull() const
{
    return (top == size);
}
template <class ValType>
bool TStack <ValType> ::IsEmpty() const
{
	return (top == -1);
}
template <class ValType>
void TStack <ValType> ::Push(ValType a)
{
	if (IsFull())
		throw "Full Stack";
	elements[++top] = a;
}
template <class ValType>
void TStack <ValType> ::Pop()
{
	if (IsEmpty())
		throw "Empty Stack";
	top--;
}
template <class ValType>
ValType TStack <ValType> ::Top() const
{
	if (IsEmpty())
		throw "Empty Stack";
	return elements[top];
}
template <class ValType>
bool TStack <ValType>::operator==(const TStack& a) const
{
	int f = 0;
	if (size != a.size)
	{
		return false;
	}
		for (int i = 0; i < size; i++)
			if (elements[i] != a.elements[i])
				f = 1;
		if (f == 0) return true;
		return false;
}
template <class ValType>
TStack <ValType>& TStack <ValType>::operator =(const TStack& a)
{
	if (*this == a)
		return *this;
	if (size != a.size)
	{
		delete[] elements;
		size = a.size;
		elements = new ValType[size];
	}
	for (int i = 0; i < size; i++)
		elements[i] = a.elements[i];
	top = a.top;
	return *this;
}
