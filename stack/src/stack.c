#include "stack.h"
#include <stdlib.h>

#include <stdio.h>

stack_head_t* stack_init()
{
	stack_head_t* res;
	res = (stack_head_t*)malloc(sizeof(stack_head_t));
	res->num_elems = 0;
	res->root = NULL;
	return res;
} 

void stack_push(stack_head_t* stack, void* elem)
{
	if(stack == NULL) return;
	printf("1'%s'\n", elem);
	stack_node_t* node = (stack_node_t*)malloc(sizeof(stack_node_t));
    printf("2'%s'\n", elem);
	node->elem = elem;
    printf("3'%s'\n", elem);
	node->next = stack->root;
	stack->root = node;
	stack->num_elems++;

	printf("'%s''%s'\n",elem, node->elem);
}

void* stack_pop(stack_head_t* stack)
{	void* res = NULL;
	stack_node_t* tmp;
	if((stack != NULL) && (stack->num_elems > 0)){
		tmp = stack->root;
		stack->root = tmp->next;
		stack->num_elems--;
		res = tmp->elem;
		free(tmp);
	}
	return res;
}

void* stack_top(stack_head_t* stack)
{
	void* res = NULL;
	if((stack != NULL) && (stack->num_elems > 0)){
		res = stack->root->elem;
	}
	return res;
}

int stack_depth(stack_head_t* stack)
{
	if(stack == NULL) return 0;
	return stack->num_elems;
}

int is_stack_empty(stack_head_t* stack)
{
	if(stack == NULL) return 0;
	return(stack->num_elems == 0);
}

void stack_free(stack_head_t* stack)
{
	if((stack)){
		while(stack->num_elems > 0){
			stack_pop(stack);
		}
	}
}
