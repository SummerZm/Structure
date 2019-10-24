#ifndef __MAP_H__
#define __MAP_H__
template<typename K, typename V>
class Map {
	void add(const K& key, const V& value);
	bool remove(const K& key);
	bool get(const K& key, V& val );
	void set(const K& key, const V& newValue);
	int getSize();
	bool isEmpty();
};
#endif
