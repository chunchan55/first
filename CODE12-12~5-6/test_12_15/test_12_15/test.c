#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//第二题
#include <math.h>
unsigned int reserve_bit (unsigned int value)
{
	int i=0;
	int sum = 0;
	for (i=0;i<32;i++)
	{
		sum = sum+((value>>i)&1)*pow(2,32-i-1);
		
	}
	return sum;

}
int main ()
{
	int num=0;
	printf ("请输入要反转的数");
	scanf ("%d",&num);
	printf ("%u\n", reserve_bit(num));
	return 0;
}
////第四题
//int main ()
//{
//	int arr[5]={1,1,2,2,3};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int i = 0;
//	for (i=1;i<sz;i++)
//	{
//		arr[0]=arr[0]^arr[i];
//	}
//	printf ("%d ",arr[0]);
//	return 0;
//}
////第一题
//int f_com (int a,int b)
//{
//	int count = 0;
//	int m = 0;
//	m = a^b;
//	while (m>0)
//	{
//		m = m &(m-1);
//		count++;
//	}
//	return count;
//}
//int main ()
//{
//	int a = 0;
//	int b = 0;
//	printf ("请输入两个数：");
//	scanf ("%d%d",&a,&b);
//	printf ("%d\n",f_com(a,b));
//	return 0;
//}
////第三题
//int main ()
//{
//	int a = 0;
//	int b = 0;
//	int aver = 0;
//	scanf ("%d %d",&a,&b);
//	aver = a-(a-b)/2;
//	printf ("%d\n",aver);
//	return 0 ;
//}