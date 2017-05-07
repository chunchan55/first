#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*class String
{
public:
	String(char *pStr = "")//���캯��
	{
		if(NULL==pStr)//Ϊ�մ�
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
	//дʱ����
	/*String (String&s)//�������캯��
		:_pStr(s._pStr)
		,_pcount(s._pcount)
	{
		_pcount++;
		s._pcount++;
		
	}
	~String()//��������
	{
		if (_pStr&&0 == --(*_pcount))//�жϻ��м�����Ա����
		{
			delete[]_pStr;
			_pStr = NULL;
			delete _pcount;
			_pcount = NULL;
		}
	}
	String &operator = (const String &s)//��ֵ�����������
	{
		if (this!=&s)
		{
			if ((_pStr&&0)==--(*_pcount))//�ж��Ƿ�������ʹ�ã�Ȼ�����ͷ�
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

//String &operator = (const String&s)//ǳ����
//{
//	if (this!=&s)//�ж��ǲ����Լ����Լ���ֵ
//	{
//		char*ptemp = new char[sizeof(_pStr)+1];//���ٿռ�
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
			_pStr = new char[1 + 4];//����һ��ָ�룬���ĸ��ֽ�
			_pStr = (char*)(((int*)_pStr)+1);//������ĸ��ֽ�
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
	char& operator[](size_t index)//����[],�ɶ�����
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

	// ���������C�еĿ⺯��
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
				if(s._pStr[j]=='\0')//�жϵڶ��������ǲ��ǵ�ͷ��
				{
					return true;
				}
			}
			
			i++;
		}
			return false;
	}
	String operator+(const String& s)//��֪��Ϊʲô�����д�
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
