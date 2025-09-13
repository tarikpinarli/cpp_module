#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
private:
    static void validateGrade(int grade);

    const       std::string _name;
    bool        _isSigned;
    const int   _signGrade;
    const int   _execGrade;
public:
    Form();
    Form(const std::string& name, int signGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const noexcept;
    bool               isSigned() const noexcept;
    int                getSignGrade() const noexcept;
    int                getExecGrade() const noexcept;

    void beSigned(const Bureaucrat& b);

    class GradeTooHighException : public std::exception {
        virtual const char* what() const noexcept override;
    };
    class GradeTooLowException : public std::exception {
        virtual const char* what() const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
