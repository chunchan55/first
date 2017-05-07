#define  _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"
#include "game.h"
#include <string.h>
void init_board(char board[ROWS+2][COLS+2],int rows,int cols,char ch)
{
	memset(board,ch,rows*cols*sizeof(char));
}
void print_board(char board[ROWS+2][COLS+2],int rows,int cols)
{
	int i = 0;
	int j = 0;
	printf("   ");
	for (i=0;i<cols-2;i++)
	{
		printf ("%d ",i+1);
	}//输出行号
	printf("\n");
	for (i=0;i<rows-2;i++)
	{	
		printf("%2d ",i+1);//输出列号
		for(j=0;j<cols-2;j++)
		{
			printf ("%c ",board[i+1][j+1]);
			
		}
		printf ("\n");
	}
	
}
void set_mine(char board[ROWS+2][COLS+2],int rows,int cols)
{
	int x = 0;
	int y = 0;
	int count = DEFAULT_COUNT;
	while(count)
	{
		x = rand()%10+1;
		y = rand()%10+1;
		if(board[x][y]!='1')
		{
			board[x][y]='1';
			count--;
		}
	}
}
int get_mine(char board[ROWS+2][COLS+2],int rows,int cols)
{
	return (board[rows-1][cols]-'0')+
		   (board[rows-1][cols-1]-'0')+
		   (board[rows-1][cols+1]-'0')+
		   (board[rows][cols-1]-'0')+
		   (board[rows][cols+1]-'0')+
		   (board[rows+1][cols]-'0')+
		   (board[rows+1][cols-1]-'0')+
		   (board[rows+1][cols+1]-'0');

		   
}