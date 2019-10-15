#ifndef __SET_H__
#define __SET_H__
template <typename T>
class Set {
	public:
	virtual void add(const T&)=0;
	virtual bool isEmpty()=0;
	virtual bool contains(const T&)=0;
	virtual bool remove(const T&)=0;
	virtual int getSize()=0;
};
#endif
