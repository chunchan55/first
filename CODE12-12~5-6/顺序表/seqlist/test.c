#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

enum 
{
	Exit,
	pushback,
	popback,
	pushfront,
	popfront,
	move,
	removeall,
	bubblsort,
	binarysearch,
	insert,
	reverse,
	print,

};
void menu()
{
	printf ("***********************************************\n");
	printf ("******    1.pushback     2.popback    *********\n");
	printf ("******    3.pushfront     4.popfront  *********\n");
	printf ("******    5.move     6.removeall    *********\n");
	printf ("******  7.bubblsort  8.binarysearch   *********\n");
	printf ("******   9.insert      10.reverse      *********\n");
	printf ("******   11.print      0.Exit          *********\n");

}
void test ()
{
	SeqList list;
	int input = 0;
	/*InitSeqList(&list);
	PushBack(&list,3);
	PushBack(&list,4);
	PushBack(&list,5);
	PushBack(&list,6);
	Print(&list);*/
	InitSeqList(&list);
	menu();
	do 
	{
		printf("请输入你要实现的命令的数字:");
		scanf ("%d",&input);
		switch (input)
		{
		case pushback:
		{
			int d = 0;
			printf ("输入你要添加的数字:");
			scanf("%d",&d);
			PushBack(&list,d);
		}
			
			break;
		case popback:
			PopBack(&list);
			break;
		case pushfront:
			{
				int d = 0;
				printf ("输入你要添加的数字:");
				scanf("%d",&d);
				PushFront(&list,d);
			}
			break;
		case popfront:
			PopFront(&list);
			break;
		case move:
			{
				int d = 0;
				printf ("输入你要删除的数字:");
				scanf("%d",&d);
				Remove(&list,d);
			}
			break;
		case removeall:
			{
				int d = 0;
				printf ("输入你要删除的数字:");
				scanf("%d",&d);
				RemoveAll(&list,d);
			}
			break;
		case bubblsort:
			BubblSort(&list);
			break;
		case binarysearch:
			{
				int d = 0;
				int ret = 0;
				int left = 0;
				int right = list.sz-1;
				printf ("输入你要查找的数字:");
				scanf("%d",&d);
				ret = bin_sear(&list,d,left,right);
				printf ("%d\n",ret);
			}
			break;
		case insert:
			{
				int d = 0;
				int pos = 0;
				printf ("输入你要添加数的位置和要添加的数字:");
				scanf("%d %d",&pos,&d);
				Insert(&list,pos,d);
			}
			break;
		case reverse:
			Reverse(&list);
			break;
		case print:
			Print(&list);
			break;
		case Exit:
			DestorySeqList(&list);
			break;
		default:
			printf ("输入错误，请重输\n");
			break;

		}
	} while (input);
}
int main()
{
	test ();
	return 0;

}
