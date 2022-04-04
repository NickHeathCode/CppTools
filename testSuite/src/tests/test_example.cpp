/*******************************************************\
|   File: test_example.cpp                              |
|   Created by: Nicholas Heath                          |
|   Website: https://heathcode.com/                     |
|   Github: https://github.com/NickHeathCode            |
|                                                       |
|   Description: A working example of how to use        |
|   the TestSuite. Include path may need to be updated. |
|                                                       |
\*******************************************************/

#include <x/TestSuite.h>

TESTS_BEGIN
    TEST(STR_TEST)
        TEST_STR_EQ("xyz", "xyz")
        TEST_STR_EQ("123", "123")
        TEST_STR_EQ("...", "...")
        TEST_STR_EQ("¿¿¿", "¿¿¿")
        TEST_STR_EQ("this is a sentence:)", "this is a sentence:)")

        TEST_STR_NE("not", "equal")
    TEST_END(STR_TEST) 

    TEST(INT_TEST)
        TEST_INT_EQ(1, 1)
        TEST_INT_EQ(12, 6+6)

        TEST_INT_NE(123, 456)
        TEST_INT_NE(34 + 34, 69)

        TEST_INT_GE(69, 68)
        TEST_INT_GE(69, 69)

        TEST_INT_GT(69, 67)
        TEST_INT_GT(100, 99)

        TEST_INT_LE(69, 70)
        TEST_INT_LE(69, 69)

        TEST_INT_LT(69, 70)
        TEST_INT_LT(99, 100)
    TEST_END(INT_TEST)

    TEST(FLOAT_TEST)
        TEST_FLOAT_EQ(69.99, 69.9999, 2)
        TEST_FLOAT_EQ(12, 12, 0)

        TEST_FLOAT_NE(69.99, 69.9999, 3)
        TEST_FLOAT_NE(11, 12, 0)
    TEST_END(FLOAT_TEST)

    TEST(BOOL_TEST)
        TEST_BOOL_EQ(true, !false)
        TEST_BOOL_EQ(false, false)

        TEST_FALSE(!true)
        TEST_FALSE(3 == 4)
        TEST_TRUE(!false)
        TEST_TRUE(3 == 3)
    TEST_END(BOOL_TEST)
TESTS_END