#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include "vector.h"
using namespace std;
ostream &operator<<(ostream&_cout,Vector&v)
{
	unsigned int i = 0;
	for(i=0;i<v._size;i++)
	{
		_cout<<v._pData[i]<<"->";		
	}
	return _cout;
}
int main()
{
	Vector v1;
	v1.PushBack(1);
	v1.PushBack(3);
	v1.PushBack(5);
	v1.Insert(2,0);
	v1.Assign(7,8);
	v1.ReSize(10,5);
	//v1.Clear();
	//v1.Erase(2);
	//v1.Assign(7,6);
	//v1.PopBack();
 	

	cout<<v1;
	cout<<"Null"<<endl;
}

