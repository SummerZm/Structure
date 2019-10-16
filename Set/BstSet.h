#ifndef __BST_SET_H__
#define __BST_SET_H__
#include "Set.h"
#include "BinaryTree.h"
template <typename T>
class BstSet: public Set<T>
{
	public:
		void add(const T&);
		bool isEmpty();
		bool contains(const T&);
		bool remove(const T&);
		int getSize();
		void display();
	private:
		zmTree::Tree<T> m_data;
};

template <typename T>
void BstSet<T>::add(const T& e) { return m_data.add(e);}

template <typename T>
bool BstSet<T>::isEmpty() { return m_data.getSize()==0;}

template <typename T>
bool BstSet<T>::contains(const T& e) { return m_data.contains(e);}

template <typename T>
bool BstSet<T>::remove(const T& e){ m_data.remove(e);}

template <typename T>
int BstSet<T>::getSize() { return m_data.getSize();}

template <typename T>
void BstSet<T>::display() {m_data.inOrder();}
#endif
