#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__
#include "Stack.h"
#include "Linked.h"

using namespace zmLinked;
template <typename T>
class LinkedStack: public Stack<Node<T>>, public Linked<T>
{
	public:
		int getSize();
		bool isEmpty();
		void push(const Node<T>&);
		Node<T> pop();
		Node<T> peek();
};

template <typename T>
int LinkedStack<T>::getSize()
{
	return Linked<T>::getSize();
}

template <typename T>
bool LinkedStack<T>::isEmpty()
{
	return Linked<T>::isEmpty();
}

template <typename T>
void LinkedStack<T>::push(const Node<T>& element)
{
	Linked<T>::addFirst(element);
}

template <typename T>
Node<T> LinkedStack<T>::pop()
{
	Node<T> tmp = Linked<T>::get(0);
	Linked<T>::removeFirst();
	return tmp;
}

template <typename T>
Node<T> LinkedStack<T>::peek()
{
	return Linked<T>::get(0);
}
#endif
