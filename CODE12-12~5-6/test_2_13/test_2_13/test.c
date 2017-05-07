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
//	printf ("%p\n",&fun);//加不加取地址符都可以取出函数的地址
//	printf ("%p\n",fun);
//
//	return 0;
//}
//函数指针
//void fun (const char *str)
//{
//	printf ("%s\n",str);
//}
//int main ()
//{
//	int arr [3];
//	int (*parr)[3] = &arr;//数组指针
//	//用类比的方法写出函数指针
//	void (*pfun)(const char *) = &fun ;
//	//函数指针--是一个指针，它有能力指向一个函数
//	(*pfun)("hehe\n");//*可加可不加
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
//	//pfunarr是一个函数指针的数组，数组有三个元素，
//	//每个元素是一个指针，这个指针能指向一个函数，
//	//这个函数的参数是const char *，
//	//返回类型为 void
//	(*(*ppfunarr[3]))(const char *) = &pfunarr;
//	//指向函数指针数组的指针
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
	//定义一个函数指针的数组使代码更简单
	do
	{
		menu();
		printf ("请选择>");
		scanf ("%d",&input);
		printf ("请输入操作数>");
		scanf ("%d%d",&num1,&num2);
		ret = parr[input](num1,num2);
	/*	switch (input)
		{
		
			case 1:
			printf ("请输入操作数>");
			scanf ("%d%d",&num1,&num2);
			ret = Add(num1,num2);
			break;
			case 2:
			printf ("请输入操作数>");
			scanf ("%d%d",&num1,&num2);
			ret =Sub(num1,num2);
			break;
			case 3:
			printf ("请输入操作数>");
			scanf ("%d%d",&num1,&num2);
			ret = Mul(num1,num2);
			break;
			case 4:
			printf ("请输入操作数>");
			scanf ("%d%d",&num1,&num2);
			ret = Div(num1,num2);
			break;

		}*/
		printf ("ret = %d\n",ret);
	}
	while (input);
	return 0;
}

