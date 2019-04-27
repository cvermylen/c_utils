#ifndef STR_STACK_H
#define STR_STACK_H

#include "stack.h"

void str_stack_push(stack_head_t* stack, char* elem);
char* str_stack_top(stack_head_t* stack);
char* str_stack_pop(stack_head_t* stack);
void str_stack_free(stack_head_t* stack);
char* str_stack_2_print_lines(stack_head_t* stack);

int str_stack_total_length(stack_head_t* stack);
void str_stack_copy_elem_to_buffer(char* dest_buffer, stack_head_t* stack);
#endif
