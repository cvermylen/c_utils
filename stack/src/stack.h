#ifndef STACK_H
#define STACK_H

typedef struct stack_node stack_node_t;
struct stack_node {
	void* elem;
	stack_node_t* next;
};

typedef struct {
	stack_node_t* root;
	int num_elems;
}stack_head_t;

stack_head_t* stack_init();
void stack_push(stack_head_t* stack, void* elem);
void* stack_top(stack_head_t* stack);
void* stack_pop(stack_head_t* stack);
int stack_depth(stack_head_t* stack);
int is_stack_empty(stack_head_t* stack);
void stack_free(stack_head_t* stack);
#endif
