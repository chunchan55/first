#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"


void game ()
{
	char board[ROWS][COLS]={0};
	char ret = 0;
	init_board(board,ROWS,COLS);
	print_board(board,ROWS,COLS);
	srand((unsigned int)time(NULL));
	while (1)
	{
		printf ("�����>\n");
		player_move(board,ROWS,COLS);
		print_board(board,ROWS,COLS);
		if ((ret=f_win(board,ROWS,COLS))!=' ')
			break;
		printf ("������>\n");
		computer_move(board,ROWS,COLS);
		print_board(board,ROWS,COLS);
		if ((ret=f_win(board,ROWS,COLS))!=' ')
			break;
		

	}
	    ret=f_win(board,ROWS,COLS);
		if (ret=='X')
		{
			printf ("��ϲ�㣬Ӯ�ˣ�\n");
		}
		else if (ret=='0')
		{
			printf ("������˼�������ˣ�\n");
		}
		else if (ret=='p')
		{
			printf ("ƽ�֣�\n");
		}
        print_board(board,ROWS,COLS);

}
void menu ()
{
	printf ("****************************\n");
	printf ("***** 1.play  0.exit  *****\n");
	printf ("****************************\n");
}

int main ( )
{
	
	int input = 0;
	menu ();
	do
	{
		
		printf ("��ѡ��>:");
		scanf ("%d",&input);
		switch (input)
		{
		case 1:
		   {
			    game ();
				break ;
		    }
		case 0:
			{
				break;
			}
		default:
			{
				printf ("����������>:");
				break ;
			}
		}
	}while (input);
	return 0;
}