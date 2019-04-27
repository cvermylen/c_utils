#include "../src/str_stack.h"
#include <criterion/criterion.h>

Test(stack, push_pop)
{
	stack_head_t* st = stack_init();
	static const char s1[] = "key1";
	static const char s2[] = "value1";
	str_stack_push(st, s1);
	str_stack_push(st, s2);
	char* v1 = str_stack_pop(st);
	free(v1);
	char* v2 = str_stack_pop(st);
	free(v2);
	str_stack_free(st);
}

Test(stack_total_length, empty)
{
    stack_head_t* st = stack_init();
    int res = str_stack_total_length(st);
    str_stack_free(st);
    cr_assert(0 == res, "Total length of an empty stack of string should be 0, not: %d", res);
}

Test(stack_total_length, one)
{
    stack_head_t* st = stack_init();
    static const char value[] = "First Element";
    str_stack_push(st, value);
    int res = str_stack_total_length(st);
    int expectedLength = strlen(value) +1;
    cr_assert(expectedLength == res, "Total length of a string stack of 1 with 'First Element' should be:%d, "
                                       "not:%d", expectedLength, res);
}

Test(stack_total_length, four)
{
    stack_head_t* st = stack_init();
    static const char rvalue1[] = "Synthesis: Tests";
    static const char rvalue2[] = "Passing";
    static const char rvalue3[] = "Failing";
    static const char rvalue4[] = "Or otherwise..";

    str_stack_push(st, rvalue1);
    int expectedLength1 = strlen(rvalue1) + 1;
    int res = str_stack_total_length(st);
    cr_assert(expectedLength1 == res,
        "Total length of the string stack of 1 should be: %d, not: %d", expectedLength1, res);

    str_stack_push(st, rvalue2);
    int expectedLength2 = strlen(rvalue1) + strlen(rvalue2) + 2;
    res = str_stack_total_length(st);
    cr_assert(expectedLength2 == res,
        "Total length of the string stack of 2 should be: %d, not: %d", expectedLength2, res);

    str_stack_push(st, rvalue3);
    int expectedLength3 = strlen(rvalue1) + strlen(rvalue2) + strlen(rvalue3) + 3;
    res = str_stack_total_length(st);
    cr_assert(expectedLength3 == res,
        "Total length of the string stack of 3 should be: %d, not: %d", expectedLength3, res);

    str_stack_push(st, rvalue4);
    res = str_stack_total_length(st);
    int expectedLength4 = strlen(rvalue1) + strlen(rvalue2) + strlen(rvalue3) + strlen(rvalue4) +4;
    cr_assert(expectedLength4 == res,
            "Total length of the string stack of 4 should be: %d, not: %d", expectedLength4, res);
}