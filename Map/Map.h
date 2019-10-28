#ifndef __MAP_H__
#define __MAP_H__
template<typename K, typename V>
class Map {
	public:
	virtual void add(const K& key, const V& value)=0;
	virtual bool remove(const K& key)=0;
	virtual bool get(const K& key, V& val )=0;
	virtual void set(const K& key, const V& newValue)=0;
	virtual int getSize()=0;
	virtual bool isEmpty()=0;
};
#endif
