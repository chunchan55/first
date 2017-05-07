#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define DEFAULT_SZ 2
#define INC_SZ  2
typedef int DataType;
typedef struct SeqList
{
	DataType *data ;
	int capacity;
	int sz;
}SeqList,*pSeqList;
void InitSeqList (pSeqList plist);
void PushBack(pSeqList plist,DataType d);//在尾部加一个数
void PopBack(pSeqList plist);//删除尾部的一个数
void PushFront(pSeqList plist,DataType d);//在头部加一个数
void PopFront(pSeqList plist);//删除头部的一个数
void Remove(pSeqList plist,DataType d);//删除指定的一个数
void RemoveAll(pSeqList plist,DataType d);//删除制定的的所有数
void BubblSort(pSeqList plist);//冒泡排序
int BinarySearch(pSeqList plist,DataType d);//二分查找
void Insert(pSeqList plist,int pos,DataType d);//在特定的位置插入一个数
void Reverse(pSeqList plist);//逆序
void Print (pSeqList plist);
void DestorySeqList(pSeqList plist);
void checkcapacity(pSeqList plist);
int bin_sear(pSeqList plist,DataType d,int left,int right);



#endif  //__SEQLIST_H__

