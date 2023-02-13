#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
    std::string _name;
    int _grade;
public:
    // Othodox Canonical From;
    Bureaucrat(void);
    Bureaucrat(const Bureaucrat &target);
    Bureaucrat &operator=(const Bureaucrat &target);
    ~Bureaucrat();
    
    // this is constructor parameterized 
    Bureaucrat(int grade);
    Bureaucrat(std::string name);
    Bureaucrat(std::string name, int garde);

    class GradeTooHighException: public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        const char *what() const throw();
    };

    // getter
    std::string getName() const;
    int getGrade() const;

    // increment and decrement

    void incrementGrade();
    void decrementGrade();

};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src);

#endif