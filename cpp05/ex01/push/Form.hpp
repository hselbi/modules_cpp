#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
    std::string _name;
    bool isSigned;
    int signGrade;
    int requiredGrade;
public:
    Form(void);
    Form(std::string name, int siGrade, int exGrade);
    Form(const Form &src);
    Form &operator=(const Form &src);
    ~Form();

    // Exceptions
    class GradeTooHighException: public std::exception
    {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        public:
            const char* what() const throw();
    };

    void beSigned(const Bureaucrat &src);

    // getters
    std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getRequiredGrade() const;
};

std::ostream& operator<<(std::ostream &o, const Form &src);


#endif