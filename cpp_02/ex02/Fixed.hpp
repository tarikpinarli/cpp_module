#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define BLINKRED   "\033[1;5;31m"
#define RED   "\033[1;31m"
#define GREEN "\033[1;92m"
#define BLUE  "\033[1;94m"
#define YELLOW  "\033[1;33m"
#define BYELLOW   "\033[1;93m"
#define MAGENTA "\033[1;35m"
#define WHITE   "\033[1;97m"
#define RESET "\033[0m"

class Fixed {
private:
    int                 _rawValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    Fixed(const int n);
    Fixed(const float f);

    int   getRawBits(void) const;
    void  setRawBits(int const raw);
    float toFloat(void) const;
    int   toInt(void) const;

    // Comparison operators
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    // Increment / Decrement
    // pre
    Fixed& operator++();
    Fixed& operator--();
    // post
    Fixed  operator++(int);
    Fixed  operator--(int);

    // min / max
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fx);

#endif
