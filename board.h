#ifndef board_h
#define board_h

#include <stdio.h>

typedef struct Board_Struct{
   int num_rows,num_cols;
   char** board;
}Board;  // Board hhh    hhh.num_rows
void set_up(Board* b, int num_rows, int num_cols);
char** make_b(int num_rows, int num_cols);
void print_b(Board* b);
void clean_b(Board* b);


#endif

