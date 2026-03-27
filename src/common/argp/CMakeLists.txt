set(ARGP_SOURCE_DIR ${SOURCE_DIR}/argp)
set(ARGP_INCLUDE_DIR ${INCLUDE_DIR}/argp)

set(ARGP_MODULE ${ARGP_INCLUDE_DIR}/argp.cppm)
set(ARGP_SOURCE argp.cpp)

add_module_library(argp_static STATIC INCLUDE_DIR ARGP_SOURCE ARGP_MODULE)

add_module_library(argp_shared SHARED INCLUDE_DIR ARGP_SOURCE ARGP_MODULE)
