#include <iostream>
#include "BSTSet.h"
using namespace std;

int main(int argc, char** argv)
{
	int num = 1;
	BstSet<int> Bset;
	Bset.add(0);
	Bset.add(4);
	Bset.add(4);
	Bset.add(1);
	Bset.display();
	std::cout<<"Size: "<<Bset.getSize()<<std::endl;
	//std::cout<<Bset.add(num)<<std::endl;
	return 0;
}
