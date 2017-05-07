#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
使用宏实现两个数中求较大值
#define MAX(X,Y) (X>Y?X:Y)
int main ()
{
	int a = 0;
	int b = 0;
	printf ("请输入两个整数：");
	scanf ("%d%d",&a,&b);
	printf ("较大的数是：%d\n",MAX(a,b));
	return 0;
}
2.使用宏将一个数二进制中的奇数位和偶数位进行交换
#define CHANGE_BITE(NUM) ((((NUM)&0X55555555)<<1)|\
	(((NUM)&0XAAAAAAAA)>>1))
这里0x55555555和0xaaaaaaaa是16进制，奇数位左移，偶数位右移
int main ()
{
	int i= 0;
	printf ("请输入一个数：");
	scanf("%d",&i);
	printf ("移位后的数为：%d\n",CHANGE_BITE(i));
	return 0;


}
实现一个函数，可以左旋字符串中的k个字符。
char *left_move(char *str,int step)
{
	int i = 0;
	int len = strlen(str);
	for (i=0;i<step;i++)
	{
		char tmp = str[0];
		int j = 0;
		for (j=0;j<len-1;j++)
		{
			str[j] = str[j+1];
		}
		str[len-1] = tmp;
	}
	return 0;
}
int main ()
{
	char p[]="abcdef";
	int k = 0;
	printf ("请输入要左旋的数：");
	scanf ("%d",&k);
	left_move(p,k);
	printf ("%s\n",p);
	return 0;
}
int main ()
{
	char ch[20] = "abcdef";
	char *p = NULL;
	char arr[20]="aa";
	int ret = 0;
	printf ("请输入要验证的字符串：");
	scanf ("%s",&arr);
	ret = strlen(arr);
	if (ret!=strlen(ch))
	{
		printf ("no!\n");
	}
	else
	{
	    strncat(ch,ch,6);
		p = strstr(ch,"bcdefa");
		
		if (p==NULL)
		{
			printf ("no!\n");
		}
		else 
		{
			printf ("yes\n");
		}
	}
	return 0;
	
}