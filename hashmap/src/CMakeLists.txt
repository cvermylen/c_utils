cmake_minimum_required(VERSION 3.1.0)
add_library(hashmap SHARED hashmap.c)
install(TARGETS hashmap DESTINATION lib)
install(FILES hashmap.h DESTINATION include)
