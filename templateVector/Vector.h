 #define _CRT_SECURE_NO_WARNINGS 1
 #include<iostream>
 using namespace std;
 typedef int DataType;
 template<class T>
 class Vector
 {
  	
 public:
	 typedef T* Iterator;
	typedef T* ConstIterator;
 	Vector()//���캯��
 		:_start(NULL)
 		,_finish(NULL)
 		,_endofStorage(NULL)
 	{}
 	Vector(const T* array,size_t size)
 		:_start(new T[size])
 		,_finish(_start)
 		,_endofStorage(_start+size)
 	{
 		memcpy(_start,array,size*sizeof(array[0]));
 	}
 	Vector(const Vector<T>& v)//�������캯��
 	{
 		size_t size = v._finish - v._start;//���������
 		size_t capacity = v._endofStorage - v._start;//���������
 		_start = new T[capacity];//�����µĿռ�
 		_endofStorage = _start + capacity;//�µ�����
 		_finish = _start + size;//�µĽ���λ��
 		for (size_t idx=0;idx<size;idx++)
 		{
 			_start[idx] = v._start[idx];//��ֵ������ȥ
 		}
 
 	}
  	~Vector()//��������
  	{
  		if(_start)
  		{
  			delete[] _start;
  			_start = NULL;
  			_finish = NULL;
  			_endofStorage = NULL;
  		}
  	}
	Vector<T> &operator=(const Vector <T> &v)//��ֵ�����������
	{
		if(this!=&v)
		{
			Vector<int>temp(v);
			swap(temp);//��ֵ
		}
		return *this;
	}
	Iterator Begin()//���ص�һ��Ԫ�صĵ�����
	{
		return _start;
	}
	const Iterator Begin() const//�ɶԳ���
	{
		return _start;
	}
	Iterator End()//�������һ��Ԫ�صĵ�����
	{
		return _finish;
	}
	const Iterator End() const//�ɶԳ���
	{
		return _finish;
	}
	T &At(size_t idx)//�ҵ�idxλ�õ�Ԫ��
	{
		return _start[idx]
	}
	const T &At(size_t idx)const//�ɶԳ���
	{
		return _start[idx]
	}
	T&Front()//�ҵ���ǰ��һ��Ԫ�������һ��Ԫ��֮��ľ���
	{
		return *Begin();
	}
	const T&Front()const//�ɶԳ���
	{
		return *Begin();
	}
	T&Back()//�������һ��Ԫ�ص���һλ
	{
		return *(--End());
	}
	const T&Back()const//�ɶԳ���
	{
		return *(--End());
	}
	size_t Size()const
	{
		return _finish-_start;
	}

	size_t Capacity()const
	{
		return _endofStorage-_start;
	}

	bool Empty()const//�ж��Ƿ�Ϊ��
	{
		return 0==(_finish-_start);
	}

	T& operator[](size_t index)
	{
		assert(_start);
		return _start[index];
	}

	const T& operator[](size_t index) const
	{
		assert(_start);
		return _start[index];
	}
	void PushBack(const T& x)//β��
	{
		//size_t size = _finish-_start;
		ChecCapacity();//�������������
		*_finish++ = x;

	}
	void PopBack()
	{
		--_finish;
	}
	void Print()
	{
		int i = 0;
		for(i=0;i<(_finish-_start);i++)
		{
			cout<<_start[i]<<" ";
		}
		cout<<endl;
	}
	// ��posλ���ϲ���Ԫ��x
	
	void Insert(size_t pos, const T&x)  
	{  
		ChecCapacity();  
		if (pos == 0)  
		{  
			PushBack(x); 
		}  
		else  
		{  
			for (size_t i = pos; i < (_finish-_start); ++i)  
			{  
				 _start[i + 1] = _start[i];  
			 }  
				_start[pos] = x;  
				++_finish;  
		}  
}  
	//ɾ��ĳ��λ�õ�����   
	void Erase(size_t pos)  
	{  
		size_t size = _finish-_start;
	    //assert(pos >= 0 && pos <= size);        
	    size_t end = size;  
        while (end != pos)  
	    {  
		  _start[pos-1] = _start[pos];   
		   pos++;
	    }  
      --_finish;  
	}  

	//��Vector��ֵn��ֵΪx��Ԫ��
		void Assign(size_t n, const T& x)
		{
			int i = 0;
			for (i=0;i<n;i++)
			{
				ChecCapacity();
				_start[i] = x;
			}

		}

 private:
 	T  *_start;
 	T  *_finish;
 	T  *_endofStorage;
	void Swap(Vector <T> &v)
	{
		std::swap(_start,v._start);
		std::swap(_finish,v._finish);
		std::swap(_endofStorage,v._endofStorage);
	}
	void ChecCapacity()
	{
		if(_finish == _endofStorage)
		{
			size_t capacity = _endofStorage-_start;
			size_t idx = 0;
			T *temp = new T[2*(capacity)+3];
			T *pos = _start;
			while(pos!=_endofStorage)
			{
				temp[idx++] = *pos++;
			}
			delete[]_start;
			_start = temp;
			_finish = _start+capacity;
			_endofStorage = _start + capacity;
		}
	}
 };
//�����⣬�ѿռ�������