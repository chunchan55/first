#define _CRT_SECURE_NO_WARNINGS 1
#include "Vector.h"
int main()
{
	int a[3];
	Vector <int> v1(a,4);
	v1.PushBack(1);
	//v1.PopBack();
	v1.PushBack(4);
	v1.Insert(2,4);
	v1.PushBack(5);
 	v1.PushBack(6);
 	v1.PushBack(3);

	//v1.Erase(2);
    v1.Print();
// 	v1.Assign(5,4);
// 	v1.Print();
	return 0;
}

