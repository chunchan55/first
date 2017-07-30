#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;


 ///*1.传统写法完成String深拷贝。 
 //2.现代写法完成String深拷贝。 */
 // class String 
 // { 
 // private: 
 // 	char* _str; 
 // public:
 // 	String(char* str = "")
 // 		:_str(new char [strlen(str)+1])
 // 	{
 // 		strcpy(_str,str);
 // 		cout<<"String(char*)"<<endl;
 // 
 // 	}
 // 	String(const String&str)
 // 		:_str(new char [strlen(str._str)+1])
 // 	{
 // 		strcpy(_str,str._str);
 // 		cout<<"String(const &)"<<endl;
 // 
 // 	}
 // 	String &operator = (const String&str)
 // 	{
 // 		if(this!=&str)
 // 		{
 //  			char *tmp = new char[strlen(str._str)+1];
 //  			strcpy(tmp,str._str);
 //  			delete []_str;
 //  			_str = tmp;
 // 		}
 // 		return *this;
 // 
 // 		cout<<"String="<<endl;
 // 
 // 	}
 // 	~String()
 // 	{
 // 		if(_str!=NULL)
 // 		delete []_str;
 // 		_str = NULL;
 // 		cout<<"~String"<<endl;
 // 
 // 	}
 // }; 
 // 
 // void StringTest1()
 // {
 // 	String s1("hello");
 // 	String s2(s1);
 // 	String s3("i am not happy!");
 // 	s1 = s3;
 // }



class String 
{ 
public:
	String(char* str = " ")
	{
		_capacity = strlen(str);
		_str = new char [_capacity+1];
		_size = _capacity;
		strcpy(_str,str);
		//cout<<"String(char*)"<<endl;

	}
	String(const String&str)
		:_str(NULL)
		,_size(0)
		,_capacity(0)
	{
		String tmp (str._str);
		Swap(tmp);
		//cout<<"String(const &)"<<endl;

	}
	String &operator = (String s)
	{
		Swap(s);
		return *this;

		//cout<<"String="<<endl;

	}
	~String()
	{
		if(_str!=NULL)
		delete []_str;
		_str = NULL;
		//cout<<"~String"<<endl;

	}
    void Swap(String& s)
	{
		swap(_str,s._str);
		swap(_size,s._size);
		swap(_capacity,s._capacity);
	}
	char* GetStr() 
	{
		return _str;
	}
 		size_t Size()
		{
			return _size;
		}
 		size_t Capacity()
		{
			return _capacity;
		}
 
 		// 增删查改 
	void PushBack(char ch)
	{
		if(_size == _capacity)
		{
			Expand(_capacity*2);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
		
	}
	void PushBack(const char* str)
	{
		size_t len = strlen(str);
		if(len+_size>_capacity)
		{
			Expand(_size+len);
		}
		strcpy(_str+_size,str);//拷贝
		_size += len;//大小 改变

	}
	void PopBack()
	{
		assert(_size);
		--_size;
		_str[_size] = '\0';
	}
	void Insert(size_t pos, char ch)
	{
		if(_size==_capacity)
		{
			Expand(_capacity*2);
		}
		int end = _size;
		while(end>=(int)pos)
		{
			_str[end+1] = _str[end];//移动
			--end;
		}
		_str[pos] = ch;
		++_size;

	}
	void Insert(size_t pos, const char* str)
	{
		int len = strlen(str);
		if(_size+len>_capacity)
		{
			Expand(_size+len);
		}
		int end = _size;
		while(end>=(int)pos)
		{
			_str[end+len] = _str[end];
			--end;
		}
		
		while(*str)
		{
			_str[pos++] = *str++;//赋值
		}
		_size+=len;
		_str[_size] = '\0';

	}
 	void Erase(size_t pos, size_t count)
	{
		if(pos+count>=_size-1)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			strcpy(_str+pos,_str+count+pos);
		}
		_size-=count;

	}
 	int Find(char ch) const
	{
		for(size_t i = 0;i<strlen(_str);++i)
		{
			if(_str[i] == ch)
			{
				return i;
				break;
			}
		}
		return -1;
	}

	//src hello  sub  hello
	//src hello!  sub  hello
	//src hello  sub  hello!
 	int Find(char* str) const
	{
		assert(str);
		char *srcstr = _str;
		char *substr = str;
		size_t srcIndex = 0;
		size_t subIndex = 0;
		size_t sublen = strlen(substr);
		while(sublen<=_size-srcIndex)
		//当字符数小于目标字符的大小时，肯定找不到了
		{
			size_t matchIndex = srcIndex;
			while(srcstr[matchIndex]==substr[subIndex])
			{
				matchIndex++;
				subIndex++;
				if(subIndex==sublen)
				{
					return srcIndex;
				}
			}
			subIndex = 0;
			srcIndex++;
			//把值置为第一次两个相遇的地方，再次循环
		}
		return -1;
	}
 	char& operator[](size_t pos)
	{
		assert(pos<_size);
		return _str[pos];
	}
	//s1 s2
 	bool operator<(const String& s) const
	{
		size_t i = 0;
		for(i=0;i<strlen(_str);i++)
		{
			if(_str[i]<s._str[i])
			{
				return true;
			}
			else
				if(_str[i]>s._str[i])
				{
					return false;
				}
		}
		if(i==strlen(_str)&&s._str[i]!=NULL)
		{
			return true;
		}
		return false;
	}
 	bool operator<=(const String& s) const
	{
		if((*this<s)||(*this==s))
			return true;
		else
			return false;
	}
 	bool operator>(const String& s) const
	{
		return !(*this<=s);
	}
 	bool operator>=(const String& s) const
	{
		return !(*this<s);
	}
 	bool operator==(const String& s) const
	{
		size_t i = 0;
		for(i=0;i<strlen(_str);i++)
		{
			if(_str[i]>s._str[i])
			{
				return false;
			}
			else
				if(_str[i]<s._str[i])
				{
					return false;
				}
		}
		return true;
	}
 	bool operator!=(const String& s)const; 
 	void Expand(size_t n)
	{
		if(n>_capacity)
		{
			_str =(char*) realloc(_str,n+1);//容量增加到n
			assert(_str);
			_capacity = n;
		}
	}
 private: 
 	char* _str; 
 	size_t _size; // 字符个数 
 	size_t _capacity; // 容量空间 
}; 

void StringTest1()
{/*
	String s1("hello");
	cout<<s1.GetStr()<<endl;
	String s2(s1);
	cout<<s2.GetStr()<<endl;*/

	String s3("i am not happy!");
	cout<<s3.GetStr()<<endl;

	s3.PushBack(' ');
	s3.PushBack('t');
	s3.PushBack('i');
	s3.PushBack('r');
	s3.PushBack('e');
	s3.PushBack('d');
	s3.PopBack();
	cout<<s3.GetStr()<<endl;
	//s1 = s3;
	//s1.PushBack(" tired");
	//cout<<s1.GetStr()<<endl;

}

void StringTest2()
{
	String s1("hello");
	s1.Insert(2,'w');
	cout<<s1.GetStr()<<endl;
	s1.Insert(0,"word ");
	//s1.Erase(2,2);
	cout<<s1.GetStr()<<endl;

}
void StringTest3()
{
	String s1("hello word!");
	int ret = s1.Find("word!");
	cout<<s1.GetStr()<<endl;
	cout<<ret<<endl;

}

void StringTest4()
{
	String s1("serey");
	String s2("serey");
	String s3("ser");
	String s4("erey");
	String s5("sereyer");
	cout<<(s1<=s2)<<endl;
	cout<<(s1>=s2)<<endl;
	cout<<(s1>s3)<<endl;
	cout<<(s4<s5)<<endl;
	cout<<(s2==s4)<<endl;


}