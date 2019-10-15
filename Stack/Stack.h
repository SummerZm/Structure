#ifndef __STACK_H__
#define __STACK_H__
template <typename T>
class Stack {
	public:
		virtual int getSize()=0;
		virtual bool isEmpty()=0;
		virtual void push(const T&)=0;
		virtual T pop()=0;
		virtual T peek()=0;
};


#endif
