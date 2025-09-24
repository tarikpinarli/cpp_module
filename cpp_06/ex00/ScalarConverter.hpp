#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>   // cout/cerr
#include <iomanip>    // fixed, setprecision
#include <string>     // std::string, substr, find, c_str
#include <climits>    // INT_MIN, INT_MAX
#include <cstdlib>    // strtod
#include <cctype>     // isdigit
#include <cmath>      // isnan, isinf
#include <limits>     // numeric_limits, quiet_NaN(), infinity()

enum LiteralType {
    CHAR_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    PSEUDO_FLOAT,
    PSEUDO_DOUBLE,
    UNKNOWN,
    CONTINUE
};

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();
};

LiteralType detectType(const std::string &s);
void printDouble(double d);
void printFloat(double d);
void printInt(double d);
void printChar(double d);

#endif




