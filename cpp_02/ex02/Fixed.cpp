#include "Fixed.hpp"
#include <cmath> // roundf

Fixed::Fixed() : _rawValue(0) {}

Fixed::Fixed(const Fixed& other) : _rawValue(other._rawValue) {}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_rawValue = other._rawValue;
    }
    return *this;
}

Fixed::~Fixed() {}

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
    _rawValue = static_cast<int>( std::roundf(f * (1 << _fractionalBits)) );
}

int Fixed::getRawBits(void) const {
    return this->_rawValue;
}

void Fixed::setRawBits(int const raw) {
    this->_rawValue = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawValue) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed& rhs) const  {
    return _rawValue >  rhs._rawValue;
}
bool Fixed::operator<(const Fixed& rhs) const  {
    return _rawValue <  rhs._rawValue;
}
bool Fixed::operator>=(const Fixed& rhs) const {
    return _rawValue >= rhs._rawValue;
}
bool Fixed::operator<=(const Fixed& rhs) const {
    return _rawValue <= rhs._rawValue;
}
bool Fixed::operator==(const Fixed& rhs) const {
    return _rawValue == rhs._rawValue;
}
bool Fixed::operator!=(const Fixed& rhs) const {
    return _rawValue != rhs._rawValue;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed out;
    out._rawValue = this->_rawValue + rhs._rawValue;
    return out;
}
Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed out;
    out._rawValue = this->_rawValue - rhs._rawValue;
    return out;
}
Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed out;
    long long prod = static_cast<long long>(this->_rawValue) * rhs._rawValue;
    out._rawValue = static_cast<int>( prod >> _fractionalBits );
    return out;
}
Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed out;
    if (rhs._rawValue == 0) {
        std::cerr << "\033[1;5;31m"
            << "WARNING:" << "\033[0m" << " You can't devide left hand side value with 0! "
            << WHITE << "output value will be set to 0!"
            << std::endl;
        out._rawValue = 0;
    } else {
        long long num = (static_cast<long long>(this->_rawValue) << _fractionalBits);
        out._rawValue = static_cast<int>( num / rhs._rawValue );
    }
    return out;
}

Fixed& Fixed::operator++() {
    ++_rawValue;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    ++_rawValue;
    return tmp;
}
Fixed& Fixed::operator--() {
    --_rawValue;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    --_rawValue;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}
