#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
ʹ�ú�ʵ������������ϴ�ֵ
#define MAX(X,Y) (X>Y?X:Y)
int main ()
{
	int a = 0;
	int b = 0;
	printf ("����������������");
	scanf ("%d%d",&a,&b);
	printf ("�ϴ�����ǣ�%d\n",MAX(a,b));
	return 0;
}
2.ʹ�ú꽫һ�����������е�����λ��ż��λ���н���
#define CHANGE_BITE(NUM) ((((NUM)&0X55555555)<<1)|\
	(((NUM)&0XAAAAAAAA)>>1))
����0x55555555��0xaaaaaaaa��16���ƣ�����λ���ƣ�ż��λ����
int main ()
{
	int i= 0;
	printf ("������һ������");
	scanf("%d",&i);
	printf ("��λ�����Ϊ��%d\n",CHANGE_BITE(i));
	return 0;


}
ʵ��һ�����������������ַ����е�k���ַ���
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
	printf ("������Ҫ����������");
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
	printf ("������Ҫ��֤���ַ�����");
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