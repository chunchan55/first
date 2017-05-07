#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*class String
{
public:
	String(char *pStr = "")//构造函数
	{
		if(NULL==pStr)//为空串
		{
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else 
		{
			_pStr = new char[strlen(pStr)+1];
			strcpy(_pStr,pStr);
		}
		_pcount = new int (1);
	}
	friend ostream&operator<<( ostream& _cout,String &s);
	/*
	~String()
	{
		if(_pStr)
		{
			delete[] _pStr;
			_pStr = NULL;
		}
	}*/
//String(const String&s)
//:_pStr(new char [strlen(s._pStr)+1])
//
//{
//	strcpy(_pStr,s._pStr);
//}
	//写时拷贝
	/*String (String&s)//拷贝构造函数
		:_pStr(s._pStr)
		,_pcount(s._pcount)
	{
		_pcount++;
		s._pcount++;
		
	}
	~String()//析构函数
	{
		if (_pStr&&0 == --(*_pcount))//判断还有几个成员再用
		{
			delete[]_pStr;
			_pStr = NULL;
			delete _pcount;
			_pcount = NULL;
		}
	}
	String &operator = (const String &s)//赋值运算符的重载
	{
		if (this!=&s)
		{
			if ((_pStr&&0)==--(*_pcount))//判断是否还有人在使用，然后再释放
			{
				delete[]_pStr;
				_pStr = NULL;
				delete _pcount;
				_pcount = NULL;
			}
			_pStr = s._pStr;
			_pcount = s._pcount;
		}
			return *this;
	}*/

//String &operator = (const String&s)//浅拷贝
//{
//	if (this!=&s)//判断是不是自己给自己赋值
//	{
//		char*ptemp = new char[sizeof(_pStr)+1];//开辟空间
//		strcmp(ptemp,s._pStr);
//		delete []_pStr;
//		_pStr = ptemp;
//	}
//	return *this;
//}

// private:
// 	char *_pStr;
// 	int *_pcount;
// };
class String
{
public:
	String(const char* pStr = "")
	{
		if(NULL == pStr)
		{
			_pStr = new char[1 + 4];//用了一个指针，多四个字节
			_pStr = (char*)(((int*)_pStr)+1);//向后走四个字节
			*_pStr = '\0';
		}
		else
		{
			_pStr = new char[strlen(pStr) + 1 + 4];
			_pStr = (char*)(((int*)_pStr)+1);
			strcpy(_pStr, pStr);
		}

		*((int*)_pStr - 1) = 1;
	}
	friend ostream&operator<<( ostream& _cout,String &s);

	String& operator=(const String& s)
	{
		if(this != &s)
		{
			Release();
			_pStr = s._pStr;
			++GetCount();
		}

		return *this;
	}

	~String()
	{
		Release();
	}
	char& operator[](size_t index)//重载[],成对重载
	{
		if (GetCount() > 1)
		{
			char* pTemp = new char[strlen(_pStr) + 1 + 4];
			strcpy(pTemp+4, _pStr);
			--GetCount();
			_pStr = pTemp+4;
			GetCount() = 1;
		}

		return _pStr[index];
	}

	const char& operator[](size_t index)const
	{
		return _pStr[index];
	}

	// 不允许调用C中的库函数
	size_t Size()const
	{
		int count = 0;
		while(_pStr[count]!='\0')
		{
			count++;
		}
		return count;

	}
	bool Empty()const
	{
		if (_pStr==NULL)
			return true;
		else 
			return false;
	}
	bool StrStr(const String& s)
	{
		int i = 0;
		int j = 0;
		while(_pStr[i])
		{
			while(_pStr[i]==s._pStr[j])
			{
				i++;
				j++;
				if(s._pStr[j]=='\0')//判断第二个对象是不是到头了
				{
					return true;
				}
			}
			
			i++;
		}
			return false;
	}
	String operator+(const String& s)//不知道为什么总是有错
	{
		int i = 0;
		int j = 0;
		while(this->_pStr[i])
		{
			i++;
		}
		while(s._pStr[j])
		{
			this->_pStr[i] = s._pStr[j];
			i++;
			j++;
		}
		this->_pStr[i] = '\0';
		return *this;
	}
	bool operator>(const String &s)const
	{
		int i = 0;
		for(i=0;i<sizeof(_pStr);i++)
		{
			if(_pStr[i]>s._pStr[i])
			{
				return true;
			}
			else
				if(_pStr[i]<s._pStr[i])
				{
					return false;
				}
		}
		return false;

	}
	bool operator<(const String& s)const
	{
		int i = 0;
		for(i=0;i<sizeof(_pStr);i++)
		{
			if(_pStr[i]<s._pStr[i])
			{
				return true;
			}
			else
				if(_pStr[i]>s._pStr[i])
				{
					return false;
				}
		}
		return false;
	}
	bool operator==(const String& s)const
	{
		int i = 0;
		for(i=0;i<sizeof(_pStr);i++)
		{
			if(_pStr[i]>s._pStr[i])
			{
				return false;
			}
			else
				if(_pStr[i]<s._pStr[i])
				{
					return false;
				}
		}
		return true;
	}
	bool operator!=(const String& s)const
	{
		int i = 0;
		for(i=0;i<sizeof(_pStr);i++)
		{
			if(_pStr[i]>s._pStr[i])
			{
				return true;
			}
			else
				if(_pStr[i]<s._pStr[i])
				{
					return true;
				}
		}
		return false;
	}




private:
	int& GetCount()const
	{
		//cout<<*((int*)_pStr - 1)<<endl;
		return *((int*)_pStr - 1);
	}

	void Release()
	{
		if(_pStr && (0 ==GetCount()--))
		{
			_pStr = (char*)((int*)_pStr-1);
			delete[] _pStr;
			_pStr = NULL;
		}
	}

private:
	char* _pStr;
};
