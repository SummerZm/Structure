#ifndef __LINKED_QUEUE_H__
#define __LINKED_QUEUE_H__
#include "Queue.h"
#include "Linked.h"

using namespace zmLinked;
template <typename T>
class LinkedQueue: public Queue<Node<T>>, Linked<T>
{
	public:
		int getSize();
		bool isEmpty();
		bool enqueue(const Node<T>&);
		Node<T> dequeue();
		Node<T> getFront();
};

template <typename T>
int LinkedQueue<T>::getSize(){return Linked<T>::getSize();}

template <typename T>
bool LinkedQueue<T>::isEmpty() {return Linked<T>::isEmpty();}

template <typename T>
bool LinkedQueue<T>::enqueue(const Node<T>& element) { return Linked<T>::addLast(element);}

template <typename T>
Node<T> LinkedQueue<T>::dequeue()
{
	Node<T> tmp = Linked<T>::get(0);
	Linked<T>::removeFirst();
	return tmp;
}

template <typename T>
Node<T> LinkedQueue<T>::getFront(){return Linked<T>::get(0);}
#endif
