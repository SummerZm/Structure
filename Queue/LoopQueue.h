#ifndef __LOOP_QUEUE_H__
#define __LOOP_QUEUE_H__
#include <iostream>
#include "Zm.h"
#include "Queue.h"

/*
 *  问题1: 循环队列相比于普通队列的优势？
 *	循环队列的出队性能是O1, 普通队列的是On
 *
 *  问题2: 如何实现队列的循环？
 *	-- 取余运算: next=(curr+1)%capacity
 *	-- 尾索引总是指向下一个空位置
 *
 *	问题3: 循环队列无size成员实现的难点？
 *	如何区分空队列与队列回绕问题
 *	-- 空队列的唯一条件时：首尾重叠。[可能为空也可能，有一个元素]
 *	-- 入队时先判断: 尾索引加1后，首尾索引是否重叠, 若重叠则扩容。
 *
 *  问题4；模板参数N<=0时的判断处理
 *
 *	性能分析:
 *	On2: 时间复杂能处理的数据量 10万 -- 几百ms
 *	On: 时间复杂能处理的数据量 100万 -- 几十ms
 * */

template <typename T, unsigned N>
class LoopQueue: public Queue<T>
{
	public:
		LoopQueue();
		virtual ~LoopQueue();

		/* stack */
		int getSize();
		int getCapacity();
		bool isEmpty();
		bool enqueue(const T&);
		T dequeue();
		T getFront();
		
		/* show */
		void display();

	protected:
		bool resize(int);

	private:
		T* m_data;
		int m_head;
		int m_tail;
		int m_capacity;
};

template <typename T, unsigned N>
LoopQueue<T, N>::LoopQueue()
{
	if(N<=0) {
		m_data = new T[1];
		m_capacity = 1;
	}
	else {
		m_data = new T[N];
		m_capacity = N;
	}
	m_head = m_tail = 0;
}

template <typename T, unsigned N>
LoopQueue<T, N>::~LoopQueue()
{
	m_head = m_tail = m_capacity= 0;
	delete[] m_data;
}

template <typename T, unsigned N>
T LoopQueue<T, N>::getFront()
{
	return m_data[m_head];
}

template <typename T, unsigned N>
bool LoopQueue<T, N>::isEmpty()
{
	return m_head==m_tail;
}

template <typename T, unsigned N>
bool LoopQueue<T, N>::resize(int capacity)
{
	int qSize = getSize();
	if (capacity <= 0 || capacity < qSize) {
		zmDebugInfo("Illegal capacity!");
		return false;
	}

	T* tmp = new T[capacity];
	int i=0, n=m_head;
	//if (qSize==0) qSize = m_capacity;
	for(; i<qSize; i++)
	{
		tmp[i] = m_data[n%m_capacity];
		n++;
	}
	m_data = tmp;
	m_head = 0;
	m_tail = i%capacity;
	zmDebugInfoResize(m_capacity, capacity);
	m_capacity = capacity;
	return true;
}

template <typename T, unsigned N>
bool LoopQueue<T, N>::enqueue(const T& element)
{
	if (m_head==(m_tail+1)%m_capacity && m_capacity >0) {
		resize(2*m_capacity);
	}
	m_data[m_tail] = element;
	m_tail = (m_tail+1) % m_capacity;
	return true;
}

template <typename T, unsigned N>
T LoopQueue<T, N>::dequeue()
{
	int size = getSize();
	if(size==0) {
		zmDebugInfo("The queue is empty! Can't dequeue!");
		exit(1);
	}

	T tmp = m_data[m_head++];
	if ( m_capacity/4 >= getSize() && m_capacity/4 >0) {
		resize(m_capacity/2);
	}
	return tmp;
}

template <typename T, unsigned N>
int LoopQueue<T, N>::getSize()
{
	if (m_head > m_tail) {
		return m_capacity-m_head + m_tail;
	}
	return m_tail-m_head;
}

template <typename T, unsigned N>
int LoopQueue<T, N>::getCapacity()
{
	return m_capacity; 
}

template <typename T, unsigned N>
void LoopQueue<T, N>::display()
{
	std::cout<<std::endl<<"== Loop Queue =="<<std::endl;
	int size = getSize();
	for (int i=0; size>0; i++) {
		std::cout<<m_data[(i+m_head)%m_capacity]<<" ";
		size--;
	}
	std::cout<<std::endl;
	std::cout<<"head: "<<m_head<<" tail "<<m_tail<<" size: "<<getSize()<<" capacity "<<getCapacity()<<std::endl;
}
#endif
