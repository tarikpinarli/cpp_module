#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::validateGrade(int g) {
    if (g < 1)
        throw GradeTooHighException();
    if (g > 150)
        throw GradeTooLowException();
}

AForm::AForm() : _name("Food delivery"), _isSigned(false), _signGrade(150), _execGrade(150){
    std::cout << "[AForm] Default constructor called." << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << "[AForm] Custom constructor called." << std::endl;
    validateGrade(_signGrade);
    validateGrade(_execGrade);
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _execGrade(other._execGrade) {
    std::cout << "[AForm] copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    std::cout << "[AForm] Copy constructor called." << std::endl;
    return *this;
}

AForm::~AForm() {
    std::cout << RED << "[AForm] \""<< _name << "\" form destroyed" << WHITE << std::endl;
}

const std::string& AForm::getName() const noexcept {
    return _name;
}

bool AForm::isSigned() const noexcept {
    return _isSigned;
}

int AForm::getSignGrade() const noexcept {
    return _signGrade;
}

int AForm::getExecGrade() const noexcept {
    return _execGrade;
}


void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= _signGrade) {
        _isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

void AForm::execute(const Bureaucrat& executor) const{
    if (!_isSigned)
        throw NotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    executeImpl();
}

const char* AForm::GradeTooHighException::what() const noexcept {
    return "Form grade is too Low.";
}

const char* AForm::GradeTooLowException::what() const noexcept {
    return "Form grade is too High.";
}

const char* AForm::NotSignedException::what() const noexcept {
    return "Form is not signed.";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << BYELLOW << "Form details \"" << f.getName()
       << "\" [signed=" << (f.isSigned() ? "yes" : "no")
       << ", signGrade=" << f.getSignGrade()
       << ", execGrade=" << f.getExecGrade()
       << "]" << WHITE << std::endl;
    return os;
}
