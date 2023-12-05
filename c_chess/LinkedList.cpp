#include "LinkedList.h"

template <typename T>
int LinkedList<T>::size() {
	return this->length;
}

template <typename T>
T LinkedList<T>::get(int x) {
	Node<T>* iterator = this->head;
	int count;	
}

template <typename T>
void LinkedList<T>::insert(T x) {
	Node<T>* newElement = new Node<T>(x);
	if (this->head == nullptr) {
		this->head = newElement;
		this->length += 1;
	}
	else {
		Node<T>* tmp = this->head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = newElement;
		this->length += 1;
	}
}

template <typename T>
void LinkedList<T>::insert(Node<T> x) {
	if (this->head == nullptr) {
		this->head = &x;
		this->length += 1;
	}
	else {
		Node<T>* tmp = this->head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = &x;
		this->length += 1;
	}
}

template <typename T>
void LinkedList<T>::del(int x) {
	if ((x > (this->length - 1)) || (x < 0)) throw runtime_error("Out of Boundry");
	else {
		Node<T>* iterator = this->head;
		Node<T>* nextIterator = this->head;
		for (int i = 0; i < x; i++) {
			nextIterator = nextIterator->next;
			if (i < x - 1) {
				iterator = iterator->next;
			}
		}
		if (x == 0) {
			if (this->length == 1) {
				delete iterator;
				this->head = nullptr;
			}
			else {
				this->head = iterator->next;
			}
		}
		else {
			iterator->next = nextIterator->next;
		}
	}
	this->length -= 1;
}

template <typename T>
T& LinkedList<T>::operator [] (int x) {
	if ((x > (this->length - 1)) || (x < 0)) throw runtime_error("Out of Boundry");
	else {
		Node<T>* iterator = this->head;
		for (int i = 0; i < x; i++) {
			iterator = iterator->next;
		}
		return *iterator.getData();
	}
}

template <typename T>
LinkedList<T>::LinkedList() {
	this->head = nullptr;
	this->length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	delete this->head;
	this->head = nullptr;
}
