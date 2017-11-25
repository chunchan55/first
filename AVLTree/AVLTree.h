#pragma once

#include<iostream>
#include <assert.h>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K,V>*_left;
	AVLTreeNode<K,V>*_right;
	AVLTreeNode<K,V>*_parent;
	
	K _key;
	V _value;
	
	int _bf;

	AVLTreeNode(const K&key,const V&value)
		:_key(key)
		,_value(value)
		,_bf(0)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
};

template<class K,class V>

class AVLTree
{
	typedef AVLTreeNode<K,V> Node;
public:
	AVLTree()
		:_root(NULL)
	{}
	~AVLTree()
	{
		Destroy();
	}
	bool Insert(const K&key,const V&value)
	{
		if(_root==NULL)
		{
			_root = new Node(key,value);
			return true;
		}
		Node*parent  = NULL;
		Node*cur = _root;
		while(cur)
		{
			if(key>cur->_key)//�ұ�
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(key<cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			//���
			else
			{
				return false;
			}
		}
			//������Ϊ�� �����Ҫ����ƽ������
			/*1.��߲��룬bf--;�ұ߲��룬bf++
			2.������׵�bfΪ1/-1,˵������0��Ϊ�ģ���߶ȷ����仯����Ҫ�������ϸ���bf.
			������׵�bfΪ 0 ˵��������Ѿ��������ˡ�
			������׵�bfΪ2/-2 ����Ҫ��������ת
			*/
			cur = new Node(key,value);
			if(key>parent->_key)//�Ȳ��룬�ٽ���bf++
			{
				parent->_right = cur;
				cur->_parent = parent;
			}
			else if(key<parent->_key)
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
			//����ƽ������
			while(parent)
			{
				if(cur == parent->_right)//�ұ�
				{
					parent->_bf += 1;
				}
				else 
				{
					parent->_bf -= 1;
				}
				if(parent->_bf ==0)//�Ѿ�����
				{
					break;
				}
				else if(parent->_bf==1 || parent->_bf==-1)
				{
					//������
					cur = parent;
					parent = cur->_parent;
				}
				else if(parent->_bf==2||parent->_bf==-2)
				{
					//����					
					if(parent->_bf==2)
					{
						if(cur->_bf==1)
						{
							RotoL(parent);
						}
						else
						{
							RotoRL(parent);
						}
					}
					else if(parent->_bf == -2)
					{
						if(cur->_bf == -1)
						{
							RotoR(parent);
						}
						else
						{
							RotoLR(parent);
						}
					}
					//�������
					break;
				}
				else
				{
					assert(false);
				}
				
			}
			return true;
	}

	void RotoR(Node*parent)//��������������
	{
		Node*subLeft = parent->_left;
		Node*subLR = subLeft->_right;	
		parent->_left = subLR;
		if(subLR)//��Ϊ�գ���ָ������
			subLR->_parent = parent;
		subLeft->_right = parent;
		Node*parentParent = parent->_parent;
		parent->_parent = subLeft;
		//��Ϊ�Ƿ�Ϊ����
		if(parentParent==NULL)
		{
			_root = subLeft;
			subLeft->_parent = NULL;
		}
		else //parentParent��Ϊ��  ˵��������
		{
			if(parentParent->_left==parent)//��������
			{
				parentParent->_left = subLeft;
				subLeft->_parent = parentParent;
			}
			else if(parentParent->_right==parent)
			{
				parentParent->_right = subLeft;
				subLeft->_parent = parentParent;
			}
		}
		subLeft->_bf = parent->_bf = 0;
	}
	void RotoL(Node*parent)//��������������
	{
		Node*subRight = parent->_right;
		Node*subRL = subRight->_left;
		Node*parentParent = parent->_parent;
		parent->_right = subRL;
		if(subRL)//��Ϊ�ղ�ָ�����ĸ���
			subRL->_parent = parent;
		subRight->_left = parent;
		parent->_parent = subRight;	
		if(parentParent==NULL)//˵��Ϊ���ڵ�
		{
			_root = subRight;
			subRight->_parent = NULL;
		}
		else//��Ϊ��
		{
			if(parentParent->_left == parent)//������
			{
				parentParent->_left = subRight;
			}
			else if(parentParent->_right == parent)
			{
				parentParent->_right = subRight;
			}
			subRight->_parent = parentParent;

		}
		subRight->_bf = parent->_bf = 0;
	}
	void RotoLR(Node*parent)
	{
		Node*subL = parent->_left;
		Node*subLR = subL->_right;
		int bf = subLR->_bf;
		RotoL(parent->_left);
		RotoR(parent);
		if(bf==0)//�����ڵ�
		{
			parent->_bf = subL->_bf = subLR->_bf = 0;
		}
		else if(bf==-1)//����߲���
		{
			subL->_bf = subLR->_bf = 0;
			parent->_bf = 1;
		}
		else if(bf==1)//���ұ߲���
		{
			subL->_bf = -1;
			parent->_bf = subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}

	}
	void RotoRL(Node*parent)
	{
		Node*subR = parent->_right;
		Node*subRL = subR->_left;
		int bf = subRL->_bf;
		RotoR(parent->_right);
		RotoL(parent);
		if(bf==0)//�����ڵ�
		{
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else if(bf==-1)//����߲���
		{
			parent->_bf = subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if(bf==1)//���ұ߲���
		{
			parent->_bf = -1;
			subR->_bf = subRL->_bf = 0;
		}
		else
		{
			assert(false);
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
		int height = 0;
		return _IsBlance(_root,height);
	}

	size_t Height()
	{
		return _Height(_root);
	}
protected:
	void _InOrder(Node*root)
	{
		if(root == NULL)
			return;
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

	//ʱ�临�Ӷ�ΪO(N^2),�����ݹ�
	/*bool _IsBlance(Node*root)
	{
		if(root==NULL)
			return true;
		//int LH = _Height(root->_left);
		//int RH = _Height(root->_right);
		int bf = _Height(root->_right)-_Height(root->_left);
		if(root->_bf!=bf)
		{
			cout<<root->_key<<":ƽ�����Ӵ���"<<endl;
			return false;
		}
		return abs(bf)<2
				&&_IsBlance(root->_left)
				&&_IsBlance(root->_right);
	}*/
	//�����Ż���ʱ�临�Ӷ�ΪO(N)
	bool _IsBlance(Node*root,int&height)
	{
		if(root==NULL)
		{
			height = 0;
			return true;
		}
		
		int LeftHeight = 0;
		int RightHeight = 0;
		if(_IsBlance(root->_left,LeftHeight)==false)
		{
			return false;
		}
		else if(_IsBlance(root->_right,RightHeight)==false)
		{
			return false;
		}
		
		if(_root->_bf == (RightHeight-LeftHeight))//ÿ��ƽ�����ӺϷ�������height
		{
			height = RightHeight >= LeftHeight ? (RightHeight+1) : (LeftHeight+1);
			return true;
		}
		return abs(RightHeight - LeftHeight)<2;
	}
	size_t _Height(Node*root)
	{
		if(root==NULL)
			return 0;
		if(root->_left==NULL&&root->_right==NULL)
			return 1;
		size_t LH = _Height(root->_left);
		size_t RH = _Height(root->_right);
		return LH > RH ? (LH+1) : (RH+1);
	}
private:
	Node*_root;

};
void AVLTreeTest()
{
	AVLTree<int,int> avl;
	int a[] = {4,2,6,1,3,5,15,7,16,14};
	for(size_t i=0;i<sizeof(a)/sizeof(a[0]);++i)
	{
		avl.Insert(a[i],0);
	}
	avl.InOrder();
	if(avl.IsBlance())
	{
		cout<<"��ƽ����"<<endl;
	}
	else
	{
		cout<<"����"<<endl;
	}
	cout<<avl.Height()<<endl;
}
