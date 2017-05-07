#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
void Test1()
{
	List <int> l1;
	l1.PushBack(5);
	l1.PushFront(1);
	l1.PopFront();
	l1.PopFront();
	l1.PushBack(8);
	l1.Popback();
	l1.PushBack(7);
	l1.PushBack(5);
	l1.Print();
}
void Test2()
{
	List<int>l2;
	ListNode<int> *pos;
	l2.PushBack(2);
	l2.PushBack(3);
	l2.PushBack(4);
	l2.PushBack(5);

	pos = l2.Find(3);
	l2.Erase(pos);

	//l2.Insert(pos,5);
	//cout<<tmp->_data<<endl;
	l2.Print();

}
void Test4()
{
	List<int>l3;
	l3.PushBack(1);
	l3.PushBack(2);
	l3.PushBack(3);
	l3.PushBack(4);
	List<int>l4;
	l4 = l3;
	l4.Print();


}

int main()
{
	//Test1();
	Test3();
	//Test2();
	return 0;
}