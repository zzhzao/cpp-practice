#pragma once
#include<stdio.h>
#include<time.h>
#include<string.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10


void initboard(char board[ROWS][COLS], int r, int c, char set);
void displayboard(char board[ROWS][COLS], int r, int c);
void setmine(char mine[ROWS][COLS], int r, int c);
void findmine(char mine[ROWS][COLS],char show[ROWS][COLS], int r, int c);
