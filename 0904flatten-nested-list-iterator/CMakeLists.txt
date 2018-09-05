cmake_minimum_required(VERSION 3.5)
project(0904flatten-nested-list-iterator)

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../build)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-fPIC)
add_definitions(-DDEBUG_ERR -DDEBUG_INFO)
set(CMAKE_BUILD_TYPE debug)

include_directories(
    ./
)

link_directories(

)

add_executable(${PROJECT_NAME}
    main.cpp
    )

target_link_libraries(${PROJECT_NAME}
    pthread
    )
