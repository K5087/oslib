set(CMD_DIR ${SOURCE_DIR}/cmd)

set(CMD_SOURCES cmd.cpp ${CMD_DIR}/cmd.cpp)

add_library(cmd_static STATIC ${CMD_SOURCES})
target_include_directories(cmd_static PUBLIC ${INCLUDE_DIR})
target_link_libraries(cmd_static PRIVATE log_static)

add_library(cmd_shared SHARED ${CMD_SOURCES})
target_include_directories(cmd_shared PUBLIC ${INCLUDE_DIR})
target_link_libraries(cmd_shared PRIVATE log_static)
