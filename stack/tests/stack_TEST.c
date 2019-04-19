#include "../src/stack.h"
#include <criterion/criterion.h>

Test(stack, empty)
{
	stack_head_t* s = stack_init();
	cr_assert(NULL != s, "Init should return a non-NULL pointer");
	cr_assert(0 == stack_depth(s), "Stack depth expected to be '0', actually is:%d", stack_depth(s));
	cr_assert(is_stack_empty(s), "Stack expected to be empty, actually :%d", is_stack_empty(s));
}

Test(top, empty)
{
	stack_head_t* s = stack_init();
	cr_assert(NULL == stack_top(s), "top value should be NULL on an empty stack");
}

Test(top, idem)
{
	stack_head_t* s = stack_init();
	stack_push(s, "One");
	cr_assert(strcmp("One", (char*)stack_top(s)) == 0, "Not the expected value on first 'top' operation");
	cr_assert(strcmp("One", (char*)stack_top(s)) == 0, "Not the expected value on second 'top' operation");
}

Test(stack, pop_empty)
{
	stack_head_t* s = stack_init();
	void* v = stack_pop(s);
	cr_assert(NULL == v, "Popping on empty stack should return NULL");
}

Test(stack, one)
{
	stack_head_t* s = stack_init();
	stack_push(s, "a string");
	cr_assert(1 == stack_depth(s), "Stack depth expected to be '1', actually is:%d", stack_depth(s));
        cr_assert(!is_stack_empty(s), "Stack expected to be not empty, actually :%d", is_stack_empty(s));
	stack_free(s);
	cr_assert(0 == stack_depth(s), "Stack depth expected to be '0', actually is:%d", stack_depth(s));
        cr_assert(is_stack_empty(s), "Stack expected to be empty, actually :%d", is_stack_empty(s));
}

Test(stack, right_order)
{
	stack_head_t* s = stack_init();
	stack_push(s, "first");
	stack_push(s, "second");
	stack_push(s, "third");
	cr_assert(3 == stack_depth(s), "Stack depth expected to be '3', actually is:%d", stack_depth(s));
	char* popped = stack_pop(s);
	cr_assert(strcmp("third", popped) == 0, "Pop expected to return last pushed element, instead:%s", popped);
	cr_assert(2 == stack_depth(s), "Stack depth expected to be '2', actually is:%d", stack_depth(s));
	popped = stack_pop(s);
	cr_assert(strcmp("second", popped) == 0, "Pop expected to return last pushed element, instead:%s", popped);
	cr_assert(1 == stack_depth(s), "Stack depth expected to be '1', actually is:%d", stack_depth(s));
}

Test(stack, preserve)
{
	stack_head_t* s = stack_init();
	stack_push(s, "first");
	stack_push(s, "second");
	stack_push(s, "third");
	char* popped = stack_pop(s);
	popped = stack_pop(s);
	stack_push(s, "fourth");
	cr_assert(2 == stack_depth(s), "Stack depth expected to be '2', actually is:%d", stack_depth(s));
	popped = stack_pop(s);
	cr_assert(strcmp("fourth", popped) == 0, "Pop expected to return last pushed element, instead:%s", popped);
	popped = stack_pop(s);
	cr_assert(strcmp("first", popped) == 0, "Pop expected to return last pushed element, instead:%s", popped);
	cr_assert(0 == stack_depth(s), "Stack depth expected to be '0', actually is:%d", stack_depth(s));
}
