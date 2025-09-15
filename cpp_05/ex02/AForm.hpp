#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
private:
    static void validateGrade(int g);

    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _execGrade;
protected:
    virtual void executeImpl() const = 0;
public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string&  getName() const noexcept;
    bool                isSigned() const noexcept;
    int                 getSignGrade() const noexcept;
    int                 getExecGrade() const noexcept;

    void    beSigned(const Bureaucrat& b);
    void    execute(const Bureaucrat& executor) const;
    void executeForm(const AForm& form) const;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
    class NotSignedException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
