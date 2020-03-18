#include <iostream>
#include <fstream>
#include <string>
#include "BstSet.h"
#include "Array.h"
#include "LinkedSet.h"
#include "ArraySet.h"
#include "Map.h"
#include "inc/fileOperation.h"
#include "inc/timing.h"

using namespace std;

void testBstSet()
{
	int num = 1;
	BstSet<int> Bset;
	Bset.add(0);
	Bset.add(4);
	Bset.add(4);
	Bset.add(1);
	Bset.display();
	std::cout<<"Size: "<<Bset.getSize()<<std::endl;
	test();
}

void testSetPerformence(const char* filename, Set<string>& set)
{
	string s;
	ifstream file(filename);
	if(file)
	{
		int i=0;
		long start=time_msec();
		while(file>>s) {
			//std::cout<<s;
			set.add(s);
			i++;
		}
		long end=time_msec();
		//Bset.display();
		std::cout<<set.getSize()<<std::endl;
		std::cout<<"cost: "<<end-start<<" ms"<<std::endl;
		std::cout<<"size: "<<set.getSize()<<" ms"<<std::endl;
		file.close();
	}
	else {
		std::cout<<"open error"<<std::endl;
	}
}


int main(int argc, char** argv)
{
	testBstSet();
	BstSet<string> set;
	LinkedSet<string> Lset;
	ArraySet<string, 5> Aset;
	testSetPerformence("./a-tale-of-two-cities.txt", set);
	testSetPerformence("./a-tale-of-two-cities.txt", Lset);
	testSetPerformence("./a-tale-of-two-cities.txt", Aset);
	//Aset.display();
	return 0;
}
