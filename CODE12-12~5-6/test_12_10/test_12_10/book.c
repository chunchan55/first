#define  _CRT_SECURE_NO_WARNINGS
//二分查找c
#include <stdio.h>
int bin_search(int arr[],int sz,int key)
{
 int i = 0;
 int left = 0;
 int right = sz-1;
 while (left<=right)
 {
  int mid = (left + right )/2;
  if (arr[mid]>key)
  {
   right = mid - 1;
  }
  else if (arr[mid]<key)
  {
   left = mid + 1;
  }
  else 
  {
   return mid ;
  }
 }
 return -1;
 
}
int main ( )
{
 int arr [10] = {1,2,3,4,5,6,7,8,9,11};
 int key=7;
 int mid = 0;
 int sz = sizeof(arr)/sizeof(arr[0]);
 int n= bin_search (arr,sz,key);
 if (n==-1)
 {
  printf ("找不到\n");
 }
 else 
 {
  printf ("%d\n",arr[n]);
 }
 
 return 0 ;
}
//清空初始化逆序数组
void init(int arr[],int sz)
{
 int i = 0;
 int num = 0;
 printf ("请输入五个数：");
 for(i=0;i<sz;i++)
 {
  scanf ("%d",&num);
  arr[i] = num;
 }
}
void empty (int arr[],int sz)
{
 int i = 0;
 for  (i=0;i<sz;i++)
 {
  arr[i] = 0;
 }
}
void reserve (int arr[],int sz)
{
 int i = 0;
 int arr2[5];
 for (i=0;i<sz;i++)
 {
  arr2[i] = arr [i];
 }
 for (i=0;i<sz;i++)
 {
  arr[i] =arr2[sz-i-1];
 }
}
int main ( )
{
 int i = 0;
 int arr[5]={0};
 int sz = sizeof(arr)/sizeof(arr[0]);
 init (arr,sz);
 for(i=0;i<sz;i++)
 {
  printf ("%d ",arr[i]);
 }
 printf ("\n");
 reserve (arr,sz);
 for(i=0;i<sz;i++)
 {
  printf ("%d ",arr[i]);
 }
 printf ("\n");
 empty (arr,sz);
 for(i=0;i<sz;i++)
 {
  printf ("%d ",arr[i]);
 }
 printf ("\n");
 return 0;
}
//函数定义闰年
void  f_year(int year,int n )
{
 
 for (year=1000;year<=n;year++)
 {
  if (((year%4==0)&&(year%100!=0))||(year%400==0))
  printf ("%d ",year);
 }
 
}
int main ( )
{
 int i = 0;
 int n = 0;
 printf ("请输入你想输出1000到多少的闰年：");
 scanf ("%d",&n);
 f_year (i,n);
 return 0;
 
}
//交换两个数
void f_exch (int *i,int *j )
{
 int tmp = 0;
 tmp = *i;
 *i = *j;
 *j = tmp;
}
int main ( )
{ 
 int a = 0;
 int b = 0;
 printf ("请输入两个数：");
 scanf ("%d%d",&a,&b);
 f_exch(&a,&b);
 printf ("%2d%2d\n",a,b);
return 0;
}
//乘法口诀表
  void f_mul (int n)
 {
  int i=0;
  int j=0;
  for (i=1;i<=n;i++)
  {
   for (j=1;j<=i;j++)
   {
    printf ("%d*%d=%2d\t",i,j,i*j);
   }
   printf("\n");
  }
  
 }
 int main ()
 {
  int n=0;
  printf ("请输入你想输出的行：");
  scanf ("%d",&n);
  f_mul(n);
  return 0;
 }


