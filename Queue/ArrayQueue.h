#ifndef __ARRAY_QUEUE_H__
#define __ARRAY_QUEUE_H__

#include "Array.h"
#include "Queue.h"

using namespace zmArray;
template <typename T, unsigned N>
// 使用组合不要使用多继承的方式，更合理
// class ArrayQueue: Array<T, N>, public Queue<T>
class ArrayQueue: public Queue<T>
{
	public:
		int getSize();
		bool isEmpty();
		bool enqueue(const T&);
		T dequeue();
		T getFront();
	private:
		Array<T, N> m_data;
};

template <typename T, unsigned N>
int ArrayQueue<T, N>::getSize() {return m_data.getSize();}

template <typename T, unsigned N>
bool ArrayQueue<T, N>::isEmpty(){return m_data.getSize()<=0;}

template <typename T, unsigned N>
bool ArrayQueue<T, N>::enqueue(const T& element){return m_data.addLast(element);}

template <typename T, unsigned N>
T ArrayQueue<T, N>::dequeue()
{
	T tmp = m_data.get(0);
	m_data.removeFirst();
	return tmp;
}

template <typename T, unsigned N>
T ArrayQueue<T, N>::getFront()
{
	T tmp = m_data.get(0);
	return tmp; 
}
#endif

