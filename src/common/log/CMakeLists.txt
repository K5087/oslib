set(LOG_SOURCE_DIR ${SOURCE_DIR}/log)
set(LOG_INCLUDE_DIR ${INCLUDE_DIR}/log)

set(LOG_SOURCE log.cpp)
set(LOG_MODULE ${LOG_INCLUDE_DIR}/log.cppm)

add_module_library(log_static STATIC INCLUDE_DIR LOG_SOURCE LOG_MODULE)
add_module_library(log_shared SHARED INCLUDE_DIR LOG_SOURCE LOG_MODULE)
