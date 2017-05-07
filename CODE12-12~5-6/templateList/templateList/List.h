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
	void PushBack(const T&d)//β��
	{
		if(_head==NULL)//Ϊ��
		{
			_head = _tail = new Node(d);
		}
		else
		{
			Node *tmp = new Node(d);
			_tail->_next = tmp;
			tmp->_prev = _tail;
			_tail = tmp;//β��Ϊtmp

		}
	}
	void Popback()//βɾ
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
	void PushFront(const T& d)//ͷ��
	{
		if(_head==NULL)
		{
			_head = _tail = new Node(d);
		}
		else
		{
			Node *tmp = new Node(d);//��һ���µĽ��
			Node *cur = _head;
			
			cur->_prev = tmp;
			tmp->_next = cur;
			_head = tmp;
		}
	}

	void PopFront()//ͷɾ
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

    Node* Find(const T& d)//�ҽ��
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

	//ʵ������λ�õĲ���(ǰ��)
	void Insert(Node* pos, const T& data)
	{
		if(pos==NULL)//wu
		{
			return;
		}
		if(pos==_head)//һ�����
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

	// ɾ������ʵ������λ��
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

	T&Front()//�ҵ���һ�����
	{
		assert(_head);
		return _head->_data;
	}

	T&Back()//�ҵ����һ�����
	{
		assert(_tail)
		return _tail->_data;
	}

};


template<class T,template <class>class container = List>
class Quqe//���У��Ƚ��ȳ�
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