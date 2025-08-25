#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

static void show(const char* name, const Fixed& x) {
    std::cout << GREEN << std::left << std::setw(8) << name << RESET
              << " -> "
              << WHITE << x << RESET
              << "  (raw=" << x.getRawBits()
              << ", int=" << x.toInt() << ")\n";
}

int main(void) {
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2) );
    Fixed c(3);
    Fixed d(3.5f);

    std::cout << BLUE << "\n------Comparison Operations------\n" << WHITE << std::endl;

    show("a", a);
    show("b", b);
    show("c", c);
    show("d", d);
    std::cout << std::endl;
    std::cout << BYELLOW << "a < b : "  << ( (a < b) ? GREEN "true" : RED "false" ) << BYELLOW "\n";
    std::cout << "a <= b : " << ( (a <= b) ? GREEN "true" : RED "false" ) << BYELLOW << "\n";
    std::cout << "a >  b : " << ( (a >  b) ? GREEN "true" : RED "false" ) << BYELLOW << "\n";
    std::cout << "a >= b : " << ( (a >= b) ? GREEN "true" : RED "false" ) << BYELLOW << "\n";
    std::cout << "a == b : " << ( (a == b)? GREEN "true" : RED "false" ) << BYELLOW << "\n";
    std::cout << "a != b : " << ( (a != b) ? GREEN "true" : RED "false" ) << BYELLOW << "\n";
    std::cout << "c == 3 : " << ( (c == 3) ? GREEN "true" : RED "false" ) << BYELLOW << "\n";
    std::cout << "d >  c : " << ( (d > c) ? GREEN "true" : RED "false" ) << BYELLOW << "\n";

    std::cout << BLUE << "\n------Arithmatic Operations------\n" << WHITE << std::endl;

    show("a", a);
    show("c", c);
    show("(a + c)", a + c);
    std::cout << YELLOW << "---------------------------------" << WHITE << std::endl;
    show("b", b);
    show("d", d);
    show("(b - d)", b - d);
    std::cout << YELLOW << "---------------------------------" << WHITE << std::endl;
    show("c", c);
    show("d", d);
    show("(c * d)", c * d);
    std::cout << YELLOW << "---------------------------------" << WHITE << std::endl;
    show("b", b);
    show("c", c);
    show("(b / c)", b / c);
    std::cout << YELLOW << "---------------------------------" << WHITE << std::endl;
    show("a", a);
    show("a", a);
    show("(a * a)", a * a);
    std::cout << YELLOW << "---------------------------------" << WHITE << std::endl;
    // Divition by 0
    show("b", b);
    show("a", a);
    show("(b / a)", b / a);
    std::cout << YELLOW << "---------------------------------" << WHITE << std::endl;
    show("a", a);
    show("b", b);
    show("c", c);
    show("(a + b) * c", (a + b) * c);
    std::cout << YELLOW << "---------------------------------" << WHITE << std::endl;
    show("a", a);
    show("b", b);
    show("c", c);
    show("d", d);
    show("a + b + c + d", a + b + c + d);

    std::cout << BLUE << "\n------Arithmatic Operator Chaining------\n" << WHITE << std::endl;
    Fixed e(1);
    Fixed f(2);
    Fixed g(3);
    Fixed chain;

    show("a", a);
    show("b", b);
    show("c", c);
    show("d", d);
    show("e", e);
    show("f", f);
    show("g", g);
    std::cout << std::endl;
    chain = e + f * g * (a + 1) / (b - c) / d;
    show("e + f * g * (a + 1) / (b - c) / d", chain);

    std::cout << BLUE << "\n------Increment / Decrement------\n" << WHITE << std::endl;

    show("a (start)", a);
    std::cout << BYELLOW << "++a -> " << ( ++a ) << "\n";
    show("a", a);
    std::cout << BYELLOW << "a++ -> " << ( a++ ) << "\n";
    show("a", a);
    std::cout << BYELLOW << "--a -> " << ( --a ) << "\n";
    show("a", a);
    std::cout << BYELLOW << "a-- -> " << ( a-- ) << "\n";
    show("a", a);

    std::cout << BLUE << "\n------Min / Max (non-const & const overloads)------\n" << WHITE << std::endl;

    Fixed h1(4.0f);
    Fixed h2(4.5f);
    const Fixed i1(8.0f);
    const Fixed i2(2.0f);

    show("m1", h1);
    show("m2", h2);
    show("const cm1", i1);
    show("const cm2", i2);
    std::cout << std::endl;
    std::cout << MAGENTA << "min(h1, h2)" << RESET << " -> "
              << WHITE << Fixed::min(h1, h2) << RESET << "\n";
    std::cout << MAGENTA << "max(h1, h2)" << RESET << " -> "
              << WHITE << Fixed::max(h1, h2) << RESET << "\n";
    std::cout << YELLOW << "min(const i1, const i2)" << RESET << " -> "
              << WHITE << Fixed::min(i1, i2) << RESET << "\n";
    std::cout << YELLOW << "max(const i1, const i2)" << RESET << " -> "
              << WHITE << Fixed::max(i1, i2) << RESET << "\n";

    return 0;
}
