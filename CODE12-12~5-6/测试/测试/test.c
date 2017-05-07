#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//char *my_strcpy(char *m ,char const*n )
//{
//	char *ret = m;
//	assert(n!=NULL);
//	assert(m!=NULL);
//	while (*n)
//	{
//		*m = *n;
//		m++;
//		n++;
//	}
//	*m='\0';
//	return ret;
//
//}
//int main ()
//{
//	char p[]="hello i love you";
//	char *q="wan xin";
//	printf ("第一个字符串:%s\n",p);
//	printf ("第二个字符串:%s\n",q);
//	printf ("strcpy后的字符串:%s\n",my_strcpy(p,q));
//	return 0;
//
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//
//
//int my_strlen( char *p)
//{
//	int count = 0;
//	assert(p!=NULL);
//	while(*p);
//	{
//		count++;
//		p++;		
//	}
//	return count;
//}///错误的
//int main()
//{	int len = 0;
//	char *p = "abcdef";
//
//	len = my_strlen(p);
//	printf("%d\n",len);
//	return 0;
//
//}
//int my_strlen(const char *str)
//{  
//   assert(str);  
//      if(*str)
//	  {  
//        return (1+my_strlen(str+1));  
//    }  
//        return 0;  
//}  //递归

////方法三:通过char*变量,模拟实现strlen函数  
//int my_strlen3(const char *str){  
//    const char *end = str;  
//	assert(str);  
//    while(*end++){  
//        ;  
//    }  
//    return (end-str-1);  
//大小端字节检验
int sys_check()
{
	int num = 1;
	char *p = (char *)&num;
	if (*p==1)
	return 1;//小端字节序
	else 
		return 0;//大端字节序
}
int main ()
{
	int a = 1;
	int ret = sys_check();
	if (ret==1)
		printf ("小端字节序\n");
	else 
		printf ("大端字节序\n");
	return 0;
}