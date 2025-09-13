#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
public:
    // Orthodox Canonical Form
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string& getName() const;
    int                getGrade() const;

    // Grade modifiers (remember: 1 is highest, 150 is lowest)
    void incrementGrade(); // 3 -> 2
    void decrementGrade(); // 3 -> 4

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
    };

private:
    Bureaucrat(); // not implemented: name must be set

    void validateGrade(int grade) const;

    const std::string _name;
    int               _grade;
};

// Insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP
