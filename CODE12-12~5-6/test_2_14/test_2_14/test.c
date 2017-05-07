#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stu
{
	char name [20];
	int age;
	double score ; 
}Stu;
int cmp_int (const int *elem1,const int *elem2)
{
	return *elem1-*elem2;
}
int cmp_stu(const void *elem1,const void *elem2)
{
	return  strcmp ((*(Stu*)elem1).name ,(*(Stu*)elem2).name );
}

int main ()
{
	//int arr[10] = {9,8,7,6,5,4,3,2,1,0};
	struct Stu arr[10] = {{"zhangsan",15,68.8},
	                      {"lisi",16,78.6},
	                      {"wangwu",18,87.3}};
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);
	qsort (arr ,sz,sizeof (arr[0]),&cmp_stu);
	//qsort (arr ,sz,sizeof (arr[0]),&cmp_int);

	for (i=0;i<sz;i++)
	{
		printf ("%s ",arr[i].name);
		//printf ("%d ",arr[i] );

	}
	return 0;
	

}

//自己设计一个快排函数，可以排任意的类型
//typedef struct Stu
//{
//	char name [20];
//	int age;
//	double score ; 
//}Stu;
//int cmp_stu(const void *elem1,const void *elem2)
//{
//	return  strcmp ((*(Stu*)elem1).name   ,(*(Stu*)elem2).name );
//}
//
//void my_swap(char* num1,char*num2,int sz)
//{
//	int i = 0;
//	for (i=0;i<sz;i++)//一个字节一个字节的交换
//	{
//		char tmp = *(num1+i);
//		*(num1+i) = *(num2+i);
//		*(num2+i) = tmp;
//	}
//}
//void bubble_sort (void *base ,size_t sz,
//				  size_t width,int (*cmp)(const void *elem1,const void *elem2))
//{
//	size_t i = 0;
//	size_t j = 0;
//	for (i=0;i<sz-1;i++)
//	{
//		for (j=0;j<sz-1-i;j++)
//		{
//			if (cmp((char*)base+j*width,
//				(char*)base+width*(j+1))>0)
//			{
//				my_swap((char*)base+j*width,
//				(char*)base+width*(j+1),width);
//			}
//		}
//	}
//}
//
//
//int main ()
//{
//	struct Stu arr[10] = {{"zhangsan",15,68.8},
//	                      {"lisi",16,78.6},
//	                      {"wangwu",18,87.3}};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	bubble_sort (arr ,sz,sizeof (arr[0]),&cmp_stu);
//	for (i=0;i<sz;i++)
//	{
//		printf ("%s\n",arr[i].name );
//	}
//
//	return 0;
//	
//
//}
//				  