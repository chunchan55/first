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
void PushBack(pSeqList plist,DataType d);//��β����һ����
void PopBack(pSeqList plist);//ɾ��β����һ����
void PushFront(pSeqList plist,DataType d);//��ͷ����һ����
void PopFront(pSeqList plist);//ɾ��ͷ����һ����
void Remove(pSeqList plist,DataType d);//ɾ��ָ����һ����
void RemoveAll(pSeqList plist,DataType d);//ɾ���ƶ��ĵ�������
void BubblSort(pSeqList plist);//ð������
int BinarySearch(pSeqList plist,DataType d);//���ֲ���
void Insert(pSeqList plist,int pos,DataType d);//���ض���λ�ò���һ����
void Reverse(pSeqList plist);//����
void Print (pSeqList plist);
void DestorySeqList(pSeqList plist);
void checkcapacity(pSeqList plist);
int bin_sear(pSeqList plist,DataType d,int left,int right);



#endif  //__SEQLIST_H__

