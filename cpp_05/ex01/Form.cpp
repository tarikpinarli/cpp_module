#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::validateGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Form::Form() : _name("Food Delivery"), _isSigned(false),  _signGrade(150), _execGrade(150) {
    std::cout << "[Form] Default constractor called.\n'" << _name << "' form is waiting to be signed."  << std::endl;
};

Form::Form(const std::string& name, int signGrade, int execGrade)
: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << "[Form] Custom constractor called.\n" << _name << " form is waiting to be signed."  << std::endl;
    validateGrade(_signGrade);
    validateGrade(_execGrade);
}

Form::Form(const Form& other)
: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {
    std::cout << "[Form] Copy constractor called." << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    std::cout << "[Form] Copy operator called." << std::endl;
    return *this;
}

Form::~Form() {
    std::cout << RED << _name << " destroyed" << std::endl;
}

const std::string& Form::getName() const noexcept {
    return _name;
}
bool    Form::isSigned() const noexcept {
    return _isSigned;
}
int Form::getSignGrade() const noexcept {
    return _signGrade;
}
int Form::getExecGrade() const noexcept {
    return _execGrade;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= _signGrade) {
        _isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const noexcept {
    return "Form grade is too low.";
}
const char* Form::GradeTooLowException::what() const noexcept {
    return "Form grade is too high.";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << BYELLOW << "Form details \"" << f.getName()
       << "\" [signed=" << (f.isSigned() ? "yes" : "no")
       << ", signGrade=" << f.getSignGrade()
       << ", execGrade=" << f.getExecGrade()
       << "]" << WHITE;
    return os;
}
