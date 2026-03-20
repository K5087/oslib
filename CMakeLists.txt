cmake_minimum_required(VERSION 4.2.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")

project(os VERSION 0.0.1 LANGUAGES CXX)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
if(UNIX)
    set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/unix)
elseif(WIN32)
    set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/windows)
else()
    message("not support system")
endif()

file(
    GLOB_RECURSE OS_SOURCE
    ${PROJECT_SOURCE_DIR}/src/common/*.cpp
    ${SOURCE_DIR}/*.cpp
)
file(
    GLOB_RECURSE OS_MODULE
    ${INCLUDE_DIR}/*.cppm
)
include(cmake/target.cmake)
add_module_library(os_static STATIC INCLUDE_DIR OS_SOURCE OS_MODULE)
add_module_library(os_shared SHARED INCLUDE_DIR OS_SOURCE OS_MODULE)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/common/log)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/common/cmd)


# include(CTest)
# if(BUILD_TESTING)
#     add_subdirectory(test)
# endif()
