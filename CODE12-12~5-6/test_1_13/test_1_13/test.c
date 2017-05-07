#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
模拟实现strcpy函数，字符串的拷贝
char *my_strcpy(char *m ,char const*n )
{
	char *ret = m;
	assert(n!=NULL);
	assert(m!=NULL);
	while (*n)
	{
		*m = *n;
		m++;
		n++;
	}
	*m='\0';
	return ret;

}
int main ()
{
	char p[]="hello i love you";
	char *q="chun chan";
	printf ("第一个字符串:%s\n",p);
	printf ("第二个字符串:%s\n",q);
	printf ("strcpy后的字符串:%s\n",my_strcpy(p,q));
	return 0;

}
模拟实现strlen函数
int my_strlen(const char *str)
{  
   assert(str);  
      if(*str)
	  {  
        return (1+my_strlen(str+1));  
    }  
        return 0;  
}  //归递
int main()
{	int len = 0;
	char *p = "abcdefqw";

	len = my_strlen(p);
	printf("%d\n",len);
	return 0;

}
模拟实现strcat函数
char *my_strcat(char *dest,const char *src)
{
	char *ret = dest;
	assert (dest!=NULL);
	assert (src!=NULL);
	while ((*dest)!='\0') 
	{
		dest++;
	}
	while ((*dest++)=(*src++))
	{
		;
	}
	return ret ;
	
}
int main ()
{
	char p[20] ="hello ";
	char *q="my honey";
	printf ("%s\n",my_strcat(p,q));
	return 0 ;
}
模拟实现strcmp函数，比较字符串，ASCII值的比较
int my_strcmp(const char *p,const char *q)
{
	assert (p!=NULL);
	assert (q!=NULL);
	while ((*p)==(*q))
	{
		if (*q=='\0')
		
			return 0;
			p++;
			q++;
	}
		//return (*p-*q);
		if (*p>*q)
		{
		  return 1;
		}
		else 
			if (*p<*q)
		{
			return -1;
		}

}
int main ()
		  
{
 	printf ("%d\n",my_strcmp("qwer","abc"));
	printf ("%d\n",my_strcmp("abb","abc"));
	printf ("%d\n",my_strcmp("qwer","qwer"));
	return 0;

}
strstr函数的功能和实现
char *my_strstr (const char *des ,const char *src)
{
	assert (des!=NULL);
	assert (src!=NULL);
	while (*des!='\0')
	{
		const char *p = des;
		const char *q = src;
		const char *res = NULL;
	if (*p==*q)
	{
		res = p;
		while ((*p++)==(*q++))
		{
			;
		}
		if (*q=='\0')
			return res;

	}
	des++;
  }
	return NULL;
}
int main ()
{
	const char m[] = "qwerty";
	const char n[] = "wert";
	const char *res = my_strstr(m,n);
	printf ("%s\n",res);
	return 0;
}
