#include "stack.h"
#include <stdlib.h>

#include <stdio.h>

/*!
  \brief Creates a new EMPTY stack. This stack MUST be FREEd with a std 'free' call.
 */
stack_head_t* stack_init()
{
	stack_head_t* res;
	res = (stack_head_t*)malloc(sizeof(stack_head_t));
	res->num_elems = 0;
	res->root = NULL;
	return res;
} 

/*!
 * \brief Standard push, allocates the container for the stack element that can be freed using:
 *  - 'stack_pop'
 *  - 'stack_free'
 * @param stack
 * @param elem
 */
void stack_push(stack_head_t* stack, void* elem) {
	if (stack == NULL) return;
	stack_node_t *node = (stack_node_t *) malloc(sizeof(stack_node_t));
	node->elem = elem;
	node->next = stack->root;
	stack->root = node;
	stack->num_elems++;
}

/*!
 *  \brief Removes the top container (free) and returns the data.
 *  Also, decrement the number of element contained in the stack.
 * @param stack
 * @return the data pointed by the 'elem' ptr.
 */
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

/*!
 * \brief Will not modify the structure of the stack, unlike 'pop'
 * @param stack
 * @return The value contained in the top element.
 */
void* stack_top(stack_head_t* stack)
{
	void* res = NULL;
	if(stack && (stack->num_elems > 0)){
		res = stack->root->elem;
	}
	return res;
}

/*!
 * @param stack
 * @return The number of elements contained in this stack.
 */
int stack_depth(stack_head_t* stack)
{
	if (!stack ) return 0;
	return stack->num_elems;
}

int is_stack_empty(stack_head_t* stack)
{
	if (!stack) return 0;
	return(stack->num_elems == 0);
}

/*!
 * \brief Removes all containers from this stack but the ROOT.
 * The stack cannot be used further this call.
 * @param stack
 */
void stack_free(stack_head_t* stack)
{
	if (stack){
		while(stack->num_elems > 0){
			stack_pop(stack);
		}
		free(stack);
	}
}
