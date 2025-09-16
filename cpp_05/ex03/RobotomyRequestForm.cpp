#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("default RobotomyRequestForm", 72, 45), _target("default") {
    std::cout << "[RobotomyRequestForm] Default constructor called. \"" << _target << "\" form is ready to be signed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(target, 72, 45), _target(target) {
    std::cout << "[RobotomyRequestForm] Custom constructor called. \"" << _target << "\" form is ready to be signed." << std::endl;;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "[RobotomyRequestForm] copy constructor called. \"" << _target << "\" form is ready to be signed." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "[RobotomyRequestForm] assignment operator called. \"" << _target << "\" form is ready to be signed." << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << RED << "[RobotomyRequestForm] \"" << _target << "\" destroyed." << std::endl;
}

void RobotomyRequestForm::executeImpl() const {
    std::cout << "bzzzz... brrrr...\n";
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed on " << _target << ".\n";
}
