#include <iostream>
#include <fstream>
#include "Array.h"
#include "Map.h"
#include "LinkedMap.h"
#include "BstMap.h"

void  test()
{
	std::cout<<"test fileOperation !"<<std::endl;
}

bool readFile(const char* fileName, zmArray::Array<std::string, 5ul>& words)
{
	//std::fstream file(fileName, std::ios::out);
	std::fstream file(fileName);
	if (file) {
		int i=0;
		std::string s;
		while(file>>s) {
			words.addLast(s);	
			i++;
		}
		return true;
	}
	std::cout<<"Open failed"<<std::endl;
	return false;
}


bool readFileToMap(const char* fileName, Map<std::string, int>& map) 
{
	std::fstream file(fileName);
	if(file) {
		int i=0;
		std::string s;
		while(file>>s) {
			int count = 1;
			map.add(s, count);
			i++;
		}
	}
	return true;
}






