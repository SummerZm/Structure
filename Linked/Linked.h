#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include "zm.h"

namespace zmLinked 
{
	template <typename T> class Node;
	template <typename T>
	bool operator==(const Node<T>& n1, const Node<T>& n2)
	{
		return n1.m_elemet == n2.m_elemet;
	}

	template <typename T>
	bool operator!=(const Node<T>& n1, const Node<T>& n2)
	{
		return !(n1==n2); 
	}

	template <typename T>
	class Node
	{
		public:
			Node();
			Node(const T&);
			Node(const Node<T>&);
			virtual ~Node();
			const Node<T>& operator=(const Node<T>&);
			friend bool operator!=<>(const Node<T>&, const Node<T>&);
			friend bool operator==<>(const Node<T>&, const Node<T>&);
			void display();

		public:
			//private:
			T m_elemet;
			Node<T> *m_next;
	};

	template <typename T>
	Node<T>::Node()
	{
		m_next = NULL;
	}

	template <typename T>
	Node<T>::Node(const T& element)
	{
		m_elemet = element;
		m_next = NULL;
	}

	template <typename T>
	Node<T>::~Node()
	{
		m_next = NULL;
	}

	template <typename T>
	Node<T>::Node(const Node<T>& node)
	{
		m_elemet = node.m_elemet;
		m_next = node.m_next;
	}

	template <typename T>
	const Node<T>& Node<T>::operator=(const Node<T>& node)
	{
		if(*this != node) {
			m_elemet = node.m_elemet;
		}
		return *this;
	}

	template <typename T>
	void Node<T>::display()
	{
		std::cout<<" "<<m_elemet<<" ";
	}

	template <typename T>
	class Linked 
	{
		public:
			Linked();
			Linked(const T[], const int);
			virtual ~Linked();

			/*add*/
			bool add(int, const Node<T>&);
			bool addFirst(const Node<T>&);
			bool addLast(const Node<T>&);

			/* remove */
			bool remove(int);
			bool removeFirst();
			bool removeLast();

			/* get/pos */
			int getSize();
			Node<T> get(int);
			Node<T> getLast();
			Node<T>& getFront();
			bool set(int, const Node<T>&);
			int getPos(const Node<T>&);
			bool contains(const Node<T>&);
			bool isEmpty();

			void display();
			
		private:
			Node<T> m_head; 
			int m_size;
	};

	template <typename T>
	Linked<T>::Linked()
	{
		m_head.m_next = NULL;
		m_size = 0;
	}

	template <typename T>
	Linked<T>::Linked(const T val[], const int size)
	{
		m_size = 0;
		for(int i=0; i<size; i++)
			addLast(val[i]);
	}

	template <typename T>
	Linked<T>::~Linked()
	{
		m_head.m_next = NULL;
		m_size = 0;
	}

	template <typename T>
	bool Linked<T>::add(int pos, const Node<T>& node) 
	{
		if(pos<0 || pos>m_size) {
			zmDebugInfo("Illegal pos !");	
			return false;
		}

		/*copy*/
		Node<T>* cur = &m_head;
		Node<T>* tmp = new Node<T>();
		tmp->m_elemet = node.m_elemet;

		for(int i=0; i<pos; i++)
			if(cur!=NULL) cur = cur->m_next;	

		tmp->m_next = cur->m_next;
		cur->m_next = tmp;
		m_size++;
		return true;
	}

	template <typename T>
	bool Linked<T>::addFirst(const Node<T>& node)
	{
		return add(0, node);
	}

	template <typename T>
	bool Linked<T>::addLast(const Node<T>& node) 
	{
		return add(m_size, node);
	}

	template <typename T>
	bool Linked<T>::remove(int pos)
	{
		if(pos<0 || pos>=m_size) {
			zmDebugInfo("Illegal pos !");	
			return false;
		}

		Node<T>* cur = &m_head;
		for(int i=0; i<pos; i++)
			if(cur!=NULL) cur=cur->m_next;	
		
		Node<T>* tmp = cur->m_next;
		cur->m_next = tmp->m_next;
		m_size--;
		delete tmp;
		return true;
	}

	template <typename T>
	bool Linked<T>::removeFirst()
	{
		return remove(0);
	}

	template <typename T>
	bool Linked<T>::removeLast()
	{
		return remove(m_size-1);
	}

	template <typename T>
	int Linked<T>::getSize()
	{
		return m_size;
	}

	template <typename T>
	Node<T> Linked<T>::get(int pos)
	{
		if(pos<0 || pos>=m_size) {
			zmDebugInfo("Illegal pos !");	
			exit(1);
			//return false;
		}

		Node<T>* cur = &m_head;
		for(int i=0; i<pos; i++)
			if(cur!=NULL) cur=cur->m_next;	
		return *(cur->m_next);
	}

	template <typename T>
	Node<T> Linked<T>::getLast()
	{
		return get(m_size-1);
	}

	template <typename T>
	Node<T>& Linked<T>::getFront()
	{
		return m_head;
	}

	template <typename T>
	bool Linked<T>::set(int pos, const Node<T>& node)
	{
		if(pos<0 || pos>=m_size) {
			zmDebugInfo("Illegal pos !");	
			return false;
		}

		Node<T>* cur = &m_head;
		for(int i=0; i<pos; i++)
			if(cur!=NULL) cur=cur->m_next;	

		cur->m_next->m_elemet = node.m_elemet;
		return true;
	}


	template <typename T>
	int Linked<T>::getPos(const Node<T>& element)
	{
		Node<T>* cur = &m_head;
		for(int i=0; i<m_size; i++) {
			if(*(cur->m_next) == element)
				return i;
			cur = cur->m_next;
		}
		return -1;
	}

	template <typename T>
	bool Linked<T>::contains(const Node<T>& element)
	{
		return getPos(element)>=0;
	}

	template <typename T>
	bool Linked<T>::isEmpty()
	{
		return m_size==0;
	}

	template <typename T>
	void Linked<T>::display()
	{
		
		Node<T>* cur = m_head.m_next;
		while(cur!=NULL) {
			cur->display();
			cur = cur->m_next;
		}
		std::cout<<" "<<std::endl;
		std::cout<<"Linked size: "<<m_size<<std::endl;
	}
}
#endif
