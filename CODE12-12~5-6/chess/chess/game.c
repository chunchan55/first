#define  _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"
#include "game.h"
#include<string.h>
void init_board(char board[ROWS][COLS],int rows,int cols )
{
	memset(board,' ',rows*cols*(sizeof(char)));
}
void print_board (char board[ROWS][COLS],int rows,int cols )
{
	int i = 0;
	for (i=0;i<cols;i++)
	{
		printf (" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		if (i!=(cols-1))
		printf ("---|---|---\n");


	}
}
void player_move (char board[ROWS][COLS],int rows,int cols)
{
	int x = 0;
	int y = 0;
	printf ("请输入两个下标>:");
	scanf ("%d%d",&x,&y);
	x--;
	y--;
	if ((x>=0)&&(x<=rows-1)&&(y>=0)&&(y<=cols-1))
	{
		if (board[x][y]==' ')
		{
			board[x][y]='X';
			
		}
		else 
		{
			printf ("下标错误，请重新输入！");
		}
	}
	else 
	{
		printf ("输入有误！");
	}

}

void computer_move (char board[ROWS][COLS],int rows,int cols)
{
	while (1)
	{
		int x=rand()%3;
		int y=rand()%3;
		if (board[x][y]==' ')
		{
			board[x][y]='0';
			break ;
		}
			
	}

}
static int f_full(char board[ROWS][COLS],int rows,int cols)
{
	int i = 0;
	int j = 0;
	for (i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
			if (board[i][j]==' ')
			return 0;
	}
	return 1;
}
char f_win(char board[ROWS][COLS],int rows,int cols)
{
	int i =0;
	for (i=0;i<rows;i++)
	{
		if ((board[i][0]==board[i][1])&&(board[i][1]==board[i][2])&&(board[i][0])!=' ')
		return board[i][0];
	}
//判断每行的元素是否相同
for (i=0;i<cols;i++)
	{
		if ((board[0][i]==board[1][i])&&(board[1][i]==board[2][i])&&(board[0][i])!=' ')
		return board[0][i];
	}


if ((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])&&(board[0][0])!=' ')
return board [0][0];
if ((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])&&(board[1][1])!=' ')
return board [0][2];
if (f_full(board,rows,cols))
{
	return 'p';
}
return ' ';
}