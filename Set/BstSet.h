#ifndef __BST_SET_H__
#define __BST_SET_H__
#include "Set.h"
#include "BinaryTree.h"
template <typename T>
class BstSet: public Set<T>, zmTree::Tree<T>
{
	public:
		void add(const T&);
		bool isEmpty();
		bool contains(const T&);
		bool remove(const T&);
		int getSize();
};

template <typename T>
void BstSet<T>::add(const T& e) {
	return zmTree::Tree<T>::add(e);
}

template <typename T>
bool BstSet<T>::isEmpty() {
	return true;
}

template <typename T>
bool BstSet<T>::contains(const T& e) 
{
	return true;
}

template <typename T>
bool BstSet<T>::remove(const T& e){return true;}

template <typename T>
int BstSet<T>::getSize() { return 1;}

#endif
