#ifndef cases_h
#define cases_h

#include <stdio.h>
#include <stdbool.h>
#include "board.h"

bool validinput(int num_args_read, int num_args_need);
void w_write(Board* b);
void get_command(Board* b);

#endif 

