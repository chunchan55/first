#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __LIST_H__
#define __LIST_H__
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node*next;
}Node,*pNode,*pList;//结点

typedef struct ComplexNode
{
	DataType D;
	struct ComplexNode*next;
	struct ComplexNode*random;
}ComplexNode,*pComplexNode;


void InitList(pList *pplist);
void PushBack(pList *pplist,DataType d);
void PopBack(pList *pplist);
void PushFront(pList *pplist,DataType d);
void PopFront(pList *pplist);
void PrintList(pList plist);//打印
pNode Find(pList plist,DataType d);//找到那个元素，返回他的地址
void Remove(pList *pplist,DataType d);//删除指定的元素
void RemoveAll(pList *pplist,DataType d);//删除指定元素的所有

void Insert(pList *pplist,pNode pos,DataType d);//指定位置的后面插入
void Erase(pList *pplist,pNode pos);//指定位置删除
void ReverseList(pList *pplist);//逆序
void BubbleSort(pList *pplist);//冒泡排序
void DelNotTailNode(pNode pos);//删除指定位置的下一个，不是尾结点
void InsertFrontNode(pNode pos,DataType d);//在指定位置的前面插入一个

void ReversePrint(pList plist);//逆序打印链表
pNode FindMidNode(pList plist);//找到中间结点，遍历一次
void DelKNode(pList *pplist,int k);//删除链表的倒数第K个结点
pList Merge(pList l1,pList l2);//合并两个链表
pNode JosephCircle(pList *pplist,int num);//约瑟夫环
pNode CheckCircle(pList plist);//判断是否带环，若带环，返回相遇点
int GetCircleLen(pNode meet);//求环的长度
pNode GetCircleEntry(pList plist,pNode meet);//求环的入口点
int CheckCross(pList l1,pList l2);//判断两个单链表是否相交

void DestroyList(pList *pplist);


pComplexNode CrecteComplexNode(DataType d);//创建复杂链表的结点
void PrintComplexList(pComplexNode head);//打印复杂链表
pComplexNode CloneComplexNode(pComplexNode head);//复制复杂链表

#endif //__LIST_H__
