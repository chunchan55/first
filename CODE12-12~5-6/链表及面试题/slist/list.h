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
}Node,*pNode,*pList;//���

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
void PrintList(pList plist);//��ӡ
pNode Find(pList plist,DataType d);//�ҵ��Ǹ�Ԫ�أ��������ĵ�ַ
void Remove(pList *pplist,DataType d);//ɾ��ָ����Ԫ��
void RemoveAll(pList *pplist,DataType d);//ɾ��ָ��Ԫ�ص�����

void Insert(pList *pplist,pNode pos,DataType d);//ָ��λ�õĺ������
void Erase(pList *pplist,pNode pos);//ָ��λ��ɾ��
void ReverseList(pList *pplist);//����
void BubbleSort(pList *pplist);//ð������
void DelNotTailNode(pNode pos);//ɾ��ָ��λ�õ���һ��������β���
void InsertFrontNode(pNode pos,DataType d);//��ָ��λ�õ�ǰ�����һ��

void ReversePrint(pList plist);//�����ӡ����
pNode FindMidNode(pList plist);//�ҵ��м��㣬����һ��
void DelKNode(pList *pplist,int k);//ɾ������ĵ�����K�����
pList Merge(pList l1,pList l2);//�ϲ���������
pNode JosephCircle(pList *pplist,int num);//Լɪ��
pNode CheckCircle(pList plist);//�ж��Ƿ������������������������
int GetCircleLen(pNode meet);//�󻷵ĳ���
pNode GetCircleEntry(pList plist,pNode meet);//�󻷵���ڵ�
int CheckCross(pList l1,pList l2);//�ж������������Ƿ��ཻ

void DestroyList(pList *pplist);


pComplexNode CrecteComplexNode(DataType d);//������������Ľ��
void PrintComplexList(pComplexNode head);//��ӡ��������
pComplexNode CloneComplexNode(pComplexNode head);//���Ƹ�������

#endif //__LIST_H__
