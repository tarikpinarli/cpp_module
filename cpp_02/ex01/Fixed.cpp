#include "Fixed.hpp"
#include <cmath>   // roundf

Fixed::Fixed() : _rawValue(0) {
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) : _rawValue(other._rawValue) {
    std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << BYELLOW << "Copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        this->_rawValue = other._rawValue;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(const int n) {
    if (n > 8388607 || n < -8388608) {
        std::cerr << "\033[1;5;31m"
                  << "WARNING:" << "\033[0m" << "\033[1;91m" << " value " << n
                  << " is outside safe range (-8388608  ..  8388607 ) and may overflow when shifted!\n"
                  << "_rawValue will be set to 0 to be cautious!"
                  << "\033[0m" << std::endl;
        _rawValue = 0;
        return;
    }
    std::cout << YELLOW << "Int constructor called" << RESET << std::endl;
    _rawValue = (n << _fractionalBits);
}

Fixed::Fixed(const float f) {
    long roundFloat;

    roundFloat = roundf(f);
    if (roundFloat > 8388607 || roundFloat < -8388608)
    {
        std::cerr << "\033[1;5;31m"
            << "WARNING:" << "\033[0m" << "\033[1;91m" << " value " << f
            << " is outside safe range (-8388608  ..  8388607 ) and may overflow when shifted!\n"
            << "_rawValue will be set to 0 to be cautious!"
            << "\033[0m" << std::endl;
        _rawValue = 0;
        return;
    }
    std::cout << MAGENTA << "Float constructor called" << RESET << std::endl;
    _rawValue = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawValue) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawValue >> _fractionalBits;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called"  << std::endl;
    this->_rawValue = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs) {
    os << rhs.toFloat();
    return os;
}
