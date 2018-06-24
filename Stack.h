#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "LinkedList.h" 


class Stack : public LinkedList
{
public:
	Stack();
	Stack(const Stack&);
	~Stack();

	void pop();
	void push(int const &);

	bool empty() const { return (this->start); }

private:
	Node* start;

	void copy(const Stack&);
	void clear();
};

#endif // STACK_H_INCLUDED
#pragma once
