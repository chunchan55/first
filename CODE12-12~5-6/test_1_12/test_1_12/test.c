#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//编写一个函数实现n^k，使用递归实现
#include <stdlib.h>
#include <string.h>
//int my_pow(int n,int k)
//{
//	int sum = 0;
//	if (k==0)
//	{
//		sum = 1;
//	}
//	else 
//	{
//		sum = n*my_pow(n,k-1);
//	}
//	return sum ;
//}
//int main ()
//{
//	int n = 0;
//	int k = 0;
//
//	printf  ("请输入两个整数>:");
//	scanf ("%d%d",&n,&k);
//	printf ("%d\n",my_pow(n,k));
//	return 0;
//}
//写一个递归函数DigitSum(n)，输入一个非负整数，
//返回组成它的数字之和
//int my_sum(unsigned int num)
//{
//	int sum = 0;
//	int m = 0;
//	int n = num;
//	if (n)
//	{
//		m = n%10;
//		n = n/10;
//		sum = m+my_sum(n);
//	}
//	return sum ;
//
//}
//int main ()
//{
//	unsigned int num = 0;
//	printf ("请输入一个正整数>:");
//	scanf ("%d",&num);
//	printf ("各个位数字之和为：%d\n",my_sum(num));
//	return 0;
//}
//编写一个函数reverse_string(char * string)（递归实现)
//char *reverse_string(char * string)
//{
//	char temp = '0';
//	char *first = string;
//	char *last = string;
//	int len = strlen (string);
//	last = last+len-1;//最后一个字符的地址
//	while(string<last)
//	{
//		temp = *string;
//		*string++ = *last;
//		*last--=temp;
//	}
//	return first;
//}
//int main ()
//{
//	char *reverse_string(char * string);
//	char p[]="qweryu";
//	printf ("源字符串:%s\n",p);
//	printf ("反转后的：%s\n",reverse_string(p));
//	return 0;
//}
//模拟实现printf函数
#include <stdarg.h>
char print (char *format, ...)
{
	
	va_list arg;
	char *p=NULL;
	va_start(arg,format);
	while (*format)
	{
		switch (*format)
		{
		case 's':
			{
				p = va_arg(arg,char*);
				while (*p)
				{
					putchar (*p);
					p++;
				}
				break ;
		case 'c':
			{
				char *ch = va_arg(arg,char*);
				putchar (*ch);
			}
			break ;
		default :
			{
				char *str = va_arg(arg,char*);
				putchar (*str);
			}
			break ;

			}
		}
		/*if (*format!='\0')
		{
			if (*format=='s')
			{
				p = va_arg(arg,char*);
				printf ("%s",p);
			}
			else if (*format =='c')
			{
				p = va_arg(arg,char*);
				printf ("%c",p);
			}
			
		}*/
		format++;
	}
	va_end (arg);
	return 0;
}
int main ()
{
	print("s ccc.\n","hello",'b','i','t');
	return 0 ;
}