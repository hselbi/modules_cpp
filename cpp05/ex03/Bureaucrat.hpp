#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    std::string _name;
    int _grade;
public:
    Bureaucrat(void); //default constructor
    Bureaucrat(int grade); //user-define
    Bureaucrat(std::string name);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &src); // copy constructor

    void executeForm(Form const & form);

    void increaseGrade();
    void decreaseGrade();
    
    // getters
    const std::string getName(void) const;
    int getGrade(void) const;

    void signForm(Form &target);

    class GradeTooLowException : public std::exception{
        const char *what() const throw() {
            return "Grade Too Low";
        }
    };

    class GradeTooHighException : public std::exception{
        const char *what() const throw() {
            return "Grade Too High";
        }
    };
    ~Bureaucrat(); // default destructor
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat &src);

#endif