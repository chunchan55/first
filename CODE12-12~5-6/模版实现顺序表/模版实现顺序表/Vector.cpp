#define _CRT_SECURE_NO_WARNINGS 1
#include "Vector.h"
#include<string>
#include <vector>
int main()
{
	//Vector <int> v1;
	//v1.PushBack(1);
	////v1.PopBack();
	//v1.PushBack(4);
	//v1.PushBack(5);
	//v1.PushBack(6);
	//v1.Print();
	//v1.Insert(2,0);
	//v1.Print();
	//v1.PushBack(3);
	//v1.Print();
	//v1.Erase(2);
	//v1.Print();
	//v1.Assign(3,4);
	//v1.Resize(2,7);
	//v1.Resize(8,6);
	//v1.Print();
	Vector<string> v2;
	v2.PushBack("aqqqihwihiwunrhiejioejvi");
	v2.PushBack("b");
	v2.PushBack("g");
	v2.PushBack("h");
	v2.Insert(2,"f");
	v2.Assign(8,"q");
	v2.Resize(4,"y");
	v2.Resize(10,"m");
	
 	//v2.Print();
// 	vector<int> v3;
// 	v3.push_back(4);
// 	v3.push_back(4);
// 	v3.resize(2,5);
// 	v3.resize(8,8);
	
    
 	//v2.Print();
	test();
	return 0;
}

