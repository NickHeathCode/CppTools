cmake_minimum_required(VERSION 3.13.4)

set(INCLUDES ../includes)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

if (${EBUG})
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)
endif()

project(testSuiteTest)
add_executable(${PROJECT_NAME} src/tests/test_example.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})