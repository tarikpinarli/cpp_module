#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << WHITE << "\n";
}

static void subSection(const std::string& title) {
    std::cout << YELLOW << "------ " << title << " ------" << WHITE << "\n";
}

int main() {
    section("Default constructor for both Bureaucrat and Form");
    try {
        Form FoodDelivery;

        std::cout << FoodDelivery << std::endl;
        Bureaucrat intern;

        subSection("First sign attempt");
        intern.signForm(FoodDelivery);
        subSection("Second sign attempt");
        intern.signForm(FoodDelivery);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    section("Same form, different ranks: fail -> succeed -> already signed");
    try {
        Form policy("Policy", 28, 14);
        std::cout << policy << std::endl;
        Bureaucrat eng("Engineer", 90);
        Bureaucrat dir("Director", 15);

        subSection("Engineer, sign attempt");
        eng.signForm(policy);
        subSection("Director, sign attempt");
        dir.signForm(policy);
        subSection("Engineer, already signed document sign attempt");
        eng.signForm(policy);

    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    section("Default Bureaucrat and custom Form");
    try {
        Form resignationForm("Resignation", 10, 10);

        std::cout << resignationForm << std::endl;
        Bureaucrat intern;
        subSection("Low authority sign attempt");
        intern.signForm(resignationForm);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    section("Promote until sign is possible");
    try {
        Form badge("Office Access", 100, 80);
        Bureaucrat junior("Junior", 120);
        std::cout << badge << "\n" << junior << std::endl;

        subSection("Try sign (should fail first)");
        junior.signForm(badge);

        subSection("Promote until grade <= 100, then sign");
        while (junior.getGrade() > 100) {
            junior.incrementGrade();
        }
        junior.signForm(badge);
        std::cout << badge << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
