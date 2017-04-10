#ifndef     __GANE_H__
#define     __GANE_H__
#define    ROWS  10
#define    COLS  10
#define    DEFAULT_COUNT 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void init_board(char board[ROWS+2][COLS+2],int rows,int cols,char ch);
void print_board(char board[ROWS+2][COLS+2],int rows,int cols);
void set_mine(char board[ROWS+2][COLS+2],int rows,int cols);
int get_mine(char board[ROWS+2][COLS+2],int rows,int cols);




#endif      //__GANE_H__