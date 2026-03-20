set(ARGP_DIR ${SOURCE_DIR}/argp)

set(ARGP_SOURCES argp.cpp)

add_library(argp_static STATIC ${ARGP_SOURCES})
target_include_directories(argp_static PUBLIC ${INCLUDE_DIR})
target_link_libraries(argp_static PRIVATE log_static)

add_library(argp_shared SHARED ${ARGP_SOURCES})
target_include_directories(argp_shared PUBLIC ${INCLUDE_DIR})
target_link_libraries(argp_shared PRIVATE log_static)
