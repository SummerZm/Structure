#ifndef __Array__
#define __Array__
#include "zm.h"
#include <cstring>
#include <iostream>

namespace zmArray 
{
	template <typename T, unsigned N> class Array;
	template <typename T, unsigned N> bool operator==(const Array<T, N>&, const Array<T, N>&);
	template <typename T, unsigned N> bool operator!=(const Array<T, N>&, const Array<T, N>&);

	template <typename T, unsigned N>
	class Array 
	{
		public:
			/* Default, copy, assignment, []*/
			Array();
			Array(const Array<T, N>&);
			virtual ~Array();
			Array<T, N>& operator=(const Array<T, N>&);
			friend bool operator==<>(const Array<T, N>&, const Array<T, N>&);
			friend bool operator!=<>(const Array<T, N>&, const Array<T, N>&);
			/* Prop*/
			int getSize();
			int getCapacity();
			bool isEmpty();
			/* Del can' t return pointer*/ 
			void remove(const unsigned);
			void removeFirst();
			void removeLast();
			/* Add */
			bool add(const T&, const unsigned);
			bool addFirst(const T&);
			bool addLast(const T&);
			/* Get/set/pos/swap */
			T get(unsigned);
			bool set(const T&, unsigned);
			int pos(const T&);
			void swap(const int&, const int&);
			/* Show*/
			char* display();

		protected:
			bool resize(const unsigned);

		private:
			T* m_data;
			unsigned m_size;
			unsigned m_capacity;
	};

	template <typename T, unsigned N>
	Array<T, N>::Array() {
		m_size = 0;
		m_capacity = N;
		m_data = new T[N];
	}

	template <typename T, unsigned N>
	Array<T, N>::Array(const Array<T, N>& arr)
	{	
		m_size = arr.m_size;
		m_capacity = arr.m_capacity;
		m_data = calloc(sizeof(T), m_capacity);
		memcpy(m_data, arr.m_data, sizeof(T)*m_capacity);
	}

	template <typename T, unsigned N>
	Array<T, N>::~Array() { delete[] m_data; }

	template<typename T, unsigned N>
	Array<T, N>& Array<T,N>::operator=(const Array<T, N>& arr)
	{
		if(*this != arr) {
			m_size = arr.m_size;
			m_capacity = arr.m_capacity;
			if(m_data) free(m_data);
			m_data = (T*)calloc(sizeof(T), m_capacity);
			memcpy(m_data, arr.m_data, sizeof(T)*m_capacity);
		}
		return *this;
	}

	template<typename T, unsigned N> 
	bool operator==(const Array<T, N>& arr1, const Array<T, N>& arr2)
	{
		if (arr1.m_size != arr2.m_size) return false;
		for (int i=0; i<arr1.m_size; i++) 
			if (arr1.m_data[i] != arr2.m_data[i])
				return false;
		return true;
	}

	template<typename T, unsigned N>
	bool operator!=(const Array<T, N>& arr1, const Array<T, N>& arr2) { return !operator==(arr1, arr2);}

	template<typename T, unsigned N>
	int Array<T, N>::getSize() { return m_size;}

	template<typename T, unsigned N>
	int Array<T, N>::getCapacity() {return m_capacity;}

	template<typename T, unsigned N>
	bool Array<T, N>::isEmpty() { return m_size==0; }
 
	template<typename T, unsigned N>
	bool Array<T, N>::resize(const unsigned capacity)
	{
		if (capacity<=m_size) {
			zmDebugInfo("Resize failed capacity<=m_size!");
			return false;
		}

		// Do not surpport String. why ??
		std::cout<<m_capacity<<" => "<<capacity<<std::endl;
		T* tmp = (T*)new T[capacity];
		for(unsigned int i=0; i<m_size; i++) {
			tmp[i] = m_data[i];
		}
		m_data = tmp;
		m_capacity = capacity;
		zmDebugInfo("Resize succss!");
		return true;
	}

	template<typename T, unsigned N>
	void Array<T, N>::remove(const unsigned pos)
	{
		if (pos>=0 && pos<m_size) {
			for (unsigned int i=pos; i<m_size; i++) m_data[i] = m_data[i+1]; 
			if (--m_size<m_capacity/4 && m_capacity/4>0) resize(m_capacity/2);
		}
	}

	template<typename T, unsigned N>
	void Array<T, N>::removeFirst() { remove(0); }

	template<typename T, unsigned N>
	void Array<T, N>::removeLast() { remove(m_size-1); }

	template<typename T, unsigned N>
	bool Array<T, N>::add(const T& val, const unsigned pos)
	{
		if (pos>=0 && pos<=m_size) {
			if (m_size == m_capacity) resize(m_capacity*2);
			for (unsigned i=m_size; i>pos; i--) { m_data[i] = m_data[i-1]; }
			m_data[pos] = val;
			m_size++;
			return true;
		}
		return false;
	}

	template<typename T, unsigned N>
	bool Array<T, N>::addFirst(const T& val) { return add(val, 0); }

	template<typename T, unsigned N>
	bool Array<T, N>::addLast(const T& val) { return add(val, m_size);}

	template<typename T, unsigned N>
	T Array<T, N>::get(unsigned pos) { if(pos>=0 && pos<m_size) return m_data[pos]; }

	template<typename T, unsigned N>
	bool Array<T, N>::set(const T& val, unsigned pos) {if(pos>=0 && pos<m_size) m_data[pos]=val; return true;}

	template<typename T, unsigned N>
	int Array<T, N>::pos(const T& val) 
	{ 
		for(int i=0; i<m_size; i++)
			if(m_data[i]==val) return i;
		return -1;
	}

	template<typename T, unsigned N>
	char* Array<T, N>::display()
	{
		for(int i=0; i<m_size; i++)
			std::cout<<m_data[i]<<" ";
		std::cout<<std::endl<<"Capacity: "<<m_capacity<<" Size: "<<m_size<<std::endl;
		return NULL;
	}

	template<typename T, unsigned N>
	void Array<T, N>::swap(const int& i, const int& j)
	{
		if(i>=0 && i<m_size && j>=0 && j<m_size) {
			T tmp = m_data[i];
			m_data[i] = m_data[j];
			m_data[j] = tmp;
		}
	}
}
#endif
