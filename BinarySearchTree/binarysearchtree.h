#include<iostream>
using namespace std;
template<class K>
struct BinarySearchTreeNode
{
	BinarySearchTreeNode<K> *_left;
	BinarySearchTreeNode<K> *_right;
	K _key;
	BinarySearchTreeNode(const K&key)
		:_right(NULL)
		,_left(NULL)
		,_key(key)
	{}
};

template<class K>
class BinarySearchTree
{
	typedef BinarySearchTreeNode<K> Node;
protected:
	Node*_root;
public:
	BinarySearchTree()
		:_root(NULL)
	{}
	~BinarySearchTree()
	{}//xigou

	//非递归实现插入
	//0123456789
	bool Insert(const K& key)//3
	{
		if(_root==NULL)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = NULL;
		Node* cur = _root;
		while(cur)
		{
			if(cur->_key>key)//左，插入的小
			{
				parent = cur;
				cur = cur->_left;
			}
			else if(cur->_key<key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		if(parent->_key<key)
		{
			parent->_right = new Node(key);
		}
		else
			{
				parent->_left = new Node(key);
			}
		return true;
	}
	bool InsertR(const K&key)
	{
		return _InsertR(_root,key);
	}
	bool _InsertR(Node*& root,const K&key)
	{
		if(root==NULL)
		{
			root = new Node(key);
			return true;
		}
		if(root->_key<key)
			return _InsertR(root->_right,key);
		else if(root->_key>key)
			return _InsertR(root->_left,key);
		else 
			return false;
	}

	//中序
	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}
	void _InOrder(Node* root)
	{
		if(root==NULL)
			return;
		_InOrder(root->_left);
		cout<<root->_key<<" ";
		_InOrder(root->_right);
		//cout<<root->_key<<" ";
	}
};

void BinarySearchTreeTest()
{
	int a[] = {5,3,4,1,7,8,2,6,0,9};
	BinarySearchTree<int> b1;
	for(size_t i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		b1.Insert(a[i]);
	}
	b1.InOrder();
	
}