#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::validateGrade(int grade) const {
    if (grade < 1)
    {
        std::cout << YELLOW << "INVALID BUREAUCRAT GRADE " << "(name=" << _name << ", grade=" << grade << ")" << WHITE << std::endl;
        std::cout << "Throwing GradeTooHighException() exception, " << _name << " will be destroyed!" << std::endl;
        throw GradeTooHighException();
    }

    if (grade > 150)
    {
        std::cout << YELLOW << "INVALID BUREAUCRAT GRADE " << "(name=" << _name << ", grade=" << grade << ")" << WHITE << std::endl;
        std::cout << "Throwing GradeTooLowException() exception, " << _name << " will be destroyed!" << std::endl;
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat() : _name("Intern"), _grade(150) {
    std::cout << "[Bureaucrat] Default constractor called. (name=" << _name << ", grade=" << _grade << ")" << std::endl;
    validateGrade(_grade);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name), _grade(grade) {
    std::cout << "[Bureaucrat] Custom constractor called. (name=" << _name << ", grade=" << _grade << ")" << std::endl;
    validateGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: _name(other._name), _grade(other._grade){
    std::cout << "[Bureaucrat] Copy constractor called. (name=" << _name << ", grade=" << _grade << ")" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade;
    }
    std::cout << "[Bureaucrat] Copy operator called. (name=" << _name << ", grade=" << _grade << ")" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << RED << _name << " destroyed" << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return _name;
}
int                Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    std::cout << "Increment operator called. (" << _grade << " -> "  << _grade -1 << ")" << std::endl;
    validateGrade(_grade - 1);
    --_grade;
}

void Bureaucrat::decrementGrade() {
    std::cout << "Increment operator called. (" << _grade << " -> "  << _grade + 1 << ")" << std::endl;
    validateGrade(_grade + 1);
    ++_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    std::cout << RED;
    return "Bureaucrat grade is too high (must be >= 1).";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    std::cout << RED;
    return "Bureaucrat grade is too low (must be <= 150).";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(Form& form) const {
    if (form.isSigned())
    {
        std::cout << form.getName() << " form is already signed." << std::endl;
        return;
    }
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << "\n";
    } catch (const std::exception& e) {
        std::cout << RED << "Authority exception caught: " << WHITE << this->getName() << " couldn't sign " << form.getName()
                  << " form because " << e.what() << "\n";
    }
}
