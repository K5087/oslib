set(CMD_SOURCE_DIR ${SOURCE_DIR}/cmd)
set(CMD_INCLUDE_DIR ${INCLUDE_DIR}/cmd)

set(CMD_MODULE ${CMD_INCLUDE_DIR}/cmd.cppm)
set(CMD_SOURCE cmd.cpp ${CMD_SOURCE_DIR}/cmd.cpp)

add_module_library(cmd_static STATIC INCLUDE_DIR CMD_SOURCE CMD_MODULE)
target_link_libraries(cmd_static PRIVATE log_static)

add_module_library(cmd_shared SHARED INCLUDE_DIR CMD_SOURCE CMD_MODULE)
target_link_libraries(cmd_shared PRIVATE log_static)
