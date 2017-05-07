#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,


};
void menu ()
{
	printf ("***************1.ADD      *******\n");
	printf ("***************2.DEL      *******\n");
	printf ("***************3.SEARCH   *******\n");
	printf ("***************4.MODIFY   *******\n");
	printf ("***************5.SHOW     *******\n");
	printf ("***************6.SORT     *******\n");
	printf ("***************0.EXIT     *******\n");

}
void test ()
{
	int input = 0;
	Contact con = {0} ;
	InitContact(&con);
	do
	{
		menu();
		printf ("请选择>:");
	    scanf ("%d",&input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
		    SortContact(&con);
			break;
		case EXIT:
			break;
		default :
			printf ("输入有误，请重新输入！\n");
			break;

		}
	}while (input);

}
int main ()
{
  
	test();
	return 0;
}
