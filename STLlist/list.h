#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<iostream>
using namespace std;
template <class T>
struct __ListNode
{
	__ListNode<T> * _prev;
	__ListNode<T> * _next;
	T _data;
	__ListNode (const T&x)//���캯��
		:_prev(NULL)
		,_next(NULL)
		,_data(x)
	{}

};
//typedef __ListIterator<T,T&,T*> ��const ���͵ĵ�����
//typedef __ListIterator<T,constT&,constT*> const ���͵ĵ�����

template<class T,class Ref,class Ptr>
struct __ListIterator
{
	typedef __ListNode<T> Node;
	Node * _node;
	typedef __ListIterator<T,Ref,Ptr> Self;
	__ListIterator(Node *node)
		:_node(node)
	{}
	Ref operator*()
	{
		return _node->_data;
	}
	Ptr operator->()
	{
		return &(operator*());
	}
	Self &operator ++()//ǰ�üӼ�
	{
		_node = _node->_next;
		return *this;
	}
	Self &operator --()//ǰ�ü���
	{
		_node = _node->_prev;
		return *this;
	}
	Self &operator++(int)
	{
		Self tmp (*this);
		_node = _node->_next;
		return tmp;
	}
	Self &operator--(int)
	{
		Self tmp (*this);
		_node = _node->_prev;
		return tmp;
	}
	bool operator != (const Self& s) const
	{
		return _node != s._node;
	}
};
template<class T>
class MyList//˫��ѭ������
{
	typedef __ListNode<T> Node;
public:
typedef __ListIterator<T,T&,T*>  Iterator;
typedef __ListIterator<T,const T&,const T*> ConstIterator;

	MyList()//���캯��
	{
		_head = _Buynode(T());//��һ��ͷ���
		_head->_next = _head;
		_head->_prev = _head;
	}
	~MyList()//��������
	{
		Clear();
		delete _head;
		_head = NULL;

	}
	Iterator Begin()
	{
		return Iterator(_head->_next);
	}
	Iterator End()
	{
		return Iterator(_head);
	}
	ConstIterator Begin()const
	{
		return ConstIterator(_head->_next);
	}
	ConstIterator End()const
	{
		return ConstIterator(_head);
	}

	void PushBack(const T&x)//β��
	{
 		Node * tail = _head ->_prev;
 		Node *tmp = _Buynode(x);
 		tail->_next = tmp;
 		tmp ->_prev = tail;
 		tmp ->_next = _head;
 		_head->_prev = tmp;

	}
	void PopBack()//βɾ
	{
 		if(_head->_next ==_head)//
 		{
 			return;
 		}
 		else
 		{
 			Node *tail = _head->_prev;
 			Node *prev = tail->_prev;
 			delete tail;
 			_head->_prev = prev;
 			prev->_next = _head;
 			
 		}

	}
	void PushFront(const T&x)
	{
		// 		Node* next = _head->_next;
		// 		Node* tmp = _Buynode(x);
		// 		_head->_next = tmp ;
		// 		tmp->_prev = _head;
		// 		tmp->_next = next;
		// 		next->_prev = tmp;
		Insert(x,Begin());
	}
	void PopFront()
	{
		Node* cur = _head->_next;
		Node* prev = cur->_prev;
		Node* next = cur->_next;
		_head->_next = next;
		next->_prev = _head;
		delete cur;

		//Erase(Begin());
	}
	Iterator Find(const T&x)
	{
		Node* cur = _head->_next ;
		while(cur->_next!=_head)
		{
			if (cur->_data == x)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}
	void Insert(const T&x,Iterator pos)
	{
		
		Node *cur = _Buynode(x);
		Node *next = pos._node;
		Node *prev = next->_prev;
		assert((pos._node)&&(pos!=End()));
		prev->_next = cur;
		cur->_prev = prev;
		cur->_next = next;
		next->_prev = cur;
	}
	
	Iterator  Erase(Iterator pos)
	{
		assert((pos._node)&&(pos!=End()));
		Node *cur = pos._node;
		Node *prev = cur->_prev;
		Node *next = cur->_next;
		prev->_next = next;
		next->_prev = prev;
		delete cur;
		pos = prev;//����ʹ��ʱ��ֹ������ʧЧ
		return next;//������һ��λ�õĵ�����

	}
	void Clear()
	{
		Node *cur = _head->_next;//ָ���һ�����
		while(cur!=_head)
		{
			Node *next = cur->_next;
			delete cur;
			cur = next;
		}
	}
protected:
	Node *_Buynode(const T& x)//newһ���µĽ��
	{
		return new Node(x);
	}


private:
	Node * _head;

};
void Print (const MyList<int>&x)
{
	MyList<int>::ConstIterator it = x.Begin();
	while(it != x.End())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}
//����PushBack/PopBack
void test1()
{
	MyList<int> x;
	x.PushBack(3);
	x.PushBack(4);
	x.PushBack(5);
 	x.PopBack();
 	x.PopBack();
 	x.PopBack();
	x.PopBack();
	Print(x);
}
//����Insert/Erase
 void test2()
 {
 	MyList<int> x;
 	x.PushBack(3);
 	x.PushBack(4);
 	x.PushBack(5);
	MyList<int>::Iterator pos = x.Find(4);
	x.Insert(6,pos);
	x.Erase(pos);
 	Print(x);
 }
 //����PushFront/PopFront
 void test3()
 {
	 MyList<int> x;
	 x.PushBack(3);
	 x.PushBack(4);
	 x.PushBack(5);
	 x.PushFront(6);
 	 x.PopFront();
 	 x.PopFront();
 	 x.PopFront();
 	 x.PopFront();

	 Print(x);
 }