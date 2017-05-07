#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<assert.h>
using namespace std;
typedef  int DataType;

class Vector
{
private:
	DataType *_pData;
	unsigned int _capacity;//��Ч�ռ�Ĵ�С
	unsigned int _size;//�������ЧԪ�صĸ���
	void CheckCapacity()//��������,�Ѿ�����
	{
		while(_size>=_capacity)
		{
			size_t n = 1;
			if(_size>_capacity)
			{
				n =n+(_size/_capacity) ;
			}
			DataType *tmp = new DataType[_capacity + n*10];//����
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
	Vector(DataType*pdata = NULL)//���캯��
		:_size(0)
		,_capacity(0)

	{
		_pData = new DataType[_size];
		memcpy(_pData,pdata,_size*sizeof(DataType));
		_capacity = _size;
	}
	Vector(const Vector&v)//�������캯��
	{
		_pData = new DataType[v._capacity];
		memcpy(_pData,v._pData,(v._size*sizeof(DataType)));
		_capacity = v._capacity;
		_size = v._size;
	}
	friend ostream&operator<<(ostream&os,Vector &v);
	Vector &operator=(const Vector &v)//��ֵ�����������
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
	size_t size()const//��˳���ĳ���
	{
		return _size;
	}
	size_t Capacity()const//����
	{
		return _capacity;
	}
	bool Empty()
	{
		return 0==_size;
	}
	DataType &operator[](size_t index)//[]�ɶԳ���
	{
		assert (index<=_size);
		return _pData[index];
	}
	const DataType &operator[](size_t index)const
	{
		assert (index<=_size);
		return _pData[index];
	}
	DataType& Front()//���ʵ�һ��Ԫ�أ��ɶԳ��֣�
	{
		return _pData[0];
	}
	const DataType& Front()const//���ʵ�һ��Ԫ�أ��ɶԳ��֣�
	{
		return _pData[0];
	}
	DataType &Back()//�������һ��Ԫ�أ��ɶԳ��֣�
	{
		return _pData[_size-1];
	}
	const DataType &Back()const //�������һ��Ԫ�أ��ɶԳ��֣�
	{
		return _pData[_size-1];
	}
	 // ��˳����posλ���ϲ���Ԫ��data
	void Insert(size_t pos, const DataType& data)//�����λ�õĺ������
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
	   // ��˳������¸�ֵ���ú���ִ������������n��Ԫ��data
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
			_size = n;//��n������С���Ա����ݣ�����Ͳ������ݣ��������ִ���
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


	// ɾ��˳���posλ���ϵ�Ԫ��
	void Erase(size_t pos)
	{
		for (size_t i=pos;i<_size;i++)
		{
			_pData[i] = _pData[i+1];
		}
		--_size;
	}
	void ReSize(size_t n, const DataType& data = DataType())
		// �ı�˳����е�Ԫ��Ϊn�������n>ԭ��˳����е�Ԫ�صĸ�����������Ŀռ�
		// ����data�����
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
	void Clear()//��գ����ǲ��ͷſռ�
	{
		_size = 0;

	}

	void PushBack(DataType data)//β��
	{
		CheckCapacity();//�������
		_pData[_size++] = data;
	}
	void PopBack()//βɾ
	{
		assert(!Empty());
		--_size;
	}
};
