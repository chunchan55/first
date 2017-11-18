#include<iostream>
#include<stack>
#include<queue>
#include <assert.h>
using namespace std;
/*ʵ��ջ�Ͷ��е������⡣
��1��ʵ��һ��ջ��Ҫ��ʵ��Push����ջ����Pop����ջ����Min��������Сֵ�Ĳ�������ʱ�临�Ӷ�ΪO(1)
��2��ʹ������ջʵ��һ������
��3��ʹ����������ʵ��һ��ջ
��4���ж�Ԫ�س�ջ����ջ˳��ĺϷ��ԡ��磺��ջ�����У�1,2,3,4,5������ջ����Ϊ��4,5,3,2,1���ǺϷ����У�
     ��ջ�����У�1,2,3,4,5������ջ����Ϊ��1,5,3,2,4���ǲ��Ϸ�����
��5��һ������ʵ������ջ */
/*ʹ������ջ��ʵ��Min������ԭ����һ��ջ���������ݣ���һ��ջ��������������Сֵ�������Թ��е��Ǹ�
�����·������ͬ����ѹջҲֻ�Ǳ�����һ�飬����Min������˵��ֻ��������ջ�������ݶ��ѣ���Ϊ����ջ��
ʱ����Ѿ�����С�����ݾ���ջ���ˣ�ֱ��ȡ�����Ϳ��ԡ�
*/
template<class T>
class StackMin
{
public:
	void Push(const T&s)
	{
		//�Ȱ�����ѹ��ջ��Ƚϴ�С����С����ѹ����һ��ջ��
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
		return _min.top();//���ջβ�ϵ����ݾ�����С���Ǹ�
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
/*������ջʵ��һ�����У�˼�룺ջ����ȳ��������Ƚ��ȳ����Ȱ����ݴ���һ��ջ�У�
�ٰ����ջ��ջ������ѹ����һ��ջ�У�ѹһ����popһ��
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

/* ����������ʵ��һ��ջ��˼�룺�����ݷŵ������У��ٰ����Ķ�ͷ����ȡ�������η�����һ��ջ��
ֱ����һ��ջ��ֻʣ��һ��Ԫ�أ�Ȼ��ȡ��ʣ�µ����Ԫ�أ�ѭ�����൱�ڰ��������еĴ������һ��
����������ջһ��������ȡ��
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
		if(_que2.empty())//����2Ϊ��
		{
			while(_que1.size()-1)//����һ�����ݣ��������
			{
				_que2.push(_que1.front());
				_que1.pop();
			}
			t = _que1.front();
			_que1.pop();
		}
		else //1Ϊ��
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

/*�ж�Ԫ�س�ջ����ջ˳��ĺϷ��ԡ��磺��ջ�����У�1,2,3,4,5����
��ջ����Ϊ��4,5,3,2,1���ǺϷ����У���ջ�����У�1,2,3,4,5����
��ջ����Ϊ��1,5,3,2,4���ǲ��Ϸ�����*/
/*˼�룺����һ��ջ����ջ����Ϊinstack����ջ����Ϊoutstack
���г��ȷֱ�Ϊlenin,lenout,�����������Ϊ�ջ��߲���ȣ��򲻺Ϸ�
��instack�ĵ�һ��Ԫ����ջ��ѭ��ʹ��������Ԫ����ջ��
�����ǰջΪ������ջ���в�Ϊ�գ�����ջ���к��ƣ���ջ��
�����ǰջ��Ԫ�ز����ڳ�ջ����Ԫ������ջ���в�Ϊ�գ���instack���ƣ�s��ջ
���ջ��Ԫ�ص��ڳ�ջ����Ԫ�أ�s��ջ����ջ���к���
ѭ���Ƚϣ�ջΪ�գ����ջ���кϷ������򲻺Ϸ�
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
		while(s.size()>0&&s.top()==outstack[j])//��ջ��ջ��Ԫ���뵱ǰ��ջ���в���
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
		cout<<"��ջ���кϷ�"<<endl;
	}
	else 
		cout<<"��ջ���в��Ϸ�"<<endl;
}


//һ������ʵ������ջ
/*˼�룺1.��������λ�ô�ջ1��ż��λ�ô�ջ2
2.���м������ߴ棬�м�λ�þ���ջ�ף�ָ��ֱ��ƶ��������������ͷ��������β����������
3.����ͷ���м�ѹջ��ͷβ�ֱ���ջ�ף�������ָ�����м������������ݡ�
��һ�ַ����͵ڶ��ַ��������˷ѿռ䣬���Բ��õ�����

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
	T& TopA1()//ջ1��ջ��Ԫ��
	{
		assert(_index1>0);
		return _a[_index1-1];
	}
	T& TopA2()//ջ2��ջ��Ԫ��
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
				tmp[i] = _a[i];//���ݣ���ջ1��ֵһ��һ��������ȥ
			}
			for(size_t i=_capacity-1;i>_capacity-_index2;--i)
			{
				tmp[n] = _a[i];//��ջ2��ֵһ��һ��������ȥ
				n--;
			}
			delete[]_a;
			_index2 = newcapacity - (_capacity - _index2);
			/*����ջ1����ֵѹ��ȥ����Ӧ��ջ2���±�Ҳ��Ҫ���иı�*/
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
