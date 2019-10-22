#ifndef __BST_MAP_H__
#define __BST_MAP_H__
template <typename K, typename V>
namespace zmBstMap 
{
	class BstMap: public Map<K, V>
	{
		public：
			void add(const K& key, const V& value);
			//V remove(const K& key);
			bool remove(const K& key);
			bool get(const K& key, V& val );
			void set(const K& key, const V& newValue);
			int getSize();
			bool isEmpty();

		private:
			Node<K, V> m_data;
	};
};



#endif
