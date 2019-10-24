#ifndef __TREE_H__
#define __TREE_H__
#include "LinkedQueue.h"

namespace zmTree 
{
	template <typename T> class Node;
	template <typename T> bool operator<(const Node<T>& n1, const Node<T>& n2) { return n1.m_data<n2.m_data; }
	template <typename T> bool operator>(const Node<T>& n1, const Node<T>& n2) { return n1.m_data>n2.m_data; }
	template <typename T> bool operator==(const Node<T>& n1, const Node<T>& n2) { return n1.m_data==n2.m_data;}

	template <typename T> 
	class Node
	{
		public:
			Node();
			Node(const T&);
			Node(const Node<T>&);
			virtual ~Node();
			void display() const;
			friend bool operator< <>(const Node<T>&, const Node<T>&);
			friend bool operator> <>(const Node<T>&, const Node<T>&);
			friend bool operator==<>(const Node<T>&, const Node<T>&);

		public:
			T m_data;
			Node<T>* m_left;
			Node<T>* m_right;
	};

	template <typename T>
	Node<T>::Node() { m_left = NULL; m_right = NULL;}

	template <typename T>
	Node<T>::~Node() { 
		m_left = m_right = NULL; 
		//std::cout<<"Delete node: "<<m_data<<std::endl;
	}

	template <typename T>
	Node<T>::Node(const T& data) { m_data = data; m_left = NULL; m_right = NULL;}

	template <typename T>
	Node<T>::Node(const Node<T>& node) { m_data = node.m_data; m_left = NULL; m_right = NULL;}

	template <typename T>
	void Node<T>::display() const { using namespace std; cout<<" "<<m_data<<" ";}

	template <typename T>
	class Tree
	{
		public:
			Tree();
			Tree(const Node<T>&);
			~Tree();
			/*add/remove*/
			void add(const Node<T>&);
			Node<T>* add(Node<T>*, const Node<T>&);
			void remove(const Node<T>&);
			Node<T>* remove(Node<T>*, const Node<T>&);
			Node<T>* removeMin();
			Node<T>* removeMax();
			Node<T>* removeMin(Node<T>*);
			Node<T>* removeMax(Node<T>*);

			/*show*/
			void preOrder();
			void inOrder();
			void postOrder();
			void levelOrder();
			void preOrder(const Node<T>*);
			void inOrder(const Node<T>*);
			void postOrder(const Node<T>*);
			void levelOrder(const Node<T>*);
			/*get*/
			int getSize();
			Node<T>* getRootNode();
			bool contains(const Node<T>&);
			bool contains(const Node<T>* node, const Node<T>& val);
			Node<T>* minimum();
			Node<T>* maximum();
			Node<T>* minimum(const Node<T>*);
			Node<T>* maximum(const Node<T>*);

		protected:
			Node<T>* freeNode(Node<T>*);
			
		private:
			Node<T>* m_root;
			int m_size;
	};

	template <typename T>
	Tree<T>::Tree() { m_root = NULL; m_size = 0;}

	template <typename T>
	Tree<T>::Tree(const Node<T>& node) { m_root = new Node<T>(node); m_size = 0;}

	template <typename T>
	Tree<T>::~Tree() { freeNode(m_root);}

	template <typename T>
	Node<T>* Tree<T>::freeNode(Node<T>* node)
	{
		if(node==NULL) return node;
		node->m_left = freeNode(node->m_left);
		node->m_right = freeNode(node->m_right);
		if(node->m_left==NULL && node->m_right==NULL) {
			delete node;
			return NULL;
		}
		return node;
	}

	template <typename T>
	Node<T>* Tree<T>::add(Node<T>* root, const Node<T>& node)
	{
		if(root==NULL) { m_size++; return new Node<T>(node); } 
		if(node < *root)
			root->m_left = add(root->m_left, node);
		else if(node > *root) 
			root->m_right = add(root->m_right, node);
		return root;	
	}

	template <typename T>
	void Tree<T>::add(const Node<T>& val) { m_root = add(m_root, val);}

	/* Show */
	template <typename T>
	void Tree<T>::preOrder() { preOrder(m_root); std::cout<<std::endl;}

	template <typename T>
	void Tree<T>::preOrder(const Node<T>* node)
	{
		if (node==NULL) return;
		node->display();
		preOrder(node->m_left);
		preOrder(node->m_right);
	}

	template <typename T>
	void Tree<T>::inOrder() { inOrder(m_root); std::cout<<std::endl;}

	template <typename T>
	void Tree<T>::inOrder(const Node<T>* node)
	{
		if (node==NULL) return;
		inOrder(node->m_left);
		node->display();
		inOrder(node->m_right);
	}

	template <typename T>
	void Tree<T>::postOrder(const Node<T>* node)
	{
		if(node==NULL) return;
		postOrder(node->m_left);
		postOrder(node->m_right);
		node->display();
	}

	template <typename T>
	void Tree<T>::postOrder() { postOrder(m_root);std::cout<<std::endl;}

	template <typename T>
	void Tree<T>::levelOrder(const Node<T>* node)
	{
		if(node==NULL) return;
		LinkedQueue<const Node<T>*> nQueue;
		if(node->m_left) nQueue.enqueue(node->m_left);
		if(node->m_right) nQueue.enqueue(node->m_right);
		node->display();

		while (!nQueue.isEmpty()) {
			node = nQueue.dequeue().m_elemet;
			//nQueue.display();
			if(node->m_left) nQueue.enqueue(node->m_left);
			if(node->m_right) nQueue.enqueue(node->m_right);
			node->display();
		}
		return;
	}

	template <typename T>
	void Tree<T>::levelOrder() { levelOrder(m_root);std::cout<<std::endl;}

	/* Get */
	template <typename T>
	Node<T>* Tree<T>::getRootNode() { return m_root;}

	template <typename T>
	int Tree<T>::getSize() { return m_size;}

	template <typename T>
	bool Tree<T>::contains(const Node<T>& val) { return contains(m_root, val);}

	template <typename T>
	bool Tree<T>::contains(const Node<T>* node, const Node<T>& val)
	{
		if(node==NULL)
			return false;
		if(*node == val)
			return true;
		else if(*node > val)
			return contains(node->m_left, val);
		else 
			return contains(node->m_right, val);
	}

	template <typename T>
	Node<T>* Tree<T>::minimum() { return minimum(m_root);}

	template <typename T>
	Node<T>* Tree<T>::minimum(const Node<T>* node)
	{
		if(node==NULL || node->m_left==NULL) return (Node<T>*)node;
		return minimum(node->m_left);
	}

	template <typename T>
	Node<T>* Tree<T>::maximum() { return maximum(m_root);}

	template <typename T>
	Node<T>* Tree<T>::maximum(const Node<T>* node)
	{
		if(node==NULL || node->m_right==NULL) return (Node<T>*)node;
		return maximum(node->m_right);
	}

	template <typename T>
	void Tree<T>::remove(const Node<T>& val) { m_root=remove(m_root, val);}

	template <typename T>
	Node<T>* Tree<T>::remove(Node<T>* root, const Node<T>& val)
	{
		if(root==NULL) { return root; }
		if(*root>val) {
			root->m_left = remove(root->m_left, val);
			return root;
		}
		else if(*root<val) {
			root->m_right = remove(root->m_right, val);
			return root;
		}
		else {
			if(root->m_left==NULL) {
				Node<T>* rightNode = root->m_right;
				root->m_right = NULL;
				m_size--;
				delete root;
				return rightNode;
			}

			if(root->m_right==NULL) {
				Node<T>*  leftNode = root->m_left;
				root->m_left = NULL;
				m_size--;
				delete root;
				return leftNode;
			}
			
			Node<T>* node = minimum(root->m_right);
			node->m_right = removeMin(root->m_right);
			node->m_left = root->m_left;
			delete root;
			return node;
			
		}
	}

	template <typename T>
	Node<T>* Tree<T>::removeMin()
	{
		Node<T>* min = minimum();
		m_root = removeMin(m_root);
		return min;
	}

	template <typename T>
	Node<T>* Tree<T>::removeMax()
	{
		Node<T>* max = maximum();
		m_root = removeMax(m_root);
		return max;
	}

	template <typename T>
	Node<T>* Tree<T>::removeMin(Node<T>* root)
	{
		if(root==NULL) return NULL;
		if(root->m_left == NULL) {
			Node<T>* rightNode = root->m_right;
			root->m_left = NULL;
			m_size--;
			return rightNode;
		}
		root->m_left = removeMin(root->m_left);
		return root;
	}

	template <typename T>
	Node<T>* Tree<T>::removeMax(Node<T>* root)
	{
		if(root==NULL) return NULL;
		if(root->m_right==NULL) {
			Node<T>* leftNode = root->m_left;
			leftNode->m_right = NULL;
			m_size--;
			return leftNode;
		}
		root->m_right = removeMax(root->m_right);
		return root;
	}
}
#endif
