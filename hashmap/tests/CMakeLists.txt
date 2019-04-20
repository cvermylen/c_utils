
include_directories(SYSTEM /usr/local/include/)

link_directories(/usr/lib /usr/local/lib)

add_executable(hashmap_TEST hashmap_TEST.c)

target_link_libraries(hashmap_TEST hashmap ${CRITERION_LIBRARIES})

set_property (TARGET hashmap_TEST PROPERTY C_STANDARD 99)

add_test(hashmap_TEST hashmap_TEST)
