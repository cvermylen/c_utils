
include_directories(SYSTEM /usr/local/include/)

add_executable(stack_TEST stack_TEST.c how_to_use.c)
add_executable(str_stack_TEST str_stack_TEST.c)
add_executable(how_to_use how_to_use.c)

target_link_libraries(stack_TEST stack ${CRITERION_LIBRARIES})
target_link_libraries(str_stack_TEST stack ${CRITERION_LIBRARIES})
target_link_libraries(how_to_use stack)

set_property (TARGET stack_TEST PROPERTY C_STANDARD 99)
set_property (TARGET str_stack_TEST PROPERTY C_STANDARD 99)

add_test(stack_TEST stack_TEST)
add_test(str_stack_TEST str_stack_TEST)
add_test(how_to_use how_to_use)