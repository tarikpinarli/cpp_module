#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>

static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << WHITE << "\n";
}

static void subSection(const std::string& title) {
    std::cout << YELLOW << "------ " << title << " ------" << WHITE << "\n";
}

int main() {

    section("Creating ShrubberyCreationForm with intern");
    try
    {
        AForm *ptr;
        subSection("Intern creation");
        Intern a;
        subSection("Form creation");
        ptr = a.makeForm("ShrubberyCreationForm", "ShrubberyCreationForm by Intern");
        delete ptr;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }
    section("Creating RobotomyRequestForm with intern");
    try
    {
        AForm *ptr;

        subSection("Intern creation");
        Intern a;
        subSection("Form creation");
        ptr = a.makeForm("RobotomyRequestForm", "RobotomyRequestForm by Intern");
        delete ptr;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }

    section("Creating PresidentialPardonForm with intern");
    try
    {
        AForm *ptr;

        subSection("Intern creation");
        Intern a;
        subSection("Form creation");
        ptr = a.makeForm("PresidentialPardonForm", "PresidentialPardonForm by Intern");
        delete ptr;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }

    section("Unknown form creation attempt");
    try
    {
        AForm *ptr;

        subSection("Intern creation");
        Intern a;
        subSection("Form creation");
        ptr = a.makeForm("unknown", "PresidentialPardonForm by Intern");
        delete ptr;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }
    std::cout << RESET;
    return 0;
}
