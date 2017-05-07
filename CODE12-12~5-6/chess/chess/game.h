#ifndef     __GANE_H__
#define     __GANE_H__
#define    ROWS  3
#define    COLS  3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>


void print_board (char board[ROWS][COLS],int rows,int cols );
void init_board (char board[ROWS][COLS],int rows,int cols );
void player_move (char board[ROWS][COLS],int rows,int cols);
void computer_move (char board[ROWS][COLS],int rows,int cols);
char f_win(char board[ROWS][COLS],int rows,int cols);





#endif      //__GANE_H__