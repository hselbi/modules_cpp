#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
<<<<<<< HEAD
=======
#include <string>
>>>>>>> d9bb8f6f4a8fc9e4641c1ec4718b10c078217c9e

class Bureaucrat
{
private:
<<<<<<< HEAD
    /* data */
public:
    Bureaucrat(/* args */);
    ~Bureaucrat();
};

Bureaucrat::Bureaucrat(/* args */)
{
}

Bureaucrat::~Bureaucrat()
{
}

=======
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
>>>>>>> d9bb8f6f4a8fc9e4641c1ec4718b10c078217c9e

#endif