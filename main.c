#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "board.h"
#include "case.h"




void read_args(int argc, char* argv[], int* num_rows, int* num_cols){
    //when the arguments in command line are 3
    if(argc== 3){
        int i = 0;
        for(i=0;i<strlen(argv[1]);++i){
	   if(i==0 && argv[1][i]=='-'){
               continue;
            }
          //evaluate the arguments in command line are valid
           else if(!isdigit(argv[1][i])){
                printf("The number of rows is not an integer.\n");
                printf("Making default board of 10 X 10.\n");
                *num_rows = 10;
                *num_cols = 10;
                return;
            }
           else{
                 *num_rows = atoi(argv[1]);
                 *num_cols = atoi(argv[2]);
           }
        }

        for(i=0;i<strlen(argv[2]);++i){
            if(i==0 && argv[2][i] == '-'){
                continue;
            }
            //evaluate the arguments in command line are valid
            else if(!(isdigit(argv[2][i]))){
                printf("The number of columns is not an integer.\n");
                printf("Making default board of 10 X 10.\n");
                *num_rows = 10;
                *num_cols = 10;
                return;
            }

            else{
                 *num_rows = atoi(argv[1]);
                 *num_cols = atoi(argv[2]);
           }

        }
      

        //num_rows can't less than 1
        
        if(*num_rows < 1){
           printf("The number of rows is less than 1.\n");
           printf("Making default board of 10 X 10.\n");
           *num_rows = 10;
           *num_cols = 10;
           return;
        }
        //num_cols can't less than 1
        else if(*num_cols < 1){
            printf("The number of columns is less than 1.\n");
            printf("Making default board of 10 X 10.\n");
            *num_rows = 10;
            *num_cols = 10;
            return;
        }
         *num_rows = atoi(argv[1]);
         *num_cols = atoi(argv[2]); 
         
          }
    else if(argc==1){
        *num_rows = 10;
        *num_cols = 10;
    }
    
    //wrong number of arguments or commnad in command line
    else{
        printf("Wrong number of command line arguements entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        printf("Making default board of 10 X 10.\n");
        *num_rows = 10;
        *num_cols = 10;
        
    }
}


int main(int argc, char* argv[]) {
    Board b;
    int num_rows = 0;
    int num_cols = 0;
    
    
    read_args(argc,argv,&num_rows,&num_cols);
    set_up(&b,num_rows,num_cols);
    print_b(&b);
    get_command(&b);
    clean_b(&b);
    return 0;
}

