#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
