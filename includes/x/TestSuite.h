/*******************************************************\
|   File: TestSuite.h                                   |
|   Created by: Nicholas Heath                          |
|   Website: https://heathcode.com/                     |
|   Github: https://github.com/NickHeathCode            |
|                                                       |
|   Description: A small test suite to allow            |
|   easier testing using CTEST and CMAKE.               |
|                                                       |
|   Usage: All tests MUST be inside of                  |
|   TESTS_BEGIN and TESTS_END tags. Each                |
|   individual test should be in TEST(testName)         |
|   and TEST_END tags. Example usage below.             |
|                                                       |
|   The first test will pass,                           |
|   the second will fail:                               |
|  +---------------------------------------------+      |
|  | TESTS_BEGIN                                 |      |
|  |                                             |      |
|  |    TEST(myFirstTest)                        |      |
|  |        bool myBool = false;                 |      |
|  |        TEST_TRUE(!myBool)                   |      |
|  |        TEST_FALSE(myBool)                   |      |
|  |        TEST_INT_EQ(2, 2)                    |      |
|  |    TEST_END(myFirstTest)                    |      |
|  |                                             |      |
|  |    TEST(mySecondTest)                       |      |
|  |        std::string test("a string");        |      |
|  |        TEST_STR_EQ(test, "something else")  |      |
|  |    TEST_END(mySecondTest)                   |      |
|  |                                             |      |
|  | TESTS_END                                   |      |
|  +---------------------------------------------+      |
|                                                       |
\*******************************************************/

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

/* Every test should be placed after this macro */
#define TESTS_BEGIN                                                     \
    int main()                                                          \
    {                                                                   \
        std::map<std::string, std::function<int(std::string&)>> TESTS;

/* This indicates the beginning of a single unit test */
#define TEST(testName)                          \
    auto testName = [](std::string& MESSAGE) { 

/* This indicates the end of a single unit test */
#define TEST_END(testName)       \
    return 0; };                 \
    TESTS[#testName] = testName; 

/* This indicates the end of all unit tests. The last test must still have a TEST_END(<testname>) after it */
#define TESTS_END                                                                                               \
    int RETVAL = 0;                                                                                             \
    for (auto t : TESTS)                                                                                        \
    {                                                                                                           \
        std::cout << "-------------\n\u001b[36;1mRunning test: \u001b[38;5;220m" << t.first << "\u001b[0m\n";   \
        std::string msg;                                                                                        \
        if (t.second(msg) || RETVAL == 1)                                                                       \
        {                                                                                                       \
            RETVAL = 1;                                                                                         \
            break;                                                                                              \
        }                                                                                                       \
        else                                                                                                    \
        {                                                                                                       \
            printPass();                                                                                        \
        }                                                                                                       \
    }                                                                                                           \
    std::cout << "---------------\n \n";                                                                        \
    return RETVAL;                                                                                              \
}

/* Function used by the comparison tests, no real use for it alone */
#define RETURN_ON_FALSE(result, reason)                                          \
    if (!(result))                                                               \
    {                                                                            \
        std::cout <<"File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; \
        printFailure(reason);                                                    \
        return 1;                                                                \
    }

/* Comparison tests */
#define TEST_STR_EQ(actual, expected)               RETURN_ON_FALSE(std::string(expected) == std::string(actual), std::string("Expected: ") + #actual + " == " + expected + "\n\t    Actual:   " + #actual + " =  " + actual)
#define TEST_STR_NE(actual, expected)               RETURN_ON_FALSE(std::string(expected) != std::string(actual), std::string("Expected: ") + #actual + " != " + expected + "\n\t    Actual:   " + #actual + " =  " + actual)
#define TEST_INT_EQ(actual, expected)               RETURN_ON_FALSE(expected == actual, std::string("Expected: ") + #actual + " == " + std::to_string(expected) + "\n\t    Actual:   " + #actual + " =  " + std::to_string(actual))
#define TEST_INT_NE(actual, expected)               RETURN_ON_FALSE(expected != actual, std::string("Expected: ") + #actual + " != " + std::to_string(expected) + "\n\t    Actual:   " + #actual + " =  " + std::to_string(actual))
#define TEST_INT_GT(first, second)                  RETURN_ON_FALSE(first   >   second, std::string("Expected: ") + #first  + " > "  + #second + "\n\t    Actual:   " + #first + " = " + std::to_string(first) + ", " + #second + " = " + std::to_string(second))
#define TEST_INT_GE(first, second)                  RETURN_ON_FALSE(first   >=  second, std::string("Expected: ") + #first  + " >= " + #second + "\n\t    Actual:   " + #first + " = " + std::to_string(first) + ", " + #second + " = " + std::to_string(second))
#define TEST_INT_LT(first, second)                  RETURN_ON_FALSE(first   <   second, std::string("Expected: ") + #first  + " < "  + #second + "\n\t    Actual:   " + #first + " = " + std::to_string(first) + ", " + #second + " = " + std::to_string(second))
#define TEST_INT_LE(first, second)                  RETURN_ON_FALSE(first   <=  second, std::string("Expected: ") + #first  + " <= " + #second + "\n\t    Actual:   " + #first + " = " + std::to_string(first) + ", " + #second + " = " + std::to_string(second))
#define TEST_FLOAT_GT(first, second)                RETURN_ON_FALSE(first   >   second, std::string("Expected: ") + #first  + " > "  + #second + "\n\t    Actual:   " + #first + " = " + std::to_string(first) + ", " + #second + " = " + std::to_string(second))
#define TEST_FLOAT_GE(first, second)                RETURN_ON_FALSE(first   >=  second, std::string("Expected: ") + #first  + " >= " + #second + "\n\t    Actual:   " + #first + " = " + std::to_string(first) + ", " + #second + " = " + std::to_string(second))
#define TEST_FLOAT_LT(first, second)                RETURN_ON_FALSE(first   <   second, std::string("Expected: ") + #first  + " < "  + #second + "\n\t    Actual:   " + #first + " = " + std::to_string(first) + ", " + #second + " = " + std::to_string(second))
#define TEST_FLOAT_LE(first, second)                RETURN_ON_FALSE(first   <=  second, std::string("Expected: ") + #first  + " <= " + #second + "\n\t    Actual:   " + #first + " = " + std::to_string(first) + ", " + #second + " = " + std::to_string(second))
#define TEST_FLOAT_EQ(actual, expected, precision)  RETURN_ON_FALSE(abs(actual - expected) <  pow(0.1f, precision),  std::string("Expected: ") + #actual + " == " + std::to_string(expected) + "\n\t    Actual:   " + #actual + " =  " + std::to_string(actual))
#define TEST_FLOAT_NE(actual, expected, precision)  RETURN_ON_FALSE(abs(actual - expected) >= pow(0.1f, precision), std::string("Expected: ") + #actual + " != " + std::to_string(expected) + "\n\t    Actual:   " + #actual + " =  " + std::to_string(actual))
#define TEST_BOOL_EQ(actual, expected)              RETURN_ON_FALSE(expected == actual, std::string("Expected: ") + #actual + " == " + (expected ? "TRUE" : "FALSE") + "\n\t    Actual:   " + #actual + " == " + (actual ? "TRUE" : "FALSE"))

#define TEST_TRUE(actual)   TEST_BOOL_EQ((actual), true)
#define TEST_FALSE(actual)  TEST_BOOL_EQ((actual), false)

void printFailure(const std::string& msg)
{
    std::cout << "\x1B[91mFAILURE: \033[0m" << msg << "\n";
}

void printPass()
{
    std::cout << "\x1B[92mPASS\033[0m\n";
}

#endif