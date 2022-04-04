#include <string>
#include <vector>

namespace x
{
    class string : public std::string
    {
        public:
            string() : std::string() {}
            
            template <typename T>
            string(T s) : std::string(s) {}

            std::vector<x::string> split(const char* delimiter);
            std::vector<x::string> split(const char delimiter);

            static x::string join(std::vector<std::string> tokens, const char* delimiter);
            static x::string join(std::vector<x::string> tokens, const char* delimiter);

            x::string replace(const char* find, const char* replace);
            x::string replace_first(const char* find, const char* replace);
            x::string replace_last(const char* find, const char* replace);

            std::string toStdString() { return static_cast<std::string>(*this); }
            //const char* c_str() { return "cake"; }

            x::string operator+(x::string rhs);
            x::string operator+(std::string rhs);
            x::string operator+=(x::string rhs);
            x::string operator+=(std::string rhs);
            x::string operator*(unsigned int multiplier);
    };
}