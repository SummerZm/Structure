#ifndef __QUEUE_H__
#define __QUEUE_H__
template <typename T>
class Queue {
	public:
		virtual int getSize()=0;
		virtual bool isEmpty()=0;
		virtual bool enqueue(const T&)=0;
		virtual T dequeue()=0;
		virtual T getFront()=0;
};
#endif
