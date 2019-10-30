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
		bool extractMax(T&);
		bool replace(T&, T&);
		bool getMax(T&);

	protected:
		int shiftUp(int&);
		void shiftDown(int);
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
template <typename T, unsigned N> bool Heap<T, N>::getMax(T& max) { 
	if(m_data.getSize() >0) {
		max = m_data.get(0);
		return true;
	}
	return false;
}

template <typename T, unsigned N> bool Heap<T, N>::extractMax(T& max) {
	if(getMax(max)) {
		m_data.swap(0, m_data.getSize()-1);
		m_data.removeLast();
		shiftDown(0);
		return true;
	}
	return false;
}
// find the max
template <typename T, unsigned N> void Heap<T, N>::shiftDown(int k) {
	while ( leftChild(k) < m_data.getSize() ) {
		int j = leftChild(k);
		if ( j+1 < m_data.getSize() && m_data.get(j) < m_data.get(j+1)) j++;
		if ( m_data.get(k) > m_data.get(j)) break;
		m_data.swap(k, j);
		k = j;
	}
}

template <typename T, unsigned N> bool Heap<T, N>::replace(T& e, T& max) {
	if ( getMax(max) ) {
		m_data.set(e, 0);
		shiftDown(0);
		return true;
	}
	return false;
}

#endif
