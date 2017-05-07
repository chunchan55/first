#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <ctype.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483646
//模拟实现atoi函数
long long  my_atoi(const char *str)
{
	long long  ret = 0;
	int p = 1;
	assert (str);
	while (isspace(*str))
	{
		str++;
	}
	if (*str=='-')
	{
		p = -1;
		str++;
	}
	else if (*str=='+')
	{
		;
	}
	else 
	{
		return 0;
	}
	if (((ret*10 + p*(*str-'0'))>INT_MAX)||((ret*10 + p*(*str-'0')))<(INT_MIN))
	{
		printf("数据溢出\n");
		return 0;
	}
	
	while((*str)&&(isdigit(*str)))
	{
		ret = ret*10 + p*(*str-'0');
		str++;
	}
	return ret;
}
int main ()
{
	char arr[] = "   -12#3";
  long long  ret = my_atoi(arr);
 int  bat = atoi(arr) ;
 printf ("%d\n",bat);
  printf ("ret = %ld\n",ret);
  return 0;
}
//int main ()
//{
//	char c;//-128~127
//	unsigned char uc;//0~255
//	unsigned short us;///
//	c = 128;//  11111111 11111111 11111111 10000000
//	uc = 128;// 00000000 00000000 00000000 10000000
//	us = c+uc;//1 00000000 00000000 00000000 00000000 读取两个字节
//	printf ("0x%x\n",us);//0
//	us = (unsigned char)c+uc;//00000000 00000000 00000001 00000000
//	printf ("0x%x\n",us);//读取两个字节 258
//	us = c+(char)uc;// 11111111 11111111 11111111 10000000
//	                // 11111111 11111111 11111111 10000000
//				//   1 11111111 11111111 11111111 00000000
//	             //    f    f    f   f    f   f    0  0
//	printf ("0x%x\n",us);//读取两个字节 ff00
//	return 0;
//
//}
//int main ()
//{
//	printf ("int=%d\n",sizeof(int));
//	printf ("unsigned int=%d\n",sizeof(unsigned int));
//	printf ("char=%d\n",sizeof(char));
//	printf ("unsigned char=%d\n",sizeof(unsigned char));
//	printf ("short=%d\n",sizeof(short));
//	printf ("unsigned short=%d\n",sizeof(unsigned short));
//	printf ("double=%d\n",sizeof(double));
//	printf ("float=%d\n",sizeof(float));
//	printf ("long=%d\n",sizeof(long));
//	printf ("long long=%d\n",sizeof(long long));
//	return 0;
//}
//void main()
//{
//	unsigned char a = 100;//00000000 00000000 00000000 01100100
//	unsigned char b = 200;//00000000 00000000 00000000 11001000
//	unsigned char c = 0; // 00000000 00000000 00000001 00101100//a+b一个字节
//	c = a+b;//无符号的字符型0~255
//	printf ("%d %d\n",c,a+b);
//	return 0;
//}
//void fun (char achello[])
//{
//	printf ("%d\n",sizeof(achello));
//	return;
//}
//int main()
//{
//	char achello[] = "hello,bit";
//	fun (achello);//传的是首元素的地址，是一个指针
//	return 0;
//}
//int main ()
//{
//	char arr[] = "qwert";
//	char brr[] = {'q','w','e','r','t'};
//	printf ("%d %d\n",strlen(arr),strlen(brr));//第二个没有\0,所以为随机值
//	printf ("%d %d\n",sizeof(arr),sizeof(brr));
//	return 0;
//}
//int main()
//{
//	char s[]="123";
//	printf ("%s\n",s);
//	return 0;
//}
//大小端
//int sys_check()
//{
//	int num = 1;
//	char *p = (char*)&num;
//	return *p;
//}
//union St
//{
//	int a;
//	char b;
//};//联合体共用一块内存；
//int sys_check()
//{
//	union St s;
//	s.a = 1;
//	return s.b;
//}
//int main ()
//{
//	//int ret = sys_check();
//	int ret = sys_check();
//	if (ret==1)
//	{
//		printf ("小端字节序\n");
//
//	}
//	else if (ret==0)
//	{
//		printf ("大端字节序\n");
//
//	}
//	return 0;
//}
//void bit_set(unsigned char*p_data,unsigned char pos,int flag)
//{
//	assert(p_data!=NULL);
//	assert (pos>=1&&pos<=8);
//	if (flag==1)
//	{
//		*p_data |=(1<<(pos-1));
//
//	}
//	else if(flag==0)
//	{
//		*p_data &=~(1<<(pos-1));
//
//	}
//
//}
//int main ()
//{
//	unsigned char c = 10;//00001010
//	//bit_set(&c,3,1);
//	bit_set(&c,3,0);
//	printf("%d\n",c);
//
//
//	/*unsigned short *p[10][10];
//	printf ("%d\n",sizeof(p));
//	return 0;*/
//}
//字符串的右旋
//
//void right_hand(char*str,unsigned short len)
//{
//	int num = 0;
//	int i = 0;
//	char tmp = 0;
//	assert(str);
//
//	for (i=0;i<len;i++)
//	{
//		num = strlen (str)-1;
//		//num--;
//		tmp = str[num];
//		while (num>0)
//		{
//			str[num] = str[num-1];
//			num--;
//		}
//		str[num] = tmp;
//	}
//}
//int main()
//{
//	char a[] = "abcdefg";
//	right_hand(a,3);
//	printf ("%s\n",a);
//	return 0;
//}
//int main ()
//{
//	FILE*pf = fopen("test.txt","w");//r+既允许读也允许写
//	                                //写入文件的开头，a写入末尾
//	                               //w可以清空文件的内容，fopen
//	int ch = 0;
//	char arr[20] = {0};
//	if (pf==NULL)
//	{
//		perror("open file");
//		return 0;
//	}
//	fgets(arr,20,pf);
//	fputs("hehe",pf);
//return 0;
//}
//void main( void )
//{
//	char  buffer[200], s[] = "computer", c = 'l';
//	int   i = 35, j;
//	float fp = 1.7320534f;
//
//	/* Format and print various data: */
//	j  = sprintf( buffer,     "\tString:    %s\n", s );
//	j += sprintf( buffer + j, "\tCharacter: %c\n", c );
//	j += sprintf( buffer + j, "\tInteger:   %d\n", i );
//	j += sprintf( buffer + j, "\tReal:      %f\n", fp );
//
//	printf( "Output:\n%s\ncharacter count = %d\n", buffer, j );
//}
//
