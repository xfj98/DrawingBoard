#include "case.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

bool validinput(int num_args_read, int num_args_need){
    return (num_args_read == num_args_need);
}

void w_write(Board* b){
    int x1=0;
    int x2=0;
    int y1=0;
    int y2=0;
    int num_args_read = 0;    
    
    char new_line;
    bool test = true;
    
    
   
       num_args_read = scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
   do{
       scanf("%c",&new_line);
        if(!isspace(new_line)){           
            test = false;
         }
        }while(new_line != '\n');
   
  //number of arguments we need should be 4 in this case
   if(num_args_read != 4){
      printf("Improper draw command.\n");
      print_b(b);
    }

  else if(test == false){
         printf("Improper draw command.\n");
         print_b(b);
         return;
      }
   //those int can't less than 0 or larger than numrows or numcols
   else if (x1 < 0 || y1 <0 || x2 < 0 || y2 < 0|| x1 >= b->num_rows || x2 >= b->num_rows || y1 >= b->num_cols|| y2 >= b->num_cols){
     printf("Improper draw command.\n");
      print_b(b);
     }
    else{
 
        int i = 0; int j = 0;
        
        //horizontal
        if(x1 == x2 && y1 < y2){
            for(i = y1;i <= y2;++i){
                if(b->board[x1][i] == '-'|| b->board[x1][i] == '*'){
                b->board[x1][i] = '-';
            }
                //differnt direction intersects at one point
               else{
                b->board[x1][i] = '+';
              }
            }
         print_b(b);
        
      }
        //horizontal
        else if(x1 == x2 && y1 > y2){
            for(i = y1;i >= y2;--i){
                if(b->board[x1][i] == '-' || b->board[x1][i] == '*'){
                b->board[x1][i] = '-';
            }
                //differnt direction intersects at one point
                else{
                b->board[x1][i] = '+';
              }
             }
       print_b(b);
        
      }
        //vertical
        else if(y1 == y2 && x1 < x2){
            for(j = x1; j <= x2; ++j){
                if(b->board[j][y1] == '|' || b->board[j][y1] == '*'){
                b->board[j][y1] = '|';
            }
                //differnt direction intersects at one point
                else{
                b->board[j][y1] = '+';
             }
            }
          print_b(b);
        
     }
        //vertical
        else if(y1 == y2 && x1 > x2){
            for(j = x1; j >= x2; --j){
               if(b->board[j][y1] == '|' || b->board[j][y1] == '*'){
                b->board[j][y1] = '|';
            }
               //differnt direction intersects at one point
               else{
                 b->board[j][y1] = '+';
            }
           }
       print_b(b);
        }
       else if(x1 == x2 && y1 == y2){
        b->board[x1][y1] = '-';
        print_b(b);
        }

       //diagonal
        else{
            int deltx = 0; int delty = 0;
                deltx = x2 - x1;
                delty = y2 - y1;
            
                 //right diagonal
                if(delty % deltx == 0){
                    if(delty / deltx == 1 && x1 < x2){
                       
                            for(i=x1; i<= x2;++i){
                                if(b->board[i][y1+(i-x1)] == '/' || b->board[i][y1+(i-x1)] == '*'){
                                b->board[i][y1+(i-x1)] = '/';
                            }
                               //differnt direction intersects at one point
                                else{
                                  b->board[i][y1+(i-x1)] = '+';
                               }
                            }
                      print_b(b);
                   }
                    else if(delty / deltx == 1 && x1 > x2){
                            for(i=x1; i >= x2; --i){
                               if(b->board[i][y1+(i-x1)] == '/' || b->board[i][y1+(i-x1)] == '*'){
                                b->board[i][y1+(i-x1)] = '/';
                            }
                               //differnt direction intersects at one point
                               else{
                                b->board[i][y1+(i-x1)] = '+';
                             }
                          }
                       print_b(b);
                        }
                    //left diagonal
                    else if(delty / deltx == -1 && x1 < x2){
                        for(i=x1; i <= x2;++i){
                           if(b->board[i][y1-(i-x1)] == '\\' || b->board[i][y1-(i-x1)] == '*'){
                            b->board[i][y1-(i-x1)] = '\\';
                        }
                           //differnt direction intersects at one point
                           else{
                            b->board[i][y1-(i-x1)] = '+';
                         }
                       }
                    print_b(b);
                    }
                    else if(delty / deltx == -1 && x1 > x2){
                         for(i=x1; i >= x2; --i){
                            if(b->board[i][y1-(i-x1)] == '\\' || b->board[i][y1-(i-x1)] == '*'){
                            b->board[i][y1-(i-x1)] = '\\';
                        }
                            //differnt direction intersects at one point
                            else{
                                b->board[i][y1-(i-x1)] = '+';
                          }
                      }
                     print_b(b);
                    }
                   else{
                     printf("Cannot draw the line as it is not straight.\n");
                     print_b(b);
                    }
                }
                //invalid command
                else{
                    printf("Cannot draw the line as it is not straight.\n");
                }
            }
        
   }
}

void add(Board* b){
    char position;
    int value;
    int i =0;
    int j =0;
    int num_args_read = 0;
    bool test = true;
    char new_line;
    num_args_read = scanf(" %c %d",&position,&value);
    do{
       scanf("%c",&new_line);
        if(!isspace(new_line)){
            test = false;
         }
        }while(new_line != '\n');
         //to evaluate the valid command
        if(test == false){
          printf("Improper add command.\n");
          print_b(b);
          return;
        }
   

    if((!(validinput(num_args_read,2)))||((position == 'r') && (value > b->num_rows))||((position =='c') && (value > b->num_cols))||(value < 0)){
        printf("Improper add command.\n");
        print_b(b);
    }
    //when the command is valid
    else{
        //add row
        if(position == 'r'){
        b->board = (char**)realloc(b->board, (b->num_rows+1)*sizeof(char*));
            b->board[b->num_rows] = (char*)malloc(b->num_cols*sizeof(char));
            
             
            for(i=b->num_rows-1;i>=value;--i){
                for(j=0;j<b->num_cols;++j){
                    b->board[i+1][j]= b->board[i][j];
                }
            }
            for(i=0;i<b->num_cols;++i){
                b->board[value][i] = '*';
            }
            b->num_rows = b->num_rows + 1;
            print_b(b);
        }
       //add col
        else if(position == 'c'){
            for(i=0;i<b->num_rows;++i){
                b->board[i] = (char*)realloc(b->board[i], (b->num_cols+1)*sizeof(char));

                for(j=b->num_cols;j>=value;--j){
                    b->board[i][j+1] = b->board[i][j];
                }
            }
            for(i=0;i<b->num_rows;++i){
                b->board[i][value] = '*';
            }
            b->num_cols = b->num_cols + 1;
            print_b(b);
            
        }
        //unrecognized command
        else{
            printf("Improper add command.\n");

        }
    }
    
}

void delete(Board* b){
    char position;
    int value;
    int i =0;
    int j =0;
    bool test = true;
    char new_line;
    
    int num_args_read = 0;
    num_args_read = scanf(" %c %d",&position,&value);
      do{
       scanf("%c",&new_line);
        if(!isspace(new_line)){
            test = false;
         }
        }while(new_line != '\n');

        if(test == false){
          printf("Improper delete command.\n");
          print_b(b);
          return;
        }
  //to evaluate the valid command
   else if((!(validinput (num_args_read,2)))||((position == 'r') && (value >= b->num_rows))||((position =='c') && (value >= b->num_cols))||value < 0){
        printf("Improper delete command.\n");
        print_b(b);
    }
    else{
        //delete row
        if(position == 'r'){
            for(i=value;i<b->num_rows-1;++i){
                for(j=0;j<b->num_cols;++j){
                    b->board[i][j] = b->board[i+1][j];
                }
            }
            b->board = (char**)realloc(b->board,(b->num_rows-1)*sizeof(char*));
            b->num_rows = b->num_rows - 1;
            print_b(b);
        }
        //delete col
        else if(position == 'c'){
            for(j=value;j<b->num_cols-1;++j){
                for(i=0;i<b->num_rows;++i){
                    b->board[i][j] = b->board[i][j+1];
                }
            }
            b->board[i] = (char*)realloc(b->board[i],(b->num_cols-1)*sizeof(char));
            b->num_cols = b->num_cols - 1;
            print_b(b);
        }
        else{
            printf("Improper delete command.\n");
        }
    }

    
}

void resize(Board* b){
    char** new_board;
    int new_rows, new_cols;
    int i =0;
    int j = 0;
    int min_num_rows, min_num_cols;

    int num_args_read = 0;
    num_args_read = scanf("%d %d",&new_rows,&new_cols);
    
    
    if((!(validinput (num_args_read,2)))|| ((new_rows <= 0) || (new_cols <= 0))){
        printf("Improper resize command.\n");
        print_b(b);
    }
    else{
        //create new 2D char array
        new_board = (char**)malloc((new_rows)*sizeof(char*));
        for(i=0;i<new_rows;++i){
            new_board[i] = (char*)malloc((new_cols)*sizeof(char));
        }
        //make a new board
        for(i=0;i<new_rows;++i){
            for(j=0;j<new_cols;++j){
                new_board[i][j] = '*';
            }
        }
        min_num_rows = b->num_rows;
        if(min_num_rows > new_rows){
            min_num_rows = new_rows;
        }
        
        min_num_cols = b->num_cols;
        if(min_num_cols > new_cols){
            min_num_cols = new_cols;
        }
        
        //Copy all the char into the new board
        for(i=0;i<min_num_rows;++i){
            for(j=0;j<min_num_cols;++j){
                new_board[i][j] = b->board[i][j];
            }
        }

    for(i = 0; i < b->num_rows; ++i){
        free(b->board[i]);
    }
    free(b->board);
    
    b->num_rows = new_rows;
    b->num_cols= new_cols;
    b->board = new_board;
    print_b(b);
   }
}

void e_erase(Board* b){
    int row, col;
    int num_args_read = 0;
    num_args_read = scanf("%d %d",&row,&col);
    
    
    if((!(validinput (num_args_read,2)))||(row>=b->num_rows)||(col>=b->num_cols)||row<0||col<0){
        printf("Improper erase command.\n");
        print_b(b);
    }
    //change the char at specific coordinate to *
    else{
        b->board[row][col] = '*';
        print_b(b);
    }
   
}

void savefile(Board* b){
    char name[100];
    int num_args_read = 0;
    int i=0;
    int j=0;
    
    num_args_read = scanf("%s",name);
    
    
    if(!(validinput (num_args_read,1))){
        printf("Improper save command or file could not be created.\n");
    }
    //create a new file
    else{
        FILE* fp= fopen(name,"w");
        
        fprintf(fp,"%d %d\n",b->num_rows,b->num_cols);
        
        for(i=0;i<b->num_rows;++i){
            for(j=0;j<b->num_cols;++j){
                fprintf(fp,"%c",b->board[i][j]);
            }
        }
        fclose(fp);
        print_b(b);
    }
}

void loadfile(Board* b){
    int numrows = 0;
    int numcols = 0;
    int num_args_read = 0;
    char name[1000];
    bool test = true;   
    int q = 0;
    num_args_read = scanf("%s",name);
     
       for(q=0;q<strlen(name);++q){
        if((!(isalpha(name[q])))&&(name[q] != '.')){
            test = false;
         }
       }
        

        if(test == false){
          printf("Failed to open file: %s\n",name);
          print_b(b);
          return;
        }
    
    
    else if(!(validinput (num_args_read,1))){
        printf("Failed to open file: %s\n",name);
        return;
    }

    
    FILE* fp = fopen(name,"r");
    
    fscanf(fp,"%d %d",&numrows,&numcols);
     //free space
    clean_b(b);
    //make new board
    set_up(b,numrows,numcols);
    
    int i =0;
    int j =0;
    // copy the char from the file to the new board
    for(i=0;i<numrows;++i){
        for(j=0;j<numcols;++j){
            fscanf(fp," %c",&(b->board[i][j]));
        }
    }
    fclose(fp);
    print_b(b);
    
    
}

void print_help(Board* b){

	printf("Commands:\n");
	printf("Help: h\n");
	printf("Quit: q\n");
	printf("Draw line: w row_start col_start row_end col_end\n");
	printf("Resize: r num_rows num_cols\n");
	printf("Add row or column: a [r | c] pos\n");
	printf("Delete row or column: d [r | c] pos\n");
	printf("Erase: e row col\n");
	printf("Save: s file_name\n");
	printf("Load: l file_name\n");
        print_b(b);
}


void get_command(Board* b){
    char command;
    bool quit_yet = false;
    char new_line;       
    bool test = true;
    while(!(quit_yet)) {
        
        printf("Enter your command: ");
        scanf(" %c",&command);
    //switch case when type in different command
    switch(command){
        //paint on the board
        case 'w':
            w_write(b);
            break;
        //add a row or col
        case 'a':
            add(b);
            break;
        //delete a row or a col
        case 'd':
            delete(b);
            break;
        //resize the board
        case 'r':
            resize(b);
            break;
        //erase a char
        case 'e':
            e_erase(b);
            break;
        //save file
        case 's':
            savefile(b);
            break;
        //load file
        case 'l':
            loadfile(b);
            break;
      //quit
        case 'q':
          test = true;
         do{
       scanf( "%c",&new_line);
        if(!isspace(new_line)){           
            test = false;
         }
        }while(new_line != '\n');

        if(test == false){
          printf("Unrecognized command. Type h for help.\n");
          print_b(b);
          break;
        }
        
        else{
         quit_yet = true; 
          break;
        }

      //help situation
       case 'h':
         test = true;
        do{
        scanf("%c",&new_line);
        if(!isspace(new_line)){
            test = false;
         }
        }while(new_line != '\n');
        //to evaluate the commands are valid
        if(test == false){
          printf("Unrecognized command. Type h for help.\n");
          print_b(b);
          break;
        }
             
          else{
            print_help(b);
            break;
         }

        //when the command can't be recognized
        default:
          test = true;
        do{
        scanf("%c",&new_line);
        if(!isspace(new_line)){
            test = false;
         }
        }while(new_line != '\n');
         
        if(test == false){
          printf("Unrecognized command. Type h for help.\n");
          print_b(b);
          break;
        }    
         else{
            printf("Unrecognized command. Type h for help.\n");
            break;
        }
    }
  }
}

