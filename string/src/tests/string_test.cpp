#include <x/TestSuite.h>
#include <x/string.h>

TESTS_BEGIN

    TEST(X_STRING_CHAR_CTOR)
        x::string xStr('x');
        TEST_STR_EQ(xStr, "x")
        TEST_STR_EQ(xStr + 'y' + 'z', "xyz")
    TEST_END(X_STRING_CHAR_CTOR)

    TEST(X_STRING_CONVERSION_TEST)
        x::string testString1 = "this is ";
        std::string testString2 = "a test ";
        TEST_STR_EQ(testString1 + testString2, "this is a test ")
        TEST_STR_EQ(testString2 + testString1, "a test this is ")

        testString1 = "something else";
        TEST_STR_EQ(testString1, "something else")
    TEST_END(X_STRING_CONVERSION_TEST)

    TEST(X_STRING_SPLIT_JOIN_TEST)
        x::string testString1("this,is,a,comma,delimited,string");
        
        std::vector<x::string> tokens = testString1.split(",");
        TEST_INT_EQ(tokens.size(), 6)
        TEST_STR_EQ(tokens[0], "this")
        TEST_STR_EQ(tokens[5], "string")

        x::string testString2 = x::string::join(tokens, " ");
        TEST_STR_EQ(testString2, "this is a comma delimited string")

        x::string testString3("");
        TEST_STR_EQ(testString3, "")
    TEST_END(X_STRING_SPLIT_JOIN_TEST)

    TEST(X_STRING_REPLACE_TEST)
        x::string testString("Hello world");
        testString = testString.replace("world", "Mr. Robinson");
        TEST_STR_EQ(testString, "Hello Mr. Robinson");

        // This should only work when the string is assigned
        x::string testString2("test test test");
        testString2 = testString2.replace_first("test", "hello");
        TEST_STR_EQ(testString2, "hello test test");

        // Same test, but this should not work as the string is not assigned
        x::string testString3("test test test");
        testString3.replace_first("test", "hello");
        TEST_STR_EQ(testString3, "test test test");

        // This should only work when the string is assigned
        x::string testString4("test test test");
        testString4 = testString4.replace_last("test", "hello");
        TEST_STR_EQ(testString4, "test test hello");

        // Same test, but this should not work as the string is not assigned
        x::string testString5("test test test");
        testString5.replace_last("test", "hello");
        TEST_STR_EQ(testString5, "test test test");

        // This should only work when the string is assigned
        x::string testString6("test test test");
        testString6 = testString6.replace("test", "hello");
        TEST_STR_EQ(testString6, "hello hello hello");

        // Same test, but this should not work as the string is not assigned
        x::string testString7("test test test");
        testString7.replace("test", "hello");
        TEST_STR_EQ(testString7, "test test test");

        // Test consecutive string replaces
        x::string testString8("test test test test test test");
        testString8 = testString8.replace_last("test", "6");
        testString8 = testString8.replace_last("test", "5");
        testString8 = testString8.replace_first("test", "1");
        testString8 = testString8.replace_first("test", "2");
        testString8 = testString8.replace("test", "3");
        TEST_STR_EQ(testString8, "1 2 3 3 5 6")
    TEST_END(X_STRING_REPLACE_TEST)

    TEST(X_STRING_PLUS_EQUALS)
        x::string testString1("Hello ");
        testString1 += "world";
        TEST_STR_EQ(testString1, "Hello world")
    TEST_END(X_STRING_PLUS_EQUALS)

    TEST(X_STRING_CONTAINS)
        x::string testString1("This is a searchable string!");
        TEST_TRUE(testString1.contains(""))
        TEST_TRUE(testString1.contains("This"))
        TEST_TRUE(testString1.contains("string!"))
        TEST_TRUE(testString1.contains("sear"))
        TEST_FALSE(testString1.contains("potato"))
    TEST_END(X_STRING_CONTAINS)

    TEST(X_STRING_NUMBERS)
        x::string str123(123);
        x::string str456(456);
        x::string pi_str(3.1415f);
        TEST_STR_EQ(str123, "123");
        TEST_STR_EQ(str123 + str456, "123456")
        TEST_TRUE(pi_str.contains("3.1415"))
    TEST_END(X_STRING_NUMBERS)

    TEST(X_STRING_TO_UPPER)
        x::string str1("This is a test string.!@#$%");
        x::string str2("ThIs Is AnOtHeR sTrInG");
        x::string str3("!!!!THE LAST TEST!!!!");

        TEST_STR_EQ(str1.toUpper(), "THIS IS A TEST STRING.!@#$%")
        TEST_STR_EQ(str2.toUpper(), "THIS IS ANOTHER STRING")
        TEST_STR_EQ(str3.toUpper(), "!!!!THE LAST TEST!!!!")
    TEST_END(X_STRING_TO_UPPER)

    TEST(X_STRING_TO_LOWER)
        x::string str1("This is a test string.!@#$%");
        x::string str2("ThIs Is AnOtHeR sTrInG");
        x::string str3("!!!!the last test!!!!");

        TEST_STR_EQ(str1.toLower(), "this is a test string.!@#$%")
        TEST_STR_EQ(str2.toLower(), "this is another string")
        TEST_STR_EQ(str3.toLower(), "!!!!the last test!!!!")
    TEST_END(X_STRING_TO_LOWER)
    
TESTS_END