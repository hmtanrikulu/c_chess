#include "Node.h"
#ifndef LINKEDLIST
#define LINKEDLIST

template <typename T>
class LinkedList {
	Node<T>* head;
	int length;
public:
	int size();
	void insert(T);
	void insert(Node<T>);
	void del(int);
	T& operator[](int);
	LinkedList();
	~LinkedList();
};

#endif