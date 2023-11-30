#ifndef NODE
#define NODE
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
	T data;
public:
	Node<T>* next;
	void setData(T);
	Node<T>& operator = (T);
	T& getData();
	Node(T);
	Node();
	~Node();
};
#include "Node.cpp"
#endif