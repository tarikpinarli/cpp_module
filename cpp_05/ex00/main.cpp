#include "Bureaucrat.hpp"
#include <iostream>

static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << WHITE << "\n";
}

static void subSection(const std::string& title) {
    std::cout << YELLOW << "------ " << title << " ------" << WHITE << "\n";
}

int main() {
    section("Default constructor test");
    try {
    Bureaucrat deneme;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    section("Copy constructor test");
    try {
        Bureaucrat c1("SHOULD COPY", 50);
        Bureaucrat c2(c1);

        std::cout << "(name=" << c2.getName() << ", grade=" << c2.getGrade() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    section("Copy operator test");
    try {
        Bureaucrat c1("SHOULDNT COPY", 50);
        Bureaucrat c2;

        c2 = c1;
        std::cout << "(name=" << c2.getName() << ", grade=" << c2.getGrade() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    section("Valid custom construction (no exception)");
    try {
        Bureaucrat ok("MiddleMan", 75);
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    section("Invalid custom construction: too high (grade < 1)");
    try {
        Bureaucrat badHigh("BadHigh", 0);
    } catch (const std::exception& e) {
        std::cout << WHITE << "Caught exception: " << e.what() << "\n";
    }

    section("Invalid custom construction: too low (grade > 150))");
    try {
        Bureaucrat badLow("BadLow", 200);
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    section("Increment at top boundary (1 -> 0) should throw");
    try {
        Bureaucrat top("Top", 1);
        top.incrementGrade();
    } catch (const std::exception& e) {
        std::cout << WHITE << "Caught exception: " << e.what() << "\n";
    }

    section("Decrement at bottom boundary (150 -> 151) should throw");
    try {
        Bureaucrat bottom("Bottom", 150);
        bottom.decrementGrade();
    } catch (const std::exception& e) {
        std::cout << WHITE << "Caught exception: " << e.what() << "\n";
    }
    section("Career rock bottom test");
    try
    {
        Bureaucrat fall("Loser", 140);
        for (int i = 50; i > 0; i--)
            fall.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << WHITE << "Caught exception: " << e.what() << "\n";
    }

    section("Promising bureaucrat test");
    try
    {
        Bureaucrat fall("Winner", 10);
        for (int i = 50; i > 0; i--)
            fall.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << WHITE << "Caught exception: " << e.what() << "\n";
    }

    section("operator<< overload test");
    try {
        Bureaucrat a("Alice", 42);
        Bureaucrat b("Bob", 1);
        Bureaucrat c("Charlie", 150);

        subSection("Testing operator<< overload: a, b, c");
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << RESET;
    return 0;
}
