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
 	Vector()//构造函数
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
 	Vector(const Vector<T>& v)//拷贝构造函数
 	{
 		size_t size = v._finish - v._start;//计算出个数
 		size_t capacity = v._endofStorage - v._start;//计算出容量
 		_start = new T[capacity];//开辟新的空间
 		_endofStorage = _start + capacity;//新的容量
 		_finish = _start + size;//新的结束位置
 		for (size_t idx=0;idx<size;idx++)
 		{
 			_start[idx] = v._start[idx];//把值拷贝过去
 		}
 
 	}
  	~Vector()//析构函数
  	{
  		if(_start)
  		{
  			delete[] _start;
  			_start = NULL;
  			_finish = NULL;
  			_endofStorage = NULL;
  		}
  	}
	Vector<T> &operator=(const Vector <T> &v)//赋值运算符的重载
	{
		if(this!=&v)
		{
			Vector<int>temp(v);
			swap(temp);//赋值
		}
		return *this;
	}
	Iterator Begin()//返回第一个元素的迭代器
	{
		return _start;
	}
	const Iterator Begin() const//成对出现
	{
		return _start;
	}
	Iterator End()//返回最后一个元素的迭代器
	{
		return _finish;
	}
	const Iterator End() const//成对出现
	{
		return _finish;
	}
	T &At(size_t idx)//找到idx位置的元素
	{
		return _start[idx]
	}
	const T &At(size_t idx)const//成对出现
	{
		return _start[idx]
	}
	T&Front()//找到当前第一个元素与最后一个元素之间的距离
	{
		return *Begin();
	}
	const T&Front()const//成对出现
	{
		return *Begin();
	}
	T&Back()//返回最后一个元素的下一位
	{
		Iterator M = End();
		return *(--M);
	}
	const T&Back()const//成对出现
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

	bool Empty()const//判断是否为空
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
	void PushBack(const T& x)//尾插
	{
		//size_t size = _finish-_start;
		CheckCapacity();//检查容量，扩容
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
	// 在pos位置上插入元素x
	
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
	//删除某个位置的数据   
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

	//给Vector赋值n个值为x的元素,size比n小，就减小空间，大就扩大空间
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
//如果size比n大，就不处理，比n小就在n个元素之后全赋值为x
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
	void CheckCapacity()//扩容考虑深浅拷贝的问题
	{
		if (_finish==_endofStorage)
		{
			size_t newcapacity = (_endofStorage-_start)*2+3;
			size_t size = _finish-_start;
			T *tmp = new T[newcapacity];//扩容
			if(_start)//直接赋值
			{
				for (size_t i=0;i<size;i++)
				{
					tmp[i] = _start[i];//赋值
				}
				//释放原来的空间
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
