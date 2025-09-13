#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define CYAN    "\033[1;36m"
#define BLINKRED   "\033[1;5;31m"
#define RED   "\033[1;31m"
#define GREEN "\033[1;92m"
#define DGREEN "\033[1;32m"
#define BLUE  "\033[1;94m"
#define YELLOW  "\033[1;33m"
#define BYELLOW   "\033[1;93m"
#define MAGENTA "\033[1;35m"
#define WHITE   "\033[1;97m"
#define RESET "\033[0m"

class Form;

class Bureaucrat {
private:
    void validateGrade(int grade) const;

    const std::string _name;
    int               _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int                getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form& form) const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
