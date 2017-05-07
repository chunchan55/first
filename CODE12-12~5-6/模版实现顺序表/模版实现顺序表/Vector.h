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
 	/*Vector(const T* array,size_t size)
 		:_start(new T[size])
 		,_finish(_start)
 		,_endofStorage(_start+size)
 	{
 		memcpy(_start,array,size*sizeof(array[0]));
 	}*/
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
		Iterator M = End();
		return *(--M);
	}
	const T&Back()const//�ɶԳ���
	{
		Iterator M = End();
		return *(--M);
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
		CheckCapacity();//�������������
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
		CheckCapacity();  
		if (0 == _finish)  
		{  
			PushBack(x); 
		}  
		else  
		{  
			size_t size = _finish-_start;

			for (size_t i = size; i >= pos; --i)  
			{  
				 _start[i] = _start[size-1];
				 --size;
			 }  
				_start[pos-1] = x;  
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

	//��Vector��ֵn��ֵΪx��Ԫ��,size��nС���ͼ�С�ռ䣬�������ռ�
		void Assign(size_t n, const T& x)
		{
			unsigned i = 0;
			size_t size = _finish-_start;
			size_t capacity = _endofStorage-_start;
			if (size>n)
			{
				for (i=0;i<n;i++)
				{
					_start[i] = x;
				}
				_finish = _start + n;
			}
			else if(size <= n)
			{
				for (i=0;i<=n;i++)
				{
					_finish = _start+i;
					CheckCapacity();
					_start[i] = x;
				}
			}

		}
//���size��n�󣬾Ͳ�������nС����n��Ԫ��֮��ȫ��ֵΪx
		void Resize(size_t n,const T&x)
		{
			unsigned i = 0;
			size_t size = _finish-_start;
			size_t capacity = _endofStorage-_start;
			if(size<n)
			{
				for (i=size;i<n;i++)
				{
					_finish = _start+i;
					CheckCapacity();
					_start[i] = x;
				}
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
	void CheckCapacity()//���ݿ�����ǳ����������
	{
		if (_finish==_endofStorage)
		{
			size_t newcapacity = (_endofStorage-_start)*2+3;
			size_t size = _finish-_start;
			T *tmp = new T[newcapacity];//����
			if(_start)//ֱ�Ӹ�ֵ
			{
				for (size_t i=0;i<size;i++)
				{
					tmp[i] = _start[i];//��ֵ
				}
				//�ͷ�ԭ���Ŀռ�
			}
			delete[]_start;
			_start = tmp;
			_endofStorage = _start+ newcapacity;
			_finish = _start+size;

		}
	}
 };
template<class T,class Container = Vector<T>>
 class  Stack
 {
 private:
	 Container _con;
 public:
	 void Push(const T&x)
	 {	
		 _con.PushBack(x);
	 }
	 void Pop()
	 {
		 _con.PopBack();
	 }
	 bool Empty()
	 {
		 if(_con.Empty())
			 return true;
		 else 
			 return false;

	 }
	 T&Top()
	 {
		 return _con.Back();
	 }

	 size_t Size()
	 {
		 return _con.Size();
	 }

 };
 void test()
 {
	 
	 Stack<int,Vector<int>>s3;
	 s3.Push(4);
	 s3.Push(5);
	 s3.Push(6);
	 s3.Push(7);
// 	 s3.Pop();
// 	 s3.Pop();
// 	 s3.Pop();
// 	 s3.Pop();
	 // 	 s3.Pop();
	 cout<<s3.Top()<<endl;

	 cout<<s3.Size()<<endl;

 	
  	while(!s3.Empty())
  	{
  		cout<<s3.Top()<<" ";
  			s3.Pop();
  	}
  	cout<<endl;
  	

 }
