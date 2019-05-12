#ifndef STR_STACK_H
#define STR_STACK_H

#include "stack.h"

/*!
 * \brief Allocates a new string to hold a copy of the 'elem' passed and pushes the copy onto the stack.
 * Once popped, this copy will have to be de-allocated.
 * @param stack. Should have been initialized with 'stack_init'
 * @param elem
 */
void str_stack_push(stack_head_t* stack, char* elem);

/*!
 * \brief Reference to the String sitting on top of the stack.
 * @param stack
 * @return
 */
char* str_stack_top(stack_head_t* stack);

/*!
 * \brief Return a pointer to the string sitting on top of the stack, and de-allocates the stack element that contained it.
 * @param stack
 * @return
 */
char* str_stack_pop(stack_head_t* stack);

/*!
 * \brief Empty the stack, including all the strings still referenced by this stack. After this operation, the stack
 * cannot be used anymore.
 * @param stack
 */
void str_stack_free(stack_head_t* stack);

/*!
 * \brief Browse the stack from the root and returns a formatted string of all elements. Note, as per stack definition,
 * string will be returned in the same order as they would be popped. Each element is single quoted and elements are
 * comma separated. Single quotes inside the elements are not escaped.
 * @param stack
 * @return a newly created string, must be freed manually
 */
char* str_stack_2_formatted_line(stack_head_t *stack);

#endif
