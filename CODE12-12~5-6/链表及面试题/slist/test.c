#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
void test1()
{
	pList plist ;//结构体指针定义一个链表
	pNode pos = NULL;//结点的位置
	InitList(&plist);
	PushBack(&plist,3);
	PushBack(&plist,4);
	//PopFront(&plist);
	PushBack(&plist,5);
	//PushBack(&plist,3);
	//PopBack(&plist);
	PushFront(&plist,2);
	//PushBack(&plist,4);
	/*pos = Find(plist,4);
	printf ("%d\n",pos->data);*/
	//PrintList(plist);
	//Remove(&plist,3);
	//RemoveAll(&plist,3);
	PrintList(plist);
	//Insert(&plist,Find(plist,4),8);
	//Erase(&plist,Find(plist,4));
	ReverseList(&plist);
	PrintList(plist);
	//DestroyList(&plist);

}
void test2()
{
	pList plist1 ;
	pList plist2 ;
	int ret = 0;
	pNode pos = NULL;
	InitList(&plist1);
	InitList(&plist2);

	PushBack(&plist1,2);
	PushBack(&plist1,6);
	PushBack(&plist1,4);
	PushBack(&plist1,8);
	PushBack(&plist1,10);
	PushBack(&plist1,12);
	/*Find(plist1,12)->next = plist1->next->next;
	ret = GetCircleLen(CheckCircle(plist1));
	printf ("len = %d\n",ret);
	pos = GetCircleEntry(plist1,CheckCircle(plist1));
	printf ("pos = %d\n",pos->data);*/
	PushBack(&plist2,3);
	PushBack(&plist2,5);
	PushBack(&plist2,4);
	PushBack(&plist2,9);
	Find(plist2,4)->next = plist1->next;
	ret = CheckCross(plist1,plist2);
	printf ("%d\n",ret);


	/*if(ret!=NULL)
	{
		printf ("带环\n");
	}
	else
	{
		printf ("no\n");
	}*/
	/*ret = JosephCycle(&plist1,3);
	printf ("ret = %d\n",ret->data);*/
	//PrintList(plist1);

	/*PushBack(&plist2,3);
	PushBack(&plist2,5);
	PushBack(&plist2,7);
	PushBack(&plist2,13);
	PrintList(plist2);*/

	//DelNotTailNode(Find(plist,6));
	//InsertFrontNode(Find(plist,4),8);
	//BubbleSort(&plist);
	//DelKNode(&plist,2);
	/*ret = Merge(plist1,plist2);
	PrintList(ret);*/
    /*ret = FindMidNode(plist);
	printf ("%d\n",ret->data);*/
	//ReversePrint(plist);


}
void test3()
{
	pComplexNode pNode1 = CrecteComplexNode(1);
	pComplexNode pNode2 = CrecteComplexNode(2);
	pComplexNode pNode3 = CrecteComplexNode(3);
	pComplexNode pNode4 = CrecteComplexNode(4);
	pComplexNode pNode5 = CrecteComplexNode(5);


	pNode1->next = pNode2;
	pNode2->next = pNode3;
	pNode3->next = pNode4;

	pNode1->random = pNode4;
	pNode2->random = pNode1;
	pNode3->random = pNode2;
	pNode4->random = pNode2;
	CloneComplexNode(pNode1);
	PrintComplexList(pNode1);

}
int main()
{
	test3();
	return 0;
}