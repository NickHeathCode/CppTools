cmake_minimum_required(VERSION 3.13.4)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

project(xstring)
add_library(${PROJECT_NAME} SHARED src/string.cpp)

set(INCLUDES ../includes)

add_executable(stringtest src/tests/test.cpp)
target_include_directories(stringtest PRIVATE ${INCLUDES})


set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

enable_testing()
add_test(XSTRINGTEST stringtest)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ../build/libxstring.dll ../../libs)