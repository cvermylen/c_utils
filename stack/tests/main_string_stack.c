#include "../src/str_stack.h"
#include <stdlib.h>
#include <string.h>

main(int argc, char** argv) {
    stack_head_t* st = stack_init();
    static const char rvalue1[] = "Synthesis: Tests";
    static const char rvalue2[] = "Passing";
    static const char rvalue3[] = "Failing";
    static const char rvalue4[] = "Or otherwise..";

    char* svalue1 = (char*)malloc(sizeof(char) * strlen(rvalue1)+1);
    strcpy(svalue1, rvalue1);
    str_stack_push(st, svalue1);
    int expectedLength1 = strlen(rvalue1) + 1;
    int res = str_stack_total_length(st);

    str_stack_push(st, rvalue2);
    int expectedLength2 = strlen(rvalue1) + strlen(rvalue2) + 2;
    res = str_stack_total_length(st);

    str_stack_push(st, rvalue3);
    int expectedLength3 = strlen(rvalue1) + strlen(rvalue2) + strlen(rvalue3) + 3;
    res = str_stack_total_length(st);

    str_stack_push(st, rvalue4);
    res = str_stack_total_length(st);
    int expectedLength4 = strlen(rvalue1) + strlen(rvalue2) + strlen(rvalue3) + strlen(rvalue4) +4;
}
