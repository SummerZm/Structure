#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__
#include "Heap.h"
#include "Queue.h"

// 通过优先队列的出队操作，取得前N最大值
template <typename T, unsigned N>
class PriorityQueue: public Queue<T>
{
	public:
		int getSize();
		bool isEmpty();
		bool enqueue(const T&);
		T dequeue();
		T getFront();

	private:
		Heap<T, N> m_data;
};

template <typename T, unsigned N> int PriorityQueue<T, N>::getSize() { return m_data.getSize(); }
template <typename T, unsigned N> bool PriorityQueue<T, N>::isEmpty() { return m_data.isEmpty(); }
template <typename T, unsigned N> bool PriorityQueue<T, N>::enqueue(const T& e) { return m_data.add(e)>=0; }
template <typename T, unsigned N> T PriorityQueue<T, N>::dequeue() { 
	T max;
	m_data.extractMax(max);
	return max;
}

template <typename T, unsigned N> T PriorityQueue<T, N>::getFront() { 
	T max;
	m_data.getMax(max);
	return max;
}
#endif
