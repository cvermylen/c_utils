#include "../src/str_stack.h"
#include <criterion/criterion.h>
#include <stdio.h>

Test(str_stack, push_pop)
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
	str_stack_free(st);
}

Test(str_stack_total_length, empty)
{
    stack_head_t* st = stack_init();

    int res = str_stack_total_length(st);

    str_stack_free(st);

    cr_assert(0 == res, "Total length of an empty stack of string should be 0, not: %d", res);
}

Test(str_stack_total_length, one)
{
    stack_head_t* st = stack_init();

    char value[] = "First Element";
    str_stack_push(st, value);

    int res = str_stack_total_length(st);

    str_stack_free(st);

    int expectedLength = strlen(value) +1;
    cr_assert(expectedLength == res, "Total length of a string stack of 1 with 'First Element' should be:%d, "
                                       "not:%d", expectedLength, res);
}

Test(str_stack_total_length, four)
{
    stack_head_t* st = stack_init();

    char rvalue1[] = "Synthesis: Tests";
    char rvalue2[] = "Passing";
    char rvalue3[] = "Failing";
    char rvalue4[] = "Or otherwise..";

    str_stack_push(st, rvalue1);
    str_stack_push(st, rvalue2);
    str_stack_push(st, rvalue3);
    str_stack_push(st, rvalue4);

    int res = str_stack_total_length(st);

    str_stack_free(st);

    int expectedLength4 = strlen(rvalue1) + strlen(rvalue2) + strlen(rvalue3) + strlen(rvalue4) +4;
    cr_assert(expectedLength4 == res,
            "Total length of the string stack of 4 should be: %d, not: %d", expectedLength4, res);
}

Test(str_stack_copy_buffer, empty)
{
    stack_head_t* st = stack_init();

    char buffer[] = "1234567890";

    str_stack_copy_elem_to_buffer(buffer, st);
    cr_assert(0 == strlen(buffer), "Content of an empty string stack should be an empty string, not a string of size:%lu", strlen(buffer));
}

Test(str_atck_copy_buffer, one)
{
    stack_head_t* st = stack_init();

    char value[] = "First Element";
    str_stack_push(st, value);

    char buffer[] = "12345678901234567890";

    str_stack_copy_elem_to_buffer(buffer, st);
    cr_assert(strlen(value) == strlen(buffer), "Content of an empty string stack should be an empty string, not a string of size:%lu", strlen(buffer));
}