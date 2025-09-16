#include "PresidentialPardonForm.hpp"
#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("default PresidentialPardonForm", 25, 5), _target("default") {
    std::cout << "[PresidentialPardonForm] Default constructor called. \"" << _target << "\" form is ready to be signed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(target, 25, 5), _target(target) {
    std::cout << "[PresidentialPardonForm] Custom constructor called. \"" << _target << "\" form is ready to be signed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "[PresidentialPardonForm] Copy constructor called. \"" << _target << "\" form is ready to be signed." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << "[PresidentialPardonForm] Copy operator called. \"" << _target << "\" form is ready to be signed." << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << RED << "[PresidentialPardonForm] \"" << _target << "\" destroyed." << std::endl;
}

void PresidentialPardonForm::executeImpl() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
