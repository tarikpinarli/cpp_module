#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
    std::cout << "[Intern] Default Constructor called." << std::endl;
}

Intern::~Intern() {
    std::cout << RED << "[Intern] destroyed." << std::endl;
}

AForm* Intern::shruberryMaker(std::string formTarget) {
    std::cout << "Intern creates [ShrubberyCreationForm] \"" << formTarget << "\"" << std::endl;
    return (new ShrubberyCreationForm(formTarget));
}

AForm* Intern::presidentialMaker(std::string formTarget) {
    std::cout << "Intern creates [PresidentialPardonForm] \"" << formTarget << "\"" << std::endl;
    return (new PresidentialPardonForm(formTarget));
}

AForm* Intern::robotomyMaker(std::string formTarget) {
    std::cout << "Intern creates [RobotomyRequestForm] \"" << formTarget << "\"" << std::endl;
    return (new RobotomyRequestForm(formTarget));
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
    std::string forms[3] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    AForm* (Intern::*actions[3]) (std::string) = {
        &Intern::shruberryMaker,
        &Intern::robotomyMaker,
        &Intern::presidentialMaker
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == forms[i]) {
            AForm* ptr = (this->*actions[i])(formTarget);
            return ptr;
        }
    }
    throw (UnknownFormException());
    return (nullptr);
}

const char* Intern::UnknownFormException::what() const noexcept {
    return ("Unknown form to Intern.");
}



