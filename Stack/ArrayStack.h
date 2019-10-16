#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__
#include "Array.h"
#include "Stack.h"

using namespace zmArray;
template <typename T, unsigned N>
class ArrayStack:public Stack<T>
{
	public:
		int getSize();
		bool isEmpty();
		void push(const T&);
		T pop();
		T peek();
		void display();

	private:
		Array<T, N> m_data;
};

template <typename T, unsigned N>
int ArrayStack<T, N>::getSize() {return m_data.getSize();}

template <typename T, unsigned N>
bool ArrayStack<T, N>::isEmpty() {return m_data.getSize()<=0;}

template <typename T, unsigned N>
void  ArrayStack<T, N>::push(const T& element) { m_data.addFirst(element);}

template <typename T, unsigned N>
void ArrayStack<T, N>::display() { m_data.display();}

template <typename T, unsigned N>
T  ArrayStack<T, N>::pop()
{
	T temp = m_data.get(0);
	m_data.removeFirst();
	return temp;
}

template <typename T, unsigned N>
T  ArrayStack<T, N>::peek()
{
	T temp = m_data.get(0);
	return temp;
}
#endif
