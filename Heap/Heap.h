#ifndef __HEAP_H__
#define __HEAP_H__
#include <iostream>
#include "Array.h"
template <typename T, unsigned N>
class Heap
{
	public:
		int getCapacity();
		int getSize();
		int isEmpty();
		int add(const T&);
		void inOrder(); // just for fun
		void display();

	protected:
		int shiftUp(int&);
		int parent(const int&);
		int leftChild(const int&);
		int rightChild(const int&);
		void inOrder(int);

	private:	
		zmArray::Array<T, N> m_data;	
};

template <typename T, unsigned N> int Heap<T, N>::getCapacity() { return m_data.getCapacity();}
template <typename T, unsigned N> int Heap<T, N>::getSize() { return m_data.getSize(); }
template <typename T, unsigned N> int Heap<T, N>::isEmpty() { return m_data.isEmpty(); }
template <typename T, unsigned N> int Heap<T, N>::parent(const int& index) { return (index-1)/2; }
template <typename T, unsigned N> int Heap<T, N>::leftChild(const int& index) { return index*2+1; }
template <typename T, unsigned N> int Heap<T, N>::rightChild(const int& index) { return index*2+2; }
template <typename T, unsigned N>
int Heap<T, N>::add(const T& element) {
	m_data.addLast(element);
	int pos = m_data.getSize()-1;
	return shiftUp(pos);
}

template <typename T, unsigned N>
int Heap<T, N>::shiftUp(int& pos) {
	int parentPos = parent(pos);
	while(pos>0 && m_data.get(pos) > m_data.get(parentPos)) {
		//std::cout<<pos<<"=>"<<parentPos<<std::endl;
		m_data.swap(pos, parentPos);
		pos = parentPos;
		parentPos = parent(pos);
	}
	return pos;
}

template <typename T, unsigned N>
void Heap<T, N>::inOrder(int index)
{
	int size = m_data.getSize();
	int left = leftChild(index);
	int right = rightChild(index);
	if ( index>size ) return;
	if ( left<size ) inOrder(left);
	std::cout<<"index: "<<index<<"val: "<<m_data.get(index)<<std::endl;
	if (right < size) inOrder(right);
}

template <typename T, unsigned N> void Heap<T, N>::inOrder() { inOrder(0); }
template <typename T, unsigned N> void Heap<T, N>::display() { m_data.display(); }

#endif
