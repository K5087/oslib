function(add_module_test target_name)
    add_executable(${target_name}_test ${target_name}/main.cpp)
    target_link_libraries(${target_name}_test PRIVATE ${target_name}_static)
    add_test(NAME ${target_name}_test COMMAND ${target_name}_test)
endfunction()

add_module_test(log)
add_module_test(cmd)
add_module_test(argp)

