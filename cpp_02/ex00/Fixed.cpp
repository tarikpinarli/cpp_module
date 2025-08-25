#include "Fixed.hpp"

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

int Fixed::getRawBits(void) const {
    std::cout << YELLOW << "getRawBits member function called" << WHITE << std::endl;
    return this->_rawValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << MAGENTA << "setRawBits member function called" << RESET << std::endl;
    this->_rawValue = raw;
}
