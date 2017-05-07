#define  _CRT_SECURE_NO_WARNINGS
//讲一个数组中的奇数都放到偶数的前面
#include <stdio.h>
void f_change (int *arr,int sz)
{
	int i = 0;
	int j = sz-1;
	for (i=0;i!=j;i++)
	{
		if (arr[i]%2!=0)
		{
			continue ;
		}
		else 
		{
			int t = arr[i];
			arr[i]=arr[j];
			arr[j]=t;
			
		if (arr[j]%2==0)
		{	
			j--;
			i--;

		}
		    
		}


	}
}
int main ( )
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);
	f_change(arr,sz);
	for (i=0;i<sz;i++)
	{
		printf ("%d ",arr[i]);
	}
	return 0;
}
//杨氏矩阵中查找一个数字
//#include <stdio.h>
//int f_num(int arr[][3],int key,int rows,int cols)
//{
//	int row = 0;
//	int col = cols-1;
//	while ((col>=0)&&(row<=2))
//	{
//		if (arr[row][col]<key)
//			row++;
//		else if (arr[row][col]>key)
//			col--;
//		else 
//		{
//			return 1;
//		
//		}
//	}
//		return 0;
//}
//int main ( )
//{
//	int arr [3][3]={1,2,3,4,5,6,7,8,9};
//	int key =15;
//	int ret=f_num(arr,key,3,3);
//	if (ret)
//		printf("存在！\n");
//	else printf("不存在！\n");
//	return 0;
//
//
//}
