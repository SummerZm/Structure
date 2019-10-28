#include "Map.h"
#include "Array.h"
#include "LinkedMap.h"
#include "BstMap.h"
#include "inc/fileOperation.h"
#include <iostream>
#include <string>
#include <fstream>

template<typename K, typename V>
void testMapPerformence(Map<K, V>& map)
{
	using namespace std;
	long start=time_msec();
	readFileToMap("./pride-and-prejudice.txt", map);
	long end=time_msec();
	std::cout<<"Cost: "<<end-start<<" ms"<<std::endl;
	std::cout<<"Map size: "<<map.getSize()<<std::endl;
}


int main(int argc, char** argv)
{
	using namespace std;
	cout<<"Test Map"<<endl;
	zmMap::LinkedMap<string, int> lMap;
	testMapPerformence(lMap);
	zmBstMap::BstMap<string, int> BstMap;
	testMapPerformence(BstMap);

	/*zmBstMap::BstMap<std::string, int> ma;
	ma.add("2", 1);
	ma.add("3", 16);
	ma.display();*/
	return 0;
}
