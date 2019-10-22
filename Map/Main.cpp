#include "Map.h"
#include "Array.h"
#include "LinkedMap.h"
#include "inc/fileOperation.h"
#include <iostream>
#include <string>
#include <fstream>

template<typename K, typename V>
void testMapPerformence(Map<K, V>& map)
{
	zmArray::Array<std::string, 5> words;
	readFile("./pride-and-prejudice.txt", words);
	std::cout<<"Array size: "<<words.getSize()<<std::endl;
	long start=time_msec();
	long end=time_msec();
	std::cout<<"Cost: "<<end-start<<std::endl;
	//words.display();
}


int main(int argc, char** argv)
{
	using namespace std;
	cout<<"Test Map"<<endl;
	zmMap::LinkedMap<string, int> lMap;
	testMapPerformence(lMap);
}
