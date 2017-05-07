#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
// template<class T>
// class Vector 
// {
// public:
// 	Vector(int capacity)
// 		:_size(0)
// 		,_capacity(capacity)
// 		,_data(new T[_capacity])
// 	{}
// 	~Vector()
// 	{
// 		delete[]_data;
// 	}
// private:
// 	int _size;
// 	int _capacity;
// 	T * _data;
// 
// };
/*template<>
class Vector <int>
{
public:
	Vector(int capacity)
		:_size(0)
		,_capacity(capacity)
		,_data(new int[_capacity])
	{}
	~Vector()
	{
		delete[]_data;
	}
private:
	int _size;
	int _capacity;
	int * _data;

};

void test1()
{
	Vector <int> s1(2);
	//ector <double> s2(5);
}

int main()
{
	test1();
	return 0;
}
*/
/*
template<class T1,class T2>
class Data
{
private:
	T1 _d1;
	T2 _d2;
public:
	Data()
	{
		cout<<"Data(T1,T2)"<<endl;
	}

};
//局部特化第二个参数

template<class T1>
class Data <T1,int>
{
public:
	Data()
	{
		cout<<"Data(T1,int)"<<endl;
	}
private:
	T1 _d1;
	int _d2;
};
void test()
{
	Data <double ,int>d1;
	Data <double,double> d2;
}
int main()
{
	test(); 
	return 0;
}*/

 template<class T1,class T2>
 class Data 
 {
 private:
 	T1* d3;
 	T2* d4;
 public:
 	Data()
 	{
 		cout<<"Data(T1,T2)"<<endl;
 	}
 		
 };
template<class T1,class T2>
class Data <T1*,T2*>
{
private:
	T1* d3;
	T2* d4;
public:
	Data()
	{
		cout<<"Data(T1*,T2*)"<<endl;
	}

};
void test()
{
	Data<int ,int> d1;
	Data<int*,int*> d2;
}
int main()
{
	test();
	return 0;
}