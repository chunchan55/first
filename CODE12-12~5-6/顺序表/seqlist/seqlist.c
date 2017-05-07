#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"
void InitSeqList (pSeqList plist)
{
	plist->sz = 0;
	plist->data = (DataType*)malloc(DEFAULT_SZ*sizeof(SeqList));
	if (plist->data==NULL)
	{
		strerror(errno);
		return ;
	}
	memset(plist->data,0,DEFAULT_SZ*sizeof(SeqList));
	plist->capacity = DEFAULT_SZ;
}
void checkcapacity(pSeqList plist)
{
	if(plist->sz==plist->capacity)
	{
		DataType *ptr = (DataType*)realloc(plist->data,(plist->sz+INC_SZ)*sizeof(SeqList));
		if (ptr==NULL)
		{
			printf ("out of memory\n");
			exit(EXIT_FAILURE);
		}
		else 
		{
			plist->data = ptr;
		}
		plist->capacity += INC_SZ;
	}
}

void PushBack(pSeqList plist,DataType d)//在尾部加一个数
{
	assert(plist);
	checkcapacity(plist);
	plist->data[plist->sz] = d;
	plist->sz++;

}
void PopBack(pSeqList plist)//删除尾部的一个数
{
	assert(plist);
	plist->sz--;
}
void PushFront(pSeqList plist,DataType d)//在头部加一个数
{
	int i = 0;
	assert(plist);
	checkcapacity(plist);
	for(i=plist->sz;i>0;i--)
	{
		plist->data[i] = plist->data[i-1];
	}
	plist->data[0] = d;
	plist->sz++;
}
void PopFront(pSeqList plist)//删除头部的一个数
{
	int i = 0;
	assert(plist);
	for (i=0;i<plist->sz-1;i++)
	{
		plist->data[i] = plist->data[i+1];
	}
	plist->sz--;
}
int Find(pSeqList plist,DataType d)
{
	int i = 0;
	for (i=0;i<plist->sz;i++)
	{
		if(plist->data[i]==d)
			return i;
	}
	return -1;
}
void Remove(pSeqList plist,DataType d)//删除指定的一个数
{
	int i = 0;
	int pos = Find (plist,d);
	assert (plist);
	for (i=pos;i<plist->sz-1;i++)
	{
		plist->data[i] = plist->data[i+1];
	}
	plist->sz--;
	
}
void RemoveAll(pSeqList plist,DataType d)//删除指定的的所有数
{
	int i = 0;
	int pos = 0;
	assert (plist);
	while((pos=Find(plist,d))!=-1)
	{
		for (i=pos;i<plist->sz-1;i++)
		{
			plist->data[i] = plist->data[i+1];
		}
		plist->sz--;
	}
}
void BubblSort(pSeqList plist)//冒泡排序
{
	int i =0;
	assert (plist);
	for(i=0;i<plist->sz-1;i++)
	{
		int j = 0;
		for (j=0;j<plist->sz-i-1;j++)
		{
			DataType tmp = 0;
			if (plist->data[j]>plist->data[j+1])
			{
				tmp = plist->data[j];
				plist->data[j] = plist->data[j+1];
				plist->data[j+1] = tmp;
			}
		}
	}

}
int BinarySearch(pSeqList plist,DataType d)//二分查找
{
	int left = 0;
	int right = plist->sz-1;
	int mid = 0;
	assert(plist);
	while (left<=right)
	{
	    mid = left-(left-right)/2;
		if(plist->data[mid]>d)
		{
			right = mid-1;
		}
		else if(plist->data[mid]<d)
		{
			left = mid+1;
		}
		else if(plist->data[mid]==d)
		return mid;
	}
	return -1;
}
void Insert(pSeqList plist,int pos,DataType d)//在特定的位置插入一个数
{
	int i =0;
	assert(plist);
	checkcapacity(plist);
	for (i=plist->sz;i>=pos;i--)
	{
		plist->data[i] = plist->data[i-1];
	}
	plist->data[pos] = d;
	plist->sz++;
}
void Reverse(pSeqList plist)//逆序
{
	DataType tmp = 0;
	int left = 0;
	int right = plist->sz-1;
	while(left<right)
	{
		tmp = plist->data[left];
		plist->data[left] = plist->data[right];
		plist->data[right] = tmp;
		left++;
		right--;
	}

}
void Print (pSeqList plist)
{
	int i = 0;
	for(i=0;i<plist->sz;i++)
	{
		printf ("%d ",plist->data[i]);
	}
printf ("\n");
}
void DestorySeqList(pSeqList plist)
{
	if (plist->data!=NULL)
	{
		free(plist->data);
		plist->data = NULL;
	}
}

int bin_sear(pSeqList plist,DataType d,int left,int right)
{
	if (left<=right)
	{
		int mid = left-(left-right)/2;
		if (plist->data[mid]>d)
			return bin_sear(plist,d,left,mid-1);
		else if(plist->data[mid]<d)
			return bin_sear(plist,d,mid+1,right);
		else if (plist->data[mid]==d)
			return mid;
	}
	else 
		return -1;
}