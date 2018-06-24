#include "Stack.h"

Stack::Stack() :start(nullptr){
}


Stack::Stack(const Stack& other) : start(nullptr)
{
	this->copy(other);
}


void Stack::pop()
{
	if (this->empty())
		throw "Empty stack!";

	Node* forDel = this->start;
	this->start = this->start->next;

	delete forDel;
}

void Stack::push(int const& elem)
{
	Node* newElem = new Node;
	this->start = newElem;
	start->data = elem;
	start->next = this->start;
}

void Stack::clear()
{
	Node *p;
	while (start){
		p = start;
		start = start->next;
		delete p;
	}
}

Stack::~Stack()
{
	this->clear();
}

void Stack::copy(const Stack& other)
{
	if (other.empty())
	{
		this->start = nullptr;
		return;
	}

	Node *current = other.start, *q = nullptr, *s = nullptr;
	Node *newElem = nullptr, *prev = nullptr;

	start = new Node;
	start->data = current->data;
	start->next = q;

	q = start;
	current = current->next;

	while (current)
	{
		s = new Node;
		s->data = current->data;
		q->next = s;
		q = s;
		current = current->next;
	}
	q->next = nullptr;
}
