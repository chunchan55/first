//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<assert.h>
//#include<string.h>
//using namespace std;
//
//class String
//{
//private:
//	char* _pStr;
//public:
//	String(const char* pStr = "")
//	{
//		if(NULL == pStr)
//		{
//			_pStr = new char[1 + 4];//����һ��ָ�룬���ĸ��ֽ�
//			_pStr = (char*)(((int*)_pStr)+1);//������ĸ��ֽ�
//			*_pStr = '\0';
//		}
//		else
//		{
//			_pStr = new char[strlen(pStr) + 1 + 4];
//			_pStr = (char*)(((int*)_pStr)+1);
//			strcpy(_pStr, pStr);
//		}
//
//		*((int*)_pStr - 1) = 1;//���ü�����ʼ��Ϊ1
//	}
//	String(const String&s)
//		:_pStr(s._pStr)
//	{
//		++GetCount();
//	}
//	String& operator=(const String& s)
//	{
//		if(this != &s)
//		{
//			Release();
//			_pStr = s._pStr;
//			++GetCount();
//		}
//
//		return *this;
//	}
//
//	~String()
//	{
//		Release();
//	}
//	
//private:
//	int& GetCount()const
//	{
//		return *((int*)_pStr - 1);//�����ü���ȡ����
//	}
//
//	void Release()
//	{
//		if(_pStr && (0 ==GetCount()--))
//		{
//			_pStr = (char*)((int*)_pStr-1);
//			delete[] _pStr;
//			_pStr = NULL;
//		}
//	}
//};
//void CTest()
//{
//	String s1("dsew");
//	String s2(s1);
//	String s3(s2);
//
//	String s4("trtr");
//	String s5(s4);
//}
//class String
//{
//private:
//	char *_str;
//	int *_refCountPtr;
//	int _capacity;
//	int _size;
//public:
//	String(char *str = "")
//		:_refCountPtr(new int(1))
//	{
//		_capacity = strlen(str);
//		_size = _capacity;
//		_str = new char[_capacity+1];
//		strcpy(_str,str);
//
//		cout<<"String(char *str = "")"<<endl;
//	}
//
//	String(String&s)
//		:_str(s._str)
//		,_capacity(0)
//		,_size(0)
//	{
//		_refCountPtr = s._refCountPtr;
//		(*_refCountPtr)++;
//
//		cout<<"String(String&s)"<<endl;
//
//	}
//	String &operator = (String&s)
//	{
//		cout<<"operator="<<endl;
//		if(_str!=s._str)//�Լ����Լ���ֵ
//		{
//			if((*_refCountPtr)==1)
//			{
//				delete[]_str;
//				delete _refCountPtr;
//			}
//			_str = s._str;
//			_refCountPtr = s._refCountPtr;
//			(*_refCountPtr)++;
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		Release();
//		cout<<"~String()"<<endl;
//
//	}
//
//char *GetStr()
//{
//	return _str;
//}
//size_t Size()
//{
//	return _size;
//}
//size_t Capacity()
//{
//	return _capacity;
//}
//
//void PushBack(char ch)//����һ���ַ�
//{
//	//����Ӧ���ж��Ƿ��ж������ʹ��ͬһ��ռ�
//	if((*_refCountPtr)>1)
//	{
//		CoptOnWrite();
//	}
//	if(_size==_capacity)
//	{
//		Expand(_capacity*2);
//		_str[_size++] = ch;
//		_str[_size] = '\0';
//	}	
//}
//void PushBack(const char *str)
//{
//	size_t len = strlen(str);
//	if((*_refCountPtr)>1)
//	{
//		CoptOnWrite();
//	}
//	if(_size+len>(size_t)_capacity)
//	{
//		Expand(len+_size);
//	}
//	strcpy(_str+_size,str);
//	_size+=len;
//}
//char&operator[](size_t pos)
//{
//	assert(pos<(size_t)_size);
//	if((*_refCountPtr)>1)
//	{
//		CoptOnWrite();
//		return _str[pos];
//	}
//	else
//		return _str[pos];
//}
//
//private:
//	void Release()
//	{
//		if(--(*_refCountPtr)==0)
//		{
//			delete[]_str;
//			delete _refCountPtr;
//			_refCountPtr = NULL;
//		}
//	}
//	void CoptOnWrite()
//	{
//			//�����µĿռ俽������д
//			char *newstr = new char[_capacity+1];
//			strcpy(newstr,_str);
//			(*_refCountPtr)--;
//			_str = newstr;
//			_refCountPtr = new int(1);//�������µĿռ䣬�����µĶ������Գ�ʼ�����ü���
//	}
//
//	void Expand(size_t n)
//	{
//		//��Ҫ��������ʱ�������ǲ���ֻ��һ�����ÿռ䣬����Ƕ��������Ҫ�����������ݡ�
//		if(n>(size_t)_capacity)
//		{
//			_str = (char*)realloc(_str,n+1);
//			assert(_str);
//			_capacity = n;
//		}
//	}
//
//
//};
//
//void COWstringTest1()
//{
//	String s1("agdf");
//	String s2("de");
//	s1 = s2;
//	String s3(s2);
//	//s2.PushBack('d');
//	s2.PushBack("def");
//	s2.GetStr()[2] = '7';
//	cout<<s2.GetStr()[2]<<endl;
//}