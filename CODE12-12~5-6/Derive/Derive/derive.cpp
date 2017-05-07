#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
// #include <stdio.h>
//#include <iostream>
//#include "derive.h"
//using namespace std;
//int main()
//{
//	D d;
//	d._b = 1;
//	d.c1 = 2;
//	d.c2 = 3;
//	d._d = 4;
//	C1 &c1 = d;
//	c1._b = 5;
//	C2 &c2 = d;
//	c2._b = 6;
//
//    cout<<sizeof(D)<<endl;
//	return 0;
//}

//int Add(int a,int b)
//{
//	int ret = a+b;
//	return ret;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int ret = 0;
//	printf("请输入两个位数小于1000的数:");
//	scanf("%d%d",&m,&n);
//	
//	ret = Add(m,n);
//		printf("%d\n",ret);
//	return 0;
//
//}

// template <class T>
 //  T Add(T left,T right)
 //  {
 //  	return left+right;
 //  }
 //  int main()
 //  {
 //  	cout<<Add(2,3)<<endl;
 //  	cout<<Add(2.3,(int)4.5)<<endl;
 //  	cout<<Add('3','5')<<endl;
 //  }
/*template <class T,int N>
void Funtest(T (&array)[N])
{
	for (int i = 0;i<N;i++)
	{
		array[i] = i;
		cout<<array[i]<<endl;
	}
}
int main()
{
	int a[5];
	float b[5];
	Funtest(a);
	Funtest(b);
	return 0;
}*/
/*template <class T>
T Max(const T& left,const T& right)
{
	return left>right? left:right ;
}
template <class T>

T Max(const T&a,const T&b,const T&c)
{
	return Max(Max(a,b),c);
}
int main()
{
	cout<<Max(2,3)<<endl;
	cout<<Max<>(2,3)<<endl;
	cout<<Max(2,3,4)<<endl;
	cout<<Max<>(2,3,4)<<endl;
	cout<<Max<int>(2.0,4.0)<<endl;
	cout<<Max(2.0,4.0)<<endl;

}*/
/*
template <class T>
class Vector
{
private:
	T * _data;
	int _siza;
	int _cappacity;

};
//动态实现顺序表
template <class T>
class Vector
{
private:
	T * _data;
	int _siae;
	int _capacity;
public:
	Vector()
		:_siae(0)
		,_cappacity(0)
		,_data(new T[_cappacity])
	{}
};*/
template <class T,size_t N = 5>//带缺省值的模板参数
class Arr
{
	protected:
		T _a[N];
public:
	Arr(){}
};
int main ()
{
	Arr <int ,10> a1;
	Arr <int> a2;
	Arr <char,10> a3;
	return 0;
	
}