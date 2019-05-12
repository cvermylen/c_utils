#include "../src/str_stack.h"
#include <criterion/criterion.h>
#include <stdio.h>

// Private methods from str_stack.c
int str_stack_total_length(stack_head_t* stack);
void str_stack_copy_elem_to_buffer(char* dest_buffer, stack_head_t* stack);

Test(str_stack, push_pop)
{
	stack_head_t* st = stack_init();
	char s1[] = "key1";
	char s2[] = "value1";

	str_stack_push(st, s1);
	str_stack_push(st, s2);
	char* v1 = str_stack_pop(st);
    char* v2 = str_stack_pop(st);

    cr_assert(strcmp("value1", v1) == 0, "Expected first value popped to be 'value1', not:'%s'", v1);
    cr_assert(strcmp("key1", v2) == 0, "Expected second value popped to be 'key1', not:%s", v2);

    free(v1);
	free(v2);
	str_stack_free(st);
}

Test(str_stack_total_length, empty)
{
    stack_head_t* st = stack_init();

    int res = str_stack_total_length(st);

    cr_assert(0 == res, "Total length of an empty stack of string should be 0, not: %d", res);

    str_stack_free(st);
}

Test(str_stack_total_length, one)
{
    stack_head_t* st = stack_init();
    char value[] = "First Element";

    str_stack_push(st, value);
    int res = str_stack_total_length(st);

    int expectedLength = strlen(value) +3;
    cr_assert(expectedLength == res, "Total length of a string stack of 1 with 'First Element' should be:%d, "
                                       "not:%d, as we have to add 2 single quotes and 1 comma", expectedLength, res);

    str_stack_free(st);
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

    int expectedLength4 = strlen(rvalue1) + strlen(rvalue2) + strlen(rvalue3) + strlen(rvalue4) +12;
    cr_assert(expectedLength4 == res,
            "Total length of the string stack of 4 should be: %d, not: %d, as we have to add 2 single quotes and 1 comma"
            " per stack element", expectedLength4, res);
    str_stack_free(st);
}

Test(str_stack_copy_buffer, empty_stack)
{
    stack_head_t* st = stack_init();
    char dest_buffer[] = "1234567890";

    str_stack_copy_elem_to_buffer(dest_buffer, st);

    cr_assert(0 == strlen(dest_buffer), "Content of an empty string stack should be an empty string, not a string of size:%lu",
            strlen(dest_buffer));
}

Test(str_stack_copy_buffer, one)
{
    stack_head_t* st = stack_init();
    char value[] = "First Element";
    str_stack_push(st, value);
    char buffer[] = "12345678901234567890";

    str_stack_copy_elem_to_buffer(buffer, st);

    cr_assert(strlen(value)+3 == strlen(buffer), "Expected the size to be size of the element + 3:%lu", strlen(buffer));
}

Test(str_stack_print, empty)
{
    stack_head_t* st = stack_init();

    char* result = str_stack_2_formatted_line(st);

    cr_assert(0 == strlen(result), "Formatted string of empty stack should have length of 0, not: %lu", strlen(result));
}

Test(str_stack_print, one)
{
    stack_head_t* st = stack_init();
    char sample[] = "First element";
    str_stack_push(st, sample);

    char* result = str_stack_2_formatted_line(st);

    cr_assert(strcmp("'First element'", result) == 0, "Not formatted as expected: [%s]", result);
}

Test(str_stack_print, two)
{
    stack_head_t* st = stack_init();
    char sample1[] = "First element";
    str_stack_push(st, sample1);
    char sample2[] = "Next in line";
    str_stack_push(st, sample2);

    char* result = str_stack_2_formatted_line(st);

    cr_assert(strcmp("'Next in line','First element'", result) == 0, "Not formatted as expected: [%s]", result);
}

Test(str_stack_print, three)
{
    stack_head_t* st = stack_init();
    char sample1[] = "First element";
    str_stack_push(st, sample1);
    char sample2[] = "Next in line";
    str_stack_push(st, sample2);
    char sample3[] = "Last one";
    str_stack_push(st, sample3);

    char* result = str_stack_2_formatted_line(st);

    cr_assert(strcmp("'Last one','Next in line','First element'", result) == 0, "Not formatted as expected: [%s]", result);
}
