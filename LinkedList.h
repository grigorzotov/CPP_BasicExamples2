#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
	int  data;
	Node *next;
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList&);
	LinkedList& operator= (const LinkedList&);
	~LinkedList();

	bool empty() const;

	int size() const;
	int calculateSize() const;

	bool getAt(int index, int& result) const;

	void insertAtBeginning(int data);//- �������� �� ������� � �������� �� �������
	void insertToEnd(int data); // - �������� �� ������� � ���� �� �������
	bool insertBefore(int index, int data); //- �������� �� ������� ����� ����� ������� � �������
	bool insertAfter(int index, int data); // - �������� �� ������� ���� ����� ������� � �������

	bool removeAt(int index); // - ���������� �� ������� �� ������ ������� � �������
	bool removeBefore(int index);// - ���������� �� ������� ����� ����� ������� � �������
	bool removeAfter(int index);

	void print() const;

private:

	void copyList(const LinkedList&);
	void deleteList();

	Node* lookup(int index) const;

	Node *root;
	int  _size;
};

#endif // LINKEDLIST_H
