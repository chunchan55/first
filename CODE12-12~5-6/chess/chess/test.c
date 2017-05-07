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
		printf ("玩家走>\n");
		player_move(board,ROWS,COLS);
		print_board(board,ROWS,COLS);
		if ((ret=f_win(board,ROWS,COLS))!=' ')
			break;
		printf ("电脑走>\n");
		computer_move(board,ROWS,COLS);
		print_board(board,ROWS,COLS);
		if ((ret=f_win(board,ROWS,COLS))!=' ')
			break;
		

	}
	    ret=f_win(board,ROWS,COLS);
		if (ret=='X')
		{
			printf ("恭喜你，赢了！\n");
		}
		else if (ret=='0')
		{
			printf ("不好意思，你输了！\n");
		}
		else if (ret=='p')
		{
			printf ("平局！\n");
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
		
		printf ("请选择>:");
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
				printf ("请重新输入>:");
				break ;
			}
		}
	}while (input);
	return 0;
}