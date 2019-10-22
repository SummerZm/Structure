#ifndef __LINKED_MAP_H__
#define __LINKED_MAP_H__
#include "Map.h"
#include <cstdlib>
#include "zm.h"

namespace zmMap 
{
	
	template <typename K, typename V> class Node;
	template <typename K, typename V> bool operator==(const Node<K, V>&, const Node<K, V>&);
	template <typename K, typename V> bool operator!=(const Node<K, V>&, const Node<K, V>&);

	template <typename K, typename V>
	class Node {
		public: 
			Node();
			Node(const K& , const V&);
			Node(const Node<K, V>&);
			~Node();
			K getKey();
			V getVal();
			Node<K, V>* getNext();
			bool setVal(const V&);
			friend bool operator== <>(const Node<K, V>&, const Node<K, V>&);
			friend bool operator!= <>(const Node<K, V>&, const Node<K, V>&);

		private:
			K m_key;
			V m_val;
			Node<K, V>* m_next;
	};

	template <typename K, typename V>
	Node<K, V>::Node() { m_next = NULL;}

	template <typename K, typename V>
	Node<K, V>::Node(const K& key, const V& val) : m_key(key), m_val(val), m_next(NULL) {}

	template <typename K, typename V>
	Node<K, V>::Node(const Node<K, V>& node) {
		m_key = node.getKey();		
		m_val = node.getVal();
		m_next = NULL;
	} 

	template <typename K, typename V>
	bool operator==(const Node<K, V>& n1, const Node<K, V>& n2)
	{
		if (n1.m_key==n2.m_key && n1.m_val==n2.m_val) return true;
		return false;
	}

	template <typename K, typename V>
	bool operator!=(const Node<K, V>& n1, const Node<K, V>& n2) { return !operator==(n1, n2);}

	template <typename K, typename V>
	Node<K, V>::~Node() { m_next = NULL;}

	template <typename K, typename V>
	K Node<K, V>::getKey() { return m_key; } 

	template <typename K, typename V>
	V Node<K, V>::getVal() { return m_val; }

	template <typename K, typename V>
	Node<K, V>* Node<K, V>::getNext() { return m_next;}

	template <typename K, typename V>
	bool Node<K, V>::setVal(const V& val) { return m_val=val; }

	template <typename K, typename V>
	class LinkedMap: public Map<K, V>
	{
		public:
			LinkedMap();
			LinkedMap(const Node<K,V>&);
			LinkedMap(const K&, const V&);
			~LinkedMap();
			void add(const K& key, const V& value);
			bool remove(const K& key);
			bool get(const K& get, V& val);
			void set(const K& key, const V& newValue);
			int getSize();
			bool isEmpty();

		protected:
			bool contains(const Node<K, V>&);
			bool contains(const K&, const V&);
			Node<K, V>* getNode(const K&);
		
		private:
			Node<K, V> *m_data;
			int m_size;
	};

	template <typename K, typename V>
	LinkedMap<K, V>::LinkedMap(): m_data(NULL), m_size(0) {} 

	template <typename K, typename V>
	LinkedMap<K, V>::LinkedMap(const Node<K, V>& data) {
		m_data = new Node<K, V>(data);
		m_size = 1;
	} 

	template <typename K, typename V>
	LinkedMap<K, V>::LinkedMap(const K& key, const V& val) {
		m_data = new Node<K, V>(key, val);
		m_size = 1;
	}

	template <typename K, typename V>
	LinkedMap<K, V>::~LinkedMap() {
		Node<K, V> *cursor = m_data;
		while(cursor) {
			cursor = cursor->getNext();
			delete m_data;
			m_data = cursor;
		}
		m_size = 0;
	}

	template <typename K, typename V>
	bool LinkedMap<K, V>::contains(const K& key, const V& val) { 
		bool ret = false;
		Node<K, V> node = new Node<K, V>(key, val);
		if(node) ret = contains(node);
		delete node;
		return ret;
	}

	template <typename K, typename V>
	bool LinkedMap<K, V>::contains(const Node<K, V>& node) { 
		Node<K, V> *cursor = m_data;
		while(cursor) {
			if(*cursor == node) return true;
			cursor = cursor->getNext();
		}
		return false;
	}

	template <typename K, typename V>
	Node<K, V>* LinkedMap<K, V>::getNode(const K& key) {
		Node<K, V>* cursor = m_data;
		while(cursor) {
			if(cursor->getKey() == key) return cursor;
			cursor = cursor->getNext();
		}
		return NULL;
	}

	template <typename K, typename V>
	void LinkedMap<K, V>::add(const K& key, const V& value) {
		if(contains(key, value)) return;
		Node<K, V> node = new Node<K, V>(key, value);
		if (node) {
			if(m_data) node->getNext = m_data;
			m_data = node;
		}
		else {
			zmDebugInfo("LinkedMap add failed!")
			exit(1);
		}
	}

	template <typename K, typename V>
	bool LinkedMap<K, V>::remove(const K& key) {
		Node<K, V> *cursor = m_data;
		if(!cursor) return false;
		if(cursor->getKey() == key)	{
			delete cursor;
			m_data = cursor = NULL;
			return true;
		}	
		while(cursor->getNext()) {
			if(cursor->getNext()->getKey() == key) {
				Node<K, V> *tmp = cursor->getNext();
				cursor->getNext()= tmp->getNext();	
				delete tmp;
				return true;
			}
			cursor = cursor->getNext();
		}
		return false;
	}

	template <typename K, typename V>
	bool LinkedMap<K, V>::get(const K& key, V& val) {
		const Node<K, V> *node = getNode(key);
		if (node) {
			val = node->getVal();
			return true;
		}
		return false;
	}

	template <typename K, typename V>
	void LinkedMap<K, V>::set(const K& key, const V& newValue) {
		Node<K, V> *node = getNode(key);
		if (node) node->setVal(newValue);
	}

	template <typename K, typename V>
	int LinkedMap<K, V>::getSize() { return m_size; }

	template <typename K, typename V>
	bool LinkedMap<K, V>::isEmpty() { return getSize()==0;}

};
#endif







