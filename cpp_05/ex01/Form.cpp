#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::validateGrade(int grade) {
    if (grade < 1)   throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
}

Form::Form() : _name("Food Delivery"), _isSigned(false),  _signGrade(150), _execGrade(150) {

};

Form::Form(const std::string& name, int signGrade, int execGrade)
: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    validateGrade(_signGrade);
    validateGrade(_execGrade);
}

Form::Form(const Form& other)
: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {

}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {

}

const std::string& Form::getName() const noexcept {
    return _name;
}
bool               Form::isSigned() const noexcept {
    return _isSigned;
}
int                Form::getSignGrade() const noexcept {
    return _signGrade;
}
int                Form::getExecGrade() const noexcept {
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
    return "Form grade is too high (must be >= 1).";
}
const char* Form::GradeTooLowException::what() const noexcept {
    return "Form grade is too low (must be <= 150, or signer grade too low).";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form \"" << f.getName()
       << "\" [signed=" << (f.isSigned() ? "yes" : "no")
       << ", signGrade=" << f.getSignGrade()
       << ", execGrade=" << f.getExecGrade()
       << "]";
    return os;
}
