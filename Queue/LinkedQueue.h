#ifndef __LINKED_QUEUE_H__
#define __LINKED_QUEUE_H__
#include "Queue.h"
#include "Linked.h"

using namespace zmLinked;
template <typename T>
class LinkedQueue: public Queue<Node<T>>
{
	public:
		int getSize();
		bool isEmpty();
		bool enqueue(const Node<T>&);
		Node<T> dequeue();
		Node<T> getFront();
	private:
		Linked<T> m_data;
};

template <typename T>
int LinkedQueue<T>::getSize(){return m_data.getSize();}

template <typename T>
bool LinkedQueue<T>::isEmpty() {return m_data.isEmpty();}

template <typename T>
bool LinkedQueue<T>::enqueue(const Node<T>& element) { return m_data.addLast(element);}

template <typename T>
Node<T> LinkedQueue<T>::dequeue()
{
	Node<T> tmp = m_data.get(0);
	m_data.removeFirst();
	return tmp;
}

template <typename T>
Node<T> LinkedQueue<T>::getFront(){return m_data.get(0);}
#endif
