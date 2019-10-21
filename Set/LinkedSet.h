#ifndef __LINKED_SET
#define __LINKED_SET
#include "Set.h"
#include "Linked.h"

template <typename T>
class LinkedSet: public Set<T> {
	public:
		void add(const T&);
		bool isEmpty();
		bool contains(const T&);
		bool remove(const T&);
		int getSize();
		void display();
		
	private:
		Linked<T> m_data;
};

template <typename T>
void LinkedSet<T>::add(const T& e) { if(!contains(e)) m_data.addLast(e); } 

template <typename T>
bool LinkedSet<T>::isEmpty() { return m_data.isEmpty(); }

template <typename T>
bool LinkedSet<T>::contains(const T& e) { return m_data.contains(e); }

template <typename T>
bool LinkedSet<T>::remove(const T& e) { return m_data.remove(m_data.getPos(e)); }

template <typename T>
int LinkedSet<T>::getSize() { return m_data.getSize(); }

template <typename T>
void LinkedSet<T>::display() { m_data.display(); }

#endif
