#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__
#include "Array.h"
#include "Stack.h"

using namespace zmArray;
template <typename T, unsigned N>
class ArrayStack:public Array<T, N>, public Stack<T>
{
	public:
		int getSize();
		bool isEmpty();
		void push(const T&);
		T pop();
		T peek();
};

template <typename T, unsigned N>
int ArrayStack<T, N>::getSize() {return Array<T, N>::getSize();}

template <typename T, unsigned N>
bool ArrayStack<T, N>::isEmpty() {return Array<T, N>::getSize()<=0;}

template <typename T, unsigned N>
void  ArrayStack<T, N>::push(const T& element) { Array<T, N>::addFirst(element);}

template <typename T, unsigned N>
T  ArrayStack<T, N>::pop()
{
	T temp = Array<T, N>::get(0);
	Array<T, N>::removeFirst();
	return temp;
}

template <typename T, unsigned N>
T  ArrayStack<T, N>::peek()
{
	T temp = Array<T, N>::get(0);
	return temp;
}
#endif
