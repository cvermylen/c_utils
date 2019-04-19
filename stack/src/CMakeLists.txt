cmake_minimum_required(VERSION 3.1.0)
add_library(stack SHARED stack.c str_stack.c)
install(TARGETS stack DESTINATION lib)
install(FILES stack.h str_stack.h DESTINATION include)
