#include "ScalarConverter.hpp"

void printChar(double d) {
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0.0 || d > 127.0) {
        std::cout << "impossible\n";
        return;
    }
    if (d < 32.0 || d == 127.0) {
        std::cout << "Non displayable\n";
        return;
    }
    std::cout << "'" << static_cast<char>(d) << "'\n";
}

void printInt(double d) {
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX) {
        std::cout << "impossible\n";
        return;
    }
    std::cout << static_cast<int>(d) << "\n";
}

void printFloat(double d) {
    std::cout << "float: ";
    if (std::isnan(d)) {
        std::cout << "nanf\n";
        return;
    }
    if (std::isinf(d)) {
        if (d > 0)
            std::cout << "+inff\n";
        else
            std::cout << "-inff\n";
        return;
    }
    float f = static_cast<float>(d);
    std::cout << std::fixed << std::setprecision(1) << f << "f\n";
}

void printDouble(double d) {
    std::cout << "double: ";
    if (std::isnan(d)) {
        std::cout << "nan\n";
        return;
    }
    if (std::isinf(d)) {
        if (d > 0) std::cout << "+inf\n";
        else std::cout << "-inf\n";
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << d << "\n";
}
