#include <stdio.h>
#include <stdlib.h>
#include "board.h"


//set up the board
void set_up(Board* b, int num_rows, int num_cols){
    b->board = make_b(num_rows,num_cols);
    b->num_rows = num_rows;
    b->num_cols = num_cols;
    //pass in the type of numrows and numcols from struct
    
    return;
}

//make the board by using the values of numrows and numcols
char** make_b(int num_rows, int num_cols){
     char** b = (char**)malloc((num_rows) * sizeof(char*));
    
    int i, j;
    
    for(i = 0; i < num_rows; ++i){
        b[i] = (char*)malloc(num_cols*sizeof(char));
        for(j = 0; j < num_cols; ++j){
            b[i][j] = '*';
        }
    }
    return b;

}

//print out the board
void print_b(Board* b){
    
    int i,j;
   
    for(i =(b->num_rows) - 1; i >= 0; --i){
        printf("%d ", i);
        for(j = 0; j < b->num_cols; ++j){
            printf("%c ",b->board[i][j]);
        }
        printf("\n");
    }
    
    printf("  ");
    for(j = 0; j < b->num_cols; ++j){
        printf("%d ", j);
    }
    printf("\n");
}

//clean up the board(free the 2D array we created)
void clean_b(Board* b){
    int i;
    for(i = 0; i < b->num_rows; ++i){
        free(b->board[i]);
    }
    free(b->board);
}


