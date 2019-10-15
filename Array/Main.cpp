#include "assert.h"
#include <iostream>
#include "Array.h"

void testArray()
{
	using namespace std;
	using namespace zmArray;
    Array<int, 2> arr1;
	Array<int, 2> arr2;
	arr1.add(1,0);
	arr1.add(2,1);
	arr1.display();
	arr1.add(3,2);
	arr1.add(5,3);
	arr1.display();
	arr1.add(6,4);
	arr1.display();
	arr1.add(4,3);
	arr1.display();
	arr1.addFirst(0);
	arr1.addLast(7);
	arr1.display();
	arr2 = arr1;
	arr2.addLast(9);
	arr2.addLast(10);
	arr2.addLast(11);
	arr2.addLast(12);
	arr2.display();
	arr2.removeFirst();
	arr2.display();
	arr2.removeLast();
	arr2.display();
	arr2.removeFirst();
	arr2.display();
	arr2.removeLast();
	arr2.display();
	arr2.remove(2);
	arr2.remove(2);
	arr2.remove(2);
	arr2.remove(2);
	arr2.display();
	arr2.remove(1);
	arr2.remove(1);
	arr2.display();
	cout<<arr2.get(0)<<endl;
	cout<<arr2.set(100, 0)<<endl;
	cout<<arr2.get(0)<<endl;
	cout<<arr2.pos(0)<<endl;
}

int main(int argc, char** argv)
{
    testArray();
    return 0;
}
