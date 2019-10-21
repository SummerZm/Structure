#ifndef __ARRAY_SET_H__
#define __ARRAY_SET_H__
#include "Array.h"
using namespace zmArray;


template <typename T, unsigned N>
class ArraySet: public Set<T>
{
	public:
		void add(const T&);
		bool isEmpty();
		bool contains(const T&);
		bool remove(const T&);
		int getSize();
		void display();

	private:
		Array<T, N> m_data;
	
};

template <typename T, unsigned N>
void ArraySet<T, N>::add(const T& e) { if(!contains(e)) m_data.addLast(e);}

template <typename T, unsigned N>
bool ArraySet<T, N>::isEmpty() { return m_data.getSize()==0; }

template <typename T, unsigned N>
bool ArraySet<T, N>::contains(const T& e) { return m_data.pos(e)>=0; } ;

template <typename T, unsigned N>
bool ArraySet<T, N>::remove(const T& e)
{ 
	if(!contains(e)) return false;
	m_data.remove(m_data.pos(e));
	return true;
};

template <typename T, unsigned N>
int ArraySet<T, N>::getSize() { return m_data.getSize(); }

template <typename T, unsigned N>
void ArraySet<T, N>::display() { m_data.display(); };
#endif
