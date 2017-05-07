#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//int fib (int n)
//{
//	if (n<=2)	printf ("%d\n",sizeof(p));
//	return 1;
//	else 
//		return fib (n-1)+fib(n-2);
//}
//int main ()
//{
//	printf ("%d\n",fib(40));
//	return 0;
//}
//int main ()
//{
//	int *p = NULL;
//	int a[100];
//	char b[100];
//
//	printf ("%d\n",sizeof(p));//指针变量的长度为4
//	printf ("%d\n",sizeof(*p));//借用指针为整型长度为4
//	printf ("%d\n",sizeof(a));
//	printf ("%d\n",sizeof(a[100]));
//	printf ("%d\n",sizeof(&a));
//	printf ("%d\n",sizeof(&a[0]));
//
//	
//	printf ("%d\n",sizeof(b));
//	printf ("%d\n",sizeof(b[100]));
//	printf ("%d\n",sizeof(&b));
//	printf ("%d\n",sizeof(&b[0]));
//	
//}
//二分法
//#include <stdio.h>
//int bin_search(int arr[],int key,int sz)
//{
//	int left = 0;
//	int right = sz-1;
//	while (left<=right)
//	{
//		int mid = (left+right)/2;
//		if (arr[mid]<key)
//		{
//			left = mid+1;
//		}
//		else if(arr[mid]>key)
//		{
//			right = mid-1;
//		}
//		else 
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main ()
//{
//	int arr[10]={1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int n = bin_search(arr,7,sz);
//	if (n==-1)
//	{
//		printf ("找不到\n");
//	}
//	else 
//	printf ("找到了：%d\n",arr[n]);
//	return 0;
//}
//字符串的反转
//#include <stdio.h>
//#include <string.h>
//int main ()
//{
//	char p[]="abcdefg";
//	int n = strlen(p);
//	char tmp = 'q';
//	int i = 0;
//	for (i=0;i<(n/2);i++)
//	{
//		tmp = p[i];
//		p[i] = p[n-1-i];
//		p[n-1-i] = tmp;
//	}
//	printf ("%s\n",p);
//	return 0;
//
//}
模拟实现strcpy函数
#include <stdio.h>
#include <assert.h>
char *my_strcpy(char *des,const char *src)
{
	char *ret = des;
	assert (des!=NULL);
	assert (src!=NULL);
	while ((*des++)=(*src++))
	{
		;
	}
	return ret;
}
int main ()
{
	char arr[10] ={0};
	char *p = "abcdef";
	char *ret = my_strcpy(arr,p);
	printf ("%s\n",ret);
	return 0;
}
模拟实现strlen函数

int my_strlen(const char *src)
{
	int count = 0;
	assert(src);
	while ((*src++))
	{
		count ++;
	}
	return count;
}
int main ()
{
	char *p="abcdef";
	int ret = my_strlen(p);
	printf ("%d\n",ret);
	return 0;
}
模拟实现字符串的追加strcat
char *my_strcat(char *des,const char *src)
{
	char *ret = des;
	assert(des);
	assert(src);
	while (*des)
	{
		des++;
	}
	while ((*des++)=(*src++))
	{
		;
	}
	return ret;
}
int main ()
{
	char arr[20] = "hello ";
	char *p = "world!";
	char *ret = my_strcat(arr,p);
	printf ("%s\n",ret);
	return 0;
}
模拟实现字符串的比较函数strcmp
int my_strcmp(const char *des,const char *src)
{
	assert (des);
	assert(src);
	while ((*src)||(*des))
	{
		if (*des>*src)
		{
			return 1;
			break;
		}
		else if (*des<*src)
		{
			return -1;
			break;
		}
		else if (*des==*src)
		{
			des++;
			src++;
		}
	}
	return 0;
}
int main ()
{
	char *p = "cdefdf";
	char *q ="cdef";
	int ret = my_strcmp(p,q);
	if (ret==1)
	{
		printf ("较大的字符串是：%s\n",p);
	}
	else 
		if (ret==-1)
	{
		printf ("较大的字符串是：%s\n",q);
	}
	else if (ret==0)
	{
		printf ("两个字符串相等\n");
	}
	return 0;
}
//模拟实现字符串中查找字符串函数strstr
