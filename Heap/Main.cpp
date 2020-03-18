#include "Heap.h"

void testMaxHeap()
{
	int max;
	std::cout<<"Test heap."<<std::endl;
	Heap<int, 5> intHeap;
	intHeap.add(1);
	intHeap.add(3);
	intHeap.add(2);
	intHeap.add(14);
	intHeap.add(51);
	intHeap.add(4);
	intHeap.add(5);
	intHeap.add(6);
	intHeap.add(100);
	std::cout<<"Size: "<<intHeap.getSize()<<std::endl;
	std::cout<<"Capacity: "<<intHeap.getCapacity()<<std::endl;
	intHeap.extractMax(max);
	std::cout<<"Max: "<<max<<std::endl;
	intHeap.display();
	int newVal = 13;
	intHeap.replace(newVal, max);
	std::cout<<"Max: "<<max<<std::endl;
	intHeap.display();
	intHeap.extractMax(max);
	std::cout<<"Max: "<<max<<std::endl;
	intHeap.display();
	intHeap.extractMax(max);
	std::cout<<"Max: "<<max<<std::endl;
	intHeap.display();
	intHeap.extractMax(max);
	std::cout<<"Max: "<<max<<std::endl;
	intHeap.display();
	//intHeap.inOrder();
}


int main(int argc, char** agrv)
{
	testMaxHeap();
	return 0;
}
