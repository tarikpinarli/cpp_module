#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter&) {

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

ScalarConverter::~ScalarConverter() {

}

void ScalarConverter::convert(const std::string& s) {
    LiteralType type = detectType(s);
    double d = 0.0;

    switch (type) {
        case CHAR_TYPE: {
            char c = s[0];
            std::cout << "char: '" << c << "'\n";
            std::cout << "int: " << static_cast<int>(c) << "\n";
            std::cout << std::fixed << std::setprecision(1)
                      << "float: " << static_cast<float>(c) << "f\n"
                      << "double: " << static_cast<double>(c) << "\n";
            break;
        }
        case INT_TYPE: {
            d = std::strtod(s.c_str(), 0);
            printChar(d);
            printInt(d);
            printFloat(d);
            printDouble(d);
            break;
        }
        case FLOAT_TYPE: {
            std::string core = s.substr(0, s.size() - 1);
            d = std::strtod(core.c_str(), 0);
            printChar(d);
            printInt(d);
            printFloat(d);
            printDouble(d);
            break;
        }
        case DOUBLE_TYPE: {
            d = std::strtod(s.c_str(), 0);
            printChar(d);
            printInt(d);
            printFloat(d);
            printDouble(d);
            break;
        }
        case PSEUDO_FLOAT: {
            if (s == "nanf")
                d = std::numeric_limits<double>::quiet_NaN();
            else if (s == "+inff")
                d = std::numeric_limits<double>::infinity();
            else if (s == "-inff")
                d = -std::numeric_limits<double>::infinity();
            printChar(d);
            printInt(d);
            if (std::isnan(d))
                std::cout << "float: nanf\n";
            else if (d > 0)
                std::cout << "float: +inff\n";
            else
                std::cout << "float: -inff\n";

            if (std::isnan(d))
                std::cout << "double: nan\n";
            else if (d > 0)
                std::cout << "double: +inf\n";
            else
                std::cout << "double: -inf\n";
            break;
        }
        case PSEUDO_DOUBLE: {
            if (s == "nan")
                d = std::numeric_limits<double>::quiet_NaN();
            else if (s == "+inf")
                d = std::numeric_limits<double>::infinity();
            else if (s == "-inf")
                d = -std::numeric_limits<double>::infinity();
            printChar(d);
            printInt(d);
            printFloat(d);
            printDouble(d);
            break;
        }
        default:
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            break;
    }
}
