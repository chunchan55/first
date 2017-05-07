#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<assert.h>
using namespace std;
typedef  int DataType;

class Vector
{
private:
	DataType *_pData;
	unsigned int _capacity;//有效空间的大小
	unsigned int _size;//保存的有效元素的个数
	void CheckCapacity()//存在问题,已经改正
	{
		while(_size>=_capacity)
		{
			size_t n = 1;
			if(_size>_capacity)
			{
				n =n+(_size/_capacity) ;
			}
			DataType *tmp = new DataType[_capacity + n*10];//扩容
			memcpy(tmp,_pData,_size*sizeof(DataType));
			delete[] _pData;
			_pData = tmp;
			_capacity+=10;
		}
	}
public:
	/*Vector()
	:_pData(NULL)
	,_capacity(0)
	,_size(0)
	{}*/
	Vector(DataType*pdata = NULL)//构造函数
		:_size(0)
		,_capacity(0)

	{
		_pData = new DataType[_size];
		memcpy(_pData,pdata,_size*sizeof(DataType));
		_capacity = _size;
	}
	Vector(const Vector&v)//拷贝构造函数
	{
		_pData = new DataType[v._capacity];
		memcpy(_pData,v._pData,(v._size*sizeof(DataType)));
		_capacity = v._capacity;
		_size = v._size;
	}
	friend ostream&operator<<(ostream&os,Vector &v);
	Vector &operator=(const Vector &v)//赋值运算符的重载
	{
		
	}
	~Vector()
	{
		if(_pData!=NULL)
		{
			delete[]_pData;
			_pData = NULL;
			_size = 0;
			_capacity = 0;
		}
	}
public:
	size_t size()const//求顺序表的长度
	{
		return _size;
	}
	size_t Capacity()const//容量
	{
		return _capacity;
	}
	bool Empty()
	{
		return 0==_size;
	}
	DataType &operator[](size_t index)//[]成对出现
	{
		assert (index<=_size);
		return _pData[index];
	}
	const DataType &operator[](size_t index)const
	{
		assert (index<=_size);
		return _pData[index];
	}
	DataType& Front()//访问第一个元素，成对出现？
	{
		return _pData[0];
	}
	const DataType& Front()const//访问第一个元素，成对出现？
	{
		return _pData[0];
	}
	DataType &Back()//访问最后一个元素，成对出现？
	{
		return _pData[_size-1];
	}
	const DataType &Back()const //访问最后一个元素，成对出现？
	{
		return _pData[_size-1];
	}
	 // 在顺序表的pos位置上插入元素data
	void Insert(size_t pos, const DataType& data)//在这个位置的后面插入
	{
		CheckCapacity();
		if(pos==_size)
		{
			PushBack(data);
		}
		for (size_t i = pos;i<_size;i++)
		{
			_pData[i+1] = _pData[i];
		}
		_pData[pos] = data;
		_size++;
	}
	   // 给顺序表重新赋值，该函数执行完里面存放了n个元素data
	void Assign(size_t n, const DataType& data)//
	{
		CheckCapacity();
		if (_size>n)
		{
			size_t i = 0;
			for(i=0;i<n;i++)
			{
				_pData[i] = data;
			}
		}
		else if(_size<=n)
		{
			size_t i = 0;
			_size = n;//把n赋给大小，以便扩容，否则就不会扩容，程序会出现错误
			CheckCapacity();
			for (i=0;i<=n;i++)
			{
				_pData[i] = data;
				if(i>_size)
				{
					_size++;
				}
			}
		}
		

	}


	// 删除顺序表pos位置上的元素
	void Erase(size_t pos)
	{
		for (size_t i=pos;i<_size;i++)
		{
			_pData[i] = _pData[i+1];
		}
		--_size;
	}
	void ReSize(size_t n, const DataType& data = DataType())
		// 改变顺序表中的元素为n个，如果n>原来顺序表中的元素的个数，多出来的空间
		// 请用data来填充
	{
		int tmp = _size;
		if(_size<n)
		{
			_size = n;
			CheckCapacity();
		}
		_size = tmp;
		for(size_t i=_size;i<=n;i++)
		{
			_pData[i] = data;
			if(i>tmp)
			{
				++_size;
			}
		}
	}
	void Clear()//清空，但是不释放空间
	{
		_size = 0;

	}

	void PushBack(DataType data)//尾插
	{
		CheckCapacity();//检查容量
		_pData[_size++] = data;
	}
	void PopBack()//尾删
	{
		assert(!Empty());
		--_size;
	}
};
