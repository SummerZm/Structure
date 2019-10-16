#include <iostream>
#include "Array.h"
#include "LoopQueue.h"
#include "ArrayQueue.h"
#include "Linked.h"
#include "LinkedQueue.h"

//using namespace zmLinked;
template <typename T>
void testQueue(Queue<T>& q)
{
	int loop =100000;
	long start=time_msec();
	//std::cout<<"Start time (cpu-ns): "<<cpu_nsec()<<std::endl;
	//std::cout<<"Start time (time-ms): "<<time_msec()<<std::endl;
	for(int i=0; i<loop; i++)
		q.enqueue(loop);
		//q.enqueue(random_rang(0, loop));
	for(int i=0; i<loop; i++)
		q.dequeue();
	long end=time_msec();
	//std::cout<<"End time (cpu-ns): "<<cpu_nsec()<<std::endl;
	//std::cout<<"End time (time-ms): "<<time_msec()<<std::endl;
	std::cout<<"cost time: "<<end-start<<"ms "<<std::endl;
}

void testQueuePerformance()
{
	using namespace std;
	ArrayQueue<unsigned int, 1> Aq;
	LoopQueue<unsigned int, 0> Lq;
	LinkedQueue<unsigned>Linkedq;
	cout<<"==== ArrayQueue ===="<<endl;
	testQueue(Aq);
	cout<<"==== LoopQueue ===="<<endl;
	testQueue(Lq);
	cout<<"==== LinkedQueue ===="<<endl;
	testQueue(Linkedq);
}

int main(int argc, char** argv)
{
	testQueuePerformance();
	return 0;
}
