#include "str_stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void str_stack_push(stack_head_t* stack, char* elem)
{
	if(stack == NULL) return;
	char* s = (char*)malloc(sizeof(char) * (strlen((elem) + 1)));
	strcpy(s, elem);
	stack_push(stack, s);
}

char* str_stack_top(stack_head_t* stack)
{
	return (char*)stack_top(stack);
}

char* str_stack_pop(stack_head_t* stack)
{
	return (char*)stack_pop(stack);
}

void str_stack_free(stack_head_t* stack)
{
	if((stack)){
		while(stack->num_elems > 0){
			char* s = stack_pop(stack);
			free(s);
		}
	}
}
