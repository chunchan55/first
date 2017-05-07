#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*int main ()
{
	int i = 0;
	for (i=1;i<=100;i++)
	{
		int j = 0;
		int count = 0;
		int sum = 0;
		for(j=1;j<=i;j++)
		{
			if((i%j)==0)
			{
				count++;
			}
		}
		if(count<=2)
		{
			sum = sum + i;
			printf ("%d ",i);
		}
	}
	printf ("\n");
	printf ("%d\n",sum);
	return 0;
}*/

int main ()
{
	char ch[] = {"abc\0def"};
	char *p = ch;
	printf ("%c\n",*p+4);
	printf ("%d\n",sizeof(ch));
	return 0;
}
