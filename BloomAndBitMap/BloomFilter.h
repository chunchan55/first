#pragma once

#include "BitMap.h"

struct __HashFunc1
{
	template<class T>  
	size_t BKDRHash(const T *str)  
	{  
		register size_t hash = 0;  
		while (size_t ch = (size_t)*str++)  
		{         
			hash = hash * 131 + ch;   // 也可以乘以31、131、1313、13131、131313..  
		}  
		return hash;  
	}  

	size_t operator()(const string& s)
	{
		return BKDRHash(s.c_str());
	}
};

struct __HashFunc2
{
	template<class T>  
	size_t SDBMHash(const T *str)  
	{  
		register size_t hash = 0;  
		while (size_t ch = (size_t)*str++)  
		{  
			hash = 65599 * hash + ch;         
			//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
		}  
		return hash;  
	}
	size_t operator()(const string& s)
	{
		return SDBMHash(s.c_str());
	}
};

struct __HashFunc3
{
	template<class T>
	size_t RSHash(const T *str)  
	{  
		register size_t hash = 0;  
		size_t magic = 63689;     
		while (size_t ch = (size_t)*str++)  
		{  
			hash = hash * magic + ch;  
			magic *= 378551;  
		}  
		return hash;  
	}   

	size_t operator()(const string& s)
	{
		return RSHash(s.c_str());
	}
};

struct __HashFunc4
{
	template<class T>
	size_t APHash(const T *str)  
	{  
		register size_t hash = 0;  
		size_t ch;  
		for (long i = 0; ch = (size_t)*str++; i++)  
		{  
			if ((i & 1) == 0)  
			{  
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));  
			}  
			else  
			{  
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));  
			}  
		}  
		return hash;  
	}    

	size_t operator()(const string& s)
	{
		return APHash(s.c_str());
	}
};

struct __HashFunc5
{
	template<class T>  
	size_t JSHash(const T *str)  
	{  
		if(!*str)        // 这是由本人添加，以保证空字符串返回哈希值0  
			return 0;  
		register size_t hash = 1315423911;  
		while (size_t ch = (size_t)*str++)  
		{  
			hash ^= ((hash << 5) + ch + (hash >> 2));  
		}  
		return hash;  
	}   

	size_t operator()(const string& s)
	{
		return JSHash(s.c_str());
	}
};
template<class K = string,class HashFunc1 = __HashFunc1,
		class HashFunc2 = __HashFunc2,class HashFunc3 = __HashFunc3,
		class HashFunc4 = __HashFunc4,class HashFunc5 = __HashFunc5>
class BloomFilter
{
protected:
	BitMap _bitmap;//位图
public:
	BloomFilter()
		:_bitmap(-1)
	{}
	void Set(const K&key)//置位
	{
		size_t index1 = HashFunc1()(key);
		size_t index2 = HashFunc2()(key);
		size_t index3 = HashFunc3()(key);
		size_t index4 = HashFunc4()(key);
		size_t index5 = HashFunc5()(key);


		_bitmap.Set(index1);
		_bitmap.Set(index2);
		_bitmap.Set(index3);
		_bitmap.Set(index4);
		_bitmap.Set(index5);
		cout<<index1<<"-"<<index2<<"-"<<index3<<"-"<<index4<<"-"<<index5<<endl;
	}

	bool Test(const K&key)//检测是否存在
	{
		size_t index1 = HashFunc1()(key);
		if(_bitmap.Test(index1)==false)
			return false;

		size_t index2 = HashFunc2()(key);
		if(_bitmap.Test(index2)==false)
			return false;

		size_t index3 = HashFunc3()(key);
		if(_bitmap.Test(index3)==false)
			return false;

		size_t index4 = HashFunc4()(key);
		if(_bitmap.Test(index4)==false)
			return false;

		size_t index5 = HashFunc5()(key);
		if(_bitmap.Test(index5)==false)
			return false;

		return true;//可能是误判了

	}
	
};

void TestBloomFilter()
{
	BloomFilter<> bm;
	bm.Set("http://www.cnblogs.com/haippy/archive/2012/07/13/2590351.html");
	bm.Set("http://www.cnblogs.com/haippy/archive/2012/07/13/2590352.html");
	bm.Set("http://www.cnblogs.com/haippy/archive/2012/07/13/2590353.html");
	bm.Set("http://www.cnblogs.com/haippy/archive/2012/07/13/2590354.html");
	bm.Set("http://www.cnblogs.com/haippy/archive/2012/07/13/2590355.html");
	bm.Set("http");

	cout<<bm.Test("http://www.cnblogs.com/haippy/archive/2012/07/13/2590351.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/haippy/archive/2012/07/13/2590352.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/haippy/archive/2012/07/13/2590353.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/haippy/archive/2012/07/13/2590354.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/haippy/archive/2012/07/13/2590355.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/haippy/archive/2012/07/13/2590356.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/haippy/archive/2012/07/13/2590315.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/haippy/archive/2012/07/13/2590325.html")<<endl;
	cout<<bm.Test("http://www.cnblogs.com/haippy/archive/2012/07/13/2590135.html")<<endl;
}