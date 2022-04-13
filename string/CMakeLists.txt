cmake_minimum_required(VERSION 3.13.4)

set(INCLUDES ../includes)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

if(EBUG STREQUAL ON)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)
endif()

project(xstring)
add_library(${PROJECT_NAME} SHARED src/string.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

add_executable(xstringtest src/tests/string_test.cpp src/string.cpp)
target_include_directories(xstringtest PRIVATE ${INCLUDES})

enable_testing()
add_test(XSTRINGTEST xstringtest)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ../build/libxstring.dll ../../libs)