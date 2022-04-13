#include <x/string.h>
#include <cstring>
#include <iostream>

std::vector<x::string> x::string::split(const char* delimiter)
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

std::vector<x::string> x::string::split(const char delimiter)
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
             
bool x::string::contains(const x::string& substr)
{
    const std::string& me = *this;
    return me.find(substr) != me.npos;
}

x::string x::string::join(std::vector<std::string> tokens, const char* delimiter)
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

x::string x::string::join(std::vector<x::string> tokens, const char* delimiter)
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

x::string x::string::toLower()
{
    x::string lower = *this;
    for (auto& c : lower)
    {
        if (c >= 65 && c <= 90)
        {
            c += 32; // Convert ASCII to lower
        }
    }

    return lower;
}

x::string x::string::toUpper()
{
    x::string upper = *this;
    for (auto& c : upper)
    {
        if (c >= 97 && c <= 122)
        {
            c -= 32; // Convert ASCII to upper
        }
    }

    return upper;
}

x::string x::string::replace_first(const char* find, const char* replace)
{
    std::string str = this->toStdString();
    size_t start_pos = str.find(find);
    if(start_pos == std::string::npos)
        return x::string(str);
    str.replace(start_pos, std::strlen(find), replace);
    return x::string(str);
}

x::string x::string::replace_last(const char* find, const char* replace)
{
    std::string str = this->toStdString();
    size_t start_pos = str.find_last_of(find);
    if(start_pos == std::string::npos)
        return x::string(str);
    str.replace(start_pos - std::strlen(find) + 1, std::strlen(find), replace);
    return x::string(str);
}

x::string x::string::replace(const char* find, const char* replace)
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

x::string x::string::operator+(const std::string& rhs)
{
    std::string x = *this;
    x += rhs;
    return x;
}

x::string x::string::operator+=(const std::string& rhs)
{
    std::string& x = *this;
    x += rhs;

    return *this;
}

x::string x::string::operator*(unsigned int multiplier)
{
    std::string str("");
    for (auto i = 0u; i < multiplier; ++i)
    {
        str += *this;
    }

    return x::string(str);
}