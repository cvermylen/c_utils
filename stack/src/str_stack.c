#include "str_stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void str_stack_push(stack_head_t* stack, char* elem)
{
	if(stack == NULL) return;
	char* s = (char*) malloc (sizeof(char) * (strlen(elem) + 1));
	strcpy(s, elem);
	s[strlen(elem)] = '\0';
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

char* str_stack_2_print_lines(stack_head_t* stack)
{
    if(stack == NULL){
        return NULL;
    }
    int total_length = str_stack_total_length(stack);
    char* result = (char*) malloc(sizeof(char) * total_length + 1);
    str_stack_copy_elem_to_buffer(result, stack);
    result[total_length] = 0x00;
    return result;
}

int str_stack_total_length(stack_head_t* stack)
{
    int total_length = 0;
    stack_node_t* e = stack->root;
    for (int i = 0; i < stack->num_elems; i++) {
        total_length += strlen(e->elem) + 1;
        e = e->next;
    }
    return total_length;
}

void str_stack_copy_elem_to_buffer(char* dest_buffer, stack_head_t* stack)
{
    stack_node_t* e = stack->root;
    int pos = 0;
    for (int i = 0; i < stack->num_elems; i++) {
        strcpy(&dest_buffer[pos], e->elem);
        pos += strlen(e->elem);
        e = e->next;
    }
    dest_buffer[pos] = 0x00;
}