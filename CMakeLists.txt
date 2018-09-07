cmake_minimum_required(VERSION 3.5)
project(LeetCode)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

add_compile_options(-fPIC)
add_definitions(-DDEBUG_ERR -DDEBUG_INFO)
set(CMAKE_BUILD_TYPE debug)

add_subdirectory(0902minStack)
add_subdirectory(0903UTF-8Validation)
add_subdirectory(0904flatten-nested-list-iterator)
add_subdirectory(0905largest-palindrome-product)
add_subdirectory(0906Repeated-DNA-Sequences)
add_subdirectory(0907Delete-Operation-for-Two-Strings)