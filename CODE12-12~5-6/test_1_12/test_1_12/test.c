#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
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
//	printf  ("��������������>:");
//	scanf ("%d%d",&n,&k);
//	printf ("%d\n",my_pow(n,k));
//	return 0;
//}
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ�������
//���������������֮��
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
//	printf ("������һ��������>:");
//	scanf ("%d",&num);
//	printf ("����λ����֮��Ϊ��%d\n",my_sum(num));
//	return 0;
//}
//��дһ������reverse_string(char * string)���ݹ�ʵ��)
//char *reverse_string(char * string)
//{
//	char temp = '0';
//	char *first = string;
//	char *last = string;
//	int len = strlen (string);
//	last = last+len-1;//���һ���ַ��ĵ�ַ
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
//	printf ("Դ�ַ���:%s\n",p);
//	printf ("��ת��ģ�%s\n",reverse_string(p));
//	return 0;
//}
//ģ��ʵ��printf����
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