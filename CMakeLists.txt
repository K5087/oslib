cmake_minimum_required(VERSION 4.2.0)

project(os VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
if(UNIX)
    set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/unix)
elseif(WIN32)
    set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/windows)
else()
    message("not support system")
endif()

file(
    GLOB_RECURSE SOURCE_FILE
    ${PROJECT_SOURCE_DIR}/src/common/*.cpp
    ${SOURCE_DIR}/*.cpp
)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/common/log)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/common/cmd)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/common/argp)

add_library(os_static STATIC ${SOURCE_FILE})
target_include_directories(os_static PUBLIC ${INCLUDE_DIR})

add_library(os_shared SHARED ${SOURCE_FILE})
target_include_directories(os_shared PUBLIC ${INCLUDE_DIR})

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()
