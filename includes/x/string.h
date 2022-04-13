#ifndef X_STRING_H
#define X_STRING_H

#include <string>
#include <vector>

namespace x
{
    class string : public std::string
    {
        public:
            string() : std::string() {}
            string(const std::string& str) : std::string(str) {}
            string(const char* str) : std::string(str) {}
            string(const char& str) : std::string(1, str) {}
            string(const bool& boolean) : std::string(boolean? "true" : "false") {}
            string(const short& num) : std::string(std::to_string(num)) {}
            string(const int& num) : std::string(std::to_string(num)) {}
            string(const float& num) : std::string(std::to_string(num)) {}
            string(const double& num) : std::string(std::to_string(num)) {}
            string(const long& num) : std::string(std::to_string(num)) {}
            string(const long long& num) : std::string(std::to_string(num)) {}
            string(const unsigned char& str) : std::string(1, str) {}
            string(const unsigned short& num) : std::string(std::to_string(num)) {}
            string(const unsigned int& num) : std::string(std::to_string(num)) {}
            string(const unsigned long& num) : std::string(std::to_string(num)) {}
            string(const unsigned long long& num) : std::string(std::to_string(num)) {}

            std::vector<x::string> split(const char* delimiter);
            std::vector<x::string> split(const char delimiter);

            static x::string join(std::vector<std::string> tokens, const char* delimiter);
            static x::string join(std::vector<x::string> tokens, const char* delimiter);

            bool contains(const x::string& substr);

            x::string replace(const char* find, const char* replace);
            x::string replace_first(const char* find, const char* replace);
            x::string replace_last(const char* find, const char* replace);

            std::string toStdString() { return *this; }
            x::string toLower();
            x::string toUpper();

            x::string operator+(const std::string& rhs);
            x::string operator+=(const std::string& rhs);
            x::string operator*(unsigned int multiplier);
    };
}

#endif