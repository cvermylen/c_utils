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

/*! \private
 * \brief Sum up the length of all the strings referenced by the stack, adding 1 for each string.
 * @param stack
 * @return
 */
int str_stack_total_length(stack_head_t* stack)
{
    int total_length = 0;
    stack_node_t* e = stack->root;
    for (int i = 0; i < stack->num_elems; i++) {
        total_length += strlen(e->elem) + 3;
        e = e->next;
    }
    return total_length;
}

/*! \private
 *  \brief Traverse the stack and append each string into the dest_buffer, enclosed by curly braces
 * @param dest_buffer
 * @param stack
 */
void str_stack_copy_elem_to_buffer(char* dest_buffer, stack_head_t* stack)
{
    stack_node_t* e = stack->root;
    int pos = 0;
    for (int i = 0; i < stack->num_elems; i++) {
        dest_buffer[pos] = '\'';
        strcpy(&dest_buffer[pos+1], e->elem);
        dest_buffer[pos + strlen(e->elem) + 1] = '\'';
        dest_buffer[pos + strlen(e->elem) + 2] = ',';
        pos += strlen(e->elem) + 3;
        e = e->next;
    }
    dest_buffer[pos] = 0x00;
}

char* str_stack_2_formatted_line(stack_head_t *stack)
{
    if(stack == NULL){
        return NULL;
    }
    int total_length = str_stack_total_length(stack);
    char* result = (char*) malloc(sizeof(char) * total_length + 1);
    str_stack_copy_elem_to_buffer(result, stack);
    result[total_length - 1] = 0x00;
    return result;
}
