#include <iostream>
#include "BinaryTree.h"

int main(int argc, char** agrv)
{
	using namespace std;
	zmTree::Tree<char> t1;
	t1.add('A');
	t1.add('B');
	t1.add('C');
	t1.add('3');
	t1.add('F');
	t1.add('D');
	t1.add('1');
	t1.add('3');
	t1.add('4');
	t1.add('5');
	t1.preOrder();
	cout<<"========Right tree========="<<endl;
	t1.preOrder();
	cout<<"========Left tree========="<<endl;
	t1.preOrder();
	cout<<"========Middle========="<<endl;
	t1.inOrder();
	cout<<"========Post========="<<endl;
	t1.postOrder();
	cout<<t1.contains('1')<<endl;
	cout<<t1.contains(t1.getRootNode()->m_left, '5')<<endl;
	cout<<t1.contains(t1.getRootNode()->m_right, 'A')<<endl;
	cout<<"========LevelOrder========="<<endl;
	t1.levelOrder();
	cout<<"========Remove========="<<endl;
	/*zmTree::Node<char>* node = t1.minimum();
	cout<<"min: "<<endl;
	node->display();
	node = t1.maximum();
	cout<<"max: "<<endl;
	node->display();*/
	t1.inOrder();
	// t1.removeMin();  error: mem leak
	delete t1.removeMin();
	t1.remove('5');
	delete t1.removeMax();
	t1.inOrder();
	cout<<"========Remove========="<<endl;
	return 0;
}
	
