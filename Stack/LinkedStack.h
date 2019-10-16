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
		void display();
	private:
		Linked<T> m_data;
};

template <typename T>
int LinkedStack<T>::getSize() { return m_data.getSize();}

template <typename T>
bool LinkedStack<T>::isEmpty() { return m_data.isEmpty();}

template <typename T>
void LinkedStack<T>::push(const Node<T>& element) { m_data.addFirst(element);}

template <typename T>
void LinkedStack<T>::display() { m_data.display();}

template <typename T>
Node<T> LinkedStack<T>::pop()
{
	Node<T> tmp = m_data.get(0);
	m_data.removeFirst();
	return tmp;
}

template <typename T>
Node<T> LinkedStack<T>::peek() { return m_data.get(0);}
#endif
