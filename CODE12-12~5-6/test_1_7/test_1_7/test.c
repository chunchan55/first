#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int add(int x,int y)
//{
//	int ret = 0;
//	ret = x+y;
//	return ret ;
//}
//int main ()
//{
//	int x = 10;
//	int y = 5;
//	int m = 0;
//	m = add(x,y);
//	printf ("%d\n",m);
//	return 0;
//}
//
//2.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
 // 找出这两个数字，编程实现。

int f_two(int num)
{
	int ret = 0;
	while (num)
	{
		if (num%2==1)
		{
			return ret;
		}
		ret++;
		num/=2;
	}
	return -1;
}
void find (int *a,int sz,int *p,int *q)
{
	int find = 0;
	int pos = 0;
	int i = 0;
	for (i=0;i<sz;i++)
	{
		find ^=a[i];
	}
		pos = f_two(find);
		for (i=0;i<sz;i++)
		{
			if (1&(a[i]>>pos))
		{
			*p^=a[i];
		}
		else 
		{
			*q ^=a[i];
		}	
	}
}
int main ()
{
	int a[8]={1,1,2,2,4,5,3,3};
	int sz = sizeof(a)/sizeof(a[0]);
	int num1 = 0;
	int num2 = 0;
	find (a,sz,&num1,&num2);
	printf ("num1=%d\n",num1);
	printf ("num2=%d\n",num2);

}