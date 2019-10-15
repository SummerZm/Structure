#ifndef __ARRAY_QUEUE_H__
#define __ARRAY_QUEUE_H__

#include "Array.h"
#include "Queue.h"

using namespace zmArray;
template <typename T, unsigned N>
class ArrayQueue: Array<T, N>, public Queue<T>
{
	public:
		int getSize();
		bool isEmpty();
		bool enqueue(const T&);
		T dequeue();
		T getFront();
};

template <typename T, unsigned N>
int ArrayQueue<T, N>::getSize() {return Array<T, N>::getSize();}

template <typename T, unsigned N>
bool ArrayQueue<T, N>::isEmpty(){return Array<T, N>::getSize()<=0;}

template <typename T, unsigned N>
bool ArrayQueue<T, N>::enqueue(const T& element){return this->addLast(element);}

template <typename T, unsigned N>
T ArrayQueue<T, N>::dequeue()
{
	T tmp = Array<T, N>::get(0);
	Array<T, N>::removeFirst();
	return tmp; 
}

template <typename T, unsigned N>
T ArrayQueue<T, N>::getFront()
{
	T tmp = Array<T, N>::get(0);
	return tmp; 
}
#endif

