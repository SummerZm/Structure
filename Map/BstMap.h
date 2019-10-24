#ifndef __BST_MAP_H__
#define __BST_MAP_H__
namespace zmBstMap 
{

	template <typename K, typename V> class Node;
	template <typename K, typename V> bool operator==(const Node<K, V>&, const Node<K, V>&);
	template <typename K, typename V> bool operator!=(const Node<K, V>&, const Node<K, V>&);

	template <typename K, typename V>
	class Node
	{
		public:
			Node();
			Node(const Node<K, V>&);
			Node(const K&, const V&);
			virtual ~Node();

			/*K getKey();	// Return reference or valua make great different.
			V getVal();		// 不要返回指针或者引用，应该通过getXX返回一个备份, setXX设置数据
			Node<K, V>& getLeft();
			Node<K, V>& getRight();*/

			K getKey();	
			V getVal();
			bool setKey(const K&);	
			bool setVal(const V&);
			Node<K, V>* getLeft();
			Node<K, V>* getRight();
			bool setLeft(Node<K, V>*);
			bool setRight(Node<K, V>*);
			Node<K, V>& operator=(const Node<K, V>&); // 连续赋值
			void display();

			friend bool operator== <>(const Node<K, V>&, const Node<K, V>&);
			friend bool operator!= <>(const Node<K, V>&, const Node<K, V>&);

		private:
			K m_key;
			V m_val;
			Node<K, V> *m_left;
			Node<K, V> *m_right;
	};

	template <typename K, typename V> Node<K, V>::Node() { m_left = NULL; m_right = NULL;}
	template <typename K, typename V>
	Node<K, V>::Node(const Node<K, V>& node) 
	{ 
		m_key = node.getKey();
		m_val = node.getVal();
		m_left = node.getLeft();
		m_right = node.getRight();
	}
	template <typename K, typename V> Node<K, V>::Node(const K& key, const V& val): m_key(key), m_val(val) { m_left=NULL, m_right=NULL; } 
	template <typename K, typename V> Node<K, V>::~Node() { m_left=NULL; m_right=NULL; }
	template <typename K, typename V> K Node<K, V>::getKey() { return m_key; }
	template <typename K, typename V> V Node<K, V>::getVal() { return m_val; }
	template <typename K, typename V> bool Node<K, V>::setKey(const K& key) { return m_key=key; }
	template <typename K, typename V> bool Node<K, V>::setVal(const V& val) { return m_val=val; }
	template <typename K, typename V> Node<K, V>* Node<K, V>::getLeft() { return m_left; }
	template <typename K, typename V> Node<K, V>* Node<K, V>::getRight(){ return m_right; }
	template <typename K, typename V> bool Node<K, V>::setLeft(Node<K, V>* left) { return m_left=left; }
	template <typename K, typename V> bool Node<K, V>::setRight(Node<K, V>* right) { return m_right=right; }
	template <typename K, typename V> Node<K, V>& Node<K, V>::operator=(const Node<K, V>& node) 
	{
		m_key = node.getKey();
		m_val = node.getVal();
		m_left = node.getLeft();
		m_right = node.getRig();
		return *this;
	}
	template<typename K, typename V> void Node<K, V>::display() {
		std::cout<<"["<<m_key<<"] - ["	<< m_val <<"]"<<std::endl;
	};

	template <typename K, typename V> bool operator==(const Node<K, V>& n1, const Node<K, V>& n2) { return n1.getKey()==n2.getKey() && n1.getVal()==n2.getVal();}
	template <typename K, typename V> bool operator!=(const Node<K, V>& n1, const Node<K, V>& n2) { return n1.getKey()!=n2.getKey() || n1.getVal()!=n2.getVal();} 

	template <typename K, typename V>
	class BstMap: public Map<K, V>
	{
		public:
			BstMap();
			virtual ~BstMap();
			void add(const K& key, const V& value);
			bool remove(const K& key);
			bool get(const K& key, V& val );
			void set(const K& key, const V& newValue);
			int getSize();
			bool isEmpty();
			void display();
			void display(Node<K, V>*);

		protected:
			//bool addNode(const Node<K, V>* root, const Node<K, V>& node);
			/*Node<K, V>& addNode(Node<K, V>& root, const K& key, const V& val);
			bool getNode(const Node<K. V>& root, const K& key, Node<K, V>& node);
			Node<K, V>& getMinimumNode(const Node<K, V>& node);
			Node<K, V>& removeNode(Node<K, V>& root, const K& key);
			void setNode(Node<K, V>* root, const K& key, const V& newValue);*/

			Node<K, V>* addNode(Node<K, V>* root, const K& key, const V& val);
			Node<K, V>* getNode(Node<K, V>* root, const K& key);
			Node<K, V>* removeNode(Node<K, V>*, const K& key);
			Node<K, V>* getMinimumNode(Node<K, V>* node);
			Node<K, V>* removeMinimumNode(Node<K, V>* root);
			Node<K, V>* freeNode(Node<K, V>*);
			bool setNode(Node<K, V>* root, const K& key, const V& Val);

		private:
			Node<K, V>* m_root;
			int m_size;
	};
	template <typename K, typename V> BstMap<K, V>::BstMap():m_size(0), m_root(NULL){};
	template <typename K, typename V> BstMap<K, V>::~BstMap() {
		freeNode(m_root);	
	};
	template <typename K, typename V> int  BstMap<K, V>::getSize(){ return m_size; };
	template <typename K, typename V> bool BstMap<K, V>::isEmpty(){ return getSize()==0; };
	template <typename K, typename V> void BstMap<K, V>::display(Node <K, V>* root)
	{	
		if(root==NULL) return;
		display(root->getLeft());
		root->display();
		display(root->getRight());
		//using namespace std;
		//cout<<"Size: "<<m_size<<endl;
	}

	template <typename K, typename V> void BstMap<K, V>::display() { display(m_root);}

	/*template <typename K, typename V>
	Node<K, V>& BstMap<K, V>::addNode(Node<K, V>& root, const K& key, const V& val) // The priority of '->' higher than '*'
	{	
		if(root==NULL) 
			return new Node<K, V>(key, val);
		if(root->getKey() < key)	root->getLeft() = addNode(root->getLeft(), key, val);	// 破坏了封装性，用setXX;
		else if(root->getKey() > key) root->getRight() = addNode(root->getRight(), key, val);
		return root;
	}*/
	/*template<>
	Node<std::string, int>* BstMap<std::string, int>::addNode(Node<std::string, int>* root, const std::string& key, const int& val)
	{
		if ( root==NULL )	{ m_size++; return new Node<std::string, int>(key, 1);}
		else if( root->getKey()>key ) root->setLeft(addNode(root->getLeft(), key, 1));
		else if( root->getKey()<key ) root->setRight(addNode(root->getRight(), key, 1));
		else { //else return root; [error]
			int tmp = root->getVal();
			root->setVal(++tmp);
		}
		return root;
	}*/
	template <typename K, typename V>
	Node<K, V>* BstMap<K, V>::addNode(Node<K, V>* root, const K& key, const V& val)
	{
		if ( root==NULL )	{ m_size++; return new Node<K, V>(key, val);}
		else if( root->getKey()>key ) root->setLeft(addNode(root->getLeft(), key, val));
		else if( root->getKey()<key ) root->setRight(addNode(root->getRight(), key, val));
		else { //else return root; [error]
			//std::cout<<"Key: "<<root->getKey();
			V tmp = root->getVal();
			root->setVal(++tmp);
			//m_size++;
			//std::cout<<"Val: "<<root->getVal()<<std::endl;
		}	
		return root;
	}

	template <typename K, typename V>
	void BstMap<K, V>::add(const K& key, const V& value) { m_root=addNode(m_root, key, value);}

	/*template <typename K, typename V>
	bool BstMap<K, V>::getNode(const Node<K. V>& root, const K& key, Node<K, V>& node)
	{
		if( root==NULL ) return false;
		if( root->getKey()>key ) return getNode(root->getLeft(), key, node);
		else if( root->getKey()<key ) return getNode(root->getRight(), key, node);
		else {
			node = *root;
			return true;
		}
	}*/

	template <typename K, typename V>
	Node<K, V>* BstMap<K, V>::getNode(Node<K, V>* root, const K& key) // 返回一个指针，意味着该接口封装性差，不应该被放到public中
	{
		if( root==NULL ) return root;
		if( root->getKey()>key ) return getNode(root->getLeft(), key);
		else if ( root->getKey()<key ) return  getNode(root->getRight(), key);
		else return root;
	}

	template <typename K, typename V>
	bool BstMap<K, V>::get(const K& key, V& val)
	{
		Node<K, V>* node = getNode(m_root, key);
		if (node) {
			val = node->getVal();
			return true;
		}
		return false;
	}

	template <typename K, typename V>
	Node<K, V>* BstMap<K, V>::removeNode(Node<K, V>* root, const K& key)
	{
		if( root==NULL ) return root;	// 引用的对象是指针，可以用来判断NULL[error]
		if( root->getKey()>key ) root->setLeft(removeNode(root->getLeft(), key)); 
		else if( root->getKey()<key ) root->setRight(removeNode(root->getRight(), key)); // 修改引用的数据 [error]
		else 
		{
			if (root->getRight()==NULL) {
				Node<K, V>* tmp = root->getLeft();
				m_size--;
				delete root;
				return tmp;
			}
			if (root->getLeft()==NULL) {
				Node<K, V>* tmp = root->getRight();
				m_size--;
				delete root; // 释放引用的数据 [error] -- delete 应该作用于指针
				return tmp;
			}

			Node<K, V>* minimum = getMinimumNode(root->getRight());	// 要先把最小节点摘下，避免在树中形成环
			removeMinimumNode(root->getRight());	// 在此已 --
			minimum->setLeft(root->getLeft());
			minimum->setRight(root->getRight());
			delete root;
			return minimum;
		}

	}

	template <typename K, typename V> bool BstMap<K, V>::remove(const K& key) { m_root = removeNode(m_root, key); return true;}

	template <typename K, typename V>
	Node<K, V>* BstMap<K, V>::getMinimumNode(Node<K, V>* root)
	{
		if(root==NULL || root->getLeft()==NULL ) return root;
		if(root->getLeft()!=NULL) return getMinimumNode(root->getLeft());
	}

	template <typename K, typename V>
	Node<K, V>* BstMap<K, V>::removeMinimumNode(Node<K, V>* root) 
	{
		if(root==NULL) return root;	
		if(root->getLeft()!=NULL) root->setLeft(removeMinimumNode(root->getLeft()));
		else {
			m_size--;
			return root->getRight();
		} 
		return root;
	}

	template <typename K, typename V>
	bool BstMap<K, V>::setNode(Node<K, V>* root, const K& key, const V& val) 
	{
		if(root) {
			Node<K, V> *node = getNode(root, key);
			node->setVal(val);
			return true;
		}
		return false;
	}
	
	template <typename K, typename V> void BstMap<K, V>::set(const K& key, const V& val) { setNode(m_root, key, val); }

	template <typename K, typename V>
	Node<K, V>* BstMap<K, V>::freeNode(Node<K, V>* node) {
		if(node==NULL) return node;
		node->setLeft(freeNode(node->getLeft()));
		node->setRight(freeNode(node->getRight()));
		if(node->getLeft()==NULL && node->getRight()==NULL) {
			delete node;
			node = NULL;
		}
		return node;
	}
};
#endif
