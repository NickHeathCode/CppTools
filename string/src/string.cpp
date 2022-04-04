#include <x/string.h>
#include <cstring>
#include <iostream>
namespace x
{
    std::vector<x::string> string::split(const char* delimiter)
    {
        std::vector<x::string> tokens;

        if (strcmp(delimiter, "") == 0)
        {
            tokens.emplace_back(*this);
            return tokens;
        }

        std::string s = std::string(*this);
        std::size_t prevIndex = 0;
        auto index = this->find(delimiter);
        while (index != std::string::npos)
        {
            x::string token(s.substr(0, index));
            tokens.emplace_back(token);

            prevIndex = index + 1;
            s = s.substr(prevIndex);
            index = s.find(delimiter);
        }

        tokens.emplace_back(s);
        return tokens;
    }

    std::vector<x::string> string::split(const char delimiter)
    {
        std::vector<x::string> tokens;

        std::string s = std::string(*this);
        std::size_t prevIndex = 0;
        auto index = this->find(delimiter);
        while (index != std::string::npos)
        {
            x::string token(s.substr(0, index));
            tokens.emplace_back(token);

            prevIndex = index + 1;
            s = s.substr(prevIndex);
            index = s.find(delimiter);
        }

        tokens.emplace_back(s);
        return tokens;
    }

    x::string string::join(std::vector<std::string> tokens, const char* delimiter)
    {
        x::string str;
        if (!tokens.empty())
        {
            str = tokens[0];
            for (auto i = 1u; i < tokens.size(); ++i)
            {
                str += x::string(delimiter) + tokens[i];
            }
        }

        return str;
    }

    x::string string::join(std::vector<x::string> tokens, const char* delimiter)
    {
        x::string str;
        if (!tokens.empty())
        {
            str = tokens[0];
            for (auto i = 1u; i < tokens.size(); ++i)
            {
                str += x::string(delimiter) + tokens[i];
            }
        }

        return x::string(str);
    }

    x::string string::replace_first(const char* find, const char* replace)
    {
        std::string str = this->toStdString();
        size_t start_pos = str.find(find);
        if(start_pos == std::string::npos)
            return x::string(str);
        str.replace(start_pos, std::strlen(find), replace);
        return x::string(str);
    }

    x::string string::replace_last(const char* find, const char* replace)
    {
        std::string str = this->toStdString();
        size_t start_pos = str.find_last_of(find);
        if(start_pos == std::string::npos)
            return x::string(str);
        str.replace(start_pos, std::strlen(find), replace);
        return x::string(str);
    }

    x::string string::replace(const char* find, const char* replace)
    {
        std::string str = this->toStdString();
        size_t start_pos = str.find(find);
        while (start_pos != std::string::npos)
        {
            str.replace(start_pos, std::strlen(find), replace);
            start_pos = str.find(find);
        }

        return x::string(str);
    }

    x::string string::operator+(x::string rhs)
    {
        *this += rhs;
        return *this;
    }

    x::string string::operator+(std::string rhs)
    {
        *this += rhs;
        return *this;
    }

    x::string string::operator+=(x::string rhs)
    {
        std::string& x = *this;
        x += rhs.toStdString();

        return *this;
    }

    x::string string::operator+=(std::string rhs)
    {
        std::string& x = *this;
        x += rhs;

        return *this;
    }

    x::string string::operator*(unsigned int multiplier)
    {
        std::string str("");
        for (auto i = 0u; i < multiplier; ++i)
        {
            str += *this;
        }

        return x::string(str);
    }
}