#include "ScalarConverter.hpp"

bool isChar(const std::string &s) {
    if (s.size() == 1 && !std::isdigit(static_cast<char>(s[0])))
        return true;
    else
        return false;
}

bool isPseudoFloat(const std::string &s) {
    if (s == "nanf" || s == "+inff" || s == "-inff")
        return true;
    else
        return false;
}

bool isPseudoDouble(const std::string &s) {
    if (s == "nan" || s == "+inf" || s == "-inf")
        return true;
    else
        return false;
}

LiteralType isFloat(const std::string &s) {
    size_t i = 0;
    int dotCount = 0;
    if (s.size() > 1 && s[s.size() - 1] == 'f')
    {
        for (; i < s.size(); i++) {
            if (s[i] == '.')
            {
                dotCount++;
                if (dotCount > 1)
                    return UNKNOWN;
            }
        }
        i = 0;
        for (; i < s.size() - 1; i++) {
            if (!std::isdigit(static_cast<char>(s[i])) && s[i] != '.')
                return UNKNOWN;
        }
        return FLOAT_TYPE;
    }
    return CONTINUE;
}

LiteralType isDouble(const std::string &s) {
    size_t i = 0;
    int dotCount = 0;

    if (s.find('.') != std::string::npos)
    {
        dotCount = 0;
        for (; i < s.size(); i++) {
            if (s[i] == '.')
            {
                dotCount++;
                if (dotCount > 1)
                    return UNKNOWN;
            }
        }
        i = 0;
        for (; i < s.size(); i++) {
            if (!std::isdigit(static_cast<char>(s[i])) && s[i] != '.')
                return UNKNOWN;
        }
        return DOUBLE_TYPE;
    }
    return CONTINUE;
}

LiteralType isInt(const std::string &s) {
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i < s.size()) {
        for (; i < s.size(); i++) {
            if (!std::isdigit(static_cast<char>(s[i])))
                return UNKNOWN;
        }
        return INT_TYPE;
    }
    return CONTINUE;
}



LiteralType detectType(const std::string &s) {
    if (isChar(s))
        return CHAR_TYPE;

    if (isPseudoFloat(s))
        return PSEUDO_FLOAT;

    if (isPseudoDouble(s))
        return PSEUDO_DOUBLE;

    if (isFloat(s) == UNKNOWN)
        return UNKNOWN;
    else if (isFloat(s) == FLOAT_TYPE)
        return FLOAT_TYPE;

    if (isDouble(s) == UNKNOWN)
        return UNKNOWN;
    else if (isDouble(s) == DOUBLE_TYPE)
        return DOUBLE_TYPE;

    if (isInt(s) == UNKNOWN)
        return UNKNOWN;

    else if (isInt(s) == INT_TYPE)
        return INT_TYPE;

    return UNKNOWN;
}
