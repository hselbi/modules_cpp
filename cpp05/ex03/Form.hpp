
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

class Bureaucrat;

class Form
{
private:
    std::string name_;
    std::string targetForm;
    bool issigned;
    int signGrade;
    int excuteGrade;
public:
    Form(void) ;
    Form(std::string name, int siGrade, int exGrade);
    Form(std::string name, std::string target, int siGrade, int exGrade);
    virtual ~Form();
    Form(const Form& src);
    Form &operator=(const Form &src);

    void beSigned(Bureaucrat &src);

    std::string getName() const;
    std::string getTargetForm() const;
    bool getSigned() const;
    int getSignedGrade() const;
    int getExcuteGrade() const;

    class GradeTooLowException: std::exception {
        const char* what() const throw()
        {
            return "Grade Too Low";
        }
    };
    class GradeTooHighException: std::exception {
        const char* what() const throw()
        {
            return "Grade Too High";
        }
    };
    class isNotSigned: public std::exception
    {
        const char* what() const throw()
        {
            return ("Unfortuanally, it's not signed!");
        }
    };
    class lowGrade: public std::exception
    {
        const char* what() const throw()
        {
            return ("Unfortuanally, Grade is inadequate!");
        }
    };
};


std::ostream& operator<<(std::ostream &o, const Form &src);


#endif