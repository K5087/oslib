add_executable(log_test log/main.cpp)
target_link_libraries(log_test PRIVATE log_static)
add_test(NAME log_test COMMAND log_test)

add_executable(cmd_test cmd/main.cpp)
target_link_libraries(cmd_test PRIVATE cmd_static)
add_test(NAME cmd_test COMMAND cmd_test)

add_executable(argp_test argp/main.cpp)
target_link_libraries(argp_test PRIVATE argp_static)
add_test(NAME argp_test COMMAND argp_test)
