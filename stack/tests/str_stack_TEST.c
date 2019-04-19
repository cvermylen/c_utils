#include "../src/str_stack.h"
#include <criterion/criterion.h>

Test(stack, push_pop)
{
	stack_head_t* st = stack_init();
	char s1[] = "key1";
	char s2[] = "value1";
	str_stack_push(st, s1);
	str_stack_push(st, s2);
	char* v1 = str_stack_pop(st);
	free(v1);
	char* v2 = str_stack_pop(st);
	free(v2);
}
