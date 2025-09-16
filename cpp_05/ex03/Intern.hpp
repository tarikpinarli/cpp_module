#pragma once
#include <iostream>
#include <exception>
class AForm;

class Intern {
public:
    Intern();
    ~Intern();
    AForm* makeForm(std::string formName, std::string formTarget);
    AForm* shruberryMaker(std::string formTarget);
    AForm* robotomyMaker(std::string formTarget);
    AForm* presidentialMaker(std::string formTarget);

    class UnknownFormException : public std::exception {
    public:
        const char* what() const noexcept override;
    };

};
