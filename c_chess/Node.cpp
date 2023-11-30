#include "Node.h"

template <typename T>
void Node<T>::setData(T x) {
	this->data = x;
}

template <typename T>
Node<T>& Node<T>::operator = (T x) {
	this->data = x;
	return *this;
}

template <typename T>
T& Node<T>::getData() {
	return this->data;
}


template <typename T>
Node<T>::Node() {
	this->data = NULL;
	this->next = nullptr;
}

template <typename T>
Node<T>::Node(T x) {
	this->data = x;
	this->next = nullptr;
}

template <typename T>
Node<T>::~Node() {
	delete this->next;
	this->next = nullptr;
}