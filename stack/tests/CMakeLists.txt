
include_directories(SYSTEM /usr/local/include/)

add_executable(stack_TEST stack_TEST.c main_string_stack.c)
add_executable(str_stack_TEST str_stack_TEST.c)

target_link_libraries(stack_TEST stack ${CRITERION_LIBRARIES})
target_link_libraries(str_stack_TEST stack ${CRITERION_LIBRARIES})

set_property (TARGET stack_TEST PROPERTY C_STANDARD 99)
set_property (TARGET str_stack_TEST PROPERTY C_STANDARD 99)

add_test(stack_TEST stack_TEST)
add_test(str_stack_TEST str_stack_TEST)
