#pragma once
#include <iostream>
using namespace std;

enum Colour
{
	BLACK,
	RED,
};
template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K,V>*_left;
	RBTreeNode<K,V>*_right;
	RBTreeNode<K,V>*_parent;
	
	K _key;
	V _value;
	Colour _col;
	RBTreeNode(const K&key,const V&value)
		:_left(NULL)
		,_right(NULL)
		,_parent(NULL)
		,_key(key)
		,_value(value)
		,_col(RED)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;
public:
	RBTree()
		:_root(NULL)
	{}
	~RBTree()
	{
		Destroy();
	}
	void Insert(const K& key,const V&value)
	{
		if(_root==NULL)
		{
			_root = new Node(key,value);
			_root->_col = BLACK;
			return;
		}
		Node*parent = NULL;
		Node*cur = _root;
		while(cur)
		{
			if(key>cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(key<cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				break;
			}
		}
		//插入
		cur = new Node(key,value);
		if(key>parent->_key)//先插入
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else if(key<parent->_key)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//调整红黑
		while(parent&&parent->_col==RED)//父亲为红且不为空才进行调整
		{
			Node*grandfather = parent->_parent;
			if(parent == grandfather->_left)//左边
			{
				/*在左边，要判断
				1.uncle是否存在
				2.uncle为红色
				3.uncle为黑色
				*/
				Node*uncle = grandfather->_right;
				if(uncle&&uncle->_col==RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else//为空或者黑色
				{
					if(parent->_right == cur)//双旋
					{
						RotateL(parent);//变为单旋
						//如果单旋是由双旋转换而来，那么需要调整parent和cur
						swap(parent,cur);
					}
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
				
			}
			else if(parent == grandfather->_right)//右边
			{
				Node*uncle = grandfather->_left;
				if(uncle&&uncle->_col==RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else//为空或者黑色
				{
					if(parent->_left == cur)//双旋
					{
						RotateR(parent);//变为单旋
						//如果单旋是由双旋转换而来，那么需要调整parent和cur
						swap(parent,cur);
					}
					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
		}
		//把根置为黑色
		_root->_col = BLACK;
	}

	void RotateR(Node*parent)
	{
		Node*subL = parent->_left;
		Node*subLR = subL->_right;
		parent->_left = subLR;
		if(subLR)
			subLR->_parent = parent;
		subL->_right = parent;
		Node*parentParent = parent->_parent;
		parent->_parent = subL;
		if(parentParent==NULL)
		{
			_root = subL;
			subL->_parent = NULL;
		}
		else
		{
			if(parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}
			subL->_parent = parentParent;
		}
	}
	void RotateL(Node*parent)
	{
		Node*subR = parent->_right;
		Node*subRL = subR->_left;
		parent->_right = subRL;
		if(subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node*parentParent = parent->_parent;
		parent->_parent = subR;
		if(parentParent==NULL)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			if(parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}
	
	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}
	void Destroy()
	{
		_Destroy(_root);
		_root = NULL;
	}

	bool IsBlance()
	{
		if(_root==NULL)
			return true;
		int k = 0;
		size_t blackNum = 0;
		Node*cur = _root;
		while(cur)
		{
			if(cur->_col==BLACK)
				++k;
			cur = cur->_left;
		}
		return _IsBlance(_root,blackNum,k);
	}
protected:
	void _InOrder(Node*root)
	{
		if(root==NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout<<root->_key<<" ";
		_InOrder(root->_right);

	}
	void _Destroy(Node*root)
	{
		if(root)
		{
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}
	}
	bool _IsBlance(Node*root,size_t blackNum,const int&k)
	{
		if(root==NULL)
		{
			if(blackNum!=k)
			{
				cout<<"路径上的黑结点的数量不相同"<<endl;
			}
			return true;
		}
		if(root->_col==BLACK)
			++blackNum;
		if(root->_col==RED&&root->_parent->_col==RED)
		{
			cout<<"又连续的红结点"<<endl;
			return false;
		}
		return _IsBlance(root->_left,blackNum,k)
				&&_IsBlance(root->_right,blackNum,k);
	}
private:
	Node* _root;
};

void TestRBTree()
{
	RBTree<int, int> t1;
	int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	//int a[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
	for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
	{
		t1.Insert(a[i], i);
		cout<<a[i]<<"IsBalance?"<<t1.IsBlance()<<endl;
	}

	t1.InOrder();
	cout<<"IsBalance?"<<t1.IsBlance()<<endl;
}