#include <iostream>
#include "Linked.h"

void testLinkedList()
{
	using namespace zmLinked;
	Linked<int> linkedList;
	Node<int> node(10);
	Node<int> node1(20);
	Node<int> node2(30);
	Node<int> node3(40);

	std::cout<<std::endl<<"===== add() ======="<<std::endl;
	linkedList.add(0, node);
	linkedList.add(1, node1);
	linkedList.add(2, node2);
	linkedList.add(1, node3);

	linkedList.addFirst(node3);
	linkedList.addLast(node3);
	linkedList.display();

	std::cout<<std::endl<<"===== get() getPos() ======="<<std::endl;
	Node<int> node22 = linkedList.get(3);
	node22.display();
	node22 = linkedList.getLast();
	node22.display();
	std::cout<<linkedList.getPos(node22)<<std::endl;

	std::cout<<std::endl<<"===== set() ======="<<std::endl;
	linkedList.set(0, node);
	linkedList.set(1, node);
	linkedList.set(2, node);
	linkedList.set(3, node);
	linkedList.display();

	std::cout<<std::endl<<"===== remove() ======="<<std::endl;
	linkedList.remove(2);
	linkedList.display();
	linkedList.removeFirst();
	linkedList.display();
	linkedList.removeLast();
	linkedList.display();
	linkedList.removeLast();
	linkedList.removeFirst();
	linkedList.removeLast();
	linkedList.display();

}

// 递归删除的概念
// 什么是尾递归优化?
// 1. 函数的最后一句是纯递归调用
// 2. 递归调用的返回值不能在本函数内使用
// 符合以上标准的编译器会进行尾递归优化 [编译器布局的时候使用一个栈帧].
using namespace zmLinked;
Node<int>* recursiveDelete(Node<int>* node, int val)
{
	Node<int>* tmp = NULL;
	if(node==NULL) return node; // 递归到底时的退出条件
	node->m_next = recursiveDelete(node->m_next, val); // 递归的上下层函数迭代关系
	
	// 要处理的子问题
	if(node->m_elemet==val) {
		tmp = node->m_next;
		delete node;
	}
	else {
		tmp = node;
	}
	return  tmp;
}

void recursiveDeleteLinkedNode()
{
	using namespace zmLinked;
	int val = 5;
	int arr[] = {5,4,5,5,5,6,6,5};
	Linked<int> *p = new Linked<int>(arr, sizeof(arr)/sizeof(int));
	p->display();
	// 如何将引用转化为指针? 通过引用屏蔽了指针的复杂性，这是一个中间层编程哲学
	recursiveDelete(&(p->getFront()), val);
	p->display();
}

int main(int argc, char** argv)
{
	testLinkedList();
	recursiveDeleteLinkedNode();
	return 0;
}
