#include "Whatever.hpp"

static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << WHITE << "\n";
}

static void subSection(const std::string& title) {
    std::cout << YELLOW << "------ " << title << " ------" << WHITE << "\n";
}


int main() {
    section("Test with integers");
    {
    int a = 2;
    int b = 3;

    subSection("a and b integers before swap");
    std::cout << "a = " << a << "\n" << "b = " << b << std::endl;
    subSection("a and b integers after swap");
    ::swap(a, b);
    std::cout << "a = " << a << "\n" << "b = " << b << std::endl;
    subSection("template min() function test");
    std::cout << ::min(a, b) << std::endl;
    subSection("template max() function test");
    std::cout << ::max(a, b) << std::endl;
    }

    section("Test with double");
    {
    double a = 2.1;
    double b = 3.1;

    subSection("a and b doubles before swap");
    std::cout << "a = " << a << "\n" << "b = " << b << std::endl;
    subSection("a and b doubles after swap");
    ::swap(a, b);
    std::cout << "a = " << a << "\n" << "b = " << b << std::endl;
    subSection("template min() function test");
    std::cout << ::min(a, b) << std::endl;
    subSection("template max() function test");
    std::cout << ::max(a, b) << std::endl;
    }

    section("Test with float");
    {
    float a = 2.1f;
    float b = 3.1f;

    subSection("a and b floats before swap");
    std::cout << "a = " << a << "\n" << "b = " << b << std::endl;
    subSection("a and b floats after swap");
    ::swap(a, b);
    std::cout << "a = " << a << "\n" << "b = " << b << std::endl;
    subSection("template min() function test");
    std::cout << ::min(a, b) << std::endl;
    subSection("template max() function test");
    std::cout << ::max(a, b) << std::endl;
    }

    section("Test with char");
    {
    char char1 = 'a';
    char char2 = 'z';

    subSection("char1 and char2 chars before swap");
    std::cout << "char1 = " << char1 << "\n" << "char2 = " << char2 << std::endl;
    subSection("char1 and char2 chars after swap");
    ::swap(char1, char2);
    std::cout << "char1 = " << char1 << "\n" << "char2 = " << char2 << std::endl;
    subSection("template min() function test");
    std::cout << ::min(char1, char2) << std::endl;
    subSection("template max() function test");
    std::cout << ::max(char1, char2) << std::endl;
    }

    section("Test with std::string");
    {
    std::string string1 = "hello";
    std::string string2 = "world";

    subSection("string1 and string2 chars before swap");
    std::cout << "string1 = " << string1 << "\n" << "string2 = " << string2 << std::endl;
    subSection("string1 and string2 chars after swap");
    ::swap(string1, string2);
    std::cout << "string1 = " << string1 << "\n" << "string2 = " << string2 << std::endl;
    subSection("template min() function test");
    std::cout << ::min(string1, string2) << std::endl;
    subSection("template max() function test");
    std::cout << ::max(string1, string2) << std::endl;
    }
    section("Subject test");
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
}
