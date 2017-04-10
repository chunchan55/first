#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
void game ()
{
	int x = 0;
	int y = 0;
	int win = 0;
	int i = 0;
	int j = 0;
	char board[ROWS+2][COLS+2]={0};//�����а������׵�λ��
	char mine[ROWS+2][COLS+2]={0};//���ɨ�׵����
	init_board(board,ROWS+2,COLS+2,'0');
	init_board(mine,ROWS+2,COLS+2,'*');
	//print_board(board,ROWS+2,COLS+2);
	//print_board(mine,ROWS+2,COLS+2);
	srand((unsigned int)time(NULL));
	set_mine(board,ROWS+2,COLS+2);
	print_board(board,ROWS+2,COLS+2);
	print_board(mine,ROWS+2,COLS+2);
	while (win<(COLS*ROWS-DEFAULT_COUNT))
	{ 
		printf ("����������>");
		scanf ("%d%d",&x,&y);
		if ((x>=1)&&(x<=ROWS)&&(y>=1)&&(y<=COLS))
		{
			;
		}
		else 
		{
			printf ("�±�����������\n");
            continue;
		}

		//�±�Ϸ����ж�
		for (i=x;i<=ROWS;i++)
		{
			for (j=y;j<=COLS;j++)
			{
				if (get_mine(board,i,j)==0)
				{
					mine[i][j]=(char)NULL;
				}
				else 
				{
					mine[i][j]=(get_mine(board,i,j))+'0';
					break;
				}
					
			}
			if (j==y)
				break ;

		}
		for (i=x;i>=0;i--)
		{
			for (j=y;j<=COLS;j++)
			{
				if (get_mine(board,i,j)==0)
				{
					mine[i][j]=(char)NULL;
				}
				else 
			{
					mine[i][j]=(get_mine(board,i,j))+'0';
					break;
				}
			}
			if (j==y)
				break;
		}
		for (i=x;i<=COLS;i++)
		{
			for (j=y;j>=0;j--)
			{
				if (get_mine(board,i,j)==0)
				{
					mine[i][j]=(char)NULL;
				}
				else 
				{
					mine[i][j]=(get_mine(board,i,j))+'0';
					break;
				}
			}
			if (j==y)
				break;
		}
		for (i=x;i>=0;i--)
		{
			for (j=y;j>=0;j--)
			{
				if (get_mine(board,i,j)==0)
				{
					mine[i][j]=(char)NULL;
				}
				else 
					{
					mine[i][j]=(get_mine(board,i,j))+'0';
					break;
				}
			}
			if (j==y)
				break;
		}//�����̽�����չ
		if (board[x][y]=='1')
		{
			printf ("���ź����㱻ը����\n");
			break ;
		}
		else 
		{
			int count = 0;
			win++;
			 count=get_mine(board,x,y);
			mine[x][y] = count + '0';
			print_board(mine,ROWS+2,COLS+2)	;

		}

	}
	if(win>=(COLS*ROWS-DEFAULT_COUNT))
	printf("��ϲ�㣬ɨ�׳ɹ�\n");
	
}
void menue ()
{
	printf ("****************************\n");
	printf ("***** 1.play  0.exit  *****\n");
	printf ("****************************\n");
}
int main ( )
{
	int input = 0;
	menue();
	do
	{
		printf ("��ѡ��>:");
		scanf ("%d",&input);
		switch(input)
		{
		case 1:
			{
				game ();
				break ;
			}
		case 0:
			{
				break ;
			}
		default :
		 {
			printf ("����������>:\n");
			break ;
		 }
		}
	}
	while (input);
	return 0;
}