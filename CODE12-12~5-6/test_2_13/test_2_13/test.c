#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//void fun ()
//{
//	printf ("hehe\n");
//}
//int main ()
//{
//	fun ();
//	(*&fun)();
//	printf ("%p\n",&fun);//�Ӳ���ȡ��ַ��������ȡ�������ĵ�ַ
//	printf ("%p\n",fun);
//
//	return 0;
//}
//����ָ��
//void fun (const char *str)
//{
//	printf ("%s\n",str);
//}
//int main ()
//{
//	int arr [3];
//	int (*parr)[3] = &arr;//����ָ��
//	//����ȵķ���д������ָ��
//	void (*pfun)(const char *) = &fun ;
//	//����ָ��--��һ��ָ�룬��������ָ��һ������
//	(*pfun)("hehe\n");//*�ɼӿɲ���
//	pfun("hehe\n");
//	fun ("hehe\n");
//	return 0;
//	
//}
//void fun1(const char *str)
//{
//	printf ("fun1:%s\n",str);
//}
//void fun2(const char *str)
//{
//	printf ("fun2:%s\n",str);
//}
//void fun3(const char *str)
//{
//	printf ("fun3:%s\n",str);
//}
//int main ()
//{
//	void (*pfun1)(const char *) = fun1;
//	void (*pfun2)(const char *) = fun2;
//	void (*pfun3)(const char *) = fun3;
//	void (*pfunarr[3])(const char *) = {fun1,fun2,fun3};
//	//pfunarr��һ������ָ������飬����������Ԫ�أ�
//	//ÿ��Ԫ����һ��ָ�룬���ָ����ָ��һ��������
//	//��������Ĳ�����const char *��
//	//��������Ϊ void
//	(*(*ppfunarr[3]))(const char *) = &pfunarr;
//	//ָ����ָ�������ָ��
//	int i = 0;
//	for (i=0;i<3;i++)
//	{
//		pfunarr[i]("zhangsan");
//	}
//	return 0;
//
//}

#include <stdio.h>
#include <string.h>
void menu()
{
	printf (" 1.add 2.sub 3.mul 4.div\n");
}
int Add(int a,int b)
{
	return a+b;
}
int Sub(int a,int b)
{
	return a-b;
}
int Mul(int a,int b)
{
	return a*b;
}
int Div(int a,int b)
{
	return a/b;
}
int main ()
{
	int input = 0;
	int num1 = 0;
	int num2 = 0;
	int ret = 0;
	int (*parr[5])(int, int) = {0,Add,Sub,Mul,Div};
	//����һ������ָ�������ʹ�������
	do
	{
		menu();
		printf ("��ѡ��>");
		scanf ("%d",&input);
		printf ("�����������>");
		scanf ("%d%d",&num1,&num2);
		ret = parr[input](num1,num2);
	/*	switch (input)
		{
		
			case 1:
			printf ("�����������>");
			scanf ("%d%d",&num1,&num2);
			ret = Add(num1,num2);
			break;
			case 2:
			printf ("�����������>");
			scanf ("%d%d",&num1,&num2);
			ret =Sub(num1,num2);
			break;
			case 3:
			printf ("�����������>");
			scanf ("%d%d",&num1,&num2);
			ret = Mul(num1,num2);
			break;
			case 4:
			printf ("�����������>");
			scanf ("%d%d",&num1,&num2);
			ret = Div(num1,num2);
			break;

		}*/
		printf ("ret = %d\n",ret);
	}
	while (input);
	return 0;
}

