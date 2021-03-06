#include <malloc.h>
#include "../src/str_stack.h"


void should_free_empty_stack()
{
    stack_head_t* st = stack_init();
    free(st);
}

void should_free_using_pop()
{
    stack_head_t* st  = stack_init();
    stack_push(st, "A");
    stack_pop(st);
    free(st);
}

void should_free_the_same_way()
{
    stack_head_t* st  = stack_init();
    stack_push(st, "A");
    stack_pop(st);
    stack_free(st);
}

void should_free_using_utility()
{
    stack_head_t* st  = stack_init();
    stack_push(st, "A");
    stack_free(st);
}

void should_free_str_stack()
{
    stack_head_t* st  = stack_init();
    str_stack_push(st, "John");
    str_stack_free(st);
}

void formatted_string_of_stack_content()
{
    stack_head_t* st = stack_init();
    str_stack_push(st, "John Doe");
    str_stack_push(st, "Jane Doe");

    char* output = str_stack_2_formatted_line(st);

    free(output);
    str_stack_free(st);
}

int main()
{
    should_free_empty_stack();
    should_free_using_pop();
    should_free_the_same_way();
    should_free_using_utility();
    should_free_str_stack();
    formatted_string_of_stack_content();
}