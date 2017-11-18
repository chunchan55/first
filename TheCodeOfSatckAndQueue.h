#include<iostream>
#include<stack>
#include<queue>
#include <assert.h>
using namespace std;
/*实现栈和队列的面试题。
（1）实现一个栈，要求实现Push（入栈）、Pop（出栈）、Min（返回最小值的操作）的时间复杂度为O(1)
（2）使用两个栈实现一个队列
（3）使用两个队列实现一个栈
（4）判断元素出栈、入栈顺序的合法性。如：入栈的序列（1,2,3,4,5），出栈序列为（4,5,3,2,1）是合法序列，
     入栈的序列（1,2,3,4,5），出栈序列为（1,5,3,2,4）是不合法序列
（5）一个数组实现两个栈 */
/*使用两个栈来实现Min函数，原理：用一个栈来保存数据，另一个栈用来更新数据最小值，就像迷宫中的那个
求最短路径异曲同工。压栈也只是遍历了一遍，对于Min函数来说就只是用了他栈顶的数据而已，因为在入栈的
时候就已经是最小的数据就在栈顶了，直接取出来就可以。
*/
template<class T>
class StackMin
{
public:
	void Push(const T&s)
	{
		//先把数据压到栈里，比较大小把最小的再压到另一个栈里
		_data.push(s);
		if((_min.size()==0)||(s<_min.top()))
		{
			_min.push(s);
		}
		else 
			_min.push(_min.top());
	}
	void Pop()
	{
		assert(_data.size()>0&&_min.size()>0);
		_data.pop();
		_min.pop();
	}
	T Min()
	{
		assert(_data.size()>0&&_min.size()>0);
		return _min.top();//最后栈尾上的数据就是最小的那个
	}
protected:
	stack<T> _data;
	stack<T> _min;
};
void MinSatckTest()
{
	StackMin<int> m_stack;
	m_stack.Push(3);
	m_stack.Push(2);
	m_stack.Push(1);
	m_stack.Push(5);
	cout<<m_stack.Min()<<endl;


}
/*用两个栈实现一个队列，思想：栈后进先出，队列先进先出，先把数据存入一个栈中，
再把这个栈的栈顶数据压到另一个栈中，压一个，pop一个
*/
template<class T>
class MyQueue
{
public:
	void Push(const T&s)
	{
		_s1.push(s);
	}
	T deleteTail()
	{
		if(_s2.size()<=0)
		{
			while(!_s1.empty())
			{
				T&data = _s1.top();
				_s2.push(data);
				_s1.pop();
			}
		}
		if(_s2.size()==0)
		{
			cout<<"queue is empty!"<<endl;
		}
		
		T head = _s2.top();
		_s2.pop();
		return head;
	}
	size_t Size()
	{
		return _s1.size();
	}
protected:
	stack<T> _s1;
	stack<T> _s2;
};

void MyQueueTest()
{
	MyQueue<int> q1;
	q1.Push(3);
	q1.Push(4);
	q1.Push(5);
	q1.Push(6);
	size_t s = q1.Size();
	while(s--)
	cout<<q1.deleteTail()<<" ";
	cout<<endl;	

}

/* 用两个队列实现一个栈，思想：将数据放到队列中，再把它的队头数据取出，依次放入另一个栈，
直到第一个栈中只剩下一个元素，然后取出剩下的这个元素，循环，相当于把两个队列的次序调换一下
这样就能像栈一样把数据取出
*/

template<class T>
class MySatck
{
public:
	void Input(const T&q)
	{
		_que1.push(q);
	}

	T Output()
	{
		T t;
		if(_que2.empty())//队列2为空
		{
			while(_que1.size()-1)//留下一个数据，进行输出
			{
				_que2.push(_que1.front());
				_que1.pop();
			}
			t = _que1.front();
			_que1.pop();
		}
		else //1为空
		{
			while(_que2.size()-1)
			{
				_que1.push(_que2.front());
				_que2.pop();
			}
			t = _que2.front();
			_que2.pop();
		}
		return t;
	}
	size_t Size()
	{
		return _que1.size();
	}

protected:
	queue<T> _que1;
	queue<T> _que2;
};

void MyStackTest()
{
	MySatck<int> sta;
	sta.Input(3);
	sta.Input(4);
	sta.Input(5);
	sta.Input(6);
	size_t s = sta.Size();
	while(s--)
		cout<<sta.Output()<<" ";
	cout<<endl;

}

/*判断元素出栈、入栈顺序的合法性。如：入栈的序列（1,2,3,4,5），
出栈序列为（4,5,3,2,1）是合法序列，入栈的序列（1,2,3,4,5），
出栈序列为（1,5,3,2,4）是不合法序列*/
/*思想：定义一个栈，入栈序列为instack，出栈序列为outstack
序列长度分别为lenin,lenout,如果两个长度为空或者不相等，则不合法
将instack的第一个元素入栈，循环使所有所有元素入栈，
如果当前栈为空且入栈序列不为空，则入栈序列后移，入栈，
如果当前栈顶元素不等于出栈序列元素且入栈序列不为空，则instack后移，s入栈
如果栈顶元素等于出栈序列元素，s出栈，出栈序列后移
循环比较，栈为空，则出栈序列合法，否则不合法
*/
bool CheckStackOutIsLegal(int*instack,int*outstack,int lenin,int lenout)
{
	assert(instack&&outstack);
	if(lenin!=lenout)
		return false;
	stack<int> s;
	int i = 0;
	int j = 0;
	for(;i<lenin;i++)
	{
		s.push(instack[i]);
		while(s.size()>0&&s.top()==outstack[j])//入栈序栈顶元素与当前出栈序列不等
		{
			s.pop();
			j++;
		}
	}
	return (s.size()>0)?false:true;
}

void CheckStackOutIsLegalTest()
{
	int instack[] = {1,2,3,4,5};
	int outstack[] = {1,5,3,2,4};
	int lenin = sizeof(instack)/sizeof(instack[0]);
	int lenout = sizeof(outstack)/sizeof(outstack[0]);
	if(CheckStackOutIsLegal(instack,outstack,lenin,lenout))
	{
		cout<<"出栈序列合法"<<endl;
	}
	else 
		cout<<"出栈序列不合法"<<endl;
}


//一个数组实现两个栈
/*思想：1.可以奇数位置存栈1，偶数位置存栈2
2.从中间向两边存，中间位置就是栈底，指针分别移动，当到达数组的头部或者是尾部，就扩容
3.从两头向中间压栈，头尾分别是栈底，当两个指针在中间相遇，就扩容。
第一种方法和第二种方法都会浪费空间，所以采用第三种

*/

template<class T>
class TwoStack
{
public:
	TwoStack()
		:_a(new int[2])
		,_index1(0)
		,_index2(1)
		,_capacity(2)
	{}
	~TwoStack()
	{
		if(_a!=NULL)
		{
			delete[]_a;
			_a = NULL;
			_index1 = 0;
			_index2 = 0;
			_capacity = 0;
		}
	}
	void PushA1(const T&s)
	{
		CheckCapacity();
		_a[_index1] = s;
		_index1++;
	}
	void PushA2(const T&s)
	{
		CheckCapacity();
		_a[_index2] = s;
		_index2--;
	}
	void PopA1()
	{
		if(_index1>0)
		{
			_index1--;
		}
	}
	void PopA2()
	{
		if(_index2>0)
		{
			_index2++;
		}
	}
	T& TopA1()//栈1的栈顶元素
	{
		assert(_index1>0);
		return _a[_index1-1];
	}
	T& TopA2()//栈2的栈顶元素
	{
		assert(_index2>0);
		return _a[_index2+1];
	}
	size_t Size1()
	{
		return _index1;
	}
	size_t Size2()
	{
		return _capacity-_index2-1;
	}
	bool EmptyA1()
	{
		return _index1==0;
	}
	bool EmptyA2()
	{
		return _index2 == _capacity-1;
	}
	void PrintA1()
	{
		if(_index1>0)
		{
			for(size_t i=_index1-1;i>0;--i)
			{
				cout<<_a[i]<<" ";
			}
			cout<<endl;
		}
	}
	void PrintA2()
	{
		if(_index2>0)
		{
			for(size_t i=_index2+1;i<_capacity;++i)
			{
				cout<<_a[i]<<" ";
			}
			cout<<endl;
		}
	}
private:
	void CheckCapacity()
	{
		if(Size1()+Size2()>=_capacity)
		{
			size_t newcapacity = _capacity*2;
			T*tmp = new T[newcapacity];
			size_t n = newcapacity - 1;
			for(size_t i=0;i<_index1;++i)
			{
				tmp[i] = _a[i];//扩容，把栈1的值一个一个拷贝过去
			}
			for(size_t i=_capacity-1;i>_capacity-_index2;--i)
			{
				tmp[n] = _a[i];//把栈2的值一个一个拷贝过去
				n--;
			}
			delete[]_a;
			_index2 = newcapacity - (_capacity - _index2);
			/*当把栈1的数值压进去后，相应的栈2的下边也就要进行改变*/
			_capacity = newcapacity;
			_a = tmp;
		}
	}
protected:
	T*_a;
	size_t _index1;
	size_t _index2;
	size_t _capacity;
};
void TwoStacktest()
{
	TwoStack<int> s;
	s.PushA1(1);
	s.PushA1(2);
	s.PushA1(3);
	s.PushA1(4);
	s.PushA1(5);
	s.PushA1(6);
	s.PrintA1();
	s.PopA1();
	s.PrintA1();
	cout<<"Stack1 Top:"<<s.TopA1()<<endl;
	cout<<"Stack1 Size:"<<s.Size1()<<endl;

	cout<<endl;

	s.PushA2(8);
	s.PushA2(9);
	s.PushA2(10);
	s.PrintA2();
	s.PopA2();
	s.PrintA2();
	cout<<"Stack2 Top:"<<s.TopA2()<<endl;
	cout<<"Stack2 Size:"<<s.Size2()<<endl;
}
