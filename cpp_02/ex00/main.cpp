#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;

    std::cout << a.getRawBits() << RESET << std::endl;
    std::cout << b.getRawBits() << RESET << std::endl;
    std::cout << c.getRawBits() << RESET << std::endl;


    return 0;
}
