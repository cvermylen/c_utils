#ifndef STR_STACK_H
#define STR_STACK_H

#include "stack.h"

void str_stack_push(stack_head_t* stack, char* elem);
char* str_stack_top(stack_head_t* stack);
char* str_stack_pop(stack_head_t* stack);
void str_stack_free(stack_head_t* stack);
#endif
