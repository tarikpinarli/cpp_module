#include "Bureaucrat.hpp"

void Bureaucrat::validateGrade(int grade) const {
    if (grade < 1)  throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name), _grade(grade) {
    validateGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: _name(other._name), _grade(other._grade) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // _name is const and cannot be reassigned (by design).
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() { }

// --- Getters -----------------------------------------------------------------
const std::string& Bureaucrat::getName() const { return _name; }
int                Bureaucrat::getGrade() const { return _grade; }

// --- Mutators ----------------------------------------------------------------
void Bureaucrat::incrementGrade() {
    validateGrade(_grade - 1);
    --_grade;
}

void Bureaucrat::decrementGrade() {
    validateGrade(_grade + 1);
    ++_grade;
}

// --- Exceptions --------------------------------------------------------------
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Bureaucrat grade is too high (must be >= 1).";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Bureaucrat grade is too low (must be <= 150).";
}

// --- Operator<< --------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
