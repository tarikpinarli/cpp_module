#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("default ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "[ShrubberyCreationForm] Default constructor called. \"" << _target << "\" form is ready to be signed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(target, 145, 137), _target(target) {
    std::cout << "[ShrubberyCreationForm] Custom constructor called. \"" << _target << "\" form is ready to be signed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "[ShrubberyCreationForm] Copy constructor called. \"" << _target << "\" form is ready to be signed." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << "[ShrubberyCreationForm] Copy operator called. \"" << _target << "\" form is ready to be signed." << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << RED << "[ShrubberyCreationForm] \"" << _target << "\" form destroyed." << WHITE << std::endl;
}

void ShrubberyCreationForm::executeImpl() const {
    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (!outFile)
        throw std::runtime_error("Failed to open shrubbery file");
    outFile <<
"       _-_        \n"
"    /~~   ~~\\    \n"
" /~~         ~~\\ \n"
"{               }\n"
" \\  _-     -_  / \n"
"   ~  \\\\ //  ~   \n"
"_- -   | | _- _  \n"
"  _ -  | |   -_  \n"
"      // \\\\      \n";
    std::cout << "\"" << _target << "_shruberry\" file created." << std::endl;
}
