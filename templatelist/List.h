#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
template<class T>
struct ListNode
{
	T _data;
	ListNode<T> *_next;
	ListNode<T> *_prev;
	ListNode(const T&d)
		:_data(d)
		,_next(NULL)
		,_prev(NULL)
	{}
};
template<class T>
class List
{
	typedef ListNode<T> Node;
private:
	Node *_head;
	Node *_tail;
public:
	List()
		:_head(NULL)
		,_tail(NULL)
	{}
	~List()
	{
		clear();
	}
	List(const List<T>&l)
		:_head(NULL)
		,_tail(NULL)
	{
		Node *cur = l._head;
		while(cur)
		{
			this->PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	List<int> &operator = (const List<T>&l)
	{
		if(this !=&l)
		{
			clear();
			Node *cur = l._head;
			while(cur)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
		return *this;
	}
	void clear()
	{
		Node *cur = _head;
		while(cur)
		{
			Node*next = cur->_next;
			delete cur;
			cur = next;
		}
		_head = _tail = NULL;
	}
	void PushBack(const T&d)//尾插
	{
		if(_head==NULL)//为空
		{
			_head = _tail = new Node(d);
		}
		else
		{
			Node *tmp = new Node(d);
			_tail->_next = tmp;
			tmp->_prev = _tail;
			_tail = tmp;//尾变为tmp

		}
	}
	void Popback()//尾删
	{
		if (_head==NULL)
		{
			return;
		}
		if(_head==_tail)
		{
			_head = _tail = NULL;
		}
		else
		{
			Node *cur = _tail;
			_tail = cur->_prev;
			_tail->_next = NULL;
		}

	}
	size_t Size()
	{
		size_t size = 0;
		Node cur = _head;
		while(cur)
		{
			count++;
			cur = cur->_next;
		}
		return size;
	}
	void Print()
	{
		Node *cur = _head;
		while(cur)
		{
			cout<<cur->_data<<" ";
			cur = cur->_next;
		}
		cout<<endl;
	}
	void PushFront(const T& d)//头插
	{
		if(_head==NULL)
		{
			_head = _tail = new Node(d);
		}
		else
		{
			Node *tmp = new Node(d);//开一个新的结点
			Node *cur = _head;
			
			cur->_prev = tmp;
			tmp->_next = cur;
			_head = tmp;
		}
	}

	void PopFront()//头删
	{
		if(_head==NULL)
		{
			return ;
		}
		if(_head==_tail)
		{
			Popback();
		}
		else
		{
			Node *cur = _head;
			_head = cur->_next;
			_head->_prev = NULL;
		}
	}

    Node* Find(const T& d)//找结点
	{
		Node *cur = _head;
		assert(_head);
		while(cur)
		{
			if(cur->_data==d)
			{
				return cur;
			}
			cur = cur->_next;
		}

		return NULL;
	}

	//实现任意位置的插入(前面)
	void Insert(Node* pos, const T& data)
	{
		if(pos==NULL)//wu
		{
			return;
		}
		if(pos==_head)//一个结点
		{
			PushFront(data);
		}
		else
		{
			Node *prev = pos->_prev;
			Node *tmp = new Node(data);
			prev->_next = tmp;
			tmp->_prev = prev;
			tmp->_next = pos;
			pos->_prev = tmp;
		}
		
	}

	// 删除链表实现任意位置
	void Erase(Node* pos)
	{
		if(_head==NULL)
		{
			return;
		}
		else
			if(pos==_head)
		{
			PopFront();
		}
		else
			if(pos==_tail)
		{
			Popback();
		}
		else
		{
			Node *next = pos->_next;
			Node *prev = pos->_prev;
			next->_prev = prev;
			prev->_next = next;
			delete pos;

		}
	}

	bool Empty()
	{
		return _head==NULL;
	}

	T&Front()//找到第一个结点
	{
		assert(_head);
		return _head->_data;
	}

	T&Back()//找到最后一个结点
	{
		assert(_tail)
		return _tail->_data;
	}

};


template<class T,template <class>class container = List>
class Quqe//队列，先进先出
{
protected:
	container<T> _con;
public:
	void Push(const T&d)
	{
		return _con.PushBack(d);
	}
	void Pop()
	{
		return _con.PopFront();
	}
	T &Front()
	{
		return _con.Front();
	}
	T &Back()
	{
		return _con.Back();
	}
	bool Empty()
	{
		return _con.Empty();
	}
	void clear()
	{

	}

};
void Test3()
{
	Quqe<char>s;
	s.Push('q');
	s.Push('w');
	s.Push('e');
	s.Push('r');
	/*s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();*/


	while(!s.Empty())
	{
		cout<<s.Front()<<" ";
		s.Pop();
	}
	cout<<endl;

}