#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << WHITE << "\n";
}

static void subSection(const std::string& title) {
    std::cout << YELLOW << "------ " << title << " ------" << WHITE << "\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    section("ShrubberyCreationForm (Success)");
    try
    {
        subSection("Bureaucrat creation");
        Bureaucrat ceo("CEO", 1);
        Bureaucrat cfo("CFO", 10);
        subSection("ShrubberyCreationForm creation");
        ShrubberyCreationForm bigDecision("Big Decision");
        std::cout << bigDecision;
        subSection("Sign attempt");
        cfo.signForm(bigDecision);
        subSection("Executiom attempt");
        ceo.executeForm(bigDecision);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }

    section("ShrubberyCreationForm (signiture authority fail)");
    try
    {
        subSection("Bureaucrat creation");
        Bureaucrat ceo("CEO", 1);
        Bureaucrat intern;
        subSection("ShrubberyCreationForm creation");
        ShrubberyCreationForm bigDecision("Big Decision");
        std::cout << bigDecision;
        subSection("Sign attempt");
        intern.signForm(bigDecision);
        subSection("Execution attempt");
        ceo.executeForm(bigDecision);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }

    section("ShrubberyCreationForm (excution authority fail)");
    try
    {
        subSection("Bureaucrat creation");
        Bureaucrat doctor("Doctor", 20);
        Bureaucrat intern;
        subSection("ShrubberyCreationForm creation");
        ShrubberyCreationForm healthApproval("Health Approval");
        std::cout << healthApproval;
        subSection("Sign attempt");
        doctor.signForm(healthApproval);
        subSection("Execution attempt");
        intern.executeForm(healthApproval);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }

    section("RobotomyRequestForm (Success)");
    try
    {
        subSection("Bureaucrat creation");
        Bureaucrat ceo("CEO", 1);
        Bureaucrat eng("Engineer", 30);
        subSection("RobotomyRequestForm creation");
        RobotomyRequestForm optimus("Optimus Project");
        std::cout << optimus;
        subSection("Sign attempt");
        ceo.signForm(optimus);
        subSection("Execution attempt");
        eng.executeForm(optimus);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }

    section("RobotomyRequestForm (signiture authority fail)");
    try
    {
        subSection("Bureaucrat creation");
        Bureaucrat ceo("CEO", 1);
        Bureaucrat juniorEngineer("Junior Engineer", 73);
        subSection("ShrubberyCreationForm creation");
        RobotomyRequestForm optimus("Optimus Project");
        std::cout << optimus;
        subSection("Sign attempt");
        juniorEngineer.signForm(optimus);
        subSection("Execution attempt");
        ceo.executeForm(optimus);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }

    section("RobotomyRequestForm (execution grade fail)");
    try
    {
        subSection("Bureaucrat creation");
        Bureaucrat ceo("CEO", 1);
        Bureaucrat juniorEngineer("Junior Engineer", 73);
        subSection("ShrubberyCreationForm creation");
        RobotomyRequestForm optimus("Optimus Project");
        std::cout << optimus;
        subSection("Sign attempt");
        ceo.signForm(optimus);
        subSection("Execution attempt");
        juniorEngineer.executeForm(optimus);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }

    section("PresidentialPardonForm (Success)");
    try
    {
        subSection("Bureaucrat creation");
        Bureaucrat rick("Rick", 1);
        Bureaucrat morty("morty", 10);
        subSection("PresidentialPardonForm creation");
        PresidentialPardonForm pardon("Summer");
        std::cout << pardon;
        subSection("Sign attempt");
        morty.signForm(pardon);
        rick.signForm(pardon);
        subSection("Execution attempt");
        rick.executeForm(pardon);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }

    section("PresidentialPardonForm (signiture authority fail)");
    try
    {
        subSection("Bureaucrat creation");
        Bureaucrat rick("Rick", 1);
        Bureaucrat Jerry("Jerry Smith", 80);
        subSection("PresidentialPardonForm creation");
        PresidentialPardonForm pardon("Summer");
        std::cout << pardon;
        subSection("Sign attempt");
        Jerry.signForm(pardon);
        subSection("Execution attempt");
        rick.executeForm(pardon);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }

    section("PresidentialPardonForm (execution grade fail)");
    try
    {
        subSection("Bureaucrat creation");
        Bureaucrat rick("Rick", 1);
        Bureaucrat Jerry("Jerry Smith", 80);
        subSection("PresidentialPardonForm creation");
        PresidentialPardonForm pardon("Summer");
        std::cout << pardon;
        subSection("Sign attempt");
        rick.signForm(pardon);
        subSection("Execution attempt");
        Jerry.executeForm(pardon);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "UNEXPECTED: " << e.what() << "\n";
    }


    return 0;
}
